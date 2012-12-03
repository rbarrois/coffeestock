#include <check.h>
#include <stdlib.h>  // EXIT_*

#include "../src/lcoffee/stock.h"


// Initalizing an 'operation' of 'inventory' kind
START_TEST (init_operation_inv)
{
  operation_t* op = operation_init(OP_INVENTORY);
  fail_unless(op->kind == OP_INVENTORY, NULL);
  for (size_t i = 0; i < COFFEE_NB_KINDS; ++i) {
    fail_unless(op->items[i] == 0, NULL);
  }
  operation_delete(op);
}
END_TEST

// Initalizing an 'operation' of 'buy' kind
START_TEST (init_operation_buy)
{
  operation_t* op = operation_init(OP_BUY);
  fail_unless(op->kind == OP_BUY);
  for (size_t i = 0; i < COFFEE_NB_KINDS; ++i) {
    fail_unless(op->items[i] == 0);
  }
  operation_delete(op);
}
END_TEST

// Initalizing an 'operation' of 'sell' kind
START_TEST (init_operation_sell)
{
  operation_t* op = operation_init(OP_SELL);
  fail_unless(op->kind == OP_SELL);
  for (size_t i = 0; i < COFFEE_NB_KINDS; ++i) {
    fail_unless(op->items[i] == 0);
  }
  operation_delete(op);
}
END_TEST

// Adding an operation to some stock
START_TEST (stock_apply_operation)
{
  operation_t* op = operation_init(OP_BUY);
  operation_set(op, COFFEE_RISTRETTO_FORTE, 2);
  operation_set(op, COFFEE_LUNGO_FORTE, 3);

  stock_t* stock = stock_init();
  stock_update(stock, op);

  fail_unless(stock->items[COFFEE_RISTRETTO_INDIA] == 0, NULL);
  fail_unless(stock->items[COFFEE_RISTRETTO_FORTE] == 2, NULL);
  fail_unless(stock->items[COFFEE_LUNGO_FORTE] == 3, NULL);

  stock_delete(stock);
  operation_delete(op);
}
END_TEST

// Adding many operations to some stock
START_TEST (stock_apply_many_operation)
{
  operation_t* op1 = operation_init(OP_BUY);
  operation_set(op1, COFFEE_RISTRETTO_FORTE, 2);
  operation_set(op1, COFFEE_LUNGO_FORTE, 3);

  operation_t* op2 = operation_init(OP_SELL);
  operation_set(op2, COFFEE_RISTRETTO_FORTE, 1);
  operation_set(op2, COFFEE_LUNGO_FORTE, 1);

  operation_t* op3 = operation_init(OP_BUY);
  operation_set(op3, COFFEE_RISTRETTO_FORTE, 4);
  operation_set(op3, COFFEE_RISTRETTO_INDIA, 8);

  stock_t* stock = stock_init();
  stock_update(stock, op1);
  stock_update(stock, op2);
  stock_update(stock, op3);

  fail_unless(stock->items[COFFEE_RISTRETTO_INDIA] == 8, NULL);
  fail_unless(stock->items[COFFEE_RISTRETTO_FORTE] == 2 + 4 - 1, NULL);
  fail_unless(stock->items[COFFEE_LUNGO_FORTE] == 3 - 1, NULL);
  fail_unless(stock->items[COFFEE_ESPRESSO_FORTE] == 0, NULL);

  stock_delete(stock);
  operation_delete(op1);
  operation_delete(op2);
  operation_delete(op3);
}
END_TEST


Suite * stock_suite(void)
{
  Suite *s = suite_create("stock");

  /* 'operation' test case */
  TCase *tc_operation = tcase_create("operation");
  tcase_add_test(tc_operation, init_operation_inv);
  tcase_add_test(tc_operation, init_operation_buy);
  tcase_add_test(tc_operation, init_operation_sell);
  suite_add_tcase(s, tc_operation);

  TCase *tc_stock = tcase_create("stock");
  tcase_add_test(tc_stock, stock_apply_operation);
  tcase_add_test(tc_stock, stock_apply_many_operation);
  suite_add_tcase(s, tc_stock);

  return s;
}


int main (void)
{
    int number_failed;
    Suite *s = stock_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
