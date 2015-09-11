/*
 * RGBConverter.h - Arduino library for converting between RGB, HSV and HSL
 *
 * Ported from the Javascript at http://mjijackson.com/2008/02/rgb-to-hsl-and-rgb-to-hsv-color-model-conversion-algorithms-in-javascript
 * The hard work was Michael's, all the bugs are mine.
 *
 * Robert Atkins, December 2010 (ratkins_at_fastmail_dot_fm).
 *
 * https://github.com/ratkins/RGBConverter
 *
 * Modifications by Aleksandar Vladimirov Atanasov, September 2015
 *  - all functions are now not bound to Arduino's header
 *  - added conversion for single and full RGB color values from/to double to/from integer
 *  - array arguments have been split into triplets of pointers (one pointer per value)
 *  - all functions are now static so there is no need for creating the RGBConverter object (constructor of RGBConverter has also been moved to private)
 *  - added alternative display of HSL using degrees and percentages
 *  - reformatted documentation
 */
#ifndef RGBConverter_h
#define RGBConverter_h

class RGBConverter {

public:
    // Unit conversions
    /**
     * @brief rgbIntToDouble_single Converts a single integer RGB color value component (red, green or blue) into its floating point representation
     * @param x   RGB single component as integer                                   (input)
     * @param _x  RGB single component as floating point                            (output)
     */
    static void rgbIntToDouble_single(int x, double *_x);
    /**
     * @brief rgbIntToDouble Converts a RGB color value (red, green and blue) into its floating point representation
     * @param r     RGB red as integer in the interval [0 .. 255]                   (input)
     * @param g     RGB green as integer in the interval [0 .. 255]                 (input)
     * @param b     RGB blue as integer in the interval [0 .. 255]                  (input)
     * @param r     RGB red as floating point in the interval [0.0 .. 1.0]          (output)
     * @param g     RGB green as floating point in the interval [0.0 .. 1.0]        (output)
     * @param b     RGB blue as floating point in the interval [0.0 .. 1.0]         (output)
     */
    static void rgbIntToDouble(int r, int g, int b, double *_r, double *_g, double *_b);
    /**
     * @brief rgbDoubleToInt_single Converts a single floating point RGB color value component (red, green or blue) into its integer representation
     * @param x   RGB single component as floating point in the interval [0.0 .. 1.0]   (input)
     * @param _x  RGB single component as integer in the interval [0 .. 255]            (output)
     */
    static void rgbDoubleToInt_single(double x, int *_x);
    /**
     * @brief rgbDoubleToInt Converts a floating point RGB color value (red, green and blue) into its integer representation
     * @param r     RGB red as floating point in the interval [0.0 .. 1.0]          (input)
     * @param g     RGB green as floating point in the interval [0.0 .. 1.0]        (input)
     * @param b     RGB blue as floating point in the interval [0.0 .. 1.0]         (input)
     * @param r     RGB red as integer in the interval [0 .. 255]                   (output)
     * @param g     RGB green as integer in the interval [0 .. 255]                 (output)
     * @param b     RGB blue as integer in the interval [0 .. 255]                  (output)
     */
    static void rgbDoubleToInt(double r, double g, double b, int *_r, int *_g, int *_b);
    /**
     * @brief hslIntervalZeroOneToDegAndPercentage Converts a HSL color value with each component in the interval [0.0 .. 1.0] to degrees (for hue) and percentages (for saturation and lightness)
     * @param h     HSL hue as floating point in the interval [0.0 .. 1.0]          (input)
     * @param s     HSL saturation as floating point in the interval [0.0 .. 1.0]   (input)
     * @param l     HSL lightness as floating point in the interval [0.0 .. 1.0]    (input)
     * @param _h    HSL hue as floating point in the interval [0.0 .. 360.0deg]     (output)
     * @param _s    HSL saturation as floating point in the interval [0.0 .. 100.0%](output)
     * @param _l    HSL lightness as floating point in the interval [0.0 .. 100.0%] (output)
     */
    static void hslIntervalZeroOneToDegAndPercentage(double h, double s, double l, double *_h, double *_s, double *_l);   // Note: all numbers after the floating point remain intact and represent minutes+seconds; if minutes and seconds are needed to be displayed, this function can be extended to conver those numbers into the desired measurement units
    /**
     * @brief hslDegAndPercentageToIntervalZeroOne Converts a HSL color value represented as degrees (for hue) and percentages (for saturation and lightness) to representation where each component in the interval [0.0 .. 1.0]
     * @param h     HSL hue as floating point in the interval [0.0 .. 360.0deg]     (input)
     * @param s     HSL saturation as floating point in the interval [0.0 .. 100.0%](input)
     * @param l     HSL lightness as floating point in the interval [0.0 .. 100.0%] (input)
     * @param _h    HSL hue as floating point in the interval [0.0 .. 1.0]          (output)
     * @param _s    HSL saturation as floating point in the interval [0.0 .. 1.0]   (output)
     * @param _l    HSL lightness as floating point in the interval [0.0 .. 1.0]    (output)
     */
    static void hslDegAndPercentageToIntervalZeroOne(double h, double s, double l, double *_h, double *_s, double *_l);   // TODO

    // Color value conversions
    // RGB/HSV
    /**
     * @brief rgbToHsl Converts a floating point RGB color value (red, green and blue) into its HSL (hue, saturation and lightness) representation (all components for both RGB and HSL are in the interval [0.0 .. 1.0]
     * @param r     RGB red as floating point in the interval [0.0 .. 1.0]          (input)
     * @param g     RGB green as floating point in the interval [0.0 .. 1.0]        (input)
     * @param b     RGB blue as floating point in the interval [0.0 .. 1.0]         (input)
     * @param h     HSL hue as floating point in the interval [0.0 .. 1.0]          (output)
     * @param s     HSL saturation as floating point in the interval [0.0 .. 1.0]   (output)
     * @param l     HSL lightness as floating point in the interval [0.0 .. 1.0]    (output)
     */
    static void rgbToHsl(double r, double g, double b, double *h, double *s, double *l);
    /**
     * @brief hslToRgb Converts a floating point RGB color value (red, green and blue) into its HSL (hue, saturation and lightness) representation (all components in the interval [0.0 .. 1.0]
     * @param h     HSL hue as floating point in the interval [0.0 .. 1.0]          (input)
     * @param s     HSL saturation as floating point in the interval [0.0 .. 1.0]   (input)
     * @param l     HSL lightness as floating point in the interval [0.0 .. 1.0]    (input)
     * @param r     RGB red as floating point in the interval [0.0 .. 1.0]          (output)
     * @param g     RGB green as floating point in the interval [0.0 .. 1.0]        (output)
     * @param b     RGB blue as floating point in the interval [0.0 .. 1.0]         (output)
     */
    static void hslToRgb(double h, double s, double l, double *r, double *g, double *b);

    // RGB/HSV
    /**
     * @brief rgbToHsv Converts a floating point RGB color value (red, green and blue) into its HSV (hue, saturation and value) representation (all components in the interval [0.0 .. 1.0]
     * @param r     RGB red as floating point in the interval [0.0 .. 1.0]          (input)
     * @param g     RGB green as floating point in the interval [0.0 .. 1.0]        (input)
     * @param b     RGB blue as floating point in the interval [0.0 .. 1.0]         (input)
     * @param h     HSV hue as floating point in the interval [0.0 .. 1.0]          (output)
     * @param s     HSV saturation as floating point in the interval [0.0 .. 1.0]   (output)
     * @param v     HSV value as floating point in the interval [0.0 .. 1.0]        (output)
     */
    static void rgbToHsv(double r, double g, double b, double *h, double *s, double *v);
    /**
     * @brief hsvToRgb
     * @param h     HSV hue as floating point in the interval [0.0 .. 1.0]          (input)
     * @param s     HSV saturation as floating point in the interval [0.0 .. 1.0]   (input)
     * @param l     HSV value as floating point in the interval [0.0 .. 1.0]        (input)
     * @param r     RGB red as floating point in the interval [0.0 .. 1.0]          (output)
     * @param g     RGB green as floating point in the interval [0.0 .. 1.0]        (output)
     * @param b     RGB blue as floating point in the interval [0.0 .. 1.0]         (output)
     */
    static void hsvToRgb(double h, double s, double v, double *r, double *g, double *b);

    // RGB/CMYK
    /**
     * @brief rgbToCmyk
     * @param r
     * @param g
     * @param b
     * @param c
     * @param m
     * @param y
     * @param k
     */
    static void rgbToCmyk(double r, double g, double b, double *c, double *m, double *y, double *k);
    /**
     * @brief cmykToRgb
     * @param c
     * @param m
     * @param y
     * @param k
     * @param r
     * @param g
     * @param b
     */
    static void cmykToRgb(double c, double m, double y, double k, double *r, double *g, double *b);

    // RGB/YIQ
    /**
     * @brief rgbToYiq
     * @param r
     * @param g
     * @param b
     * @param y
     * @param i
     * @param q
     */
    static void rgbToYiq(double r, double g, double b, double *y, double *i, double *q);
    /**
     * @brief yiqToRgb
     * @param y
     * @param i
     * @param q
     * @param r
     * @param g
     * @param b
     */
    static void yiqToRgb(double y, double i, double q, double *r, double *g, double *b);

private:
    RGBConverter();
    /**
     * @brief threeway_max Finds the maximum in a triple of floating point values. Requires fmax from cmath
     * @param a
     * @param b
     * @param c
     * @return maximum of a,b and c
     */
    static double threeway_max(double a, double b, double c);
    /**
     * @brief threeway_min Finds the minimum in a triple of floating point values. Requires fmin from cmath
     * @param a
     * @param b
     * @param c
     * @return minimum of a,b and c
     */
    static double threeway_min(double a, double b, double c);
    /**
     * @brief hueToRgb Used internally in hslToRgb for handling the hue value
     * @param p
     * @param q
     * @param t
     * @return p
     */
    static double hueToRgb(double p, double q, double t);
};

#endif
