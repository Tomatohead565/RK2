#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "decorator.cpp"
#include <string>

TEST(DecoratorTest, SimpleDrink) {
  Drink* drink = new Water();
  testing::internal::CaptureStdout();
  ClientCode(drink);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Description: Water\ntotal cost is:1\n");
  delete drink;
}

TEST(DecoratorTest, DrinkWithMilk) {
  Drink* drink = new Water();
  drink = new Milk(drink);
  testing::internal::CaptureStdout();
  ClientCode(drink);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Description: Milk + Water\ntotal cost is:2.5\n");
  delete drink;
}

TEST(DecoratorTest, DrinkWithMilkAndCoffee) {
  Drink* drink = new Water();
  drink = new Milk(drink);
  drink = new coffe(drink);
  testing::internal::CaptureStdout();
  ClientCode(drink);
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Description: Coffe + Milk + Water\ntotal cost is:4.5\n");
  delete drink;
}


