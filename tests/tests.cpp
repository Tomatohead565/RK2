#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "decorator.cpp"
#include <string>

TEST(WindowTest, BasicWindow) {
  std::unique_ptr<IWindow> window = std::make_unique<Window>();
  testing::internal::CaptureStdout();
  window->draw();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Basic Window\n");
}

TEST(WindowTest, WindowWithBorder) {
  std::unique_ptr<IWindow> window = std::make_unique<Window>();
  window = std::make_unique<BorderDecorator>(std::move(window));
  testing::internal::CaptureStdout();
  window->draw();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Basic Window\n\twith Border\n");
}

TEST(WindowTest, WindowWithScrollBar) {
  std::unique_ptr<IWindow> window = std::make_unique<Window>();
  window = std::make_unique<ScrollBarDecorator>(std::move(window));
  testing::internal::CaptureStdout();
  window->draw();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Basic Window\n\twith ScrollBar\n");
}

