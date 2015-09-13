#include <stdio.h>
#include <RGBConverter.h>
#include <gtest/gtest.h>

#define RGB_R 65
#define RGB_G 100
#define RGB_B 37

TEST(UnitCoversion, IntToDouble_single) {
  double x = .0000000, x_res;
  unsigned int color = 0;
  double step = 1/255.;
  for(; color < 256; color++) {
    RGBConverter::rgbIntToDouble_single(color, &x_res);
    EXPECT_NEAR(x, x_res, .0000001);

    x+=step;
  }
}

TEST(UnitConversion, DoubleToInt_single) {
  double x = .0000000;
  unsigned int x_res;
  unsigned int color = 0;
  double step = 1/255.;
  for(; color < 256; color++) {
    RGBConverter::rgbDoubleToInt_single(x, &x_res);
    EXPECT_EQ(color, x_res);

    x+=step;
  }
}

TEST(UnitCoversion, IntToDouble_full) {
  double x = .0000000, r_res, g_res, b_res;
  unsigned int color = 0;
  double step = 1/255.;
  for(; color < 256; color++) {
    RGBConverter::rgbIntToDouble(color, color, color, &r_res, &g_res, &b_res);
    EXPECT_NEAR(x, r_res, .0000001);
    EXPECT_NEAR(x, g_res, .0000001);
    EXPECT_NEAR(x, b_res, .0000001);

    x+=step;
  }
}

TEST(UnitConversion, DoubleToInt_full) {
  double x = .0000000;
  unsigned int r_res, g_res, b_res;
  unsigned int color = 0;
  double step = 1/255.;
  for(; color < 256; color++) {
    RGBConverter::rgbDoubleToInt(x, x, x, &r_res, &g_res, &b_res);
    EXPECT_EQ(color, r_res);
    EXPECT_EQ(color, g_res);
    EXPECT_EQ(color, b_res);

    x+=step;
  }
}

// Add hsl unit conversions

// Add color conversion test cases

int main(int argc, char** argv) {
  // Small demo
  double r, g, b;
  unsigned int _r, _g, _b;
  double h, s, l, _h, _s, _l;

  RGBConverter::rgbIntToDouble(RGB_R, RGB_G, RGB_B, &r, &g, &b);
  printf("RGB(unsigned int) -> RGB(double) -> HSL -> RGB(double) -> RGB(unsigned int)\n");
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
