#include <stdio.h>
#include <RGBConverter.h>

#define RGB_R 65
#define RGB_G 100
#define RGB_B 37

int main() {

    float r, g, b;
    int _r, _g, _b;
    float h, s, l, _h, _s, _l;

    RGBConverter::rgbIntToFloat(RGB_R, RGB_G, RGB_B, &r, &g, &b);
    printf("RGB(int) -> RGB(float) -> HSL -> RGB(float) -> RGB(int)\n");
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
    RGBConverter::rgbFloatToInt(r, g, b, &_r, &_g, &_b);
    printf("RGB: %d %d %d\n", _r, _g, _b);
    return 0;
}
