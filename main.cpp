#include <stdio.h>
#include <RGBConverter.h>
#include <gtest/gtest.h>

#define RGB_R 65
#define RGB_G 100
#define RGB_B 37

TEST(UnitCoversion, IntToDouble_single) {
  double x = 0.00000, x_res;
  int color = 0;
  for(; color < 10; color++) {
    printf("%d -> (expected: %.5f | actual: %.5f", color, x, x_res);
    RGBConverter::rgbIntToDouble_single(color, &x_res);
    EXPECT_NEAR(x, x_res, 0.0001);
    x+=0.004;
  }
}

int main(int argc, char** argv) {
  // Small demo
  double r, g, b;
  int _r, _g, _b;
  double h, s, l, _h, _s, _l;

  RGBConverter::rgbIntToDouble(RGB_R, RGB_G, RGB_B, &r, &g, &b);
  printf("RGB(int) -> RGB(double) -> HSL -> RGB(double) -> RGB(int)\n");
  printf("RGB: %d %d %d\n", RGB_R, RGB_G, RGB_B);
  printf("RGB: %.2f %.2f %.2f\n", r, g, b);

  RGBConverter::rgbToHsl(r, g, b, &h, &s, &l);
  printf("HSL: %.2f %.2f %.2f\n", h, s, l);
  RGBConverter::hslIntervalZeroOneToDegAndPercentage(h, s, l, &_h, &_s, &_l);
  printf("HSL: %.2f\u00B0 %.2f%% %.2f%%\n", _h, _s, _l);
  RGBConverter::hslDegAndPercentageToIntervalZeroOne(_h, _s, _l, &h, &s, &l);
  printf("HSL: %.2f %.2f %.2f\n", h, s, l);

  RGBConverter::hslToRgb(h, s, l, &r, &g, &b);
  printf("RGB: %.2f %.2f %.2f\n", r, g, b);
  RGBConverter::rgbDoubleToInt(r, g, b, &_r, &_g, &_b);
  printf("RGB: %d %d %d\n", _r, _g, _b);

  // Tests
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
