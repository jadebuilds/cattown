/* 
 * kinematics.cpp
 * 
 * This library is auto-generated from the Jupyter notebook v4_kinematics.ipynb.
 * 
 * It contains a giant lookup table from string length (L2, L1) to x, y, and the four partial
 * derivatives of L1 and L2 with regard to X and Y. The microcontroller can track string length
 * using either encoders (for brushed/brushless) or step pulse counting (for steppers). Given a
 * target velocity dx/dt and dy/dt, we can calculate dl1/dt and dl2/dt using the chain rule:
 *
 * dl1/dt = (δl1/δx) * dx/dt + (δl1/δy) * dy/dt
 * dl2/dt = (δl2/δx) * dx/dt + (δl2/δy) * dy/dt
 * 
 * It's useful to know X and Y so the microcontroller can take position commands as well as
 * speed commands. We'll do that with a feedback loop on the microcontroller -- ie if our current
 * position is at larger X than the requested, we'll accelerate in the negative X direction, and so on.
 */

#include <cmath> // Include cmath for NAN
#include "kinematics.h"

const LookupEntry lookupTable[108][108] = {

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            96.0,
            0.0,
            1.0,
            0.0,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            95.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            95.99479166666667,
            0.9999864365398596,
            0.9999457465277778,
            0.010416525380623537,
            -0.005208333333329123,
            0.9999864365399608
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            94.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            94.984375,
            1.7229352452646036,
            0.9998355263157894,
            0.01813616047646951,
            -0.5078125,
            0.8614676226323018
        }
    
        {
            95.97916666666667,
            1.999891490111603,
            0.9997829861111112,
            0.020832203021995864,
            -0.01041666666666614,
            0.9999457450559783
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            93.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            93.97395833333333,
            2.212499754786781,
            0.9997229609929078,
            0.023537231433901924,
            -0.6753472222221852,
            0.7374999182622182
        }
    
        {
            94.95833333333333,
            2.813348637399312,
            0.9995614035087719,
            0.029614196183150653,
            -0.3472222222222041,
            0.9377828791330508
        }
    
        {
            95.953125,
            2.9996337667080293,
            0.99951171875,
            0.031246185069875306,
            -0.015625,
            0.9998779222360098
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            92.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            92.96354166666667,
            2.603828102991775,
            0.9996079749103943,
            0.02799815164507285,
            -0.759114583333352,
            0.6509570257479609
        }
    
        {
            93.9375,
            3.427257467713799,
            0.9993351063829787,
            0.03646018582674254,
            -0.515625,
            0.8568143669284497
        }
    
        {
            94.921875,
            3.8519665736315782,
            0.9991776315789473,
            0.04054701656454293,
            -0.26953125,
            0.9629916434078946
        }
    
        {
            95.91666666666667,
            3.9991318502338413,
            0.9991319444444445,
            0.04165762343993585,
            -0.020833333333332676,
            0.9997829625584856
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            91.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            91.953125,
            2.936460919946833,
            0.9994904891304348,
            0.031918053477682964,
            -0.809375,
            0.5872921839893666
        }
    
        {
            92.91666666666667,
            3.9361218928730786,
            0.9991039426523298,
            0.0423238913212159,
            -0.616666666666676,
            0.7872243785746289
        }
    
        {
            93.890625,
            4.533270023876253,
            0.9988364361702128,
            0.04822627684974737,
            -0.421875,
            0.9066540047752506
        }
    
        {
            94.875,
            4.871793817476269,
            0.9986842105263158,
            0.05128204018396073,
            -0.225,
            0.9743587634952539
        }
    
        {
            95.86979166666667,
            4.998304291450226,
            0.9986436631944445,
            0.05206566970260652,
            -0.026041666666666144,
            0.9996608582900615
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            90.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            90.94270833333333,
            3.22859117855846,
            0.9993704212454212,
            0.03547902394020285,
            -0.8428819444444258,
            0.5380985297597308
        }
    
        {
            91.89583333333333,
            4.376735766781292,
            0.9988677536231884,
            0.04757321485631839,
            -0.6840277777777745,
            0.7294559611302108
        }
    
        {
            92.859375,
            5.112384434818551,
            0.9984879032258065,
            0.05497187564321023,
            -0.5234375,
            0.8520640724697586
        }
    
        {
            93.83333333333333,
            5.595136777198263,
            0.9982269503546098,
            0.05952273167232195,
            -0.3611111111111067,
            0.9325227961996971
        }
    
        {
            94.81770833333333,
            5.8823623158499485,
            0.9980811403508771,
            0.0619196033247363,
            -0.1970486111111091,
            0.9803937193083109
        }
    
        {
            95.8125,
            5.997069596894804,
            0.998046875,
            0.062469474967654204,
            -0.03125,
            0.9995115994824673
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            89.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            89.93229166666667,
            3.4904033551434592,
            0.9992476851851853,
            0.03878225950159399,
            -0.8668154761904805,
            0.49862905073478275
        }
    
        {
            90.875,
            4.768057780690163,
            0.9986263736263736,
            0.05239623934824355,
            -0.7321428571428571,
            0.6811511115271661
        }
    
        {
            91.828125,
            5.620983809296643,
            0.9981317934782609,
            0.06109765010105046,
            -0.5959821428571429,
            0.8029976870423775
        }
    
        {
            92.79166666666667,
            6.2214626272461695,
            0.9977598566308244,
            0.06689744760479752,
            -0.4583333333333395,
            0.8887803753208946
        }
    
        {
            93.765625,
            6.6338200427336735,
            0.9975066489361702,
            0.0705725536461029,
            -0.31919642857142855,
            0.947688577533382
        }
    
        {
            94.75,
            6.887488656977955,
            0.9973684210526316,
            0.07249988059976795,
            -0.1785714285714286,
            0.9839269509968508
        }
    
        {
            95.74479166666667,
            6.99534621777906,
            0.9973415798611112,
            0.07286818976853188,
            -0.03645833333333318,
            0.9993351739684516
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            88.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            88.921875,
            3.7282900214944386,
            0.999122191011236,
            0.04189089911791504,
            -0.884765625,
            0.4660362526868048
        }
    
        {
            89.85416666666667,
            5.121399480502158,
            0.9983796296296297,
            0.056904438672246205,
            -0.7682291666666732,
            0.6401749350627757
        }
    
        {
            90.796875,
            6.076799341295959,
            0.9977678571428571,
            0.06677801473951603,
            -0.650390625,
            0.7595999176619949
        }
    
        {
            91.75,
            6.777720855862979,
            0.9972826086956522,
            0.07367087886807586,
            -0.5312500000000001,
            0.8472151069828725
        }
    
        {
            92.71354166666667,
            7.293777596229795,
            0.9969198028673836,
            0.07842771608849242,
            -0.41080729166666685,
            0.911722199528726
        }
    
        {
            93.6875,
            7.658481817566717,
            0.9966755319148937,
            0.08147321082517783,
            -0.2890625,
            0.9573102271958396
        }
    
        {
            94.671875,
            7.888984978080196,
            0.9965460526315789,
            0.08304194713768627,
            -0.16601562500000003,
            0.9861231222600246
        }
    
        {
            95.66666666666667,
            7.99305253885452,
            0.9965277777777778,
            0.08326096394640124,
            -0.041666666666666144,
            0.9991315673568166
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            87.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            87.91145833333333,
            3.946580001291957,
            0.9989938446969696,
            0.04484750001468133,
            -0.8987268518518498,
            0.4385088890324384
        }
    
        {
            88.83333333333333,
            5.4441609903537564,
            0.99812734082397,
            0.06117034820622198,
            -0.7962962962962931,
            0.60490677670597
        }
    
        {
            89.765625,
            6.4909605113091695,
            0.9973958333333334,
            0.07212178345899077,
            -0.6927083333333334,
            0.7212178345899077
        }
    
        {
            90.70833333333333,
            7.2799906517035105,
            0.9967948717948717,
            0.07999989727146715,
            -0.5879629629629575,
            0.8088878501892707
        }
    
        {
            91.66145833333333,
            7.885242938971356,
            0.9963201992753623,
            0.08570916238012342,
            -0.4820601851851844,
            0.8761381043301482
        }
    
        {
            92.625,
            8.34322329798262,
            0.9959677419354839,
            0.0897120784729314,
            -0.375,
            0.9270248108869578
        }
    
        {
            93.59895833333333,
            8.673811095183684,
            0.9957335992907801,
            0.09227458611897536,
            -0.2667824074074062,
            0.9637567883537363
        }
    
        {
            94.58333333333333,
            8.887803753209033,
            0.9956140350877193,
            0.09355582898114771,
            -0.15740740740740694,
            0.987533750356553
        }
    
        {
            95.578125,
            8.990106867238843,
            0.99560546875,
            0.09364694653373795,
            -0.046875,
            0.9989007630265382
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            86.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            86.90104166666667,
            4.148368022278493,
            0.9988625478927203,
            0.04768239106067234,
            -0.9098958333333383,
            0.41483680222785185
        }
    
        {
            87.8125,
            5.741501872332709,
            0.9978693181818182,
            0.06524433945832624,
            -0.81875,
            0.5741501872332708
        }
    
        {
            88.734375,
            6.871003810170316,
            0.9970154494382022,
            0.07720229000191366,
            -0.7265625,
            0.6871003810170315
        }
    
        {
            89.66666666666667,
            7.7387911774958615,
            0.9962962962962963,
            0.08598656863884291,
            -0.6333333333333365,
            0.7738791177495907
        }
    
        {
            90.609375,
            8.422657663076127,
            0.9957074175824175,
            0.09255667761622118,
            -0.5390625,
            0.8422657663076126
        }
    
        {
            91.5625,
            8.961506221054583,
            0.9952445652173914,
            0.09740767631581068,
            -0.44375,
            0.8961506221054583
        }
    
        {
            92.52604166666667,
            9.377185798429275,
            0.9949036738351255,
            0.10082995482182017,
            -0.34739583333333324,
            0.9377185798429285
        }
    
        {
            93.5,
            9.682458365518542,
            0.9946808510638298,
            0.10300487622892066,
            -0.25,
            0.9682458365518543
        }
    
        {
            94.484375,
            9.88447676204335,
            0.9945723684210527,
            0.10404712381098263,
            -0.1515625,
            0.988447676204335
        }
    
        {
            95.47916666666667,
            9.98642742119967,
            0.9945746527777778,
            0.10402528563749656,
            -0.05208333333333291,
            0.9986427421199681
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            85.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            85.890625,
            4.335958614813453,
            0.9987281976744186,
            0.050418123428063406,
            -0.9190340909090909,
            0.3941780558921321
        }
    
        {
            86.79166666666667,
            6.017191805337579,
            0.9976053639846744,
            0.06916312419928251,
            -0.8371212121212137,
            0.5470174368488722
        }
    
        {
            87.703125,
            7.2223171651745535,
            0.9966264204545454,
            0.08207178596789265,
            -0.7542613636363636,
            0.6565742877431412
        }
    
        {
            88.625,
            8.161456671452713,
            0.9957865168539326,
            0.09170176035340127,
            -0.6704545454545454,
            0.7419506064957012
        }
    
        {
            89.55729166666667,
            8.915801104308951,
            0.9950810185185186,
            0.0990644567145439,
            -0.5857007575757586,
            0.8105273731189975
        }
    
        {
            90.5,
            9.526279441628825,
            0.9945054945054945,
            0.10468438946844863,
            -0.5,
            0.8660254037844386
        }
    
        {
            91.453125,
            10.016283129703103,
            0.9940557065217391,
            0.10887264271416416,
            -0.4133522727272727,
            0.910571193609373
        }
    
        {
            92.41666666666667,
            10.399986645290502,
            0.9937275985663083,
            0.11182781339022045,
            -0.3257575757575773,
            0.9454533313900513
        }
    
        {
            93.390625,
            10.686026488333958,
            0.9935172872340425,
            0.11368113285461658,
            -0.2372159090909091,
            0.9714569534849052
        }
    
        {
            94.375,
            10.879309490955757,
            0.993421052631579,
            0.1145190472732185,
            -0.14772727272727273,
            0.9890281355414324
        }
    
        {
            95.36979166666667,
            10.981932318886136,
            0.9934353298611112,
            0.11439512832173059,
            -0.05729166666666657,
            0.998357483535109
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            84.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            84.88020833333333,
            4.511123284718737,
            0.9985906862745098,
            0.05307203864374985,
            -0.9266493055555522,
            0.3759269403932266
        }
    
        {
            85.77083333333333,
            6.274085535403272,
            0.9973352713178294,
            0.07295448296980549,
            -0.8524305555555527,
            0.5228404612836041
        }
    
        {
            86.671875,
            7.548912768364396,
            0.9962284482758621,
            0.08676911228005052,
            -0.77734375,
            0.6290760640303663
        }
    
        {
            87.58333333333333,
            8.553345674192212,
            0.9952651515151515,
            0.09719710993400241,
            -0.7013888888888882,
            0.7127788061826832
        }
    
        {
            88.50520833333333,
            9.37166462658927,
            0.994440543071161,
            0.10529960254594686,
            -0.6245659722222209,
            0.7809720522157704
        }
    
        {
            89.4375,
            10.04657124346411,
            0.99375,
            0.11162856937182344,
            -0.546875,
            0.8372142702886758
        }
    
        {
            90.38020833333333,
            10.60273274317827,
            0.9931891025641025,
            0.11651354662833265,
            -0.4683159722222214,
            0.8835610619315202
        }
    
        {
            91.33333333333333,
            11.055415967851351,
            0.9927536231884058,
            0.12016756486794947,
            -0.3888888888888887,
            0.9212846639876111
        }
    
        {
            92.296875,
            11.41432719148943,
            0.9924395161290323,
            0.12273470098375731,
            -0.30859375,
            0.9511939326241192
        }
    
        {
            93.27083333333333,
            11.685531622718607,
            0.9922429078014184,
            0.12431416619913412,
            -0.22743055555555516,
            0.9737943018932139
        }
    
        {
            94.25520833333333,
            11.872476659902581,
            0.9921600877192982,
            0.12497343852529033,
            -0.14539930555555544,
            0.9893730549918782
        }
    
        {
            95.25,
            11.976539567003485,
            0.9921875,
            0.12475562048961963,
            -0.06249999999999999,
            0.998044963916957
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            83.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            83.86979166666667,
            4.675258900844931,
            0.9984499007936508,
            0.05565784405767774,
            -0.9330929487179509,
            0.35963530006499567
        }
    
        {
            84.75,
            6.514407110397691,
            0.9970588235294118,
            0.07664008365173755,
            -0.8653846153846154,
            0.5011082392613608
        }
    
        {
            85.640625,
            7.853874814979864,
            0.9958212209302325,
            0.09132412575557981,
            -0.796875,
            0.6041442165369126
        }
    
        {
            86.54166666666667,
            8.91851616332867,
            0.9947318007662835,
            0.10251168003826057,
            -0.7275641025641042,
            0.6860397048714381
        }
    
        {
            87.453125,
            9.79545444246335,
            0.9937855113636364,
            0.1113119823007199,
            -0.6574519230769231,
            0.7534964955741039
        }
    
        {
            88.375,
            10.52897787061973,
            0.9929775280898876,
            0.11830312214179473,
            -0.5865384615384616,
            0.8099213746630561
        }
    
        {
            89.30729166666667,
            11.144848817499938,
            0.9923032407407408,
            0.12383165352777709,
            -0.5148237179487188,
            0.8572960628846127
        }
    
        {
            90.25,
            11.659223816361019,
            0.9917582417582418,
            0.12812333864132988,
            -0.4423076923076923,
            0.8968633704893091
        }
    
        {
            91.203125,
            12.082631759446077,
            0.9913383152173914,
            0.13133295390702257,
            -0.36899038461538464,
            0.9294332122650828
        }
    
        {
            92.16666666666667,
            12.421978729476022,
            0.9910394265232976,
            0.13356966375780668,
            -0.29487179487179527,
            0.9555368253443118
        }
    
        {
            93.140625,
            12.681639271378721,
            0.9908577127659575,
            0.13491105607849704,
            -0.21995192307692304,
            0.9755107131829784
        }
    
        {
            94.125,
            12.864073033063828,
            0.9907894736842106,
            0.1354112950848824,
            -0.14423076923076922,
            0.9895440794664483
        }
    
        {
            95.11979166666667,
            12.970167049422678,
            0.9908311631944445,
            0.13510590676481957,
            -0.06770833333333312,
            0.9977051576479006
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            82.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            82.859375,
            4.82949009827901,
            0.9983057228915663,
            0.05818662769010855,
            -0.9386160714285714,
            0.3449635784485007
        }
    
        {
            83.72916666666667,
            6.73992947333685,
            0.9967757936507937,
            0.08023725563496249,
            -0.876488095238097,
            0.48142353380977615
        }
    
        {
            84.609375,
            8.139635256531768,
            0.9954044117647058,
            0.09576041478272669,
            -0.8136160714285714,
            0.5814025183236977
        }
    
        {
            85.5,
            9.260129588726068,
            0.9941860465116279,
            0.10767592545030312,
            -0.75,
            0.6614378277661477
        }
    
        {
            86.40104166666667,
            10.191172597642028,
            0.9931154214559388,
            0.11713991491542561,
            -0.6856398809523822,
            0.7279408998315751
        }
    
        {
            87.3125,
            10.978494603086528,
            0.9921875,
            0.12475562048961963,
            -0.6205357142857143,
            0.784178185934752
        }
    
        {
            88.234375,
            11.648822616873131,
            0.9913974719101124,
            0.130885647380597,
            -0.5546875000000001,
            0.832058758348081
        }
    
        {
            89.16666666666667,
            12.21906524884595,
            0.9907407407407408,
            0.13576739165384388,
            -0.48809523809523886,
            0.8727903749175699
        }
    
        {
            90.109375,
            12.7004148400505,
            0.9902129120879121,
            0.1395649982423132,
            -0.4207589285714286,
            0.9071724885750359
        }
    
        {
            91.0625,
            13.10042341872964,
            0.9898097826086957,
            0.14239590672532218,
            -0.35267857142857145,
            0.93574452990926
        }
    
        {
            92.02604166666667,
            13.424144485401285,
            0.989527329749104,
            0.1443456396279708,
            -0.28385416666666696,
            0.958867463242951
        }
    
        {
            93.0,
            13.674794331177344,
            0.9893617021276596,
            0.14547653543805686,
            -0.21428571428571427,
            0.9767710236555246
        }
    
        {
            93.984375,
            13.85414219139442,
            0.9893092105263158,
            0.14583307569888862,
            -0.1439732142857143,
            0.9895815850996016
        }
    
        {
            94.97916666666667,
            13.962732515720365,
            0.9893663194444445,
            0.14544513037208714,
            -0.07291666666666649,
            0.997338036837171
        }
    
        {
            95.984375,
            13.99999128068925,
            0.9895296391752577,
            0.14432980701741494,
            -0.0011160714285714285,
            0.9999993771920892
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            81.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            81.84895833333333,
            4.974738158764198,
            0.9981580284552845,
            0.0606675385215146,
            -0.9434027777777763,
            0.3316492105842792
        }
    
        {
            82.70833333333333,
            6.952093010182087,
            0.9964859437751004,
            0.08376015674918177,
            -0.8861111111111104,
            0.4634728673454719
        }
    
        {
            83.578125,
            8.408152084993171,
            0.9949776785714286,
            0.10009704863087109,
            -0.828125,
            0.560543472332878
        }
    
        {
            84.45833333333333,
            9.580706161633211,
            0.9936274509803921,
            0.1127141901368613,
            -0.7694444444444428,
            0.6387137441088792
        }
    
        {
            85.34895833333333,
            10.561974787648925,
            0.9924297480620154,
            0.12281366032149912,
            -0.7100694444444431,
            0.7041316525099267
        }
    
        {
            86.25,
            11.399013115177997,
            0.9913793103448276,
            0.1310231392549195,
            -0.65,
            0.7599342076785333
        }
    
        {
            87.16145833333333,
            12.11941340191833,
            0.9904711174242423,
            0.13772060683998102,
            -0.5892361111111108,
            0.8079608934612211
        }
    
        {
            88.08333333333333,
            12.740737376183908,
            0.9897003745318351,
            0.14315435254139222,
            -0.5277777777777771,
            0.8493824917455923
        }
    
        {
            89.015625,
            13.274731856402035,
            0.9890625,
            0.14749702062668926,
            -0.465625,
            0.8849821237601356
        }
    
        {
            89.95833333333333,
            13.729466992162864,
            0.9885531135531135,
            0.15087326365014136,
            -0.4027777777777774,
            0.9152977994775228
        }
    
        {
            90.91145833333333,
            14.110518902811393,
            0.9881680253623187,
            0.15337520546534122,
            -0.33923611111111107,
            0.9407012601874252
        }
    
        {
            91.875,
            14.421663392272057,
            0.9879032258064516,
            0.15507164937926943,
            -0.275,
            0.9614442261514706
        }
    
        {
            92.84895833333333,
            14.66529701079837,
            0.9877548758865248,
            0.15601379798721668,
            -0.21006944444444425,
            0.9776864673865556
        }
    
        {
            93.83333333333333,
            14.842693675864787,
            0.987719298245614,
            0.1562388807985767,
            -0.14444444444444443,
            0.9895129117243169
        }
    
        {
            94.828125,
            14.954153569639942,
            0.98779296875,
            0.15577243301708274,
            -0.07812499999999999,
            0.9969435713093293
        }
    
        {
            95.83333333333333,
            14.999074045494362,
            0.9879725085910652,
            0.1546296293349934,
            -0.011111111111111417,
            0.9999382696996233
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            80.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            80.83854166666667,
            5.111768892134768,
            0.9980066872427984,
            0.06310825792758973,
            -0.9475911458333343,
            0.31948555575842347
        }
    
        {
            81.6875,
            7.152086671035244,
            0.9961890243902439,
            0.0872205691589664,
            -0.89453125,
            0.44700541693970275
        }
    
        {
            82.546875,
            8.661029253753563,
            0.9945406626506024,
            0.10434975004522365,
            -0.8408203125,
            0.5413143283595977
        }
    
        {
            83.41666666666667,
            9.8822933685568,
            0.9930555555555556,
            0.11764634962567619,
            -0.786458333333334,
            0.6176433355348008
        }
    
        {
            84.296875,
            10.91040169903817,
            0.9917279411764706,
            0.12835766704750787,
            -0.7314453125,
            0.6819001061898856
        }
    
        {
            85.1875,
            11.79363573076598,
            0.9905523255813954,
            0.13713529919495324,
            -0.67578125,
            0.7371022331728737
        }
    
        {
            86.08854166666667,
            12.560373947721331,
            0.9895234674329503,
            0.1443721143416245,
            -0.6194661458333337,
            0.7850233717325841
        }
    
        {
            87.0,
            13.228756555322953,
            0.9886363636363636,
            0.15032677903776082,
            -0.5625,
            0.8267972847076845
        }
    
        {
            87.921875,
            13.81100635306403,
            0.9878862359550562,
            0.1551798466636408,
            -0.5048828125,
            0.8631878970665019
        }
    
        {
            88.85416666666667,
            14.315623142993871,
            0.9872685185185186,
            0.15906247936659856,
            -0.44661458333333354,
            0.894726446437118
        }
    
        {
            89.796875,
            14.748601297559542,
            0.9867788461538461,
            0.16207254173142355,
            -0.3876953125,
            0.9217875810974714
        }
    
        {
            90.75,
            15.11414900019184,
            0.9864130434782609,
            0.1642842282629548,
            -0.328125,
            0.94463431251199
        }
    
        {
            91.71354166666667,
            15.41513136358545,
            0.9861671146953406,
            0.16575410068371452,
            -0.26790364583333376,
            0.9634457102240933
        }
    
        {
            92.6875,
            15.653349282182392,
            0.9860372340425532,
            0.16652499236364246,
            -0.20703125,
            0.9783343301363995
        }
    
        {
            93.671875,
            15.829713641894315,
            0.9860197368421053,
            0.16662856465151912,
            -0.1455078125,
            0.9893571026183947
        }
    
        {
            94.66666666666667,
            15.944347657468485,
            0.9861111111111112,
            0.16608695476529672,
            -0.08333333333333327,
            0.9965217285917832
        }
    
        {
            95.671875,
            15.99663508317843,
            0.9863079896907216,
            0.16491376374410754,
            -0.0205078125,
            0.9997896926986519
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            79.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            79.828125,
            5.241226858701596,
            0.9978515625,
            0.06551533573376996,
            -0.9512867647058824,
            0.30830746227656447
        }
    
        {
            80.66666666666667,
            7.3409051818483375,
            0.9958847736625515,
            0.09062845903516466,
            -0.9019607843137271,
            0.4318179518734325
        }
    
        {
            81.515625,
            8.899600039292496,
            0.9940929878048781,
            0.10853170779624995,
            -0.8520220588235294,
            0.5235058846642645
        }
    
        {
            82.375,
            10.16658128379447,
            0.9924698795180723,
            0.12248893113005385,
            -0.8014705882352942,
            0.5980341931643806
        }
    
        {
            83.24479166666667,
            11.238534618590752,
            0.9910094246031746,
            0.13379207879274704,
            -0.7503063725490209,
            0.6610902716818103
        }
    
        {
            84.125,
            12.16488286010186,
            0.9897058823529412,
            0.14311626894237484,
            -0.6985294117647058,
            0.7155813447118742
        }
    
        {
            85.015625,
            12.974725656420446,
            0.9885537790697675,
            0.1508689029816331,
            -0.6461397058823529,
            0.7632191562600262
        }
    
        {
            85.91666666666667,
            13.686723088047328,
            0.9875478927203065,
            0.15731865618445204,
            -0.5931372549019618,
            0.8051013581204327
        }
    
        {
            86.828125,
            14.313514906701812,
            0.9866832386363636,
            0.16265357848524786,
            -0.5395220588235294,
            0.8419714651001066
        }
    
        {
            87.75,
            14.863966496194749,
            0.9859550561797753,
            0.16701085950780617,
            -0.4852941176470588,
            0.874350970364397
        }
    
        {
            88.68229166666667,
            15.344417380541458,
            0.9853587962962963,
            0.17049352645046065,
            -0.43045343137254966,
            0.9026127870906758
        }
    
        {
            89.625,
            15.759421785078283,
            0.9848901098901099,
            0.17318045917668443,
            -0.375,
            0.9270248108869579
        }
    
        {
            90.578125,
            16.112208771126788,
            0.9845448369565217,
            0.1751327040339868,
            -0.31893382352941174,
            0.9477769865368699
        }
    
        {
            91.54166666666667,
            16.404976802448967,
            0.9843189964157707,
            0.17639760002633298,
            -0.2622549019607841,
            0.9649986354381748
        }
    
        {
            92.515625,
            16.63908443573068,
            0.9842087765957447,
            0.1770115365503264,
            -0.20496323529411764,
            0.97876967269004
        }
    
        {
            93.5,
            16.815171720800237,
            0.9842105263157894,
            0.1770018075873709,
            -0.14705882352941177,
            0.9891277482823668
        }
    
        {
            94.49479166666667,
            16.933232056322375,
            0.9843207465277778,
            0.17638783392002474,
            -0.08854166666666642,
            0.9960724739013166
        }
    
        {
            95.5,
            16.99264546796643,
            0.9845360824742269,
            0.17518191204089104,
            -0.029411764705882353,
            0.9995673804686135
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            78.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            78.81770833333333,
            5.36366041818436,
            0.9976925105485231,
            0.06789443567321975,
            -0.9545717592592587,
            0.2979811343435753
        }
    
        {
            79.64583333333333,
            7.5193904433065315,
            0.9955729166666666,
            0.09399238054133165,
            -0.9085648148148138,
            0.41774391351702894
        }
    
        {
            80.484375,
            9.124986622421702,
            0.9936342592592593,
            0.11265415583236668,
            -0.8619791666666666,
            0.5069437012456501
        }
    
        {
            81.33333333333333,
            10.434983894999052,
            0.991869918699187,
            0.12725590115852503,
            -0.814814814814814,
            0.5797213274999465
        }
    
        {
            82.19270833333333,
            11.548103603258745,
            0.99027359437751,
            0.139133778352515,
            -0.767071759259259,
            0.641561311292152
        }
    
        {
            83.0625,
            12.51483494697393,
            0.9888392857142857,
            0.14898613032111824,
            -0.71875,
            0.6952686081652184
        }
    
        {
            83.94270833333333,
            13.364943608744916,
            0.9875612745098039,
            0.15723463069111665,
            -0.6698495370370361,
            0.742496867152494
        }
    
        {
            84.83333333333333,
            14.117561955081216,
            0.9864341085271318,
            0.16415769715210715,
            -0.6203703703703696,
            0.7843089975045107
        }
    
        {
            85.734375,
            14.78570063809541,
            0.9854525862068966,
            0.16995058204707367,
            -0.5703125,
            0.8214278132275228
        }
    
        {
            86.64583333333333,
            15.378542387762979,
            0.9846117424242423,
            0.17475616349730658,
            -0.5196759259259258,
            0.8543634659868314
        }
    
        {
            87.56770833333333,
            15.902718548986037,
            0.9839068352059924,
            0.17868223088748356,
            -0.46846064814814786,
            0.8834843638325566
        }
    
        {
            88.5,
            16.36306817195357,
            0.9833333333333333,
            0.1818118685772619,
            -0.4166666666666667,
            0.9090593428863095
        }
    
        {
            89.44270833333333,
            16.763112061853686,
            0.9828869047619047,
            0.1842100226577328,
            -0.3642939814814814,
            0.931284003436315
        }
    
        {
            90.39583333333333,
            17.105359276326897,
            0.9825634057971014,
            0.18592781822094454,
            -0.3113425925925926,
            0.9502977375737157
        }
    
        {
            91.359375,
            17.391509411473606,
            0.9823588709677419,
            0.18700547754272695,
            -0.2578125,
            0.9661949673040893
        }
    
        {
            92.33333333333333,
            17.622586517181766,
            0.9822695035460992,
            0.18747432465086986,
            -0.20370370370370364,
            0.9790325842878743
        }
    
        {
            93.31770833333333,
            17.79902557487155,
            0.9822916666666666,
            0.18735816394601632,
            -0.14901620370370372,
            0.9888347541595289
        }
    
        {
            94.3125,
            17.92072386233324,
            0.982421875,
            0.18667420689930458,
            -0.09375,
            0.9955957701296244
        }
    
        {
            95.31770833333333,
            17.98706418739861,
            0.9826567869415808,
            0.1854336514164805,
            -0.03790509259259283,
            0.9992813437443666
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            77.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            77.80729166666667,
            5.4795404459008035,
            0.9975293803418804,
            0.07025051853718979,
            -0.9575109649122823,
            0.288396865573727
        }
    
        {
            78.625,
            7.6882621573408905,
            0.995253164556962,
            0.09731977414355558,
            -0.9144736842105263,
            0.4046453767021521
        }
    
        {
            79.453125,
            9.3381436985289,
            0.9931640625,
            0.11672679623161124,
            -0.8708881578947368,
            0.4914812472909947
        }
    
        {
            80.29166666666667,
            10.688697951055019,
            0.9912551440329219,
            0.1319592339636422,
            -0.8267543859649135,
            0.5625630500555283
        }
    
        {
            81.140625,
            11.840564792668253,
            0.9895198170731707,
            0.14439713161790552,
            -0.7820723684210527,
            0.6231876206667502
        }
    
        {
            82.0,
            12.84523257866513,
            0.9879518072289156,
            0.15476183829717025,
            -0.7368421052631579,
            0.6760648725613226
        }
    
        {
            82.86979166666667,
            13.733085200466164,
            0.986545138888889,
            0.16348910952935908,
            -0.691063596491229,
            0.722793957919273
        }
    
        {
            83.75,
            14.523687548277813,
            0.9852941176470589,
            0.17086691233268014,
            -0.6447368421052632,
            0.7644046078040955
        }
    
        {
            84.640625,
            15.230384092641097,
            0.9841933139534884,
            0.17709748944931508,
            -0.5978618421052632,
            0.8015991627705841
        }
    
        {
            85.54166666666667,
            15.862637356029033,
            0.9832375478927203,
            0.18232916501182797,
            -0.5504385964912287,
            0.8348756503173189
        }
    
        {
            86.453125,
            16.4273302071388,
            0.982421875,
            0.18667420689930456,
            -0.5024671052631579,
            0.8645963266915159
        }
    
        {
            87.375,
            16.929541488179765,
            0.9817415730337079,
            0.19021956728291872,
            -0.45394736842105265,
            0.8910284993778824
        }
    
        {
            88.30729166666667,
            17.373031931653806,
            0.9811921296296297,
            0.19303368812948674,
            -0.4048793859649127,
            0.9143701016659913
        }
    
        {
            89.25,
            17.760560238911385,
            0.9807692307692307,
            0.19517099163638885,
            -0.35526315789473684,
            0.9347663283637571
        }
    
        {
            90.203125,
            18.094094070562775,
            0.98046875,
            0.1966749355495954,
            -0.3050986842105263,
            0.9523207405559355
        }
    
        {
            91.16666666666667,
            18.374952758820598,
            0.9802867383512546,
            0.19758013719161932,
            -0.25438596491228055,
            0.9671027767800319
        }
    
        {
            92.140625,
            18.603903477748293,
            0.980219414893617,
            0.1979138667845563,
            -0.203125,
            0.9791528146183313
        }
    
        {
            93.125,
            18.7812240016459,
            0.9802631578947368,
            0.19769709475416736,
            -0.1513157894736842,
            0.9884854737708368
        }
    
        {
            94.11979166666667,
            18.906739978728847,
            0.9804144965277778,
            0.19694520811175883,
            -0.09895833333333312,
            0.9950915778278344
        }
    
        {
            95.125,
            18.979841279631398,
            0.9806701030927835,
            0.19566846680032368,
            -0.046052631578947366,
            0.998939014717442
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            76.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            76.796875,
            5.5892745713889385,
            0.997362012987013,
            0.07258798144660959,
            -0.96015625,
            0.2794637285694469
        }
    
        {
            77.60416666666667,
            7.84814092458983,
            0.9949252136752137,
            0.10061719134089527,
            -0.9197916666666672,
            0.39240704622949185
        }
    
        {
            78.421875,
            9.5398910625004,
            0.9926819620253164,
            0.12075811471519494,
            -0.87890625,
            0.47699455312502004
        }
    
        {
            79.25,
            10.928746497197197,
            0.990625,
            0.13660933121496496,
            -0.8375,
            0.5464373248598599
        }
    
        {
            80.08854166666667,
            12.11715699768707,
            0.9887474279835392,
            0.14959453083564284,
            -0.795572916666667,
            0.605857849884354
        }
    
        {
            80.9375,
            13.157548926376828,
            0.9870426829268293,
            0.16045791373630278,
            -0.753125,
            0.6578774463188414
        }
    
        {
            81.796875,
            14.080882082965363,
            0.9855045180722891,
            0.16964918172247426,
            -0.71015625,
            0.7040441041482681
        }
    
        {
            82.66666666666667,
            14.907119849998582,
            0.9841269841269842,
            0.1774657124999831,
            -0.6666666666666669,
            0.7453559924999296
        }
    
        {
            83.546875,
            15.649909831509413,
            0.9829044117647059,
            0.1841165862530519,
            -0.62265625,
            0.7824954915754707
        }
    
        {
            84.4375,
            16.318964236433633,
            0.9818313953488372,
            0.1897553980980655,
            -0.578125,
            0.8159482118216816
        }
    
        {
            85.33854166666667,
            16.92138606044424,
            0.9809027777777778,
            0.1944986903499338,
            -0.5330729166666668,
            0.8460693030222127
        }
    
        {
            86.25,
            17.46245973510032,
            0.9801136363636364,
            0.19843704244432184,
            -0.4875,
            0.8731229867550161
        }
    
        {
            87.171875,
            17.946147469147103,
            0.9794592696629213,
            0.20164210639491129,
            -0.44140625,
            0.8973073734573551
        }
    
        {
            88.10416666666667,
            18.375413355139028,
            0.9789351851851852,
            0.20417125950154474,
            -0.3947916666666667,
            0.918770667756952
        }
    
        {
            89.046875,
            18.752441247324974,
            0.9785370879120879,
            0.2060707829376371,
            -0.34765625,
            0.9376220623662487
        }
    
        {
            90.0,
            19.078784028338912,
            0.9782608695652174,
            0.2073780872645534,
            -0.3,
            0.9539392014169457
        }
    
        {
            90.96354166666667,
            19.355466603949278,
            0.9781025985663083,
            0.2081232968166589,
            -0.2518229166666669,
            0.9677733301974656
        }
    
        {
            91.9375,
            19.583056292366624,
            0.9780585106382979,
            0.20833038608900664,
            -0.203125,
            0.9791528146183313
        }
    
        {
            92.921875,
            19.76170909826311,
            0.978125,
            0.20801799050803274,
            -0.15390625,
            0.9880854549131556
        }
    
        {
            93.91666666666667,
            19.891197103799982,
            0.9782986111111112,
            0.2071999698312498,
            -0.10416666666666662,
            0.9945598551900009
        }
    
        {
            94.921875,
            19.97092002097988,
            0.9785760309278351,
            0.2058857734121637,
            -0.05390625,
            0.9985460010489939
        }
    
        {
            95.9375,
            19.99990234351158,
            0.9789540816326531,
            0.20408063615828143,
            -0.003125,
            0.999995117175579
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            75.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            75.78645833333333,
            5.693218183938814,
            0.9971902412280701,
            0.07491076557814229,
            -0.9625496031746021,
            0.27110562780660985
        }
    
        {
            76.58333333333333,
            7.99956596044789,
            0.9945887445887446,
            0.10389046701880376,
            -0.9246031746031735,
            0.38093171240227996
        }
    
        {
            77.390625,
            9.73093839819033,
            0.9921875,
            0.12475562048961962,
            -0.8861607142857143,
            0.4633780189614443
        }
    
        {
            78.20833333333333,
            11.156011707694763,
            0.9899789029535865,
            0.1412153380720856,
            -0.8472222222222219,
            0.5312386527473693
        }
    
        {
            79.03645833333333,
            12.37894398255621,
            0.9879557291666666,
            0.15473679978195262,
            -0.8077876984126978,
            0.5894735229788666
        }
    
        {
            79.875,
            13.453043335989072,
            0.9861111111111112,
            0.1660869547652972,
            -0.7678571428571429,
            0.6406211112375748
        }
    
        {
            80.72395833333333,
            14.409807458750606,
            0.9844385162601625,
            0.17572935925305616,
            -0.727430555555555,
            0.686181307559552
        }
    
        {
            81.58333333333333,
            15.269568501507258,
            0.9829317269076304,
            0.18397070483743685,
            -0.6865079365079363,
            0.7271223095955832
        }
    
        {
            82.453125,
            16.04625120501281,
            0.9815848214285714,
            0.1910268000596763,
            -0.6450892857142857,
            0.7641072002387052
        }
    
        {
            83.33333333333333,
            16.74979270186818,
            0.9803921568627451,
            0.19705638472786094,
            -0.6031746031746026,
            0.7976091762794361
        }
    
        {
            84.22395833333333,
            17.387490982454356,
            0.9793483527131782,
            0.20218012770295762,
            -0.5607638888888884,
            0.8279757610692541
        }
    
        {
            85.125,
            17.964809350505227,
            0.978448275862069,
            0.20649206150006008,
            -0.5178571428571429,
            0.8554671119288203
        }
    
        {
            86.03645833333333,
            18.48588211194147,
            0.9776870265151515,
            0.2100668421811531,
            -0.474454365079365,
            0.8802801005686409
        }
    
        {
            86.95833333333333,
            18.95384562269329,
            0.9770599250936329,
            0.21296455755835159,
            -0.4305555555555554,
            0.9025640772711083
        }
    
        {
            87.890625,
            19.3710618477505,
            0.9765625,
            0.21523402053056112,
            -0.3861607142857143,
            0.9224315165595476
        }
    
        {
            88.83333333333333,
            19.739272754812667,
            0.9761904761904762,
            0.21691508521772163,
            -0.34126984126984117,
            0.9399653692767928
        }
    
        {
            89.78645833333333,
            20.059708371673743,
            0.9759397644927535,
            0.21804030838775806,
            -0.29588293650793657,
            0.9552242081749397
        }
    
        {
            90.75,
            20.33316256758894,
            0.9758064516129032,
            0.2186361566407413,
            -0.25,
            0.9682458365518543
        }
    
        {
            91.72395833333333,
            20.560045419816845,
            0.9757867907801417,
            0.21872388744486004,
            -0.2036210317460317,
            0.9790497818960389
        }
    
        {
            92.70833333333333,
            20.740417800891972,
            0.9758771929824561,
            0.21832018737781023,
            -0.1567460317460318,
            0.9876389428996165
        }
    
        {
            93.703125,
            20.87401171874671,
            0.97607421875,
            0.21743762207027825,
            -0.109375,
            0.9940005580355576
        }
    
        {
            94.70833333333333,
            20.960238481997827,
            0.9763745704467354,
            0.21608493280410132,
            -0.06150793650793671,
            0.9981065943808486
        }
    
        {
            95.72395833333333,
            20.998185659677016,
            0.9767750850340136,
            0.21426720060894916,
            -0.013144841269841471,
            0.9999136028417608
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            74.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            74.77604166666667,
            5.791683059778888,
            0.997013888888889,
            0.07722244079705184,
            -0.9647253787878797,
            0.26325832089904067
        }
    
        {
            75.5625,
            8.143008887997114,
            0.9942434210526315,
            0.10714485378943571,
            -0.9289772727272727,
            0.37013676763623243
        }
    
        {
            76.359375,
            9.911904439076025,
            0.9916801948051948,
            0.12872603167631202,
            -0.8927556818181818,
            0.45054111086709203
        }
    
        {
            77.16666666666667,
            11.371260068943755,
            0.9893162393162394,
            0.1457853854992789,
            -0.8560606060606066,
            0.5168754576792621
        }
    
        {
            77.984375,
            12.626846631656496,
            0.9871439873417721,
            0.15983350166653792,
            -0.8188920454545454,
            0.5739475741662043
        }
    
        {
            78.8125,
            13.732801744363748,
            0.98515625,
            0.17166002180454684,
            -0.78125,
            0.624218261107443
        }
    
        {
            79.65104166666667,
            14.721126363662862,
            0.9833461934156379,
            0.18174230078596126,
            -0.7431344696969702,
            0.6691421074392216
        }
    
        {
            80.5,
            15.612494995995995,
            0.9817073170731707,
            0.19039628043897555,
            -0.7045454545454546,
            0.7096588634543634
        }
    
        {
            81.359375,
            16.421087041038877,
            0.9802334337349398,
            0.1978444221811913,
            -0.6654829545454546,
            0.746413047319949
        }
    
        {
            82.22916666666667,
            17.15704372278496,
            0.9789186507936508,
            0.20425052050934475,
            -0.6259469696969701,
            0.7798656237629534
        }
    
        {
            83.109375,
            17.82783742099347,
            0.9777573529411765,
            0.20973926377639374,
            -0.5859375,
            0.810356246408794
        }
    
        {
            84.0,
            18.439088914585774,
            0.9767441860465116,
            0.21440801063471832,
            -0.5454545454545454,
            0.8381404052084442
        }
    
        {
            84.90104166666667,
            18.99508157168402,
            0.9758740421455939,
            0.21833427093889676,
            -0.5044981060606063,
            0.8634127987129107
        }
    
        {
            85.8125,
            19.49909853685549,
            0.9751420454545454,
            0.22158066519153968,
            -0.4630681818181818,
            0.8863226607661587
        }
    
        {
            86.734375,
            19.953651128537228,
            0.9745435393258427,
            0.22419832728693515,
            -0.4211647727272727,
            0.9069841422062376
        }
    
        {
            87.66666666666667,
            20.360637405433916,
            0.9740740740740741,
            0.2262293045048213,
            -0.37878787878787895,
            0.9254835184288153
        }
    
        {
            88.609375,
            20.721454150454186,
            0.9737293956043956,
            0.2277082873676284,
            -0.3359375,
            0.9418842795660993
        }
    
        {
            89.5625,
            21.037076644581585,
            0.9735054347826086,
            0.22866387657153897,
            -0.29261363636363635,
            0.9562307565718903
        }
    
        {
            90.52604166666667,
            21.3081153592928,
            0.9733982974910395,
            0.2291195199923957,
            -0.2488162878787879,
            0.9685506981496737
        }
    
        {
            91.5,
            21.534855467358028,
            0.973404255319149,
            0.2290942070995535,
            -0.20454545454545456,
            0.9788570666980921
        }
    
        {
            92.484375,
            21.71728299901659,
            0.9735197368421052,
            0.22860297893701673,
            -0.15980113636363635,
            0.9871492272280268
        }
    
        {
            93.47916666666667,
            21.855100075395555,
            0.9737413194444445,
            0.22765729245203703,
            -0.1145833333333332,
            0.9934136397907078
        }
    
        {
            94.484375,
            21.947730653973657,
            0.9740657216494846,
            0.22626526447395523,
            -0.06889204545454546,
            0.9976241206351663
        }
    
        {
            95.5,
            21.99431744792277,
            0.9744897959183674,
            0.2244318106930895,
            -0.022727272727272728,
            0.9997417021783078
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            73.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            73.765625,
            5.88494421038764,
            0.9968327702702703,
            0.07952627311334648,
            -0.9667119565217391,
            0.2558671395820713
        }
    
        {
            74.54166666666667,
            8.278884620258623,
            0.9938888888888889,
            0.11038512827011497,
            -0.9329710144927543,
            0.3599515052286361
        }
    
        {
            75.328125,
            10.083331988205833,
            0.9911595394736842,
            0.13267542089744516,
            -0.8987771739130435,
            0.4384057386176449
        }
    
        {
            76.125,
            11.575161985907584,
            0.9886363636363636,
            0.15032677903776084,
            -0.8641304347826086,
            0.5032679124307645
        }
    
        {
            76.93229166666667,
            12.861667812337938,
            0.9863114316239316,
            0.16489317708125562,
            -0.8290307971014499,
            0.5592029483625196
        }
    
        {
            77.75,
            13.997767679169419,
            0.9841772151898734,
            0.17718693264771415,
            -0.7934782608695652,
            0.6085985947464965
        }
    
        {
            78.578125,
            15.01593391981914,
            0.9822265625,
            0.18769917399773925,
            -0.7574728260869565,
            0.6528666921660495
        }
    
        {
            79.41666666666667,
            15.937159582421039,
            0.9804526748971194,
            0.19675505657309925,
            -0.7210144927536236,
            0.6929199818443936
        }
    
        {
            80.265625,
            16.775858945501867,
            0.9788490853658537,
            0.20458364567685203,
            -0.6841032608695652,
            0.7293851715435594
        }
    
        {
            81.125,
            17.5423594479192,
            0.9774096385542169,
            0.21135372828818313,
            -0.6467391304347826,
            0.762711280344313
        }
    
        {
            81.99479166666667,
            18.24429060116972,
            0.9761284722222223,
            0.21719393572821094,
            -0.6089221014492757,
            0.7932300261378147
        }
    
        {
            82.875,
            18.887413136795626,
            0.975,
            0.22220486043288973,
            -0.5706521739130435,
            0.8211918755128533
        }
    
        {
            83.765625,
            19.476141002759633,
            0.9740188953488372,
            0.22646675584604223,
            -0.5319293478260869,
            0.8467887392504189
        }
    
        {
            84.66666666666667,
            20.01388406970408,
            0.9731800766283526,
            0.23004464447935724,
            -0.49275362318840604,
            0.8701688725958303
        }
    
        {
            85.578125,
            20.503280749294124,
            0.9724786931818182,
            0.23299182669652413,
            -0.453125,
            0.8914469890997445
        }
    
        {
            86.5,
            20.946360065653412,
            0.9719101123595506,
            0.23535236028824058,
            -0.41304347826086957,
            0.9107113072023223
        }
    
        {
            87.43229166666667,
            21.344656800120486,
            0.9714699074074075,
            0.23716285333467207,
            -0.37250905797101463,
            0.9280285565269785
        }
    
        {
            88.375,
            21.699294343365178,
            0.9711538461538461,
            0.23845378399302394,
            -0.33152173913043476,
            0.9434475801463121
        }
    
        {
            89.328125,
            22.01104459094059,
            0.9709578804347826,
            0.23925048468413684,
            -0.29008152173913043,
            0.9570019387365474
        }
    
        {
            90.29166666666667,
            22.28037096988187,
            0.970878136200717,
            0.23957388139657923,
            -0.24818840579710147,
            0.9687117812992125
        }
    
        {
            91.265625,
            22.5074586161871,
            0.9709109042553191,
            0.2394410491083734,
            -0.20584239130434784,
            0.9785851572255261
        }
    
        {
            92.25,
            22.692234354509914,
            0.9710526315789474,
            0.2388656247843149,
            -0.16304347826086957,
            0.9866188849786919
        }
    
        {
            93.24479166666667,
            22.834378183780913,
            0.9712999131944445,
            0.23785810608105118,
            -0.11979166666666655,
            0.9927990514687361
        }
    
        {
            94.25,
            22.93332727713098,
            0.9716494845360825,
            0.2364260544034122,
            -0.07608695652173914,
            0.9971011859622168
        }
    
        {
            95.265625,
            22.988272952950926,
            0.9720982142857143,
            0.23457421380562168,
            -0.03192934782608695,
            0.9994901283891705
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            72.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            72.75520833333333,
            5.973245380299105,
            0.9966466894977168,
            0.08182527918217951,
            -0.9685329861111106,
            0.24888522417912917
        }
    
        {
            73.52083333333333,
            8.407560048683722,
            0.9935247747747747,
            0.11361567633356381,
            -0.9366319444444441,
            0.3503150020284882
        }
    
        {
            74.296875,
            10.245699841122372,
            0.990625,
            0.13660933121496496,
            -0.904296875,
            0.4269041600467655
        }
    
        {
            75.08333333333333,
            11.768307251068718,
            0.9879385964912281,
            0.15484614804037786,
            -0.8715277777777771,
            0.4903461354611961
        }
    
        {
            75.88020833333333,
            13.084111864774451,
            0.985457251082251,
            0.16992353071135652,
            -0.8383246527777771,
            0.545171327698935
        }
    
        {
            76.6875,
            14.248766393972497,
            0.9831730769230769,
            0.18267649223041663,
            -0.8046875,
            0.5936985997488541
        }
    
        {
            77.50520833333333,
            15.295184902661283,
            0.9810785864978903,
            0.19360993547672511,
            -0.7706163194444443,
            0.6372993709442198
        }
    
        {
            78.33333333333333,
            16.244657241348296,
            0.9791666666666666,
            0.2030582155168537,
            -0.7361111111111107,
            0.6768607183895118
        }
    
        {
            79.171875,
            17.111814894521707,
            0.9774305555555556,
            0.21125697400644083,
            -0.701171875,
            0.7129922872717378
        }
    
        {
            80.02083333333333,
            17.907155905918998,
            0.9758638211382114,
            0.21837995007218292,
            -0.6657986111111108,
            0.7461314960799577
        }
    
        {
            80.88020833333333,
            18.63845218779171,
            0.9744603413654618,
            0.22455966491315313,
            -0.6299913194444443,
            0.776602174491321
        }
    
        {
            81.75,
            19.3115897843756,
            0.9732142857142857,
            0.2298998783854238,
            -0.59375,
            0.8046495743489833
        }
    
        {
            82.63020833333333,
            19.931098082893765,
            0.9721200980392156,
            0.23448350685757371,
            -0.5570746527777773,
            0.8304624201205727
        }
    
        {
            83.52083333333333,
            20.500497538000307,
            0.9711724806201549,
            0.23837787834884078,
            -0.5199652777777775,
            0.8541873974166786
        }
    
        {
            84.421875,
            21.02253603836547,
            0.9703663793103449,
            0.24163834526856862,
            -0.482421875,
            0.8759390015985612
        }
    
        {
            85.33333333333333,
            21.49935399546281,
            0.9696969696969696,
            0.2443108408575319,
            -0.4444444444444444,
            0.8958064164776166
        }
    
        {
            86.25520833333333,
            21.932602111315123,
            0.9691596441947565,
            0.24643373158781037,
            -0.406032986111111,
            0.9138584213047961
        }
    
        {
            87.1875,
            22.32352668710748,
            0.96875,
            0.24803918541230535,
            -0.3671875,
            0.9301469452961451
        }
    
        {
            88.13020833333333,
            22.673031979055306,
            0.9684638278388278,
            0.24915419757203633,
            -0.32790798611111105,
            0.9447096657939704
        }
    
        {
            89.08333333333333,
            22.981725832108925,
            0.9682971014492753,
            0.2498013677403144,
            -0.28819444444444453,
            0.9575719096712048
        }
    
        {
            90.046875,
            23.24995274692779,
            0.9682459677419355,
            0.24999949190244936,
            -0.24804687499999997,
            0.968748031121991
        }
    
        {
            91.02083333333333,
            23.477817175060302,
            0.9683067375886524,
            0.2497640125006415,
            -0.20746527777777782,
            0.9782423822941785
        }
    
        {
            92.00520833333333,
            23.66519891190293,
            0.9684758771929824,
            0.24910735696739927,
            -0.1664496527777778,
            0.986049954662621
        }
    
        {
            93.0,
            23.811761799581316,
            0.96875,
            0.24803918541230538,
            -0.125,
            0.9921567416492215
        }
    
        {
            94.00520833333333,
            23.91695645784801,
            0.9691258591065292,
            0.2465665614211135,
            -0.0831163194444446,
            0.9965398524103333
        }
    
        {
            95.02083333333333,
            23.98001736110486,
            0.9696003401360543,
            0.24469405470515163,
            -0.04079861111111125,
            0.9991673900460345
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            71.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            71.74479166666667,
            6.056803505694791,
            0.9964554398148149,
            0.08412227091242766,
            -0.9702083333333337,
            0.24227214022779178
        }
    
        {
            72.5,
            8.52936105461599,
            0.9931506849315068,
            0.11684056239199986,
            -0.94,
            0.3411744421846396
        }
    
        {
            73.265625,
            10.399432357555627,
            0.9900760135135135,
            0.14053286969669765,
            -0.909375,
            0.4159772943022251
        }
    
        {
            74.04166666666667,
            11.95121739498624,
            0.9872222222222223,
            0.15934956526648322,
            -0.8783333333333336,
            0.4780486957994499
        }
    
        {
            74.828125,
            13.294800073125394,
            0.9845805921052632,
            0.17493157990954467,
            -0.846875,
            0.5317920029250157
        }
    
        {
            75.625,
            14.486523910172515,
            0.9821428571428571,
            0.1881366741580846,
            -0.815,
            0.5794609564069007
        }
    
        {
            76.43229166666667,
            15.559716918427428,
            0.9799011752136753,
            0.19948355023624909,
            -0.7827083333333336,
            0.6223886767370975
        }
    
        {
            77.25,
            16.535945694153693,
            0.9778481012658228,
            0.2093157682804265,
            -0.75,
            0.6614378277661477
        }
    
        {
            78.078125,
            17.430042928357206,
            0.9759765625,
            0.21787553660446507,
            -0.716875,
            0.6972017171342882
        }
    
        {
            78.91666666666667,
            18.25266342817458,
            0.9742798353909465,
            0.22534152380462444,
            -0.6833333333333336,
            0.7301065371269836
        }
    
        {
            79.765625,
            19.01170871750814,
            0.9727515243902439,
            0.23185010631107486,
            -0.649375,
            0.7604683487003255
        }
    
        {
            80.625,
            19.71317769919401,
            0.9713855421686747,
            0.23750816505053024,
            -0.615,
            0.7885271079677604
        }
    
        {
            81.49479166666667,
            20.361702561588427,
            0.9701760912698413,
            0.2424012209712908,
            -0.5802083333333334,
            0.8144681024635375
        }
    
        {
            82.375,
            20.96090110181335,
            0.9691176470588235,
            0.24659883649192174,
            -0.545,
            0.8384360440725339
        }
    
        {
            83.265625,
            21.51361646398334,
            0.9682049418604651,
            0.25015833097655044,
            -0.509375,
            0.8605446585593336
        }
    
        {
            84.16666666666667,
            22.02208487455767,
            0.9674329501915709,
            0.2531274123512376,
            -0.47333333333333344,
            0.8808833949823073
        }
    
        {
            85.078125,
            22.488055640369957,
            0.966796875,
            0.2555460868223859,
            -0.436875,
            0.8995222256147983
        }
    
        {
            86.0,
            22.9128784747792,
            0.9662921348314607,
            0.25744807275032805,
            -0.4000000000000001,
            0.9165151389911681
        }
    
        {
            86.93229166666667,
            23.297567803991832,
            0.9659143518518519,
            0.2588618644887981,
            -0.3627083333333333,
            0.9319027121596737
        }
    
        {
            87.875,
            23.642850399222173,
            0.9656593406593407,
            0.2598115428485953,
            -0.325,
            0.9457140159688869
        }
    
        {
            88.828125,
            23.949200591760366,
            0.9655230978260869,
            0.26031739773652574,
            -0.28687499999999994,
            0.9579680236704146
        }
    
        {
            89.79166666666667,
            24.216865966144788,
            0.9655017921146954,
            0.260396408238116,
            -0.24833333333333324,
            0.968674638645792
        }
    
        {
            90.765625,
            24.445885509823018,
            0.965591755319149,
            0.2600626118066279,
            -0.209375,
            0.9778354203929207
        }
    
        {
            91.75,
            24.63610155848526,
            0.9657894736842105,
            0.25932738482616063,
            -0.17,
            0.9854440623394106
        }
    
        {
            92.74479166666667,
            24.787166411403216,
            0.9660915798611112,
            0.2581996501187835,
            -0.1302083333333333,
            0.9914866564561298
        }
    
        {
            93.75,
            24.898544134145673,
            0.9664948453608248,
            0.2566860220015018,
            -0.09000000000000001,
            0.9959417653658271
        }
    
        {
            94.765625,
            24.969507771667725,
            0.9669961734693877,
            0.2547908956292625,
            -0.04937500000000001,
            0.9987803108667092
        }
    
        {
            95.79166666666667,
            24.999131929373483,
            0.9675925925925927,
            0.2525164841350857,
            -0.008333333333333153,
            0.9999652771749404
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            70.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            70.734375,
            6.135812363442595,
            0.9962588028169014,
            0.08641989244285345,
            -0.9717548076923077,
            0.23599278320933056
        }
    
        {
            71.47916666666667,
            8.644578222151026,
            0.9927662037037037,
            0.12006358641876425,
            -0.9431089743589751,
            0.3324837777750398
        }
    
        {
            72.234375,
            10.544907223839147,
            0.9895119863013698,
            0.14445078388820748,
            -0.9140625,
            0.4055733547630441
        }
    
        {
            73.0,
            12.12435565298214,
            0.9864864864864865,
            0.16384264395921813,
            -0.8846153846153846,
            0.4663213712685439
        }
    
        {
            73.77604166666667,
            13.494283085746451,
            0.9836805555555557,
            0.17992377447661934,
            -0.8547676282051289,
            0.5190108879133255
        }
    
        {
            74.5625,
            14.711682220262915,
            0.9810855263157895,
            0.193574766056091,
            -0.8245192307692307,
            0.5658339315485736
        }
    
        {
            75.359375,
            15.81026880256547,
            0.9786931818181818,
            0.20532816626708403,
            -0.7938701923076923,
            0.6080872616371334
        }
    
        {
            76.16666666666667,
            16.811867501526645,
            0.9764957264957266,
            0.2155367628400852,
            -0.7628205128205133,
            0.6466102885202563
        }
    
        {
            76.984375,
            17.73149756392209,
            0.9744857594936709,
            0.22444933625217836,
            -0.7313701923076923,
            0.681980675535465
        }
    
        {
            77.8125,
            18.579958120243436,
            0.97265625,
            0.23224947650304295,
            -0.6995192307692307,
            0.7146137738555167
        }
    
        {
            78.65104166666667,
            19.365269033717624,
            0.9710005144032923,
            0.23907739547799536,
            -0.6672676282051286,
            0.7448180397583709
        }
    
        {
            79.5,
            20.09353129741012,
            0.9695121951219512,
            0.24504306460256245,
            -0.6346153846153846,
            0.7728281268234661
        }
    
        {
            80.359375,
            20.769469170139494,
            0.9681852409638554,
            0.2502345683149337,
            -0.6015625,
            0.7988257373130575
        }
    
        {
            81.22916666666667,
            21.396786736304303,
            0.967013888888889,
            0.2547236516226703,
            -0.5681089743589747,
            0.8229533360117047
        }
    
        {
            82.109375,
            21.97841070481155,
            0.9659926470588235,
            0.2585695377036653,
            -0.5342548076923077,
            0.8453234886465981
        }
    
        {
            83.0,
            22.516660498395403,
            0.9651162790697675,
            0.2618216337022721,
            -0.5,
            0.8660254037844386
        }
    
        {
            83.90104166666667,
            23.0133701844876,
            0.9643797892720307,
            0.26452149637342065,
            -0.46534455128205154,
            0.8851296224802931
        }
    
        {
            84.8125,
            23.469977497858835,
            0.9637784090909091,
            0.26670428974839583,
            -0.43028846153846145,
            0.9026914422253397
        }
    
        {
            85.734375,
            23.88758973524485,
            0.9633075842696629,
            0.26839988466567244,
            -0.3948317307692308,
            0.9187534513555711
        }
    
        {
            86.66666666666667,
            24.26703296426837,
            0.962962962962963,
            0.2696336996029819,
            -0.3589743589743591,
            0.9333474217026304
        }
    
        {
            87.609375,
            24.608888884087698,
            0.9627403846153846,
            0.2704273503745901,
            -0.32271634615384615,
            0.9464957263110653
        }
    
        {
            88.5625,
            24.913522307172865,
            0.9626358695652174,
            0.2707991555127485,
            -0.2860576923076923,
            0.9582123964297256
        }
    
        {
            89.52604166666667,
            25.181101316230446,
            0.9626456093189965,
            0.27076453028204783,
            -0.2489983974358975,
            0.968503896778095
        }
    
        {
            90.5,
            25.411611519146124,
            0.9627659574468085,
            0.27033629275687365,
            -0.21153846153846154,
            0.9773696738133124
        }
    
        {
            91.484375,
            25.604865374755928,
            0.9629934210526315,
            0.26952489868164137,
            -0.1736778846153846,
            0.9848025144136895
        }
    
        {
            92.47916666666667,
            25.760507227903894,
            0.9633246527777778,
            0.26833861695733224,
            -0.1354166666666665,
            0.9907887395347653
        }
    
        {
            93.484375,
            25.878014430388106,
            0.963756443298969,
            0.26678365392152686,
            -0.0967548076923077,
            0.9953082473226195
        }
    
        {
            94.5,
            25.95669470483482,
            0.9642857142857143,
            0.26486423168198797,
            -0.057692307692307696,
            0.9983344117244162
        }
    
        {
            95.52604166666667,
            25.99567970833353,
            0.9649095117845118,
            0.2625826233165003,
            -0.01822916666666649,
            0.9998338349359053
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            69.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            69.72395833333333,
            6.210445582371496,
            0.9960565476190476,
            0.08872065117673565,
            -0.9731867283950614,
            0.23001650305079602
        }
    
        {
            70.45833333333333,
            8.753471533562532,
            0.9923708920187793,
            0.1232883314586272,
            -0.9459876543209872,
            0.3242026493912047
        }
    
        {
            71.203125,
            10.682461805893574,
            0.9889322916666666,
            0.1483675250818552,
            -0.9184027777777778,
            0.39564673355161384
        }
    
        {
            71.95833333333333,
            12.28813508588222,
            0.9857305936073059,
            0.16833061761482493,
            -0.8904320987654317,
            0.4551161142919337
        }
    
        {
            72.72395833333333,
            13.683050987685371,
            0.9827561936936936,
            0.1849060944281807,
            -0.8620756172839504,
            0.5067796662105691
        }
    
        {
            73.5,
            14.9248115565993,
            0.98,
            0.198997487421324,
            -0.8333333333333334,
            0.5527707983925667
        }
    
        {
            74.28645833333333,
            16.04749538993333,
            0.9774533991228069,
            0.21115125513070174,
            -0.8042052469135798,
            0.5943516811086414
        }
    
        {
            75.08333333333333,
            17.07316770712326,
            0.975108225108225,
            0.22172945074186054,
            -0.7746913580246909,
            0.6323395447082685
        }
    
        {
            75.890625,
            18.017020761196203,
            0.9729567307692307,
            0.2309874456563616,
            -0.7447916666666666,
            0.6672970652294891
        }
    
        {
            76.70833333333333,
            18.88998669195462,
            0.9709915611814346,
            0.23911375559436227,
            -0.7145061728395061,
            0.6996291367390598
        }
    
        {
            77.53645833333333,
            19.700193631618564,
            0.9692057291666666,
            0.24625242039523204,
            -0.6838348765432096,
            0.7296368011710574
        }
    
        {
            78.375,
            20.453835214941964,
            0.9675925925925926,
            0.252516484135086,
            -0.6527777777777778,
            0.757549452405258
        }
    
        {
            79.22395833333333,
            21.15571851765533,
            0.9661458333333333,
            0.25799656728847964,
            -0.6213348765432096,
            0.7835451302835302
        }
    
        {
            80.08333333333333,
            21.809624531894688,
            0.9648594377510039,
            0.2627665606252372,
            -0.5895061728395062,
            0.8077638715516549
        }
    
        {
            80.953125,
            22.418553760989468,
            0.9637276785714286,
            0.26688754477368415,
            -0.5572916666666666,
            0.8303168059625728
        }
    
        {
            81.83333333333333,
            22.984898423868586,
            0.9627450980392156,
            0.2704105696925716,
            -0.5246913580246911,
            0.8512925342173544
        }
    
        {
            82.72395833333333,
            23.510566085590785,
            0.9619064922480619,
            0.27337867541384636,
            -0.49170524691358003,
            0.8707617068737321
        }
    
        {
            83.625,
            23.997070133664234,
            0.9612068965517241,
            0.27582839234096823,
            -0.4583333333333333,
            0.8887803753208976
        }
    
        {
            84.53645833333333,
            24.445596995299535,
            0.9606415719696969,
            0.2777908749465856,
            -0.42457561728395066,
            0.9053924813073899
        }
    
        {
            85.45833333333333,
            24.857056621589162,
            0.9602059925093632,
            0.2792927710290917,
            -0.39043209876543206,
            0.9206317267255241
        }
    
        {
            86.390625,
            25.232120642335534,
            0.9598958333333333,
            0.2803568960259504,
            -0.3559027777777778,
            0.9345229867531679
        }
    
        {
            87.33333333333333,
            25.571251218680903,
            0.9597069597069596,
            0.2810027606448451,
            -0.32098765432098764,
            0.9470833784696626
        }
    
        {
            88.28645833333333,
            25.874722702989448,
            0.9596354166666666,
            0.2812469859020592,
            -0.2856867283950618,
            0.958323063073683
        }
    
        {
            89.25,
            26.142637586900065,
            0.9596774193548387,
            0.2811036299666674,
            -0.24999999999999997,
            0.9682458365518541
        }
    
        {
            90.22395833333333,
            26.37493777556511,
            0.9598293439716311,
            0.28058444442090547,
            -0.21392746913580252,
            0.9768495472431517
        }
    
        {
            91.20833333333333,
            26.57141190368996,
            0.9600877192982455,
            0.2796990726704206,
            -0.1774691358024692,
            0.9841263668033312
        }
    
        {
            92.203125,
            26.731699164743997,
            0.96044921875,
            0.27845519963274995,
            -0.14062500000000003,
            0.9900629320275556
        }
    
        {
            93.20833333333333,
            26.855289929960218,
            0.9609106529209621,
            0.27685865907175483,
            -0.1033950617283952,
            0.9946403677763039
        }
    
        {
            94.22395833333333,
            26.94152326796437,
            0.961468962585034,
            0.2749135027343303,
            -0.06577932098765442,
            0.9978341951097903
        }
    
        {
            95.25,
            26.989581323169872,
            0.9621212121212122,
            0.27262203356737247,
            -0.027777777777777776,
            0.9996141230803657
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            68.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            68.71354166666667,
            6.280859146905277,
            0.9958484299516909,
            0.09102694415804749,
            -0.9745163690476192,
            0.22431639810375995
        }
    
        {
            69.4375,
            8.856274258964659,
            0.9919642857142857,
            0.12651820369949512,
            -0.9486607142857143,
            0.3162955092487378
        }
    
        {
            70.171875,
            10.81239839186362,
            0.9883362676056338,
            0.15228730129385382,
            -0.9224330357142857,
            0.38615708542370075
        }
    
        {
            70.91666666666667,
            12.442925254492522,
            0.9849537037037037,
            0.17281840631239614,
            -0.8958333333333339,
            0.44439018766044763
        }
    
        {
            71.671875,
            13.861541544300728,
            0.981806506849315,
            0.18988413074384558,
            -0.8688616071428571,
            0.49505505515359743
        }
    
        {
            72.4375,
            15.126420387851185,
            0.9788851351351351,
            0.2044110863223133,
            -0.8415178571428571,
            0.5402292995661138
        }
    
        {
            73.21354166666667,
            16.271979493081435,
            0.9761805555555556,
            0.21695972657441914,
            -0.8138020833333339,
            0.5811421247529089
        }
    
        {
            74.0,
            17.320508075688775,
            0.9736842105263158,
            0.2279014220485365,
            -0.7857142857142857,
            0.618589574131742
        }
    
        {
            74.796875,
            18.2873587550082,
            0.971387987012987,
            0.23749816564945714,
            -0.7572544642857143,
            0.6531199555360071
        }
    
        {
            75.60416666666667,
            19.183586281998675,
            0.9692841880341881,
            0.2459434138717779,
            -0.7284226190476195,
            0.6851280814999533
        }
    
        {
            76.421875,
            20.017417952482656,
            0.9673655063291139,
            0.2533850373731982,
            -0.69921875,
            0.7149077840172378
        }
    
        {
            77.25,
            20.79513164180501,
            0.965625,
            0.25993914552256264,
            -0.6696428571428571,
            0.7426832729216075
        }
    
        {
            78.08854166666667,
            21.521609149254218,
            0.9640560699588478,
            0.26569887838585454,
            -0.6396949404761908,
            0.7686288981876512
        }
    
        {
            78.9375,
            22.20070029863923,
            0.9626524390243902,
            0.27074024754438086,
            -0.609375,
            0.7928821535228296
        }
    
        {
            79.796875,
            22.83547109727266,
            0.9614081325301205,
            0.2751261577984658,
            -0.5786830357142857,
            0.8155525391883093
        }
    
        {
            80.66666666666667,
            23.428377854407415,
            0.9603174603174603,
            0.27890926017151685,
            -0.5476190476190479,
            0.8367277805145512
        }
    
        {
            81.546875,
            23.981392322681664,
            0.959375,
            0.2821340273256666,
            -0.5161830357142857,
            0.8564782972386308
        }
    
        {
            82.4375,
            24.49609343854648,
            0.9585755813953488,
            0.2848382957970521,
            -0.484375,
            0.8748604799480886
        }
    
        {
            83.33854166666667,
            24.973735661155356,
            0.9579142720306514,
            0.2870544328868432,
            -0.45219494047619063,
            0.8919191307555491
        }
    
        {
            84.25,
            25.415300509732322,
            0.9573863636363636,
            0.28881023306514003,
            -0.41964285714285715,
            0.9076893039190115
        }
    
        {
            85.171875,
            25.82153575960142,
            0.9569873595505618,
            0.29012961527642045,
            -0.38671875000000006,
            0.9221977057000509
        }
    
        {
            86.10416666666667,
            26.192985370875306,
            0.956712962962963,
            0.2910331707875034,
            -0.3534226190476191,
            0.9354637632455474
        }
    
        {
            87.046875,
            26.53001230181349,
            0.9565590659340659,
            0.29153859672322513,
            -0.31975446428571425,
            0.9475004393504817
        }
    
        {
            88.0,
            26.832815729997478,
            0.9565217391304348,
            0.2916610405434508,
            -0.2857142857142857,
            0.9583148474999098
        }
    
        {
            88.96354166666667,
            27.10144376455363,
            0.9565972222222223,
            0.2914133738124046,
            -0.25130208333333337,
            0.967908705876916
        }
    
        {
            89.9375,
            27.335802416428166,
            0.956781914893617,
            0.290806408685406,
            -0.21651785714285715,
            0.9762786577295773
        }
    
        {
            90.921875,
            27.535661359124372,
            0.9570723684210526,
            0.28984906693815127,
            -0.18136160714285712,
            0.9834164771115846
        }
    
        {
            91.91666666666667,
            27.700656831362117,
            0.9574652777777778,
            0.2885485086600221,
            -0.14583333333333318,
            0.9893091725486471
        }
    
        {
            92.921875,
            27.830291886438687,
            0.9579574742268041,
            0.2869102256333885,
            -0.10993303571428571,
            0.9939389959442388
        }
    
        {
            93.9375,
            27.923934066495715,
            0.9585459183673469,
            0.28493810271934406,
            -0.0736607142857143,
            0.9972833595177042
        }
    
        {
            94.96354166666667,
            27.980810462230426,
            0.9592276936026937,
            0.28263444911343866,
            -0.03701636904761888,
            0.9993146593653724
        }
    
        {
            96.0,
            28.0,
            0.96,
            0.28,
            0.0,
            1.0
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            67.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            67.703125,
            6.3471934927474045,
            0.9956341911764706,
            0.09334108077569712,
            -0.9757543103448276,
            0.21886874112922083
        }
    
        {
            68.41666666666667,
            8.953196201481441,
            0.9915458937198068,
            0.12975646668813684,
            -0.9511494252873566,
            0.3087309034993602
        }
    
        {
            69.140625,
            10.93498855094851,
            0.9877232142857143,
            0.1562141221564073,
            -0.9261853448275862,
            0.37706857072236244
        }
    
        {
            69.875,
            12.58905774869589,
            0.9841549295774648,
            0.17731067251684351,
            -0.9008620689655172,
            0.4341054396102031
        }
    
        {
            70.61979166666667,
            14.03014700409788,
            0.9808304398148149,
            0.1948631528346928,
            -0.8751795977011497,
            0.48379817255509955
        }
    
        {
            71.375,
            15.316963635133433,
            0.9777397260273972,
            0.2098214196593621,
            -0.8491379310344828,
            0.5281711598321873
        }
    
        {
            72.140625,
            16.48424170562222,
            0.9748733108108109,
            0.22276002304894893,
            -0.8227370689655172,
            0.5684221277800766
        }
    
        {
            72.91666666666667,
            17.5544786941174,
            0.9722222222222223,
            0.23405971592156533,
            -0.795977011494253,
            0.6053268515212898
        }
    
        {
            73.703125,
            18.54317570521228,
            0.9697779605263158,
            0.24398915401595106,
            -0.7688577586206896,
            0.6394198519038717
        }
    
        {
            74.5,
            19.461500456028563,
            0.9675324675324676,
            0.25274675916920214,
            -0.7413793103448276,
            0.6710862226216746
        }
    
        {
            75.30729166666667,
            20.317771084240434,
            0.9654780982905984,
            0.2604842446697492,
            -0.7135416666666667,
            0.7006127960082911
        }
    
        {
            76.125,
            21.118342146106073,
            0.9636075949367089,
            0.26732078665957054,
            -0.6853448275862069,
            0.7282186946933129
        }
    
        {
            76.953125,
            21.86816299405085,
            0.9619140625,
            0.27335203742563563,
            -0.6567887931034483,
            0.7540745860017534
        }
    
        {
            77.79166666666667,
            22.571145235061106,
            0.9603909465020577,
            0.2786561140131001,
            -0.6278735632183908,
            0.7783153529331419
        }
    
        {
            78.640625,
            23.23041324663371,
            0.9590320121951219,
            0.2832977225199233,
            -0.5985991379310346,
            0.8010487326425418
        }
    
        {
            79.5,
            23.84848003542364,
            0.9578313253012049,
            0.28733108476414027,
            -0.5689655172413793,
            0.8223613805318497
        }
    
        {
            80.36979166666667,
            24.42737373228233,
            0.9567832341269842,
            0.2908020682414563,
            -0.5389727011494253,
            0.8423232321476669
        }
    
        {
            81.25,
            24.968730444297723,
            0.9558823529411765,
            0.2937497699329144,
            -0.5086206896551724,
            0.8609907049757836
        }
    
        {
            82.140625,
            25.47386355874144,
            0.9551235465116279,
            0.29620771579931904,
            -0.47790948275862066,
            0.8784090882324634
        }
    
        {
            83.04166666666667,
            25.94381616536437,
            0.9545019157088123,
            0.2982047835099353,
            -0.4468390804597701,
            0.8946143505298062
        }
    
        {
            83.953125,
            26.379401106438618,
            0.9540127840909091,
            0.2997659216640752,
            -0.41540948275862066,
            0.9096345209116765
        }
    
        {
            84.875,
            26.781231767788427,
            0.9536516853932584,
            0.3009127164920048,
            -0.38362068965517243,
            0.923490750613394
        }
    
        {
            85.80729166666667,
            27.14974579681358,
            0.9534143518518519,
            0.3016638421868176,
            -0.35147270114942525,
            0.9361981309246066
        }
    
        {
            86.75,
            27.48522330271304,
            0.9532967032967034,
            0.30203542090893454,
            -0.31896551724137934,
            0.9477663207832083
        }
    
        {
            87.703125,
            27.78780065486247,
            0.9532948369565217,
            0.3020413114658964,
            -0.2860991379310345,
            0.9582000225814643
        }
    
        {
            88.66666666666667,
            28.05748068202528,
            0.953405017921147,
            0.3016933406669385,
            -0.2528735632183907,
            0.967499333862941
        }
    
        {
            89.640625,
            28.294139845723794,
            0.953623670212766,
            0.3010014877204659,
            -0.21928879310344832,
            0.975659994680131
        }
    
        {
            90.625,
            28.497532787944994,
            0.9539473684210527,
            0.2999740293467894,
            -0.1853448275862069,
            0.9826735444118964
        }
    
        {
            91.61979166666667,
            28.667294517561224,
            0.9543728298611112,
            0.2986176512245961,
            -0.15104166666666663,
            0.9885273971572844
        }
    
        {
            92.625,
            28.802940388092324,
            0.9548969072164949,
            0.29693752977414767,
            -0.11637931034482758,
            0.9932048409687009
        }
    
        {
            93.640625,
            28.90386392179037,
            0.9555165816326531,
            0.29493738695704463,
            -0.08135775862068964,
            0.9966849628203576
        }
    
        {
            94.66666666666667,
            28.969332443503436,
            0.9562289562289563,
            0.29261951963134786,
            -0.04597701149425275,
            0.9989424980518435
        }
    
        {
            95.703125,
            28.998480395261662,
            0.95703125,
            0.2899848039526166,
            -0.010237068965517241,
            0.9999475998366091
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            66.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            66.69270833333333,
            6.409575271804799,
            0.9954135572139303,
            0.09566530256425074,
            -0.9769097222222217,
            0.21365250906015984
        }
    
        {
            67.39583333333333,
            9.044426422142896,
            0.9911151960784313,
            0.13300627091386613,
            -0.9534722222222217,
            0.3014808807380963
        }
    
        {
            68.109375,
            11.05047678199339,
            0.9870923913043478,
            0.16015183742019407,
            -0.9296875,
            0.3683492260664464
        }
    
        {
            68.83333333333333,
            12.726830800408349,
            0.9833333333333333,
            0.18181186857726214,
            -0.9055555555555554,
            0.4242276933469448
        }
    
        {
            69.56770833333333,
            14.189219754738616,
            0.9798268779342723,
            0.1998481655596988,
            -0.8810763888888886,
            0.4729739918246203
        }
    
        {
            70.3125,
            15.4968494782004,
            0.9765625,
            0.2152340205305611,
            -0.85625,
            0.5165616492733467
        }
    
        {
            71.06770833333333,
            16.684748492208822,
            0.9735302511415524,
            0.22855819852340853,
            -0.8310763888888887,
            0.5561582830736271
        }
    
        {
            71.83333333333333,
            17.775607506417963,
            0.9707207207207207,
            0.24021091224889138,
            -0.8055555555555555,
            0.5925202502139318
        }
    
        {
            72.609375,
            18.785064868383472,
            0.968125,
            0.2504675315784463,
            -0.7796875,
            0.6261688289461157
        }
    
        {
            73.39583333333333,
            19.724392241728427,
            0.9657346491228069,
            0.25953147686484773,
            -0.7534722222222219,
            0.6574797413909471
        }
    
        {
            74.19270833333333,
            20.601990927212146,
            0.9635416666666666,
            0.26755832373002786,
            -0.7269097222222219,
            0.6867330309070712
        }
    
        {
            75.0,
            21.42428528562855,
            0.9615384615384616,
            0.274670324174725,
            -0.7,
            0.714142842854285
        }
    
        {
            75.81770833333333,
            22.196285794735967,
            0.9597178270042194,
            0.28096564297134136,
            -0.6727430555555555,
            0.7398761931578653
        }
    
        {
            76.64583333333333,
            22.92195961602955,
            0.9580729166666666,
            0.2865244952003694,
            -0.6451388888888887,
            0.764065320534318
        }
    
        {
            77.484375,
            23.604483278804793,
            0.9565972222222222,
            0.29141337381240484,
            -0.6171875,
            0.7868161092934931
        }
    
        {
            78.33333333333333,
            24.246420125224457,
            0.9552845528455284,
            0.29568805030761536,
            -0.5888888888888888,
            0.8082140041741482
        }
    
        {
            79.19270833333333,
            24.849848024315914,
            0.9541290160642569,
            0.2993957593291074,
            -0.5602430555555555,
            0.8283282674771969
        }
    
        {
            80.0625,
            25.416453209486175,
            0.953125,
            0.30257682392245444,
            -0.5312499999999999,
            0.8472151069828724
        }
    
        {
            80.94270833333333,
            25.947600422099374,
            0.952267156862745,
            0.30526588731881615,
            -0.5019097222222221,
            0.8649200140699786
        }
    
        {
            81.83333333333333,
            26.44438608770407,
            0.9515503875968991,
            0.30749286148493105,
            -0.47222222222222204,
            0.8814795362568018
        }
    
        {
            82.734375,
            26.907679077902184,
            0.9509698275862069,
            0.3092836675620941,
            -0.44218750000000007,
            0.8969226359300729
        }
    
        {
            83.64583333333333,
            27.338152204789235,
            0.9505208333333333,
            0.3106608205089686,
            -0.4118055555555556,
            0.911271740159641
        }
    
        {
            84.56770833333333,
            27.736306661995656,
            0.9501989700374531,
            0.31164389507860285,
            -0.38107638888888884,
            0.9245435553998548
        }
    
        {
            85.5,
            28.10249099279279,
            0.95,
            0.3122498999199199,
            -0.35,
            0.9367496997597597
        }
    
        {
            86.44270833333333,
            28.436915725835398,
            0.9499198717948717,
            0.3124935794047846,
            -0.3185763888888889,
            0.9478971908611795
        }
    
        {
            87.39583333333333,
            28.73966450695315,
            0.9499547101449275,
            0.3123876576842734,
            -0.2868055555555556,
            0.9579888168984381
        }
    
        {
            88.359375,
            29.01070232878506,
            0.9501008064516129,
            0.3119430357933878,
            -0.2546875,
            0.9670234109595021
        }
    
        {
            89.33333333333333,
            29.24988129130709,
            0.9503546099290779,
            0.31116894990752225,
            -0.22222222222222224,
            0.9749960430435691
        }
    
        {
            90.31770833333333,
            29.45694419682618,
            0.9507127192982455,
            0.3100730968086966,
            -0.1894097222222223,
            0.9818981398942055
        }
    
        {
            91.3125,
            29.631526179898326,
            0.951171875,
            0.30866173104060757,
            -0.15625000000000003,
            0.9877175393299443
        }
    
        {
            92.31770833333333,
            29.773154486577294,
            0.9517289518900344,
            0.30693973697502364,
            -0.12274305555555569,
            0.9924384828859095
        }
    
        {
            93.33333333333333,
            29.88124644135332,
            0.9523809523809523,
            0.30491067797299304,
            -0.08888888888888898,
            0.9960415480451098
        }
    
        {
            94.359375,
            29.95510556832299,
            0.953125,
            0.30257682392245444,
            -0.05468750000000001,
            0.9985035189440997
        }
    
        {
            95.39583333333333,
            29.99391576034864,
            0.9539583333333332,
            0.2999391576034864,
            -0.02013888888888903,
            0.9997971920116204
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            65.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            65.68229166666667,
            6.468118846691807,
            0.9951862373737375,
            0.09800180070745163,
            -0.9779905913978498,
            0.20864899505457454
        }
    
        {
            66.375,
            9.130135541162574,
            0.9906716417910447,
            0.13627067971884438,
            -0.9556451612903226,
            0.294520501327825
        }
    
        {
            67.078125,
            11.159083586225842,
            0.9864430147058824,
            0.16410417038567415,
            -0.9329637096774194,
            0.35997043826534975
        }
    
        {
            67.79166666666667,
            12.856513156978247,
            0.982487922705314,
            0.1863262776373659,
            -0.9099462365591402,
            0.4147262308702663
        }
    
        {
            68.515625,
            14.339077057446026,
            0.9787946428571429,
            0.20484395796351465,
            -0.8865927419354839,
            0.46255087282083956
        }
    
        {
            69.25,
            15.666445033893298,
            0.9753521126760564,
            0.22065415540694786,
            -0.8629032258064516,
            0.5053691946417193
        }
    
        {
            69.99479166666667,
            16.873918914701758,
            0.9721498842592593,
            0.2343599849264133,
            -0.8388776881720433,
            0.5443199649903796
        }
    
        {
            70.75,
            17.984368212422698,
            0.9691780821917808,
            0.24636120838935202,
            -0.8145161290322581,
            0.5801409100781515
        }
    
        {
            71.515625,
            19.013557816972998,
            0.9664273648648649,
            0.25693997049963513,
            -0.7898185483870968,
            0.6133405747410644
        }
    
        {
            72.29166666666667,
            19.97285484239934,
            0.9638888888888889,
            0.2663047312319912,
            -0.7647849462365595,
            0.6442856400773984
        }
    
        {
            73.078125,
            20.870736606176003,
            0.9615542763157895,
            0.2746149553444211,
            -0.7394153225806451,
            0.6732495679411614
        }
    
        {
            73.875,
            21.713690957550263,
            0.9594155844155844,
            0.2819959864616917,
            -0.7137096774193549,
            0.700441643791944
        }
    
        {
            74.68229166666667,
            22.506783675481703,
            0.9574652777777778,
            0.28854850866002185,
            -0.6876680107526885,
            0.7260252798542489
        }
    
        {
            75.5,
            23.25403190846697,
            0.9556962025316456,
            0.294354834284392,
            -0.6612903225806451,
            0.7501300615634506
        }
    
        {
            76.328125,
            23.958658851955278,
            0.9541015625,
            0.29948323564944096,
            -0.6345766129032258,
            0.7728599629662993
        }
    
        {
            77.16666666666667,
            24.62327264105149,
            0.9526748971193416,
            0.30399102025989494,
            -0.6075268817204302,
            0.7942991174532742
        }
    
        {
            78.015625,
            25.249995165531715,
            0.9514100609756098,
            0.3079267703113624,
            -0.5801411290322581,
            0.8145159730816682
        }
    
        {
            78.875,
            25.840556785797013,
            0.9503012048192772,
            0.3113320094674339,
            -0.5524193548387096,
            0.8335663479289359
        }
    
        {
            79.74479166666667,
            26.396367212931587,
            0.949342757936508,
            0.31424246682061413,
            -0.5243615591397851,
            0.8514957165461807
        }
    
        {
            80.625,
            26.918569334197535,
            0.9485294117647058,
            0.3166890509905592,
            -0.49596774193548393,
            0.8683409462644367
        }
    
        {
            81.515625,
            27.408080575979323,
            0.9478561046511628,
            0.3186986113485968,
            -0.46723790322580644,
            0.884131631483204
        }
    
        {
            82.41666666666667,
            27.86562498053031,
            0.9473180076628352,
            0.32029454000609553,
            -0.43817204301075274,
            0.8988911284042039
        }
    
        {
            83.328125,
            28.29175823423449,
            0.9469105113636364,
            0.32149725266175555,
            -0.40877016129032256,
            0.912637362394661
        }
    
        {
            84.25,
            28.686887248357916,
            0.9466292134831461,
            0.32232457582424623,
            -0.3790322580645161,
            0.9253834596244489
        }
    
        {
            85.18229166666667,
            29.051285452023112,
            0.9464699074074074,
            0.32279206057803456,
            -0.3489583333333333,
            0.9371382403878428
        }
    
        {
            86.125,
            29.385104645040826,
            0.9464285714285714,
            0.3229132378575915,
            -0.31854838709677424,
            0.9479066014529299
        }
    
        {
            87.078125,
            29.688384032890287,
            0.9465013586956522,
            0.32269982644445966,
            -0.2878024193548387,
            0.9576898075125899
        }
    
        {
            88.04166666666667,
            29.961056899841747,
            0.9466845878136201,
            0.322161902148836,
            -0.2567204301075268,
            0.9664857064465084
        }
    
        {
            89.015625,
            30.20295525042831,
            0.9469747340425532,
            0.32130803457902457,
            -0.22530241935483872,
            0.9742888790460745
        }
    
        {
            90.0,
            30.4138126514911,
            0.9473684210526315,
            0.32014539633148525,
            -0.1935483870967742,
            0.9810907306932612
        }
    
        {
            90.99479166666667,
            30.593265427867124,
            0.9478624131944445,
            0.3186798482069492,
            -0.16145833333333326,
            0.986879529931198
        }
    
        {
            92.0,
            30.740852297878796,
            0.9484536082474226,
            0.31691600307091544,
            -0.12903225806451613,
            0.9916403967057676
        }
    
        {
            93.015625,
            30.856012475032724,
            0.9491390306122449,
            0.31485727015339515,
            -0.09627016129032256,
            0.9953552411300878
        }
    
        {
            94.04166666666667,
            30.938082205520672,
            0.9499158249158249,
            0.3125058808638452,
            -0.06317204301075256,
            0.9980026517909898
        }
    
        {
            95.078125,
            30.986289653399535,
            0.95078125,
            0.30986289653399535,
            -0.029737903225806453,
            0.9995577307548237
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            64.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            64.671875,
            6.5229275624044,
            0.994951923076923,
            0.10035273172929846,
            -0.97900390625,
            0.2038414863251375
        }
    
        {
            65.35416666666667,
            9.210477691496504,
            0.9902146464646465,
            0.13955269229540157,
            -0.9576822916666671,
            0.2878274278592659
        }
    
        {
            66.046875,
            11.261008069190565,
            0.9857742537313433,
            0.16807474730135172,
            -0.93603515625,
            0.35190650216220515
        }
    
        {
            66.75,
            12.97834735241741,
            0.9816176470588235,
            0.19085804930025604,
            -0.9140625,
            0.40557335476304407
        }
    
        {
            67.46354166666667,
            14.480005034181781,
            0.9777324879227054,
            0.20985514542292436,
            -0.891764322916667,
            0.45250015731818094
        }
    
        {
            68.1875,
            15.826081124207597,
            0.9741071428571428,
            0.22608687320296567,
            -0.869140625,
            0.4945650351314874
        }
    
        {
            68.921875,
            17.05213026235652,
            0.9707306338028169,
            0.24017084876558478,
            -0.84619140625,
            0.5328790706986413
        }
    
        {
            69.66666666666667,
            18.181186857726168,
            0.9675925925925927,
            0.25251648413508565,
            -0.822916666666667,
            0.5681620893039431
        }
    
        {
            70.421875,
            19.229132104293605,
            0.9646832191780822,
            0.2634127685519672,
            -0.79931640625,
            0.6009103782591751
        }
    
        {
            71.1875,
            20.20742051202973,
            0.9619932432432432,
            0.27307325016256395,
            -0.775390625,
            0.6314818910009291
        }
    
        {
            71.96354166666667,
            21.124598713110025,
            0.959513888888889,
            0.28166131617480034,
            -0.751139322916667,
            0.6601437097846886
        }
    
        {
            72.75,
            21.987212192545012,
            0.9572368421052632,
            0.2893054235861186,
            -0.7265625,
            0.6871003810170316
        }
    
        {
            73.546875,
            22.800376701589276,
            0.9551542207792207,
            0.29610878833232823,
            -0.70166015625,
            0.7125117719246649
        }
    
        {
            74.35416666666667,
            23.568154346608363,
            0.9532585470085471,
            0.3021558249565175,
            -0.6764322916666669,
            0.7365048233315118
        }
    
        {
            75.171875,
            24.293810096079515,
            0.9515427215189873,
            0.3075165834946774,
            -0.65087890625,
            0.7591815655024848
        }
    
        {
            76.0,
            24.979991993593593,
            0.95,
            0.3122498999199199,
            -0.625,
            0.7806247497997998
        }
    
        {
            76.83854166666667,
            25.6288609684459,
            0.9486239711934157,
            0.3164056909684679,
            -0.5987955729166669,
            0.8009019052639348
        }
    
        {
            77.6875,
            26.242186337079463,
            0.9474085365853658,
            0.3200266626473105,
            -0.572265625,
            0.8200683230337332
        }
    
        {
            78.546875,
            26.82141733269096,
            0.9463478915662651,
            0.32314960641796336,
            -0.54541015625,
            0.8381692916465925
        }
    
        {
            79.41666666666667,
            27.367737494275165,
            0.945436507936508,
            0.325806398741371,
            -0.5182291666666669,
            0.8552417966960993
        }
    
        {
            80.296875,
            27.882106542267838,
            0.9446691176470589,
            0.32802478285020986,
            -0.49072265625,
            0.8713158294458699
        }
    
        {
            81.1875,
            28.365292943137394,
            0.9440406976744186,
            0.3298289877108999,
            -0.462890625,
            0.8864154044730436
        }
    
        {
            82.08854166666667,
            28.81789942101835,
            0.9435464559386973,
            0.331240223230096,
            -0.4347330729166667,
            0.9005593569068239
        }
    
        {
            83.0,
            29.24038303442689,
            0.9431818181818182,
            0.3322770799366692,
            -0.40625,
            0.9137619698258403
        }
    
        {
            83.921875,
            29.633070993138308,
            0.9429424157303371,
            0.3329558538554866,
            -0.37744140625,
            0.9260334685355721
        }
    
        {
            84.85416666666667,
            29.99617307767034,
            0.9428240740740741,
            0.33329081197411486,
            -0.3483072916666667,
            0.9373804086771985
        }
    
        {
            85.796875,
            30.329791298892495,
            0.9428228021978022,
            0.3332944098779395,
            -0.31884765625000006,
            0.9478059780903906
        }
    
        {
            86.75,
            30.633927270266867,
            0.9429347826086957,
            0.33297747032898767,
            -0.2890625,
            0.9573102271958396
        }
    
        {
            87.71354166666667,
            30.90848764158366,
            0.9431563620071685,
            0.33234932947939416,
            -0.25895182291666663,
            0.9658902387994898
        }
    
        {
            88.6875,
            31.153287848154967,
            0.9434840425531915,
            0.3314179558314358,
            -0.228515625,
            0.9735402452548427
        }
    
        {
            89.671875,
            31.368054354460288,
            0.9439144736842106,
            0.3301900458364241,
            -0.19775390625,
            0.980251698576884
        }
    
        {
            90.66666666666667,
            31.552425509864605,
            0.9444444444444445,
            0.32867109906108966,
            -0.1666666666666666,
            0.9860132971832695
        }
    
        {
            91.671875,
            31.705951081530024,
            0.9450708762886598,
            0.32686547506731983,
            -0.13525390625000003,
            0.9908109712978134
        }
    
        {
            92.6875,
            31.828090482308234,
            0.9457908163265306,
            0.32477643349294116,
            -0.103515625,
            0.9946278275721323
        }
    
        {
            93.71354166666667,
            31.91820966611269,
            0.946601430976431,
            0.32240615824356256,
            -0.07145182291666655,
            0.997444052066022
        }
    
        {
            94.75,
            31.975576617162044,
            0.9475,
            0.31975576617162044,
            -0.0390625,
            0.9992367692863139
        }
    
        {
            95.796875,
            31.99935530966796,
            0.9484839108910891,
            0.31682530009572235,
            -0.00634765625,
            0.9999798534271237
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            63.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            63.661458333333336,
            6.574094832998965,
            0.9947102864583334,
            0.10272023176560882,
            -0.9799558080808082,
            0.1992149949393626
        }
    
        {
            64.33333333333333,
            9.285592184789435,
            0.9897435897435897,
            0.1428552643813759,
            -0.9595959595959596,
            0.28138158135725555
        }
    
        {
            65.015625,
            11.356430154735026,
            0.9850852272727273,
            0.17206712355659132,
            -0.9389204545454546,
            0.34413424711318263
        }
    
        {
            65.70833333333333,
            13.092552484353712,
            0.9807213930348258,
            0.1954112311097569,
            -0.9179292929292925,
            0.39674401467738496
        }
    
        {
            66.41145833333333,
            14.612262043911326,
            0.9766390931372548,
            0.21488620652810772,
            -0.8966224747474744,
            0.4427958195124641
        }
    
        {
            67.125,
            15.976056303105594,
            0.9728260869565217,
            0.23153704787109555,
            -0.875,
            0.48412291827592707
        }
    
        {
            67.84895833333333,
            17.219722793401687,
            0.9692708333333333,
            0.24599603990573837,
            -0.8530618686868686,
            0.5218097816182328
        }
    
        {
            68.58333333333333,
            18.366447367111846,
            0.9659624413145539,
            0.25868235728326544,
            -0.8308080808080806,
            0.5565590111246012
        }
    
        {
            69.328125,
            19.432217680552444,
            0.962890625,
            0.26989191222989506,
            -0.8082386363636364,
            0.588855081228862
        }
    
        {
            70.08333333333333,
            20.428567959817684,
            0.9600456621004566,
            0.27984339670983127,
            -0.7853535353535351,
            0.6190475139338689
        }
    
        {
            70.84895833333333,
            21.364107823206606,
            0.9574183558558558,
            0.28870415977306224,
            -0.7621527777777778,
            0.6473972067638364
        }
    
        {
            71.625,
            22.245434924945837,
            0.955,
            0.2966057989992778,
            -0.7386363636363636,
            0.6741040886347224
        }
    
        {
            72.41145833333333,
            23.077710069240656,
            0.9527823464912281,
            0.3036540798584297,
            -0.7148042929292926,
            0.6993245475527466
        }
    
        {
            73.20833333333333,
            23.865035733381095,
            0.9507575757575757,
            0.3099355290049493,
            -0.6906565656565653,
            0.7231829010115479
        }
    
        {
            74.015625,
            24.61071424927312,
            0.9489182692307693,
            0.31552197755478356,
            -0.6661931818181818,
            0.745779219674943
        }
    
        {
            74.83333333333333,
            25.317429218272196,
            0.9472573839662447,
            0.32047378757306577,
            -0.6414141414141414,
            0.767194824796127
        }
    
        {
            75.66145833333333,
            25.987376221413054,
            0.9457682291666666,
            0.3248422027676632,
            -0.6163194444444443,
            0.7874962491337286
        }
    
        {
            76.5,
            26.622359023948274,
            0.9444444444444444,
            0.3286710990610898,
            -0.5909090909090909,
            0.8067381522408568
        }
    
        {
            77.34895833333333,
            27.223861679568248,
            0.9432799796747967,
            0.33199831316546646,
            -0.5651830808080807,
            0.8249655054414617
        }
    
        {
            78.20833333333333,
            27.793103411138215,
            0.9422690763052208,
            0.3348566676040749,
            -0.5391414141414141,
            0.842215254882976
        }
    
        {
            79.078125,
            28.331080926861492,
            0.94140625,
            0.3372747729388273,
            -0.5127840909090909,
            0.8585176038442877
        }
    
        {
            79.95833333333333,
            28.838601397355536,
            0.9406862745098039,
            0.3392776634983004,
            -0.48611111111111094,
            0.8738970120410763
        }
    
        {
            80.84895833333333,
            29.316308369488333,
            0.9401041666666666,
            0.3408873066219574,
            -0.4591224747474746,
            0.8883729808935853
        }
    
        {
            81.75,
            29.764702249476645,
            0.9396551724137931,
            0.34212301436180054,
            -0.4318181818181818,
            0.901960674226565
        }
    
        {
            82.66145833333333,
            30.184156542905047,
            0.9393347537878788,
            0.34300177889664824,
            -0.4041982323232324,
            0.9146714103910618
        }
    
        {
            83.58333333333333,
            30.574930725823233,
            0.9391385767790261,
            0.3435385474811599,
            -0.37626262626262624,
            0.9265130522976733
        }
    
        {
            84.515625,
            30.937180396076418,
            0.9390625,
            0.34374644884529354,
            -0.34801136363636365,
            0.9374903150326187
        }
    
        {
            85.45833333333333,
            31.270965189595437,
            0.9391025641025641,
            0.34363698010544436,
            -0.3194444444444445,
            0.9476050057453158
        }
    
        {
            86.41145833333333,
            31.576254823943223,
            0.9392549818840579,
            0.3432201611298176,
            -0.2905618686868688,
            0.9568562067861581
        }
    
        {
            87.375,
            31.852933538372884,
            0.9395161290322581,
            0.34250466170293425,
            -0.26136363636363635,
            0.9652404102537238
        }
    
        {
            88.34895833333333,
            32.100803127257294,
            0.9398825354609929,
            0.34149790560912013,
            -0.23184974747474751,
            0.9727516099168872
        }
    
        {
            89.33333333333333,
            32.31958470580271,
            0.9403508771929824,
            0.34020615479792327,
            -0.20202020202020207,
            0.9793813547212938
        }
    
        {
            90.328125,
            32.508919298930486,
            0.94091796875,
            0.3386345760305259,
            -0.171875,
            0.9851187666342571
        }
    
        {
            91.33333333333333,
            32.66836730267099,
            0.9415807560137457,
            0.33678729178011324,
            -0.14141414141414152,
            0.9899505243233631
        }
    
        {
            92.34895833333333,
            32.79740682963008,
            0.9423363095238094,
            0.33466741662887833,
            -0.11063762626262631,
            0.9938608130190923
        }
    
        {
            93.375,
            32.89543091373025,
            0.9431818181818182,
            0.3322770799366692,
            -0.07954545454545454,
            0.9968312398100077
        }
    
        {
            94.41145833333333,
            32.96174351233966,
            0.9441145833333333,
            0.3296174351233966,
            -0.048137626262626375,
            0.9988407124951405
        }
    
        {
            95.45833333333333,
            32.99555420389575,
            0.9451320132013201,
            0.32668865548411635,
            -0.016414141414141555,
            0.9998652789059316
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            62.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            62.651041666666664,
            6.621705073589251,
            0.9944609788359788,
            0.10510642973951191,
            -0.9808517156862744,
            0.1947560315761544
        }
    
        {
            63.3125,
            9.35560493768308,
            0.9892578125,
            0.1461813271512981,
            -0.9613970588235294,
            0.27516485110832584
        }
    
        {
            63.984375,
            11.445512476921905,
            0.984375,
            0.1760848073372601,
            -0.9416360294117647,
            0.3366327199094678
        }
    
        {
            64.66666666666667,
            13.199326582148869,
            0.9797979797979799,
            0.1999897966992253,
            -0.9215686274509804,
            0.38821548771026093
        }
    
        {
            65.359375,
            14.73608155546701,
            0.9755130597014925,
            0.21994151575323895,
            -0.9011948529411765,
            0.4334141633960885
        }
    
        {
            66.0625,
            16.116640274883597,
            0.9715073529411765,
            0.2370094158071117,
            -0.8805147058823529,
            0.4740188316142234
        }
    
        {
            66.77604166666667,
            17.377003750117474,
            0.9677687198067634,
            0.25184063405967355,
            -0.8595281862745099,
            0.5110883455916905
        }
    
        {
            67.5,
            18.540496217739157,
            0.9642857142857143,
            0.26486423168198797,
            -0.8382352941176471,
            0.5453087122864458
        }
    
        {
            68.234375,
            19.62320229624551,
            0.9610475352112676,
            0.27638313093303535,
            -0.8166360294117647,
            0.5771530087131032
        }
    
        {
            68.97916666666667,
            20.63672856758604,
            0.9580439814814815,
            0.28662123010536167,
            -0.7947303921568628,
            0.6069626049290013
        }
    
        {
            69.734375,
            21.58974162326578,
            0.9552654109589042,
            0.29574988525021617,
            -0.7725183823529411,
            0.6349924006842876
        }
    
        {
            70.5,
            22.48888614404902,
            0.9527027027027027,
            0.30390386681147324,
            -0.75,
            0.6614378277661476
        }
    
        {
            71.27604166666667,
            23.33936340887636,
            0.9503472222222222,
            0.31119151211835144,
            -0.7271752450980394,
            0.686451864966952
        }
    
        {
            72.0625,
            24.14531204499126,
            0.9481907894736842,
            0.3177014742762008,
            -0.7040441176470589,
            0.71015623661739
        }
    
        {
            72.859375,
            24.91006773594514,
            0.9462256493506493,
            0.32350737319409273,
            -0.6806066176470589,
            0.73264905105721
        }
    
        {
            73.66666666666667,
            25.636345726764993,
            0.9444444444444445,
            0.32867109906108966,
            -0.6568627450980392,
            0.7540101684342647
        }
    
        {
            74.484375,
            26.326372345224,
            0.9428401898734177,
            0.33324521955979747,
            -0.6328125,
            0.7743050689771765
        }
    
        {
            75.3125,
            26.981981835106183,
            0.94140625,
            0.3372747729388273,
            -0.6084558823529411,
            0.7935877010325347
        }
    
        {
            76.15104166666667,
            27.604688969115315,
            0.940136316872428,
            0.3407986292483372,
            -0.5837928921568627,
            0.8119026167386859
        }
    
        {
            77.0,
            28.19574435974337,
            0.9390243902439024,
            0.34385054097248013,
            -0.5588235294117647,
            0.8292865988159814
        }
    
        {
            77.859375,
            28.756177155689087,
            0.9380647590361446,
            0.3464599657311938,
            -0.5335477941176471,
            0.8457699163437967
        }
    
        {
            78.72916666666667,
            29.286828369972426,
            0.9372519841269842,
            0.3486527186901479,
            -0.5079656862745098,
            0.8613773049991892
        }
    
        {
            79.609375,
            29.788377131179452,
            0.9365808823529411,
            0.35045149566093475,
            -0.4820772058823529,
            0.8761287391523368
        }
    
        {
            80.5,
            30.26136150274802,
            0.936046511627907,
            0.3518762965435816,
            -0.45588235294117646,
            0.8900400441984712
        }
    
        {
            81.40104166666667,
            30.706195068448267,
            0.9356441570881227,
            0.35294477090170423,
            -0.42938112745098034,
            0.9031233843661257
        }
    
        {
            82.3125,
            31.123180167682094,
            0.9353693181818182,
            0.35367250190547833,
            -0.4025735294117647,
            0.9153876519906499
        }
    
        {
            83.234375,
            31.51251843885815,
            0.9352176966292135,
            0.35407324088604664,
            -0.37545955882352944,
            0.926838777613475
        }
    
        {
            84.16666666666667,
            31.87431916484212,
            0.9351851851851852,
            0.3541591018315791,
            -0.34803921568627444,
            0.9374799754365332
        }
    
        {
            85.109375,
            32.20860579269731,
            0.9352678571428571,
            0.3539407229966738,
            -0.3203125,
            0.9473119350793328
        }
    
        {
            86.0625,
            32.51532090799659,
            0.9354619565217391,
            0.35342740117387594,
            -0.2922794117647059,
            0.9563329678822526
        }
    
        {
            87.02604166666667,
            32.794329873189916,
            0.935763888888889,
            0.352627202937526,
            -0.26393995098039214,
            0.9645391139173509
        }
    
        {
            88.0,
            33.04542328371661,
            0.9361702127659575,
            0.3515470562097512,
            -0.23529411764705882,
            0.9719242142269591
        }
    
        {
            88.984375,
            33.26831835033708,
            0.9366776315789473,
            0.3501928247403903,
            -0.20634191176470587,
            0.9784799514805025
        }
    
        {
            89.97916666666667,
            33.46265927824957,
            0.9372829861111112,
            0.3485693674817663,
            -0.1770833333333332,
            0.9841958611249872
        }
    
        {
            90.984375,
            33.628016680431436,
            0.9379832474226805,
            0.3466805843343447,
            -0.14751838235294118,
            0.9890593141303363
        }
    
        {
            92.0,
            33.76388603226827,
            0.9387755102040817,
            0.34452944930885987,
            -0.11764705882352941,
            0.993055471537302
        }
    
        {
            93.02604166666667,
            33.869685145150015,
            0.9396569865319866,
            0.3421180317691921,
            -0.08746936274509795,
            0.9961672101514717
        }
    
        {
            94.0625,
            33.94475060668439,
            0.940625,
            0.3394475060668439,
            -0.05698529411764706,
            0.9983750178436585
        }
    
        {
            95.109375,
            33.988333102836556,
            0.9416769801980198,
            0.3365181495330352,
            -0.02619485294117647,
            0.999656855965781
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            61.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            61.640625,
            6.665834502099118,
            0.9942036290322581,
            0.1075134597112761,
            -0.9816964285714286,
            0.19045241434568908
        }
    
        {
            62.291666666666664,
            9.42062969704728,
            0.9887566137566137,
            0.1495338047150362,
            -0.963095238095238,
            0.2691608484870651
        }
    
        {
            62.953125,
            11.528402002635708,
            0.983642578125,
            0.18013128129118294,
            -0.9441964285714286,
            0.32938291436102024
        }
    
        {
            63.625,
            13.29884863437433,
            0.9788461538461538,
            0.2045976712980666,
            -0.925,
            0.3799671038392666
        }
    
        {
            64.30729166666667,
            14.85167460249058,
            0.9743529040404041,
            0.22502537276500878,
            -0.9055059523809524,
            0.42433356007115947
        }
    
        {
            65.0,
            16.24807680927192,
            0.9701492537313433,
            0.24250860909361077,
            -0.8857142857142857,
            0.46423076597919777
        }
    
        {
            65.703125,
            17.524250775264974,
            0.9662224264705882,
            0.25770957022448493,
            -0.865625,
            0.500692879293285
        }
    
        {
            66.41666666666667,
            18.70364640621953,
            0.96256038647343,
            0.2710673392205729,
            -0.8452380952380952,
            0.5343898973205581
        }
    
        {
            67.140625,
            19.802436077649006,
            0.9591517857142857,
            0.28289194396641437,
            -0.8245535714285714,
            0.5657838879328287
        }
    
        {
            67.875,
            20.832291640623698,
            0.9559859154929577,
            0.29341255831864366,
            -0.8035714285714286,
            0.5952083325892485
        }
    
        {
            68.61979166666667,
            21.801930915019057,
            0.9530526620370371,
            0.30280459604193133,
            -0.7822916666666667,
            0.6229123118576875
        }
    
        {
            69.375,
            22.71804073858483,
            0.9503424657534246,
            0.31120603751486065,
            -0.7607142857142857,
            0.6490868782452809
        }
    
        {
            70.140625,
            23.585858572656942,
            0.9478462837837838,
            0.3187278185494181,
            -0.7388392857142857,
            0.673881673504484
        }
    
        {
            70.91666666666667,
            24.40955527839227,
            0.9455555555555556,
            0.32546073704523026,
            -0.716666666666667,
            0.6974158650969223
        }
    
        {
            71.703125,
            25.192496208878847,
            0.9434621710526315,
            0.33148021327472166,
            -0.6941964285714286,
            0.719785605967967
        }
    
        {
            72.5,
            25.937424698685874,
            0.9415584415584416,
            0.33684967141150485,
            -0.6714285714285714,
            0.7410692771053107
        }
    
        {
            73.30729166666667,
            26.646594313312587,
            0.9398370726495727,
            0.34162300401682805,
            -0.6483630952380955,
            0.7613312660946459
        }
    
        {
            74.125,
            27.321866242992993,
            0.9382911392405063,
            0.3458464081391518,
            -0.625,
            0.7806247497997998
        }
    
        {
            74.953125,
            27.96478236522457,
            0.9369140625,
            0.3495597795653071,
            -0.6013392857142857,
            0.7989937818635591
        }
    
        {
            75.79166666666667,
            28.576620931959184,
            0.9356995884773663,
            0.35279778928344674,
            -0.5773809523809526,
            0.8164748837702629
        }
    
        {
            76.640625,
            29.158439594899022,
            0.934641768292683,
            0.35559072676706127,
            -0.553125,
            0.8330982741399721
        }
    
        {
            77.5,
            29.71110903349116,
            0.9337349397590361,
            0.35796516907820675,
            -0.5285714285714286,
            0.8488888295283188
        }
    
        {
            78.36979166666667,
            30.235339490788967,
            0.9329737103174603,
            0.3599445177474877,
            -0.5037202380952382,
            0.863866842593971
        }
    
        {
            79.25,
            30.731701872821816,
            0.9323529411764706,
            0.3615494337979037,
            -0.4785714285714286,
            0.8780486249377661
        }
    
        {
            80.140625,
            31.200644618491058,
            0.9318677325581395,
            0.3627981932382681,
            -0.453125,
            0.8914469890997445
        }
    
        {
            81.04166666666667,
            31.642507231395047,
            0.9315134099616859,
            0.36370697967120746,
            -0.4273809523809524,
            0.904071635182716
        }
    
        {
            81.953125,
            32.057531139100135,
            0.9312855113636364,
            0.3642901265806833,
            -0.40133928571428573,
            0.9159294611171467
        }
    
        {
            82.875,
            32.445868381043525,
            0.9311797752808989,
            0.3645603188881295,
            -0.375,
            0.9270248108869579
        }
    
        {
            83.80729166666667,
            32.80758850476918,
            0.9311921296296297,
            0.364528761164102,
            -0.3483630952380952,
            0.937359671564834
        }
    
        {
            84.75,
            33.14268395890713,
            0.9313186813186813,
            0.36420531822974866,
            -0.32142857142857145,
            0.9469338273973466
        }
    
        {
            85.703125,
            33.45107420150173,
            0.9315557065217391,
            0.36359863262501885,
            -0.2941964285714286,
            0.9557449771857638
        }
    
        {
            86.66666666666667,
            33.73260868786889,
            0.931899641577061,
            0.36271622245020313,
            -0.26666666666666666,
            0.9637888196533972
        }
    
        {
            87.640625,
            33.987068858749424,
            0.9323470744680851,
            0.36156456232712153,
            -0.23883928571428573,
            0.9710591102499836
        }
    
        {
            88.625,
            34.21416921393825,
            0.9328947368421052,
            0.3601491496204026,
            -0.21071428571428572,
            0.9775476918268071
        }
    
        {
            89.61979166666667,
            34.41355752640611,
            0.9335394965277778,
            0.3584745575667303,
            -0.18229166666666663,
            0.9832445007544609
        }
    
        {
            90.625,
            34.584814225321495,
            0.9342783505154639,
            0.3565444765497061,
            -0.15357142857142858,
            0.9881375492948998
        }
    
        {
            91.640625,
            34.72745095179568,
            0.9351084183673469,
            0.35436174440607837,
            -0.12455357142857143,
            0.9922128843370195
        }
    
        {
            92.66666666666667,
            34.84090826727812,
            0.9360269360269361,
            0.3519283663361426,
            -0.09523809523809511,
            0.9954545219222319
        }
    
        {
            93.703125,
            34.92455247006574,
            0.93703125,
            0.3492455247006574,
            -0.065625,
            0.9978443562875926
        }
    
        {
            94.75,
            34.977671449083054,
            0.9381188118811881,
            0.3463135787037926,
            -0.03571428571428571,
            0.999362041402373
        }
    
        {
            95.80729166666667,
            34.9994694745258,
            0.9392871732026145,
            0.3431320536718216,
            -0.005505952380952247,
            0.9999848421293088
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            60.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            60.630208333333336,
            6.706551830605406,
            0.9939378415300547,
            0.1099434726328755,
            -0.9824942129629631,
            0.18629310640570576
        }
    
        {
            61.270833333333336,
            9.480769095326005,
            0.988239247311828,
            0.15291563056977428,
            -0.9646990740740742,
            0.26335469709238907
        }
    
        {
            61.921875,
            11.605231427437154,
            0.9828869047619048,
            0.1842100226577326,
            -0.9466145833333334,
            0.32236753965103204
        }
    
        {
            62.583333333333336,
            13.391280330457155,
            0.9778645833333334,
            0.20923875516339305,
            -0.9282407407407408,
            0.37198000917936547
        }
    
        {
            63.255208333333336,
            14.959231888923867,
            0.9731570512820513,
            0.23014202906036718,
            -0.9095775462962964,
            0.4155342191367742
        }
    
        {
            63.9375,
            16.370586237212155,
            0.96875,
            0.24803918541230538,
            -0.890625,
            0.45473850658922654
        }
    
        {
            64.63020833333333,
            17.661714831519944,
            0.9646299751243781,
            0.2636076840525365,
            -0.8713831018518514,
            0.4906031897644426
        }
    
        {
            65.33333333333333,
            18.856180831641293,
            0.9607843137254901,
            0.2772967769359014,
            -0.8518518518518516,
            0.5237828008789246
        }
    
        {
            66.046875,
            19.970235420103965,
            0.9572010869565217,
            0.2894237017406372,
            -0.83203125,
            0.5547287616695545
        }
    
        {
            66.77083333333333,
            21.015608865132187,
            0.9538690476190476,
            0.30022298378760265,
            -0.8119212962962963,
            0.5837669129203384
        }
    
        {
            67.50520833333333,
            22.001064698629122,
            0.9507775821596244,
            0.3098741506849172,
            -0.7915219907407406,
            0.611140686073031
        }
    
        {
            68.25,
            22.93332727713098,
            0.9479166666666666,
            0.318518434404597,
            -0.7708333333333334,
            0.637036868809194
        }
    
        {
            69.00520833333333,
            23.817666192833936,
            0.9452768264840182,
            0.32626939990183473,
            -0.749855324074074,
            0.6616018386898314
        }
    
        {
            69.77083333333333,
            24.658280880309206,
            0.9428490990990991,
            0.33322001189607037,
            -0.7285879629629629,
            0.6849522466752556
        }
    
        {
            70.546875,
            25.45856295501329,
            0.940625,
            0.3394475060668439,
            -0.70703125,
            0.7071823043059247
        }
    
        {
            71.33333333333333,
            26.221280585729534,
            0.9385964912280701,
            0.34501684981223074,
            -0.6851851851851849,
            0.7283689051591533
        }
    
        {
            72.13020833333333,
            26.948711393866898,
            0.9367559523809523,
            0.34998326485541426,
            -0.6630497685185183,
            0.7485753164963023
        }
    
        {
            72.9375,
            27.642740344437634,
            0.9350961538461539,
            0.35439410697996965,
            -0.640625,
            0.7678538984566009
        }
    
        {
            73.75520833333333,
            28.30493320441858,
            0.9336102320675105,
            0.3582902937268175,
            -0.6179108796296297,
            0.7862481445671826
        }
    
        {
            74.58333333333333,
            28.936592558366122,
            0.9322916666666666,
            0.36170740697957654,
            -0.5949074074074073,
            0.803794237732392
        }
    
        {
            75.421875,
            29.538801117925807,
            0.9311342592592593,
            0.3646765570114297,
            -0.5716145833333334,
            0.8205222532757168
        }
    
        {
            76.27083333333333,
            30.11245560625851,
            0.9301321138211381,
            0.3672250683690062,
            -0.5480324074074073,
            0.8364571001738472
        }
    
        {
            77.13020833333333,
            30.65829353464732,
            0.9292796184738955,
            0.36937703053791954,
            -0.5241608796296297,
            0.8516192648513143
        }
    
        {
            78.0,
            31.176914536239792,
            0.9285714285714286,
            0.37115374447904514,
            -0.5,
            0.8660254037844387
        }
    
        {
            78.88020833333333,
            31.66879747148495,
            0.9280024509803921,
            0.37257408789982294,
            -0.4755497685185185,
            0.8796888186523594
        }
    
        {
            79.77083333333333,
            32.134314203131154,
            0.9275678294573643,
            0.37365481631547853,
            -0.4508101851851851,
            0.892619838975865
        }
    
        {
            80.671875,
            32.573740712180644,
            0.9272629310344828,
            0.37441081278368554,
            -0.42578125,
            0.9048261308939067
        }
    
        {
            81.58333333333333,
            32.98726606165207,
            0.9270833333333333,
            0.3748552961551372,
            -0.400462962962963,
            0.9163129461570018
        }
    
        {
            82.50520833333333,
            33.37499959360696,
            0.9270248127340823,
            0.37499999543378604,
            -0.37485532407407407,
            0.9270833220446374
        }
    
        {
            83.4375,
            33.73697665396234,
            0.9270833333333334,
            0.3748552961551371,
            -0.3489583333333333,
            0.9371382403878427
        }
    
        {
            84.38020833333333,
            34.07316307041752,
            0.9272550366300366,
            0.3744303634111816,
            -0.3227719907407408,
            0.9464767519560421
        }
    
        {
            85.33333333333333,
            34.38345855527368,
            0.9275362318840579,
            0.37373324516601825,
            -0.2962962962962964,
            0.9550960709798242
        }
    
        {
            86.296875,
            34.6676991626842,
            0.9279233870967742,
            0.37277095873853977,
            -0.26953125,
            0.9629916434078944
        }
    
        {
            87.27083333333333,
            34.92565889579689,
            0.9284131205673758,
            0.37154956272124356,
            -0.2424768518518519,
            0.9701571915499133
        }
    
        {
            88.25520833333333,
            35.15705053100916,
            0.9290021929824561,
            0.3700742161158859,
            -0.2151331018518519,
            0.9765847369724764
        }
    
        {
            89.25,
            35.36152570237885,
            0.9296875,
            0.3683492260664463,
            -0.1875,
            0.9822646028438569
        }
    
        {
            90.25520833333333,
            35.53867426771288,
            0.9304660652920962,
            0.3663780852341534,
            -0.15957754629629642,
            0.9871853963253577
        }
    
        {
            91.27083333333333,
            35.68802295783406,
            0.9313350340136054,
            0.36416349956973526,
            -0.13136574074074076,
            0.9913339710509452
        }
    
        {
            92.296875,
            35.80903329097806,
            0.9322916666666666,
            0.3617074069795763,
            -0.10286458333333333,
            0.9946953691938349
        }
    
        {
            93.33333333333333,
            35.90109871423005,
            0.9333333333333332,
            0.3590109871423005,
            -0.07407407407407415,
            0.9972527420619451
        }
    
        {
            94.38020833333333,
            35.96354091238233,
            0.9344575082508251,
            0.3560746624988349,
            -0.04499421296296308,
            0.9989872475661756
        }
    
        {
            95.4375,
            35.99560520049635,
            0.9356617647058824,
            0.3528980902009446,
            -0.015625,
            0.9998779222360097
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            59.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            59.619791666666664,
            6.743918862446681,
            0.9936631944444444,
            0.11239864770744469,
            -0.9832488738738737,
            0.18226807736342376
        }
    
        {
            60.25,
            9.536115561380326,
            0.9877049180327869,
            0.15632976330131682,
            -0.9662162162162162,
            0.2577328530102791
        }
    
        {
            60.890625,
            11.67612037919167,
            0.9821068548387096,
            0.1883245222450269,
            -0.948902027027027,
            0.3155708210592343
        }
    
        {
            61.541666666666664,
            13.476767560839251,
            0.9768518518518519,
            0.21391694541014686,
            -0.9313063063063062,
            0.36423696110376347
        }
    
        {
            62.203125,
            15.058925600266939,
            0.971923828125,
            0.23529571250417092,
            -0.9134290540540541,
            0.40699798919640373
        }
    
        {
            62.875,
            16.484367594785066,
            0.9673076923076923,
            0.2536056553043856,
            -0.8952702702702703,
            0.4455234485077045
        }
    
        {
            63.557291666666664,
            17.78962270533763,
            0.9629892676767676,
            0.2695397379596611,
            -0.8768299549549549,
            0.4808006136577737
        }
    
        {
            64.25,
            18.99835519196333,
            0.9589552238805971,
            0.28355754017855717,
            -0.8581081081081081,
            0.5134690592422522
        }
    
        {
            64.953125,
            20.12688631493642,
            0.9551930147058824,
            0.2959836222784768,
            -0.8391047297297297,
            0.5439699004036871
        }
    
        {
            65.66666666666667,
            21.1869981094276,
            0.9516908212560388,
            0.30705794361489275,
            -0.8198198198198199,
            0.5726215705250703
        }
    
        {
            66.390625,
            22.187494498238756,
            0.9484375,
            0.3169642071176965,
            -0.8002533783783784,
            0.5996620134659123
        }
    
        {
            67.125,
            23.13513291511419,
            0.9454225352112676,
            0.32584694246639706,
            -0.7804054054054054,
            0.6252738625706538
        }
    
        {
            67.86979166666667,
            24.03521123525366,
            0.9426359953703705,
            0.3338223782674119,
            -0.7602759009009009,
            0.6496003036555044
        }
    
        {
            68.625,
            24.891954021329866,
            0.940068493150685,
            0.34098567152506665,
            -0.7398648648648649,
            0.6727555140899963
        }
    
        {
            69.390625,
            25.708775974545638,
            0.9377111486486487,
            0.347415891547914,
            -0.7191722972972973,
            0.694831783095828
        }
    
        {
            70.16666666666667,
            26.488467092092886,
            0.9355555555555556,
            0.35317956122790517,
            -0.6981981981981985,
            0.7159045160025108
        }
    
        {
            70.953125,
            27.233326141593043,
            0.93359375,
            0.35833323870517164,
            -0.6769425675675675,
            0.7360358416646768
        }
    
        {
            71.75,
            27.945258989674794,
            0.9318181818181818,
            0.36292544142434796,
            -0.6554054054054054,
            0.7552772699912107
        }
    
        {
            72.55729166666667,
            28.625852406491983,
            0.9302216880341881,
            0.36699810777553826,
            -0.633586711711712,
            0.773671686661946
        }
    
        {
            73.375,
            29.276430366422748,
            0.9287974683544303,
            0.37058772615725,
            -0.6114864864864865,
            0.7912548747681823
        }
    
        {
            74.203125,
            29.89809760226184,
            0.9275390625,
            0.373726220028273,
            -0.5891047297297297,
            0.8080566919530227
        }
    
        {
            75.04166666666667,
            30.491773708475666,
            0.926440329218107,
            0.3764416507219218,
            -0.5664414414414415,
            0.8241019921209642
        }
    
        {
            75.890625,
            31.05822012140063,
            0.9254954268292683,
            0.3787587819683004,
            -0.5434966216216216,
            0.8394113546324494
        }
    
        {
            76.75,
            31.598061649411346,
            0.9246987951807228,
            0.380699537944715,
            -0.5202702702702703,
            0.8540016662003066
        }
    
        {
            77.61979166666667,
            32.11180377405266,
            0.924045138888889,
            0.38228337826253167,
            -0.49676238738738754,
            0.8678865884879102
        }
    
        {
            78.5,
            32.59984662540608,
            0.9235294117647059,
            0.38352760735771857,
            -0.47297297297297297,
            0.8810769358217859
        }
    
        {
            79.390625,
            33.06249630789204,
            0.9231468023255814,
            0.38444763148711675,
            -0.44890202702702703,
            0.8935809812943795
        }
    
        {
            80.29166666666667,
            33.49997408788383,
            0.9228927203065135,
            0.38505717342395207,
            -0.4245495495495496,
            0.9054047050779417
        }
    
        {
            81.203125,
            33.91242383307886,
            0.9227627840909091,
            0.3853684526486234,
            -0.3999155405405405,
            0.9165519954886179
        }
    
        {
            82.125,
            34.29991800281744,
            0.922752808988764,
            0.38539233711030835,
            -0.375,
            0.9270248108869579
        }
    
        {
            83.05729166666667,
            34.66246241971656,
            0.9228587962962963,
            0.38513847133018403,
            -0.34980292792792794,
            0.9368233086409885
        }
    
        {
            84.0,
            35.0,
            0.9230769230769231,
            0.38461538461538464,
            -0.32432432432432434,
            0.9459459459459459
        }
    
        {
            84.953125,
            35.312413578434075,
            0.9234035326086957,
            0.3838305823742834,
            -0.2985641891891892,
            0.9543895561738939
        }
    
        {
            85.91666666666667,
            35.599527930702784,
            0.9238351254480287,
            0.38279062291078264,
            -0.2725225225225225,
            0.9621494035325081
        }
    
        {
            86.890625,
            35.86111106908673,
            0.9243683510638298,
            0.3815011815860291,
            -0.24619932432432431,
            0.9692192180834251
        }
    
        {
            87.875,
            36.096874864730324,
            0.925,
            0.3799671038392666,
            -0.2195945945945946,
            0.975591212560279
        }
    
        {
            88.86979166666667,
            36.3064750302651,
            0.9257269965277778,
            0.3781924482319281,
            -0.1927083333333333,
            0.9812560818990571
        }
    
        {
            89.875,
            36.48951047904041,
            0.9265463917525774,
            0.37618052040247846,
            -0.16554054054054054,
            0.9862029859200111
        }
    
        {
            90.890625,
            36.645522060810855,
            0.9274553571428571,
            0.3739338985797026,
            -0.13809121621621623,
            0.9904195151570502
        }
    
        {
            91.91666666666667,
            36.77399065764944,
            0.9284511784511785,
            0.3714544510873681,
            -0.11036036036036026,
            0.9938916393959311
        }
    
        {
            92.953125,
            36.8743346073441,
            0.92953125,
            0.36874334607344106,
            -0.08234797297297297,
            0.9966036380363271
        }
    
        {
            94.0,
            36.945906403822335,
            0.9306930693069307,
            0.3658010535031914,
            -0.05405405405405406,
            0.9985380109141172
        }
    
        {
            95.05729166666667,
            36.98798860438701,
            0.9319342320261438,
            0.3626273392586962,
            -0.025478603603603482,
            0.9996753676861356
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            58.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            58.609375,
            6.777991008357491,
            0.9933792372881356,
            0.1148812035314829,
            -0.9839638157894737,
            0.1783681844304603
        }
    
        {
            59.229166666666664,
            9.586752107581724,
            0.9871527777777778,
            0.15977920179302874,
            -0.9676535087719297,
            0.252282950199519
        }
    
        {
            59.859375,
            11.741176457637241,
            0.9813012295081968,
            0.19247830258421708,
            -0.9510690789473685,
            0.30897832783255896
        }
    
        {
            60.5,
            13.555441711725958,
            0.9758064516129032,
            0.21863615664074126,
            -0.9342105263157895,
            0.35672215030857785
        }
    
        {
            61.151041666666664,
            15.150910965403948,
            0.970651455026455,
            0.2404906502445071,
            -0.9170778508771928,
            0.3987081833001038
        }
    
        {
            61.8125,
            16.589600469872686,
            0.9658203125,
            0.2592125073417607,
            -0.899671052631579,
            0.43656843341770224
        }
    
        {
            62.484375,
            17.908179160913456,
            0.9612980769230769,
            0.2755104486294378,
            -0.8819901315789473,
            0.47126787265561726
        }
    
        {
            63.166666666666664,
            19.13040047208167,
            0.9570707070707071,
            0.28985455260729803,
            -0.8640350877192982,
            0.5034315913705703
        }
    
        {
            63.859375,
            20.272647202804446,
            0.953125,
            0.30257682392245444,
            -0.8458059210526315,
            0.5334907158632749
        }
    
        {
            64.5625,
            21.346746678358272,
            0.9494485294117647,
            0.3139227452699746,
            -0.8273026315789473,
            0.561756491535744
        }
    
        {
            65.27604166666667,
            22.36153805827311,
            0.9460295893719808,
            0.32408026171410304,
            -0.8085252192982458,
            0.5884615278492925
        }
    
        {
            66.0,
            23.323807579381203,
            0.9428571428571428,
            0.33319725113401716,
            -0.7894736842105263,
            0.6137844099837159
        }
    
        {
            66.734375,
            24.238877724832374,
            0.9399207746478874,
            0.3413926440117236,
            -0.7701480263157895,
            0.6378652032850625
        }
    
        {
            67.47916666666667,
            25.110994921990283,
            0.9372106481481483,
            0.34876381836097614,
            -0.7505482456140351,
            0.6608156558418496
        }
    
        {
            68.234375,
            25.94359397538003,
            0.9347174657534246,
            0.3553916982928771,
            -0.7306743421052632,
            0.6827261572468428
        }
    
        {
            69.0,
            26.739483914241877,
            0.9324324324324325,
            0.3613443772194848,
            -0.7105263157894737,
            0.7036706293221546
        }
    
        {
            69.77604166666667,
            27.50098197031511,
            0.9303472222222223,
            0.36667975960420146,
            -0.6901041666666669,
            0.7237100518503979
        }
    
        {
            70.5625,
            28.230012287457473,
            0.928453947368421,
            0.37144753009812465,
            -0.6694078947368421,
            0.7428950601962493
        }
    
        {
            71.359375,
            28.928180025873992,
            0.9267451298701299,
            0.3756906496866752,
            -0.6484375,
            0.7612678954177367
        }
    
        {
            72.16666666666667,
            29.596827908109034,
            0.9252136752136753,
            0.37944651164242355,
            -0.6271929824561403,
            0.7788638923186589
        }
    
        {
            72.984375,
            30.237079982355688,
            0.9238528481012658,
            0.3827478478779201,
            -0.6056743421052632,
            0.7957126311146233
        }
    
        {
            73.8125,
            30.849875911419804,
            0.92265625,
            0.3856234488927476,
            -0.5838815789473685,
            0.8118388397742053
        }
    
        {
            74.65104166666667,
            31.435998124468654,
            0.9216177983539096,
            0.3880987422773908,
            -0.5618146929824561,
            0.8272631085386489
        }
    
        {
            75.5,
            31.996093511552314,
            0.9207317073170732,
            0.3901962623360038,
            -0.5394736842105263,
            0.842002460830324
        }
    
        {
            76.359375,
            32.53069088736627,
            0.9199924698795181,
            0.3919360347875454,
            -0.516858552631579,
            0.8560708128254282
        }
    
        {
            77.22916666666667,
            33.04021513205115,
            0.9193948412698413,
            0.3933358944291804,
            -0.49396929824561403,
            0.8694793455802936
        }
    
        {
            78.109375,
            33.52499868917783,
            0.9189338235294118,
            0.39441174928444506,
            -0.4708059210526316,
            0.8822368076099428
        }
    
        {
            79.0,
            33.98529093593286,
            0.9186046511627907,
            0.39517780158061466,
            -0.4473684210526316,
            0.8943497614719174
        }
    
        {
            79.90104166666667,
            34.4212658189904,
            0.9184027777777778,
            0.3956467335516138,
            -0.423656798245614,
            0.9058227847102738
        }
    
        {
            80.8125,
            34.833028058869644,
            0.9183238636363636,
            0.39582986430533684,
            -0.3996710526315789,
            0.9166586331281485
        }
    
        {
            81.734375,
            35.22061815697412,
            0.9183637640449438,
            0.39573728266263053,
            -0.3754111842105263,
            0.9268583725519505
        }
    
        {
            82.66666666666667,
            35.58401638688671,
            0.9185185185185186,
            0.39537795985429675,
            -0.35087719298245607,
            0.9364214838654399
        }
    
        {
            83.609375,
            35.92314591053204,
            0.9187843406593407,
            0.3947598451706818,
            -0.3260690789473684,
            0.9453459450140012
        }
    
        {
            84.5625,
            36.237875127413304,
            0.9191576086956522,
            0.3938899470371011,
            -0.30098684210526316,
            0.9536282928266658
        }
    
        {
            85.52604166666667,
            36.52801933901696,
            0.9196348566308244,
            0.39277440149480597,
            -0.2756304824561403,
            0.9612636668162359
        }
    
        {
            86.5,
            36.79334178897046,
            0.9202127659574468,
            0.3914185296698985,
            -0.25,
            0.9682458365518541
        }
    
        {
            87.484375,
            37.03355412135561,
            0.9208881578947369,
            0.38982688548795374,
            -0.22409539473684212,
            0.9745672137198844
        }
    
        {
            88.47916666666667,
            37.24831628372243,
            0.9216579861111112,
            0.38800329462210864,
            -0.19791666666666657,
            0.9802188495716431
        }
    
        {
            89.484375,
            37.4372358870066,
            0.9225193298969072,
            0.3859508854330577,
            -0.17146381578947367,
            0.9851904180791211
        }
    
        {
            90.5,
            37.59986702104145,
            0.923469387755102,
            0.3836721124596066,
            -0.14473684210526316,
            0.9894701847642486
        }
    
        {
            91.52604166666667,
            37.7357085110588,
            0.9245054713804715,
            0.3811687728389778,
            -0.11773574561403503,
            0.9930449608173375
        }
    
        {
            92.5625,
            37.844201586901,
            0.925625,
            0.37844201586901,
            -0.09046052631578948,
            0.9959000417605527
        }
    
        {
            93.609375,
            37.92472692201455,
            0.926825495049505,
            0.3754923457625203,
            -0.06291118421052631,
            0.9980191295266987
        }
    
        {
            94.66666666666667,
            37.97660098300295,
            0.9281045751633987,
            0.3723196174804211,
            -0.03508771929824551,
            0.9993842363948151
        }
    
        {
            95.734375,
            37.99907161180882,
            0.9294599514563107,
            0.3689230253573672,
            -0.0069901315789473685,
            0.9999755687318111
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            57.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            57.598958333333336,
            6.808817732538462,
            0.9930854885057472,
            0.11739340918169762,
            -0.9846420940170941,
            0.1745850700650888
        }
    
        {
            58.208333333333336,
            9.632753010201975,
            0.9865819209039548,
            0.16326700017291484,
            -0.9690170940170941,
            0.24699366692825583
        }
    
        {
            58.828125,
            11.800496132975724,
            0.98046875,
            0.1966749355495954,
            -0.953125,
            0.30257682392245444
        }
    
        {
            59.458333333333336,
            13.627420783927592,
            0.9747267759562842,
            0.22340034072012446,
            -0.9369658119658121,
            0.3494210457417332
        }
    
        {
            60.098958333333336,
            15.235327605544414,
            0.9693380376344086,
            0.2457310904120067,
            -0.92053952991453,
            0.3906494257831902
        }
    
        {
            60.75,
            16.68644659596524,
            0.9642857142857143,
            0.2648642316819879,
            -0.9038461538461539,
            0.42785760502474973
        }
    
        {
            61.411458333333336,
            18.017568797517153,
            0.9595540364583334,
            0.2815245124612055,
            -0.8868856837606839,
            0.46198894352608094
        }
    
        {
            62.083333333333336,
            19.252525086913188,
            0.9551282051282052,
            0.29619269364481826,
            -0.8696581196581198,
            0.49365448940803053
        }
    
        {
            62.765625,
            20.407751428302312,
            0.9509943181818182,
            0.30920835497427746,
            -0.8521634615384616,
            0.5232756776487772
        }
    
        {
            63.458333333333336,
            21.495114108921477,
            0.9471393034825871,
            0.32082259864061907,
            -0.8344017094017095,
            0.5511567720236277
        }
    
        {
            64.16145833333333,
            22.523482513588604,
            0.9435508578431372,
            0.33122768402336183,
            -0.8163728632478631,
            0.5775251926561178
        }
    
        {
            64.875,
            23.49966755083995,
            0.9402173913043478,
            0.34057489204115865,
            -0.7980769230769231,
            0.6025555782266654
        }
    
        {
            65.59895833333333,
            24.42901278360625,
            0.9371279761904762,
            0.3489858969086607,
            -0.7795138888888888,
            0.626384943169391
        }
    
        {
            66.33333333333333,
            25.315783394730047,
            0.9342723004694835,
            0.3565603295032401,
            -0.7606837606837605,
            0.649122651146924
        }
    
        {
            67.078125,
            26.163431473802802,
            0.931640625,
            0.3633809926917056,
            -0.7415865384615384,
            0.670857217276995
        }
    
        {
            67.83333333333333,
            26.974782462308934,
            0.9292237442922374,
            0.3695175679768347,
            -0.7222222222222221,
            0.6916610887771519
        }
    
        {
            68.59895833333333,
            27.75216956530782,
            0.9270129504504504,
            0.3750293184501057,
            -0.702590811965812,
            0.7115940914181491
        }
    
        {
            69.375,
            28.497532787944994,
            0.925,
            0.3799671038392666,
            -0.6826923076923077,
            0.7307059689216665
        }
    
        {
            70.16145833333333,
            29.21249329550512,
            0.9231770833333333,
            0.38437491178296207,
            -0.6625267094017093,
            0.7490382896283361
        }
    
        {
            70.95833333333333,
            29.898410167692138,
            0.9215367965367964,
            0.38829104113885893,
            -0.642094017094017,
            0.7666259017356956
        }
    
        {
            71.765625,
            30.556424338580175,
            0.9200721153846154,
            0.3917490299817971,
            -0.6213942307692307,
            0.7834980599635942
        }
    
        {
            72.58333333333333,
            31.187493041638064,
            0.9187763713080168,
            0.3947783929321274,
            -0.6004273504273504,
            0.7996793087599502
        }
    
        {
            73.41145833333333,
            31.79241710492086,
            0.9176432291666666,
            0.3974052138115108,
            -0.579193376068376,
            0.8151901821774576
        }
    
        {
            74.25,
            32.37186278236086,
            0.9166666666666666,
            0.39965262694272663,
            -0.5576923076923077,
            0.8300477636502784
        }
    
        {
            75.09895833333333,
            32.92637935224984,
            0.9158409552845528,
            0.40154121161280293,
            -0.5359241452991452,
            0.844266137237175
        }
    
        {
            75.95833333333333,
            33.45641339447823,
            0.9151606425702811,
            0.40308931800576187,
            -0.513888888888889,
            0.8578567537045699
        }
    
        {
            76.828125,
            33.962320429917256,
            0.9146205357142857,
            0.4043133384513959,
            -0.49158653846153844,
            0.8708287289722373
        }
    
        {
            77.70833333333333,
            34.44437443989303,
            0.9142156862745098,
            0.40522793458697687,
            -0.46901709401709396,
            0.8831890882023851
        }
    
        {
            78.59895833333333,
            34.90277566204344,
            0.9139413759689922,
            0.4058462286284121,
            -0.4461805555555555,
            0.8949429656934211
        }
    
        {
            79.5,
            35.33765696816924,
            0.9137931034482759,
            0.4061799651513706,
            -0.4230769230769231,
            0.906093768414596
        }
    
        {
            80.41145833333333,
            35.74908906121382,
            0.9137665719696969,
            0.40623964842288435,
            -0.3997061965811966,
            0.9166433092618927
        }
    
        {
            81.33333333333333,
            36.137084676117546,
            0.9138576779026216,
            0.4060346592822196,
            -0.37606837606837606,
            0.9265919147722445
        }
    
        {
            82.265625,
            36.50160192867396,
            0.9140625,
            0.405573354763044,
            -0.35216346153846156,
            0.93593851099164
        }
    
        {
            83.20833333333333,
            36.84254692456657,
            0.9143772893772893,
            0.40486315301721504,
            -0.327991452991453,
            0.9446806903735014
        }
    
        {
            84.16145833333333,
            37.159775715235384,
            0.9147984601449275,
            0.4039106056003846,
            -0.30355235042735057,
            0.9528147619291124
        }
    
        {
            85.125,
            37.453095666446586,
            0.9153225806451613,
            0.40272145877899557,
            -0.27884615384615385,
            0.9603357863191432
        }
    
        {
            86.09895833333333,
            37.72226628816105,
            0.9159463652482269,
            0.40130070519320266,
            -0.2538728632478633,
            0.9672375971323343
        }
    
        {
            87.08333333333333,
            37.96699955955904,
            0.9166666666666666,
            0.39965262694272674,
            -0.22863247863247868,
            0.9735128092194623
        }
    
        {
            88.078125,
            38.18695977011492,
            0.91748046875,
            0.39778083093869704,
            -0.203125,
            0.9791528146183313
        }
    
        {
            89.08333333333333,
            38.38176288580584,
            0.9183848797250859,
            0.3956882771732561,
            -0.17735042735042744,
            0.9841477663027137
        }
    
        {
            90.09895833333333,
            38.550975438349994,
            0.91937712585034,
            0.39337730039132646,
            -0.15130876068376078,
            0.9884865497012817
        }
    
        {
            91.125,
            38.69411292431964,
            0.9204545454545454,
            0.3908496254981782,
            -0.125,
            0.9921567416492215
        }
    
        {
            92.16145833333333,
            38.810637689598266,
            0.9216145833333332,
            0.38810637689598265,
            -0.09842414529914537,
            0.9951445561435448
        }
    
        {
            93.20833333333333,
            38.89995626247185,
            0.9228547854785478,
            0.38514808180665194,
            -0.07158119658119669,
            0.9974347759608164
        }
    
        {
            94.265625,
            38.961416085139604,
            0.9241727941176471,
            0.38197466750136866,
            -0.04447115384615385,
            0.9990106688497334
        }
    
        {
            95.33333333333333,
            38.99430157799414,
            0.9255663430420712,
            0.37858545221353535,
            -0.01709401709401721,
            0.9998538866152341
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            56.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            56.588541666666664,
            6.836442937663611,
            0.9927814327485379,
            0.1199375953976072,
            -0.9852864583333334,
            0.17091107344159026
        }
    
        {
            57.1875,
            9.674184397146872,
            0.9859913793103449,
            0.16679628270942884,
            -0.9703125,
            0.2418546099286718
        }
    
        {
            57.796875,
            11.854165522480905,
            0.9796080508474576,
            0.20091805970306617,
            -0.955078125,
            0.2963541380620226
        }
    
        {
            58.416666666666664,
            13.69281036002309,
            0.9736111111111111,
            0.22821350600038484,
            -0.9395833333333334,
            0.3423202590005773
        }
    
        {
            59.046875,
            15.312300700233619,
            0.9679815573770492,
            0.2510213229546495,
            -0.923828125,
            0.38280751750584047
        }
    
        {
            59.6875,
            16.775051229429973,
            0.9627016129032258,
            0.27056534241016084,
            -0.9078125,
            0.41937628073574934
        }
    
        {
            60.338541666666664,
            18.117957653663137,
            0.9577546296296295,
            0.2875866294232244,
            -0.8915364583333334,
            0.4529489413415784
        }
    
        {
            61.0,
            19.364916731037084,
            0.953125,
            0.30257682392245444,
            -0.875,
            0.4841229182759271
        }
    
        {
            61.671875,
            20.532409356536192,
            0.9487980769230769,
            0.3158832208697876,
            -0.858203125,
            0.5133102339134048
        }
    
        {
            62.354166666666664,
            21.63233457825474,
            0.944760101010101,
            0.3277626451250718,
            -0.8411458333333334,
            0.5408083644563685
        }
    
        {
            63.046875,
            22.673587116607177,
            0.9409981343283582,
            0.3384117480090623,
            -0.823828125,
            0.5668396779151794
        }
    
        {
            63.75,
            23.662998542027594,
            0.9375,
            0.3479852726768764,
            -0.80625,
            0.5915749635506898
        }
    
        {
            64.46354166666667,
            24.605930093982014,
            0.9342542270531402,
            0.35660768252147845,
            -0.7884114583333335,
            0.6151482523495506
        }
    
        {
            65.1875,
            25.506662732509717,
            0.93125,
            0.3643808961787102,
            -0.7703125,
            0.6376665683127429
        }
    
        {
            65.921875,
            26.3686631531516,
            0.9284771126760564,
            0.37138962187537466,
            -0.751953125,
            0.65921657882879
        }
    
        {
            66.66666666666667,
            27.194770739161505,
            0.925925925925926,
            0.3777051491550209,
            -0.7333333333333335,
            0.6798692684790378
        }
    
        {
            67.421875,
            27.987332339549173,
            0.9235873287671232,
            0.38338811424039965,
            -0.714453125,
            0.6996833084887293
        }
    
        {
            68.1875,
            28.748301580267313,
            0.9214527027027027,
            0.38849056189550424,
            -0.6953125,
            0.7187075395066829
        }
    
        {
            68.96354166666667,
            29.47931343823885,
            0.919513888888889,
            0.3930575125098513,
            -0.6759114583333334,
            0.7369828359559716
        }
    
        {
            69.75,
            30.18174116912409,
            0.9177631578947368,
            0.3971281732779486,
            -0.65625,
            0.7545435292281023
        }
    
        {
            70.546875,
            30.85674039386492,
            0.9161931818181818,
            0.400736888232012,
            -0.636328125,
            0.7714185098466231
        }
    
        {
            71.35416666666667,
            31.50528367283105,
            0.9147970085470086,
            0.40391389324142374,
            -0.6161458333333334,
            0.7876320918207765
        }
    
        {
            72.171875,
            32.128187919401476,
            0.9135680379746836,
            0.4066859230303984,
            -0.595703125,
            0.8032046979850369
        }
    
        {
            73.0,
            32.72613634390714,
            0.9125,
            0.4090767042988393,
            -0.575,
            0.8181534085976786
        }
    
        {
            73.83854166666667,
            33.29969616287707,
            0.9115869341563787,
            0.4111073600355194,
            -0.5540364583333334,
            0.832492404071927
        }
    
        {
            74.6875,
            33.849332988258425,
            0.9108231707317073,
            0.4127967437592491,
            -0.5328125,
            0.8462333247064606
        }
    
        {
            75.546875,
            34.3754225826298,
            0.9102033132530121,
            0.41416171786300965,
            -0.511328125,
            0.8593855645657451
        }
    
        {
            76.41666666666667,
            34.8782605007124,
            0.9097222222222223,
            0.41521738691324284,
            -0.48958333333333337,
            0.8719565125178104
        }
    
        {
            77.296875,
            35.35807001568914,
            0.909375,
            0.41597729430222513,
            -0.467578125,
            0.8839517503922284
        }
    
        {
            78.1875,
            35.8150086381394,
            0.909156976744186,
            0.4164535888155745,
            -0.4453125,
            0.8953752159534851
        }
    
        {
            79.08854166666667,
            36.24917346698997,
            0.9090636973180077,
            0.4166571662872411,
            -0.4227864583333334,
            0.9062293366747496
        }
    
        {
            80.0,
            36.66060555964672,
            0.9090909090909091,
            0.4165977904505309,
            -0.4,
            0.916515138991168
        }
    
        {
            80.921875,
            37.049293468086205,
            0.9092345505617978,
            0.4162841962706315,
            -0.376953125,
            0.9262323367021551
        }
    
        {
            81.85416666666667,
            37.41517605605451,
            0.9094907407407408,
            0.4157241784006057,
            -0.35364583333333327,
            0.935379401401363
        }
    
        {
            82.796875,
            37.75814468739659,
            0.9098557692307693,
            0.414924666894468,
            -0.330078125,
            0.9439536171849147
        }
    
        {
            83.75,
            38.078044855270605,
            0.9103260869565217,
            0.41389179190511527,
            -0.30625,
            0.9519511213817651
        }
    
        {
            84.71354166666667,
            38.374677305352414,
            0.9108982974910395,
            0.4126309387672303,
            -0.28216145833333334,
            0.9593669326338107
        }
    
        {
            85.6875,
            38.64779869216357,
            0.9115691489361702,
            0.41114679459748477,
            -0.2578125,
            0.9661949673040893
        }
    
        {
            86.671875,
            38.897121795633865,
            0.9123355263157895,
            0.4094433873224617,
            -0.233203125,
            0.9724280448908467
        }
    
        {
            87.66666666666667,
            39.12231531435167,
            0.9131944444444445,
            0.4075241178578299,
            -0.20833333333333326,
            0.9780578828587918
        }
    
        {
            88.671875,
            39.32300324217842,
            0.9141430412371134,
            0.4053917860018394,
            -0.183203125,
            0.9830750810544606
        }
    
        {
            89.6875,
            39.49876382559333,
            0.9151785714285714,
            0.40304861046523804,
            -0.1578125,
            0.9874690956398332
        }
    
        {
            90.71354166666667,
            39.649128089907975,
            0.9162984006734007,
            0.4004962433324038,
            -0.13216145833333326,
            0.9912282022476997
        }
    
        {
            91.75,
            39.773577912981374,
            0.9175,
            0.3977357791298137,
            -0.10625,
            0.9943394478245343
        }
    
        {
            92.796875,
            39.87154361489375,
            0.9187809405940595,
            0.3947677585633045,
            -0.080078125,
            0.9967885903723438
        }
    
        {
            93.85416666666667,
            39.942401020789355,
            0.920138888888889,
            0.39159216687048387,
            -0.05364583333333323,
            0.9985600255197342
        }
    
        {
            94.921875,
            39.98546794129556,
            0.9215716019417476,
            0.38820842661452,
            -0.026953125,
            0.999636698532389
        }
    
        {
            96.0,
            40.0,
            0.9230769230769231,
            0.38461538461538464,
            0.0,
            1.0
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            55.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            55.578125,
            6.860905296269218,
            0.9924665178571429,
            0.12251616600480746,
            -0.9858993902439024,
            0.1673391535675419
        }
    
        {
            56.166666666666664,
            9.711104754638148,
            0.9853801169590642,
            0.17037025885330084,
            -0.9715447154471545,
            0.2368562135277597
        }
    
        {
            56.765625,
            11.90226106079744,
            0.9787176724137931,
            0.20521139759995585,
            -0.9569359756097561,
            0.2902990502633522
        }
    
        {
            57.375,
            13.751704439813997,
            0.972457627118644,
            0.23307973626803385,
            -0.9420731707317073,
            0.335407425361317
        }
    
        {
            57.994791666666664,
            15.381941995077561,
            0.966579861111111,
            0.2563656999179594,
            -0.9269563008130082,
            0.37516931695311123
        }
    
        {
            58.625,
            16.855544340068047,
            0.9610655737704918,
            0.276320399017509,
            -0.9115853658536586,
            0.4111108375626353
        }
    
        {
            59.265625,
            18.209494593738043,
            0.9558971774193549,
            0.2937015257054523,
            -0.8959603658536586,
            0.4441340144814157
        }
    
        {
            59.916666666666664,
            19.467743977039447,
            0.951058201058201,
            0.3090118091593563,
            -0.8800813008130082,
            0.4748230238302304
        }
    
        {
            60.578125,
            20.646810201199965,
            0.946533203125,
            0.32260640939374946,
            -0.8639481707317073,
            0.5035807366146333
        }
    
        {
            61.25,
            21.758618981911514,
            0.9423076923076923,
            0.33474798433710024,
            -0.8475609756097561,
            0.5306980239490613
        }
    
        {
            61.932291666666664,
            22.812085588891925,
            0.9383680555555555,
            0.34563766043775646,
            -0.8309197154471545,
            0.5563923314363884
        }
    
        {
            62.625,
            23.81405834795909,
            0.9347014925373134,
            0.3554337066859566,
            -0.8140243902439024,
            0.5808306914136363
        }
    
        {
            63.328125,
            24.769912878013418,
            0.9312959558823529,
            0.3642634246766679,
            -0.796875,
            0.6041442165369126
        }
    
        {
            64.04166666666667,
            25.68394304921958,
            0.9281400966183575,
            0.3722310586843417,
            -0.7794715447154473,
            0.6264376353468192
        }
    
        {
            64.765625,
            26.559627602046213,
            0.9252232142857143,
            0.37942325145780303,
            -0.7618140243902439,
            0.6477957951718588
        }
    
        {
            65.5,
            27.399817517640514,
            0.9225352112676056,
            0.38591292278366923,
            -0.7439024390243902,
            0.6682882321375735
        }
    
        {
            66.24479166666667,
            28.206871096240537,
            0.920066550925926,
            0.3917620985588963,
            -0.7257367886178863,
            0.6879724657619646
        }
    
        {
            67.0,
            28.982753492378876,
            0.9178082191780822,
            0.39702402044354623,
            -0.7073170731707317,
            0.7068964266433873
        }
    
        {
            67.765625,
            29.729111462661898,
            0.9157516891891891,
            0.40174474949543104,
            -0.6886432926829268,
            0.7251002795771194
        }
    
        {
            68.54166666666667,
            30.447330433973267,
            0.913888888888889,
            0.4059644057863102,
            -0.6697154471544716,
            0.7426178154627628
        }
    
        {
            69.328125,
            31.138578708482747,
            0.9122121710526315,
            0.40971814090108877,
            -0.6505335365853658,
            0.759477529475189
        }
    
        {
            70.125,
            31.80384214210604,
            0.9107142857142857,
            0.41303691093644207,
            -0.6310975609756098,
            0.7757034668806351
        }
    
        {
            70.93229166666667,
            32.443951653812604,
            0.9093883547008548,
            0.41594809812580263,
            -0.6114075203252034,
            0.7913158939954297
        }
    
        {
            71.75,
            33.059605260801284,
            0.9082278481012658,
            0.41847601595950995,
            -0.5914634146341463,
            0.8063318356292997
        }
    
        {
            72.578125,
            33.651385877618395,
            0.9072265625,
            0.42064232347022995,
            -0.571265243902439,
            0.8207655092102047
        }
    
        {
            73.41666666666667,
            34.2197757963952,
            0.9063786008230453,
            0.4224663678567308,
            -0.5508130081300814,
            0.8346286779608587
        }
    
        {
            74.265625,
            34.76516853632922,
            0.9056783536585366,
            0.4239654699552344,
            -0.5301067073170732,
            0.8479309399104688
        }
    
        {
            75.125,
            35.287878584579154,
            0.9051204819277109,
            0.42515516366962836,
            -0.5091463414634146,
            0.8606799654775403
        }
    
        {
            75.99479166666667,
            35.788149428825314,
            0.9046999007936508,
            0.4260493979622061,
            -0.48793191056910573,
            0.8728816933859835
        }
    
        {
            76.875,
            36.26616019101002,
            0.9044117647058824,
            0.42666070812952966,
            -0.46646341463414637,
            0.8845404924636591
        }
    
        {
            77.765625,
            36.722031103404056,
            0.9042514534883721,
            0.427000361667489,
            -0.4447408536585366,
            0.895659295204977
        }
    
        {
            78.66666666666667,
            37.155828016013245,
            0.9042145593869733,
            0.42707848294268097,
            -0.42276422764227645,
            0.9062397077076404
        }
    
        {
            79.578125,
            37.56756608411536,
            0.904296875,
            0.4269041600467655,
            -0.40053353658536583,
            0.9162820996125698
        }
    
        {
            80.5,
            37.957212753309484,
            0.9044943820224719,
            0.42648553655403915,
            -0.3780487804878049,
            0.9257856769099875
        }
    
        {
            81.43229166666667,
            38.324690134623786,
            0.9048032407407408,
            0.42582989038470875,
            -0.35530995934959353,
            0.9347485398688732
        }
    
        {
            82.375,
            38.66987684231746,
            0.9052197802197802,
            0.4249437015639281,
            -0.3323170731707317,
            0.9431677278614014
        }
    
        {
            83.328125,
            38.99260935080358,
            0.9057404891304348,
            0.42383271033482156,
            -0.3090701219512195,
            0.951039252458624
        }
    
        {
            84.29166666666667,
            39.29268291368706,
            0.9063620071684588,
            0.42250196681383934,
            -0.28556910569105687,
            0.958358119846026
        }
    
        {
            85.265625,
            39.569852076541494,
            0.9070811170212766,
            0.42095587315469674,
            -0.2618140243902439,
            0.9651183433302803
        }
    
        {
            86.25,
            39.823830805184976,
            0.9078947368421053,
            0.4191982190019471,
            -0.23780487804878048,
            0.9713129464679262
        }
    
        {
            87.24479166666667,
            40.05429224240431,
            0.9087999131944445,
            0.4172322108583782,
            -0.2135416666666666,
            0.9769339571318125
        }
    
        {
            88.25,
            40.260868097943444,
            0.9097938144329897,
            0.41506049585508703,
            -0.18902439024390244,
            0.9819723926327669
        }
    
        {
            89.265625,
            40.44314766878779,
            0.9108737244897959,
            0.41268518029375295,
            -0.1642530487804878,
            0.9864182358240924
        }
    
        {
            90.29166666666667,
            40.600676479038555,
            0.9120370370370371,
            0.4101078432226117,
            -0.1392276422764227,
            0.99026040192777
        }
    
        {
            91.328125,
            40.73295452068724,
            0.91328125,
            0.40732954520687237,
            -0.11394817073170732,
            0.9934866956265179
        }
    
        {
            92.375,
            40.839434068067106,
            0.9146039603960396,
            0.40435083235710007,
            -0.08841463414634146,
            0.9960837577577343
        }
    
        {
            93.43229166666667,
            40.919517029345904,
            0.9160028594771242,
            0.40117173558182256,
            -0.06262703252032512,
            0.9980370007157541
        }
    
        {
            94.5,
            40.97255178775176,
            0.9174757281553398,
            0.39779176492962875,
            -0.036585365853658534,
            0.9993305314085795
        }
    
        {
            95.578125,
            40.99782947284374,
            0.9190204326923077,
            0.39420989877734364,
            -0.010289634146341464,
            0.999947060313262
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            54.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            54.567708333333336,
            6.882238534682134,
            0.9921401515151516,
            0.12513160972149334,
            -0.986483134920635,
            0.16386282225433654
        }
    
        {
            55.145833333333336,
            9.74356536244419,
            0.9847470238095238,
            0.17399223861507482,
            -0.972718253968254,
            0.23198965148676645
        }
    
        {
            55.734375,
            11.94485007688983,
            0.977796052631579,
            0.20955877327876896,
            -0.9587053571428571,
            0.2844011923069007
        }
    
        {
            56.333333333333336,
            13.804186160565758,
            0.971264367816092,
            0.23800320966492686,
            -0.9444444444444445,
            0.32867109906108954
        }
    
        {
            56.942708333333336,
            15.444350671521617,
            0.9651306497175142,
            0.26176865544951894,
            -0.9299355158730159,
            0.36772263503622904
        }
    
        {
            57.5625,
            16.928041639539998,
            0.959375,
            0.2821340273256666,
            -0.9151785714285714,
            0.40304861046523804
        }
    
        {
            58.192708333333336,
            18.292312506394516,
            0.953978825136612,
            0.2998739755146642,
            -0.900173611111111,
            0.4355312501522504
        }
    
        {
            58.833333333333336,
            19.561157657175833,
            0.9489247311827957,
            0.3155025428576747,
            -0.884920634920635,
            0.46574184898037707
        }
    
        {
            59.484375,
            20.751123604744276,
            0.9441964285714286,
            0.32938291436102024,
            -0.8694196428571429,
            0.4940743715415304
        }
    
        {
            60.145833333333336,
            21.87415672977792,
            0.9397786458333334,
            0.34178369890278,
            -0.853670634920635,
            0.520813255470903
        }
    
        {
            60.817708333333336,
            22.939188152190493,
            0.9356570512820513,
            0.3529105869567768,
            -0.8376736111111112,
            0.5461711464807261
        }
    
        {
            61.5,
            23.95307913400697,
            0.9318181818181818,
            0.362925441424348,
            -0.8214285714285714,
            0.5703114079525469
        }
    
        {
            62.192708333333336,
            24.921216466395258,
            0.9282493781094527,
            0.37195845472231726,
            -0.8049355158730159,
            0.5933622968189348
        }
    
        {
            62.895833333333336,
            25.847904156924507,
            0.9249387254901961,
            0.380116237601831,
            -0.7881944444444445,
            0.6154262894505836
        }
    
        {
            63.609375,
            26.73663053021781,
            0.921875,
            0.3874873989886639,
            -0.7712053571428571,
            0.6365864411956621
        }
    
        {
            64.33333333333333,
            27.59025592890038,
            0.919047619047619,
            0.39414651327000544,
            -0.753968253968254,
            0.6569108554500089
        }
    
        {
            65.06770833333333,
            28.411148027636344,
            0.9164465962441314,
            0.4001570144737513,
            -0.7364831349206348,
            0.6764559054199127
        }
    
        {
            65.8125,
            29.201281542939174,
            0.9140625,
            0.40557335476304407,
            -0.71875,
            0.6952686081652184
        }
    
        {
            66.56770833333333,
            29.96231311578371,
            0.9118864155251141,
            0.4104426454216947,
            -0.7007688492063491,
            0.7133884075186595
        }
    
        {
            67.33333333333333,
            30.69563848859024,
            0.9099099099099098,
            0.41480592552148976,
            -0.6825396825396826,
            0.7308485354426246
        }
    
        {
            68.109375,
            31.402436802091888,
            0.908125,
            0.41869915736122515,
            -0.6640625,
            0.7476770667164735
        }
    
        {
            68.89583333333333,
            32.08370535498599,
            0.9065241228070174,
            0.422154017828763,
            -0.6453373015873015,
            0.7638977465472852
        }
    
        {
            69.69270833333333,
            32.740287188186535,
            0.9051001082251081,
            0.42519853491151344,
            -0.6263640873015872,
            0.7795306473377743
        }
    
        {
            70.5,
            33.37289319193048,
            0.9038461538461539,
            0.42785760502474973,
            -0.6071428571428571,
            0.7945926950459639
        }
    
        {
            71.31770833333333,
            33.982119976269836,
            0.9027558016877637,
            0.43015341742113716,
            -0.5876736111111112,
            0.8090980946730912
        }
    
        {
            72.14583333333333,
            34.56846442408007,
            0.9018229166666666,
            0.43210580530100084,
            -0.5679563492063492,
            0.8230586767638111
        }
    
        {
            72.984375,
            35.13233561634317,
            0.9010416666666666,
            0.43373253847337245,
            -0.5479910714285714,
            0.836484181341504
        }
    
        {
            73.83333333333333,
            35.67406465331487,
            0.9004065040650406,
            0.4350495689428643,
            -0.5277777777777777,
            0.8493824917455919
        }
    
        {
            74.69270833333333,
            36.19391277316667,
            0.8999121485943774,
            0.43607123823092375,
            -0.5073164682539683,
            0.8617598279325397
        }
    
        {
            75.5625,
            36.692078078925974,
            0.8995535714285714,
            0.4368104533205473,
            -0.48660714285714285,
            0.8736209066410946
        }
    
        {
            76.44270833333333,
            37.1687011161936,
            0.8993259803921568,
            0.43727883666110123,
            -0.4656498015873015,
            0.8849690741950855
        }
    
        {
            77.33333333333333,
            37.62386949205991,
            0.8992248062015503,
            0.4374868545588362,
            -0.4444444444444444,
            0.8958064164776166
        }
    
        {
            78.234375,
            38.057621685535935,
            0.8992456896551724,
            0.43744392741995325,
            -0.42299107142857145,
            0.9061338496556175
        }
    
        {
            79.14583333333333,
            38.469950168569525,
            0.8993844696969696,
            0.4371585246428355,
            -0.40128968253968256,
            0.9159511944897505
        }
    
        {
            80.06770833333333,
            38.860803932089006,
            0.8996371722846441,
            0.43663824642796634,
            -0.37934027777777785,
            0.9252572364783095
        }
    
        {
            81.0,
            39.230090491866065,
            0.9,
            0.4358898943540674,
            -0.35714285714285715,
            0.9340497736158587
        }
    
        {
            81.94270833333333,
            39.57767743309686,
            0.9004693223443223,
            0.4349195322318336,
            -0.3346974206349207,
            0.9423256531689727
        }
    
        {
            82.89583333333333,
            39.90339353955027,
            0.9010416666666666,
            0.4337325384733725,
            -0.31200396825396837,
            0.9500807985607208
        }
    
        {
            83.859375,
            40.207029542225264,
            0.9017137096774194,
            0.4323336509916695,
            -0.2890625,
            0.9573102271958396
        }
    
        {
            84.83333333333333,
            40.48833851315162,
            0.902482269503546,
            0.4307270054590598,
            -0.26587301587301587,
            0.9640080598369429
        }
    
        {
            85.81770833333333,
            40.74703592183033,
            0.903344298245614,
            0.428916167598214,
            -0.2424355158730159,
            0.9701675219483409
        }
    
        {
            86.8125,
            40.98279936448949,
            0.904296875,
            0.4269041600467655,
            -0.21875,
            0.9757809372497497
        }
    
        {
            87.81770833333333,
            41.19526796953259,
            0.9053371993127147,
            0.42469348422198544,
            -0.19481646825396837,
            0.9808397135602996
        }
    
        {
            88.83333333333333,
            41.38404147601935,
            0.9064625850340136,
            0.4222861375104015,
            -0.17063492063492072,
            0.9853343208576033
        }
    
        {
            89.859375,
            41.54867897550264,
            0.9076704545454546,
            0.41968362601517817,
            -0.14620535714285715,
            0.9892542613214914
        }
    
        {
            90.89583333333333,
            41.68869730081393,
            0.9089583333333333,
            0.41688697300813926,
            -0.12152777777777783,
            0.9925880309717597
        }
    
        {
            91.94270833333333,
            41.80356903820053,
            0.9103238448844884,
            0.4138967231505003,
            -0.09660218253968264,
            0.9953230723381077
        }
    
        {
            93.0,
            41.892720131306824,
            0.9117647058823529,
            0.41071294246379236,
            -0.07142857142857142,
            0.9974457174120672
        }
    
        {
            94.06770833333333,
            41.95552703655302,
            0.9132787216828478,
            0.4073352139471167,
            -0.046006944444444545,
            0.9989411199179288
        }
    
        {
            95.14583333333333,
            41.991313379144934,
            0.914863782051282,
            0.40376262864562434,
            -0.020337301587301695,
            0.9997931756939268
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            53.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            53.557291666666664,
            6.900471674573965,
            0.9918016975308641,
            0.12778651249211045,
            -0.9870397286821704,
            0.16047608545520847
        }
    
        {
            54.125,
            9.771610665596537,
            0.9840909090909091,
            0.17766564846539157,
            -0.9738372093023255,
            0.22724675966503574
        }
    
        {
            54.703125,
            11.981991288361671,
            0.9768415178571429,
            0.21396413014931556,
            -0.9603924418604651,
            0.27865096019445745
        }
    
        {
            55.291666666666664,
            13.850328415681075,
            0.9700292397660818,
            0.24298821781896623,
            -0.946705426356589,
            0.3221006608297924
        }
    
        {
            55.890625,
            15.499614095498474,
            0.9636314655172413,
            0.26723472578445645,
            -0.9327761627906976,
            0.36045614175577845
        }
    
        {
            56.5,
            16.99264546796643,
            0.9576271186440678,
            0.2880109401350242,
            -0.9186046511627907,
            0.39517780158061466
        }
    
        {
            57.119791666666664,
            18.36652933889791,
            0.9519965277777778,
            0.30610882231496517,
            -0.9041908914728681,
            0.4271285892766955
        }
    
        {
            57.75,
            19.64529205687714,
            0.9467213114754098,
            0.3220539681455269,
            -0.8895348837209303,
            0.45686725713667764
        }
    
        {
            58.390625,
            20.845501004038617,
            0.9417842741935484,
            0.3362177581296551,
            -0.8746366279069767,
            0.48477909311717715
        }
    
        {
            59.041666666666664,
            21.979117298522766,
            0.9371693121693121,
            0.3488748777543296,
            -0.8594961240310076,
            0.5111422627563433
        }
    
        {
            59.703125,
            23.055083284047686,
            0.932861328125,
            0.3602356763132451,
            -0.8441133720930233,
            0.5361647275359928
        }
    
        {
            60.375,
            24.0802694129447,
            0.9288461538461539,
            0.37046568327607227,
            -0.8284883720930233,
            0.5600062654173186
        }
    
        {
            61.057291666666664,
            25.060070517291,
            0.9251104797979798,
            0.3796980381407727,
            -0.8126211240310077,
            0.5827923376114185
        }
    
        {
            61.75,
            25.998798049140657,
            0.9216417910447762,
            0.3880417619274725,
            -0.7965116279069767,
            0.6046232104451316
        }
    
        {
            62.453125,
            26.899947541479982,
            0.9184283088235294,
            0.39558746384529386,
            -0.7801598837209303,
            0.6255801753832554
        }
    
        {
            63.166666666666664,
            27.766386553208946,
            0.9154589371980676,
            0.40241139932186876,
            -0.7635658914728681,
            0.6457299198420684
        }
    
        {
            63.890625,
            28.600490155054597,
            0.9127232142857142,
            0.40857843078649425,
            -0.7467296511627907,
            0.6651276780245255
        }
    
        {
            64.625,
            29.404240765576656,
            0.9102112676056338,
            0.4141442361348825,
            -0.7296511627906976,
            0.6838195526878292
        }
    
        {
            65.36979166666667,
            30.179303130731775,
            0.9079137731481483,
            0.4191569879268302,
            -0.7123304263565892,
            0.7018442588542274
        }
    
        {
            66.125,
            30.927081579095045,
            0.9058219178082192,
            0.42365865176842527,
            -0.6947674418604651,
            0.7192344553277917
        }
    
        {
            66.890625,
            31.648764385191644,
            0.9039273648648649,
            0.4276860052052925,
            -0.6769622093023255,
            0.7360177763998057
        }
    
        {
            67.66666666666667,
            32.3453585885552,
            0.9022222222222223,
            0.4312714478474027,
            -0.6589147286821705,
            0.7522176415943072
        }
    
        {
            68.453125,
            33.017717633633836,
            0.9006990131578947,
            0.4344436530741294,
            -0.640625,
            0.7678538984566008
        }
    
        {
            69.25,
            33.66656353119516,
            0.8993506493506493,
            0.4372280978077293,
            -0.622093023255814,
            0.7829433379347711
        }
    
        {
            70.05729166666667,
            34.292504783576206,
            0.8981704059829061,
            0.43964749722533597,
            -0.6033187984496124,
            0.7975001112459584
        }
    
        {
            70.875,
            34.89605099434605,
            0.8971518987341772,
            0.44172216448539303,
            -0.5843023255813954,
            0.8115360696359546
        }
    
        {
            71.703125,
            35.477624853340664,
            0.8962890625,
            0.4434703106667583,
            -0.5650436046511628,
            0.8250610431009456
        }
    
        {
            72.54166666666667,
            36.037572021741724,
            0.8955761316872428,
            0.44490829656471265,
            -0.5455426356589147,
            0.8380830702730635
        }
    
        {
            73.390625,
            36.576169319782174,
            0.8950076219512195,
            0.4460508453631972,
            -0.5257994186046512,
            0.8506085888321436
        }
    
        {
            74.25,
            37.09363152887568,
            0.8945783132530121,
            0.4469112232394661,
            -0.5058139534883721,
            0.8626425936947834
        }
    
        {
            75.11979166666667,
            37.59011705164799,
            0.8942832341269842,
            0.44750139347199985,
            -0.48558624031007747,
            0.8741887686429766
        }
    
        {
            76.0,
            38.06573262134856,
            0.8941176470588236,
            0.44783214848645364,
            -0.46511627906976744,
            0.8852495958453154
        }
    
        {
            76.890625,
            38.52053721210771,
            0.8940770348837209,
            0.4479132233966013,
            -0.44440406976744184,
            0.8958264467932026
        }
    
        {
            77.79166666666667,
            38.95454527038176,
            0.8941570881226054,
            0.447753393912434,
            -0.42344961240310075,
            0.9059196574507387
        }
    
        {
            78.703125,
            39.36772936345675,
            0.8943536931818182,
            0.4473605609483722,
            -0.4022529069767442,
            0.9155285898478315
        }
    
        {
            79.625,
            39.760022321422305,
            0.8946629213483146,
            0.4467418238362057,
            -0.3808139534883721,
            0.924651681893542
        }
    
        {
            80.55729166666667,
            40.1313189333667,
            0.8950810185185186,
            0.4459035437040744,
            -0.35913275193798444,
            0.9332864868224815
        }
    
        {
            81.5,
            40.48147724577254,
            0.8956043956043956,
            0.4448513983051927,
            -0.3372093023255814,
            0.941429703390059
        }
    
        {
            82.453125,
            40.81031950051819,
            0.8962296195652174,
            0.4435904293534586,
            -0.31504360465116277,
            0.9490771976864696
        }
    
        {
            83.41666666666667,
            41.11763274098135,
            0.8969534050179212,
            0.4421250832363586,
            -0.29263565891472865,
            0.9562240172321246
        }
    
        {
            84.390625,
            41.40316910707893,
            0.8977726063829787,
            0.44045924581998863,
            -0.2699854651162791,
            0.9628643978390449
        }
    
        {
            85.375,
            41.666645833328126,
            0.8986842105263158,
            0.43859627192976974,
            -0.24709302325581395,
            0.9689917635657703
        }
    
        {
            86.36979166666667,
            41.90774495790243,
            0.8996853298611112,
            0.4365390099781503,
            -0.22395833333333326,
            0.9745987199512195
        }
    
        {
            87.375,
            42.126112744947164,
            0.9007731958762887,
            0.4342898221128574,
            -0.2005813953488372,
            0.9796770405801666
        }
    
        {
            88.390625,
            42.3213588169068,
            0.9019451530612245,
            0.43185060017251836,
            -0.1769622093023256,
            0.9842176469048094
        }
    
        {
            89.41666666666667,
            42.49305498810625,
            0.9031986531986532,
            0.4292227776576389,
            -0.15310077519379836,
            0.9882105811187502
        }
    
        {
            90.453125,
            42.640733785130564,
            0.90453125,
            0.42640733785130563,
            -0.12899709302325582,
            0.9916449717472224
        }
    
        {
            91.5,
            42.7638866334668,
            0.905940594059406,
            0.4234048181531366,
            -0.10465116279069768,
            0.994508991475972
        }
    
        {
            92.55729166666667,
            42.86196168319406,
            0.9074244281045752,
            0.4202153106195496,
            -0.08006298449612395,
            0.9967898065859088
        }
    
        {
            93.625,
            42.934361238988984,
            0.9089805825242718,
            0.41683845863096103,
            -0.055232558139534885,
            0.9984735171857904
        }
    
        {
            94.703125,
            42.98043875106878,
            0.9106069711538461,
            0.4132734495295075,
            -0.030159883720930234,
            0.9995450872341577
        }
    
        {
            95.79166666666667,
            42.99949531357573,
            0.9123015873015874,
            0.4095190029864355,
            -0.004844961240309969,
            0.9999882631064126
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            52.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            52.546875,
            6.915629236329475,
            0.9914504716981132,
            0.13048357049678255,
            -0.9875710227272727,
            0.1571733917347608
        }
    
        {
            53.104166666666664,
            9.795278589141258,
            0.9834104938271605,
            0.18139404794706035,
            -0.9749053030303029,
            0.22261996793502856
        }
    
        {
            53.671875,
            12.013735222002149,
            0.9758522727272727,
            0.21843154949094815,
            -0.9620028409090909,
            0.2730394368636852
        }
    
        {
            54.25,
            13.890194383089101,
            0.96875,
            0.24803918541230538,
            -0.9488636363636364,
            0.31568623597929774
        }
    
        {
            54.838541666666664,
            15.547808458855677,
            0.962079678362573,
            0.2727685694536084,
            -0.9354876893939393,
            0.3533592831558108
        }
    
        {
            55.4375,
            17.04944555550121,
            0.9558189655172413,
            0.2939559578534692,
            -0.921875,
            0.3874873989886639
        }
    
        {
            56.046875,
            18.43224898742351,
            0.949947033898305,
            0.31241099978683917,
            -0.9080255681818182,
            0.4189147497141707
        }
    
        {
            56.666666666666664,
            19.720265943665392,
            0.9444444444444444,
            0.3286710990610899,
            -0.8939393939393938,
            0.4481878623560316
        }
    
        {
            57.296875,
            20.930076809089236,
            0.9392930327868853,
            0.34311601326375796,
            -0.8796164772727273,
            0.4756835638429372
        }
    
        {
            57.9375,
            22.073651572632926,
            0.9344758064516129,
            0.356026638268273,
            -0.8650568181818182,
            0.5016738993780211
        }
    
        {
            58.588541666666664,
            23.15993923509438,
            0.9299768518518519,
            0.3676180830967362,
            -0.8502604166666666,
            0.526362255343054
        }
    
        {
            59.25,
            24.195815753968702,
            0.92578125,
            0.37805962115576097,
            -0.8352272727272727,
            0.5499049034992887
        }
    
        {
            59.921875,
            25.18668093426315,
            0.921875,
            0.38748739898866386,
            -0.8199573863636364,
            0.5724245666877988
        }
    
        {
            60.604166666666664,
            26.136851046728815,
            0.9182449494949495,
            0.3960128946474063,
            -0.8044507575757575,
            0.5940193419711093
        }
    
        {
            61.296875,
            27.04982652872981,
            0.9148787313432836,
            0.4037287541601464,
            -0.7887073863636364,
            0.6147687847438593
        }
    
        {
            62.0,
            27.92848008753788,
            0.9117647058823529,
            0.41071294246379236,
            -0.7727272727272727,
            0.6347381838076791
        }
    
        {
            62.713541666666664,
            28.775192295157023,
            0.9088919082125604,
            0.41703177239358,
            -0.7565104166666666,
            0.6539816430717504
        }
    
        {
            63.4375,
            29.591951502900244,
            0.90625,
            0.42274216432714634,
            -0.7400568181818182,
            0.672544352338642
        }
    
        {
            64.171875,
            30.380428880849838,
            0.9038292253521126,
            0.4278933645190118,
            -0.7233664772727273,
            0.6904642927465873
        }
    
        {
            64.91666666666667,
            31.142035721655844,
            0.9016203703703705,
            0.43252827391188675,
            -0.7064393939393939,
            0.707773539128542
        }
    
        {
            65.671875,
            31.87796784590221,
            0.8996147260273972,
            0.43668449103975626,
            -0.6892755681818182,
            0.7244992692250501
        }
    
        {
            66.4375,
            32.58924045985116,
            0.8978040540540541,
            0.44039514134934005,
            -0.671875,
            0.7406645559057082
        }
    
        {
            67.21354166666667,
            33.276715832895285,
            0.8961805555555556,
            0.4436895444386038,
            -0.6542376893939393,
            0.7562889962021657
        }
    
        {
            68.0,
            33.94112549695428,
            0.8947368421052632,
            0.44659375653887207,
            -0.6363636363636364,
            0.77138921583987
        }
    
        {
            68.796875,
            34.5830882113552,
            0.8934659090909091,
            0.4491310157318857,
            -0.6182528409090909,
            0.7859792775307999
        }
    
        {
            69.60416666666667,
            35.20312461471123,
            0.8923611111111112,
            0.45132211044501575,
            -0.5999053030303032,
            0.8000710139707101
        }
    
        {
            70.421875,
            35.80166925555811,
            0.8914161392405063,
            0.4531856867792166,
            -0.5813210227272727,
            0.8136743012626844
        }
    
        {
            71.25,
            36.37908052713812,
            0.890625,
            0.45473850658922654,
            -0.5625,
            0.8267972847076845
        }
    
        {
            72.08854166666667,
            36.93564890960037,
            0.8899819958847737,
            0.4559956655506218,
            -0.5434422348484849,
            0.8394465661272813
        }
    
        {
            72.9375,
            37.471603832101984,
            0.8894817073170732,
            0.4569707784402681,
            -0.5241477272727273,
            0.8516273598204996
        }
    
        {
            73.796875,
            37.98711939900649,
            0.8891189759036144,
            0.45767613733742757,
            -0.5046164772727273,
            0.8633436227046929
        }
    
        {
            74.66666666666667,
            38.48231917243148,
            0.888888888888889,
            0.45812284729085095,
            -0.484848484848485,
            0.8745981630098069
        }
    
        {
            75.546875,
            38.95728016346078,
            0.8887867647058824,
            0.4583209430995386,
            -0.46484375,
            0.885392730987745
        }
    
        {
            76.4375,
            39.41203615331235,
            0.8888081395348837,
            0.45827949015479474,
            -0.4446022727272727,
            0.8957280943934625
        }
    
        {
            77.33854166666667,
            39.84658044140379,
            0.888948754789272,
            0.45800667174027343,
            -0.42412405303030304,
            0.9056041009409954
        }
    
        {
            78.25,
            40.260868097943444,
            0.8892045454545454,
            0.45750986474935734,
            -0.4034090909090909,
            0.9150197294987147
        }
    
        {
            79.171875,
            40.65481778318991,
            0.8895716292134831,
            0.45679570542910014,
            -0.38245738636363635,
            0.9239731314361344
        }
    
        {
            80.10416666666667,
            41.02831318295803,
            0.8900462962962964,
            0.45587014647731144,
            -0.3612689393939394,
            0.9324616632490464
        }
    
        {
            81.046875,
            41.38120409961961,
            0.890625,
            0.4547385065892265,
            -0.33984375,
            0.9404819113549912
        }
    
        {
            82.0,
            41.71330722922842,
            0.8913043478260869,
            0.45340551336117846,
            -0.3181818181818182,
            0.9480297097551914
        }
    
        {
            82.96354166666667,
            42.02440664808086,
            0.8920810931899642,
            0.45187534030194476,
            -0.29628314393939387,
            0.955100151092747
        }
    
        {
            83.9375,
            42.314254025682644,
            0.8929521276595744,
            0.45015163857109197,
            -0.2741477272727273,
            0.9616875914927874
        }
    
        {
            84.921875,
            42.5825685754673,
            0.8939144736842105,
            0.44823756395228737,
            -0.2517755681818182,
            0.9677856494424386
        }
    
        {
            85.91666666666667,
            42.82903674948676,
            0.8949652777777778,
            0.4461357994738204,
            -0.22916666666666663,
            0.9733871988519721
        }
    
        {
            86.921875,
            43.05331167848038,
            0.8961018041237113,
            0.4438485740049523,
            -0.20632102272727273,
            0.9784843563290995
        }
    
        {
            87.9375,
            43.25501235406135,
            0.8973214285714286,
            0.44137767708225867,
            -0.18323863636363635,
            0.9830684625923034
        }
    
        {
            88.96354166666667,
            43.433722545083135,
            0.898621632996633,
            0.4387244701523549,
            -0.15991950757575749,
            0.9871300578427987
        }
    
        {
            90.0,
            43.58898943540674,
            0.9,
            0.4358898943540674,
            -0.13636363636363635,
            0.9906588508046986
        }
    
        {
            91.046875,
            43.7203219651271,
            0.9014542079207921,
            0.4328744749022485,
            -0.11257102272727272,
            0.9936436810256158
        }
    
        {
            92.10416666666667,
            43.82718885165792,
            0.9029820261437909,
            0.42967832207507767,
            -0.08854166666666657,
            0.9960724739013166
        }
    
        {
            93.171875,
            43.9090162607223,
            0.9045813106796117,
            0.4263011287448767,
            -0.06427556818181818,
            0.9979321877436885
        }
    
        {
            94.25,
            43.96518509002322,
            0.90625,
            0.42274216432714634,
            -0.03977272727272727,
            0.9992087520459823
        }
    
        {
            95.33854166666667,
            43.99502781989419,
            0.9079861111111112,
            0.4190002649513732,
            -0.015033143939393832,
            0.9998869959066862
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            51.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            51.536458333333336,
            6.927731407654108,
            0.9910857371794872,
            0.13322560399334823,
            -0.9880787037037037,
            0.15394958683675797
        }
    
        {
            52.083333333333336,
            9.814600801300514,
            0.9827044025157233,
            0.18518114719434933,
            -0.975925925925926,
            0.21810224002890036
        }
    
        {
            52.640625,
            12.04012456785124,
            0.9748263888888888,
            0.22296526977502296,
            -0.9635416666666666,
            0.2675583237300276
        }
    
        {
            53.208333333333336,
            13.923837972660005,
            0.9674242424242425,
            0.25316069041200007,
            -0.9509259259259261,
            0.3094186216146668
        }
    
        {
            53.786458333333336,
            15.588999325056024,
            0.9604724702380952,
            0.278374987947429,
            -0.9380787037037036,
            0.3464222072234672
        }
    
        {
            54.375,
            17.098519672766997,
            0.9539473684210527,
            0.2999740293467894,
            -0.925,
            0.37996710383926663
        }
    
        {
            54.973958333333336,
            18.489562059846907,
            0.947826867816092,
            0.31878555275598114,
            -0.9116898148148149,
            0.4108791568854869
        }
    
        {
            55.583333333333336,
            19.786183450972935,
            0.942090395480226,
            0.33535904154191415,
            -0.8981481481481483,
            0.4396929655771764
        }
    
        {
            56.203125,
            21.004969417601515,
            0.93671875,
            0.3500828236266919,
            -0.884375,
            0.46677709816892254
        }
    
        {
            56.833333333333336,
            22.157893000513884,
            0.9316939890710383,
            0.3632441475494079,
            -0.8703703703703703,
            0.49239762223364186
        }
    
        {
            57.473958333333336,
            23.253905338636425,
            0.9269993279569892,
            0.37506298933284554,
            -0.8561342592592593,
            0.5167534519696985
        }
    
        {
            58.125,
            24.29988425898362,
            0.9226190476190477,
            0.3857124485552956,
            -0.8416666666666667,
            0.5399974279774138
        }
    
        {
            58.786458333333336,
            25.301231523846102,
            0.9185384114583334,
            0.39533174256009534,
            -0.8269675925925927,
            0.5622495894188023
        }
    
        {
            59.458333333333336,
            26.262265652875833,
            0.9147435897435898,
            0.4040348561980897,
            -0.8120370370370371,
            0.5836059033972408
        }
    
        {
            60.140625,
            27.18648974416107,
            0.9112215909090909,
            0.4119165112751677,
            -0.796875,
            0.6041442165369126
        }
    
        {
            60.833333333333336,
            28.07677965072838,
            0.9079601990049752,
            0.4190564126974385,
            -0.7814814814814816,
            0.623928436682853
        }
    
        {
            61.536458333333336,
            28.935519621909854,
            0.9049479166666667,
            0.4255223473810273,
            -0.7658564814814816,
            0.6430115471535525
        }
    
        {
            62.25,
            29.764702249476645,
            0.9021739130434783,
            0.43137249636922675,
            -0.75,
            0.6614378277661477
        }
    
        {
            62.973958333333336,
            30.566003530582744,
            0.8996279761904762,
            0.4366571932940392,
            -0.7339120370370371,
            0.6792445229018389
        }
    
        {
            63.708333333333336,
            31.34084019117689,
            0.8973004694835681,
            0.44142028438277314,
            -0.7175925925925927,
            0.6964631153594866
        }
    
        {
            64.453125,
            32.09041410973649,
            0.8951822916666666,
            0.4457001959685624,
            -0.7010416666666667,
            0.7131203135496998
        }
    
        {
            65.20833333333333,
            32.81574719382281,
            0.8932648401826483,
            0.4495307834770248,
            -0.6842592592592592,
            0.7292388265293956
        }
    
        {
            65.97395833333333,
            33.51770907791279,
            0.8915399774774774,
            0.45294201456638905,
            -0.6672453703703703,
            0.744837979509173
        }
    
        {
            66.75,
            34.197039345533994,
            0.89,
            0.45596052460711994,
            -0.65,
            0.7599342076785333
        }
    
        {
            67.53645833333333,
            34.854365519830246,
            0.8886376096491228,
            0.45861007262934533,
            -0.632523148148148,
            0.7745414559962275
        }
    
        {
            68.33333333333333,
            35.49021774454979,
            0.8874458874458874,
            0.46091191876038684,
            -0.6148148148148147,
            0.7886715054344395
        }
    
        {
            69.140625,
            36.10504084763477,
            0.8864182692307693,
            0.4628851390722406,
            -0.596875,
            0.8023342410585504
        }
    
        {
            69.95833333333333,
            36.69920431320307,
            0.885548523206751,
            0.46454689004054517,
            -0.5787037037037037,
            0.8155378736267347
        }
    
        {
            70.78645833333333,
            37.27301056559913,
            0.8848307291666666,
            0.4659126320699891,
            -0.560300925925926,
            0.8282891236799805
        }
    
        {
            71.625,
            37.826701878435024,
            0.8842592592592593,
            0.46699631948685216,
            -0.5416666666666666,
            0.8405933750763339
        }
    
        {
            72.47395833333333,
            38.36046615329726,
            0.8838287601626016,
            0.46781056284508854,
            -0.522800925925926,
            0.8524548034066056
        }
    
        {
            73.33333333333333,
            38.874441760907935,
            0.8835341365461847,
            0.46836676820371004,
            -0.5037037037037038,
            0.8638764835757318
        }
    
        {
            74.203125,
            39.36872159766399,
            0.8833705357142857,
            0.46867525711504754,
            -0.484375,
            0.8748604799480887
        }
    
        {
            75.08333333333333,
            39.84335647953817,
            0.8833333333333333,
            0.4687453703475079,
            -0.4648148148148148,
            0.8854079217675147
        }
    
        {
            75.97395833333333,
            40.29835797107534,
            0.8834181201550387,
            0.46858555780320166,
            -0.4450231481481482,
            0.8955190660238963
        }
    
        {
            76.875,
            40.73370072802126,
            0.8836206896551724,
            0.46820345664392254,
            -0.425,
            0.9051933495115836
        }
    
        {
            77.78645833333333,
            41.14932441677017,
            0.8839370265151515,
            0.4676059592814792,
            -0.4047453703703704,
            0.9144294314837814
        }
    
        {
            78.70833333333333,
            41.545135261410444,
            0.8843632958801497,
            0.46679927260011733,
            -0.3842592592592593,
            0.923225228031343
        }
    
        {
            79.640625,
            41.92100725900291,
            0.8848958333333333,
            0.4657889695444768,
            -0.36354166666666665,
            0.9315779390889536
        }
    
        {
            80.58333333333333,
            42.27678309532183,
            0.8855311355311355,
            0.46458003401452563,
            -0.3425925925925926,
            0.9394840687849293
        }
    
        {
            81.53645833333333,
            42.612274786223246,
            0.8862658514492753,
            0.4631768998502527,
            -0.32141203703703713,
            0.9469394396938499
        }
    
        {
            82.5,
            42.92726406376256,
            0.8870967741935484,
            0.46158348455658665,
            -0.3,
            0.9539392014169457
        }
    
        {
            83.47395833333333,
            43.22150252090887,
            0.8880208333333333,
            0.4598032183075412,
            -0.2783564814814815,
            0.9604778337979746
        }
    
        {
            84.45833333333333,
            43.49471152399515,
            0.8890350877192982,
            0.45783906867363316,
            -0.25648148148148153,
            0.9665491449776697
        }
    
        {
            85.453125,
            43.746581897725164,
            0.89013671875,
            0.45569356143463713,
            -0.234375,
            0.9721462643938925
        }
    
        {
            86.45833333333333,
            43.97677338348304,
            0.8913230240549828,
            0.4533687977678664,
            -0.2120370370370371,
            0.9772616307440675
        }
    
        {
            87.47395833333333,
            44.18491386772486,
            0.8925914115646258,
            0.4508664680380088,
            -0.18946759259259266,
            0.9818869748383301
        }
    
        {
            88.5,
            44.37059837324712,
            0.8939393939393939,
            0.44818786235603153,
            -0.16666666666666666,
            0.9860132971832694
        }
    
        {
            89.53645833333333,
            44.53338780199935,
            0.8953645833333332,
            0.4453338780199935,
            -0.14363425925925935,
            0.9896308400444299
        }
    
        {
            90.58333333333333,
            44.67280741370776,
            0.8968646864686468,
            0.4423050238980966,
            -0.12037037037037046,
            0.99272905363795
        }
    
        {
            91.640625,
            44.78834501976351,
            0.8984375,
            0.43910142176238737,
            -0.096875,
            0.9952965559947446
        }
    
        {
            92.70833333333333,
            44.87944886644171,
            0.9000809061488673,
            0.4357228045285603,
            -0.07314814814814824,
            0.9973210859209268
        }
    
        {
            93.78645833333333,
            44.94552517537126,
            0.9017928685897435,
            0.43216851130164674,
            -0.0491898148148149,
            0.9987894483415832
        }
    
        {
            94.875,
            44.98593530204746,
            0.9035714285714286,
            0.42843747906711865,
            -0.025,
            0.9996874511566102
        }
    
        {
            95.97395833333333,
            44.9999924647949,
            0.9054147012578616,
            0.4245282307999519,
            -0.0005787037037038088,
            0.9999998325509977
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            50.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            50.526041666666664,
            6.936794180186128,
            0.9907066993464052,
            0.13601557216051233,
            -0.9885643115942028,
            0.1507998734823071
        }
    
        {
            51.0625,
            9.829602929416835,
            0.9819711538461539,
            0.18903082556570835,
            -0.9769021739130435,
            0.2136870202047138
        }
    
        {
            51.609375,
            12.061194472745019,
            0.9737617924528302,
            0.22756970703292487,
            -0.9650135869565217,
            0.262199879842283
        }
    
        {
            52.166666666666664,
            13.951304200284973,
            0.9660493827160493,
            0.2583574851904625,
            -0.9528985507246376,
            0.30328922174532547
        }
    
        {
            52.734375,
            15.623242088611923,
            0.9588068181818182,
            0.2840589470656713,
            -0.9405570652173914,
            0.3396356975785201
        }
    
        {
            53.3125,
            17.13993418161225,
            0.9520089285714286,
            0.3060702532430759,
            -0.9279891304347826,
            0.3726072648176576
        }
    
        {
            53.901041666666664,
            18.538546524694542,
            0.9456323099415205,
            0.3252376583279744,
            -0.9151947463768115,
            0.40301188097162044
        }
    
        {
            54.5,
            19.84313483298443,
            0.9396551724137931,
            0.3421230143618005,
            -0.9021739130434783,
            0.4313724963692267
        }
    
        {
            55.109375,
            21.070282084238336,
            0.9340572033898306,
            0.35712342515658196,
            -0.8889266304347826,
            0.45804961052692034
        }
    
        {
            55.729166666666664,
            22.231958587557894,
            0.9288194444444444,
            0.3705326431259649,
            -0.8754528985507245,
            0.48330344755560634
        }
    
        {
            56.359375,
            23.337113137862083,
            0.9239241803278688,
            0.3825756252108538,
            -0.8617527173913043,
            0.5073285464752627
        }
    
        {
            57.0,
            24.392621835300936,
            0.9193548387096774,
            0.3934293844403377,
            -0.8478260869565217,
            0.5302743877239334
        }
    
        {
            57.651041666666664,
            25.403885426215105,
            0.9150958994708994,
            0.40323627660658895,
            -0.8336730072463767,
            0.552258378830763
        }
    
        {
            58.3125,
            26.375222155462502,
            0.9111328125,
            0.4121128461791016,
            -0.8192934782608695,
            0.5733743946839674
        }
    
        {
            58.984375,
            27.310135588447285,
            0.9074519230769231,
            0.4201559321299582,
            -0.8046875,
            0.593698599748854
        }
    
        {
            59.666666666666664,
            28.21150277615301,
            0.904040404040404,
            0.42744701175989414,
            -0.7898550724637681,
            0.6132935386120218
        }
    
        {
            60.359375,
            29.08170988111557,
            0.9008861940298507,
            0.4340553713599339,
            -0.774796195652174,
            0.6322110843720776
        }
    
        {
            61.0625,
            29.922752108554455,
            0.8979779411764706,
            0.44004047218462433,
            -0.7595108695652174,
            0.6504946110555316
        }
    
        {
            61.776041666666664,
            30.736308756880096,
            0.8953049516908212,
            0.44545375009971155,
            -0.7439990942028984,
            0.6681806251495672
        }
    
        {
            62.5,
            31.523800532296228,
            0.8928571428571429,
            0.4503400076042318,
            -0.7282608695652174,
            0.6853000115716571
        }
    
        {
            63.234375,
            32.28643396783508,
            0.890625,
            0.4547385065892265,
            -0.712296195652174,
            0.7018789993007626
        }
    
        {
            63.979166666666664,
            33.0252362995163,
            0.888599537037037,
            0.45868383749328195,
            -0.6961050724637681,
            0.717939919554702
        }
    
        {
            64.734375,
            33.74108316814051,
            0.8867722602739726,
            0.46220661874165087,
            -0.6796875,
            0.7335018080030546
        }
    
        {
            65.5,
            34.43472084974699,
            0.8851351351351351,
            0.4653340655371215,
            -0.6630434782608695,
            0.748580888037978
        }
    
        {
            66.27604166666667,
            35.10678425886176,
            0.8836805555555556,
            0.4680904567848234,
            -0.6461730072463768,
            0.7631909621491688
        }
    
        {
            67.0625,
            35.75781164654795,
            0.8824013157894737,
            0.4704975216651046,
            -0.6290760869565217,
            0.7773437314466946
        }
    
        {
            67.859375,
            36.38825668549367,
            0.8812905844155844,
            0.47257476214926847,
            -0.6117527173913043,
            0.7910490583802973
        }
    
        {
            68.66666666666667,
            36.99849846803095,
            0.8803418803418804,
            0.4743397239491148,
            -0.5942028985507246,
            0.8043151840876295
        }
    
        {
            69.484375,
            37.588849820915975,
            0.8795490506329114,
            0.4758082255812149,
            -0.5764266304347826,
            0.8171489091503473
        }
    
        {
            70.3125,
            38.1595642500016,
            0.87890625,
            0.47699455312502004,
            -0.5584239130434783,
            0.8295557445652522
        }
    
        {
            71.15104166666667,
            38.71084175974817,
            0.8784079218106996,
            0.4779116266635577,
            -0.5401947463768116,
            0.8415400382553953
        }
    
        {
            72.0,
            39.242833740697165,
            0.8780487804878049,
            0.4785711431792337,
            -0.5217391304347826,
            0.8531050813195036
        }
    
        {
            72.859375,
            39.755647078237516,
            0.8778237951807228,
            0.4789836997378014,
            -0.5030570652173914,
            0.8642531973529894
        }
    
        {
            73.72916666666667,
            40.24934760513377,
            0.8777281746031746,
            0.47915890006111633,
            -0.48414855072463775,
            0.8749858175029084
        }
    
        {
            74.609375,
            40.72396299612029,
            0.8777573529411765,
            0.4791054470131799,
            -0.46501358695652173,
            0.8853035433939194
        }
    
        {
            75.5,
            41.179485183765955,
            0.877906976744186,
            0.478831223067046,
            -0.44565217391304346,
            0.895206199647086
        }
    
        {
            76.40104166666667,
            41.61587235957289,
            0.8781728927203065,
            0.4783433604548608,
            -0.42606431159420294,
            0.9046928773820196
        }
    
        {
            77.3125,
            42.033050611988656,
            0.8785511363636364,
            0.477648302408962,
            -0.40625,
            0.9137619698258403
        }
    
        {
            78.234375,
            42.43091524300855,
            0.8790379213483146,
            0.4767518566630174,
            -0.38620923913043476,
            0.9224112009349684
        }
    
        {
            79.16666666666667,
            42.80933179680439,
            0.8796296296296297,
            0.47565924218671546,
            -0.36594202898550726,
            0.9306376477566175
        }
    
        {
            80.109375,
            43.16813682693955,
            0.8803228021978022,
            0.4743751299663687,
            -0.3454483695652174,
            0.9384377571073815
        }
    
        {
            81.0625,
            43.50713842290711,
            0.8811141304347826,
            0.4729036785098599,
            -0.32472826086956524,
            0.9458073570197199
        }
    
        {
            82.02604166666667,
            43.82611651171323,
            0.8820004480286738,
            0.47124856464207776,
            -0.30378170289855067,
            0.9527416632981138
        }
    
        {
            83.0,
            44.12482294582042,
            0.8829787234042553,
            0.4694130100619194,
            -0.2826086956521739,
            0.9592352814308787
        }
    
        {
            83.984375,
            44.4029813848054,
            0.884046052631579,
            0.4673998040505832,
            -0.26120923913043476,
            0.9652822040175087
        }
    
        {
            84.97916666666667,
            44.66028697443499,
            0.8851996527777778,
            0.46521132265036447,
            -0.23958333333333331,
            0.9708758037920653
        }
    
        {
            85.984375,
            44.89640582339944,
            0.8864368556701031,
            0.46284954457112826,
            -0.21773097826086957,
            0.9760088222478139
        }
    
        {
            87.0,
            45.110974274559844,
            0.8877551020408163,
            0.46031606402612085,
            -0.1956521739130435,
            0.9806733537947793
        }
    
        {
            88.02604166666667,
            45.303597964160225,
            0.8891519360269361,
            0.4576121006480831,
            -0.17334692028985504,
            0.9848608253078315
        }
    
        {
            89.0625,
            45.47385065892265,
            0.890625,
            0.4547385065892265,
            -0.15081521739130435,
            0.9885619708461446
        }
    
        {
            90.109375,
            45.62127285718117,
            0.8921720297029703,
            0.45169577086317986,
            -0.1280570652173913,
            0.9917668012430688
        }
    
        {
            91.16666666666667,
            45.74537013610108,
            0.8937908496732027,
            0.44848402094216744,
            -0.10507246376811585,
            0.9944645681761106
        }
    
        {
            92.234375,
            45.84561122244282,
            0.8954793689320388,
            0.44510302157711473,
            -0.08186141304347826,
            0.9966437222270178
        }
    
        {
            93.3125,
            45.92142575911597,
            0.8972355769230769,
            0.4415521707607305,
            -0.05842391304347827,
            0.9982918643286082
        }
    
        {
            94.40104166666667,
            45.972201733746274,
            0.8990575396825398,
            0.4378304927023455,
            -0.03475996376811583,
            0.9993956898640493
        }
    
        {
            95.5,
            45.9972825284277,
            0.9009433962264151,
            0.4339366276266764,
            -0.010869565217391304,
            0.9999409245310369
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            49.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            49.515625,
            6.9428294563077815,
            0.9903125,
            0.13885658912615562,
            -0.989029255319149,
            0.14771977566612302
        }
    
        {
            50.041666666666664,
            9.840304732182974,
            0.9812091503267973,
            0.19294715161143086,
            -0.977836879432624,
            0.20936818579112706
        }
    
        {
            50.578125,
            12.076972778158234,
            0.97265625,
            0.23224947650304298,
            -0.9664228723404256,
            0.25695686762038794
        }
    
        {
            51.125,
            13.972629494837397,
            0.964622641509434,
            0.2636345187705169,
            -0.9547872340425532,
            0.2972899892518595
        }
    
        {
            51.682291666666664,
            15.65058235598911,
            0.9570794753086419,
            0.2898255991849835,
            -0.942929964539007,
            0.33299111395721503
        }
    
        {
            52.25,
            17.173744495595596,
            0.95,
            0.3122498999199199,
            -0.9308510638297872,
            0.3653988190552254
        }
    
        {
            52.828125,
            18.579268257506133,
            0.943359375,
            0.33177264745546664,
            -0.9185505319148937,
            0.395303579946939
        }
    
        {
            53.416666666666664,
            19.891197103800028,
            0.9371345029239766,
            0.34896837024210575,
            -0.9060283687943261,
            0.4232169596553197
        }
    
        {
            54.015625,
            21.126103660149333,
            0.9313038793103449,
            0.36424316655429884,
            -0.8932845744680851,
            0.44949156723721984
        }
    
        {
            54.625,
            22.295949744292123,
            0.9258474576271186,
            0.3778974532930868,
            -0.8803191489361702,
            0.4743819094530239
        }
    
        {
            55.244791666666664,
            23.409677351612466,
            0.9207465277777778,
            0.3901612891935411,
            -0.8671320921985815,
            0.4980782415236694
        }
    
        {
            55.875,
            24.47415728886288,
            0.9159836065573771,
            0.4012156932600472,
            -0.8537234042553191,
            0.5207267508268698
        }
    
        {
            56.515625,
            25.494786346611633,
            0.9115423387096774,
            0.41120623139696183,
            -0.840093085106383,
            0.5424422626938645
        }
    
        {
            57.166666666666664,
            26.47588000845718,
            0.9074074074074073,
            0.42025206362630446,
            -0.826241134751773,
            0.5633165959246208
        }
    
        {
            57.828125,
            27.42094015500517,
            0.903564453125,
            0.4284521899219558,
            -0.8121675531914894,
            0.5834242586171313
        }
    
        {
            58.5,
            28.33284313301438,
            0.9,
            0.4358898943540674,
            -0.7978723404255319,
            0.6028264496386038
        }
    
        {
            59.182291666666664,
            29.21397530432306,
            0.8967013888888888,
            0.4426359894594403,
            -0.7833554964539007,
            0.6215739426451714
        }
    
        {
            59.875,
            30.066332915738162,
            0.8936567164179104,
            0.4487512375483308,
            -0.7686170212765957,
            0.6397092109731524
        }
    
        {
            60.578125,
            30.8915971015481,
            0.8908547794117647,
            0.454288192669825,
            -0.753656914893617,
            0.6572680234371936
        }
    
        {
            61.291666666666664,
            31.691191161302577,
            0.8882850241545893,
            0.4592926255261243,
            -0.7384751773049645,
            0.6742806630064377
        }
    
        {
            62.015625,
            32.46632495154595,
            0.8859375,
            0.46380464216494216,
            -0.7230718085106383,
            0.6907728713094883
        }
    
        {
            62.75,
            33.21802974289715,
            0.8838028169014085,
            0.46785957384362187,
            -0.7074468085106383,
            0.7067665902744075
        }
    
        {
            63.494791666666664,
            33.94718590997783,
            0.8818721064814814,
            0.47148869319413655,
            -0.6916001773049646,
            0.7222805512761241
        }
    
        {
            64.25,
            34.65454515644377,
            0.8801369863013698,
            0.47471979666361325,
            -0.675531914893617,
            0.7373307480094419
        }
    
        {
            65.015625,
            35.34074851866291,
            0.878589527027027,
            0.47757768268463396,
            -0.6592420212765957,
            0.7519308195460195
        }
    
        {
            65.79166666666667,
            36.006341069625805,
            0.8772222222222222,
            0.48008454759501074,
            -0.6427304964539007,
            0.7660923631835279
        }
    
        {
            66.578125,
            36.65178401502954,
            0.8760279605263158,
            0.4822603159872308,
            -0.6259973404255319,
            0.7798251918091392
        }
    
        {
            67.375,
            37.27746470724639,
            0.875,
            0.4841229182759271,
            -0.6090425531914894,
            0.7931375469626891
        }
    
        {
            68.18229166666667,
            37.88370498092282,
            0.8741319444444445,
            0.4856885253964464,
            -0.5918661347517731,
            0.8060362761898474
        }
    
        {
            69.0,
            38.47076812334269,
            0.8734177215189873,
            0.4869717483967429,
            -0.574468085106383,
            0.8185269813477167
        }
    
        {
            69.828125,
            39.03886472458408,
            0.8728515625,
            0.487985809057301,
            -0.5568484042553191,
            0.830614143076257
        }
    
        {
            70.66666666666667,
            39.588157600755075,
            0.8724279835390947,
            0.488742686429075,
            -0.5390070921985816,
            0.8423012255479805
        }
    
        {
            71.515625,
            40.11876594387438,
            0.872141768292683,
            0.48925324321798025,
            -0.5209441489361702,
            0.8535907647632847
        }
    
        {
            72.375,
            40.630768821177874,
            0.8719879518072289,
            0.48952733519491415,
            -0.5026595744680851,
            0.8644844430037846
        }
    
        {
            73.24479166666667,
            41.12420812254744,
            0.8719618055555556,
            0.4895739062208028,
            -0.4841533687943262,
            0.8749831515435627
        }
    
        {
            74.125,
            41.599091035742596,
            0.8720588235294118,
            0.4894010710087364,
            -0.4654255319148936,
            0.8850870433136723
        }
    
        {
            75.015625,
            42.055392113965304,
            0.8722747093023255,
            0.48901618737168956,
            -0.4464760638297872,
            0.8947955768928788
        }
    
        {
            75.91666666666667,
            42.49305498810625,
            0.8726053639846744,
            0.48842591940352015,
            -0.42730496453900707,
            0.904107552938431
        }
    
        {
            76.828125,
            42.91199376612994,
            0.873046875,
            0.4876362927969311,
            -0.40791223404255317,
            0.9130211439602115
        }
    
        {
            77.75,
            43.31209415394273,
            0.8735955056179775,
            0.4866527433027273,
            -0.3882978723404255,
            0.9215339181689942
        }
    
        {
            78.68229166666667,
            43.69321432535717,
            0.8742476851851853,
            0.4854801591706352,
            -0.3684618794326241,
            0.9296428579863228
        }
    
        {
            79.625,
            44.05518556310937,
            0.875,
            0.4841229182759271,
            -0.3484042553191489,
            0.937344373683178
        }
    
        {
            80.578125,
            44.39781268806353,
            0.8758491847826086,
            0.4825849205224297,
            -0.328125,
            0.94463431251199
        }
    
        {
            81.54166666666667,
            44.720874289555454,
            0.8767921146953406,
            0.4808696160167253,
            -0.30762411347517726,
            0.951507963607563
        }
    
        {
            82.515625,
            45.0241227661281,
            0.8778257978723404,
            0.4789800294268947,
            -0.2869015957446808,
            0.9579600588537894
        }
    
        {
            83.5,
            45.30728418256826,
            0.8789473684210526,
            0.4769187808691396,
            -0.26595744680851063,
            0.9639847698418779
        }
    
        {
            84.49479166666667,
            45.57005794605266,
            0.8801540798611112,
            0.4746881036047152,
            -0.2447916666666666,
            0.9695757009798439
        }
    
        {
            85.5,
            45.81211630125812,
            0.8814432989690721,
            0.47228985877585694,
            -0.22340425531914893,
            0.9747258787501728
        }
    
        {
            86.515625,
            46.03310364139458,
            0.8828125,
            0.4697255473611692,
            -0.20179521276595744,
            0.9794277370509485
        }
    
        {
            87.54166666666667,
            46.23263562919836,
            0.8842592592592593,
            0.46699631948685216,
            -0.1799645390070921,
            0.9836730984935823
        }
    
        {
            88.578125,
            46.410298118891404,
            0.88578125,
            0.464102981188914,
            -0.1579122340425532,
            0.9874531514657746
        }
    
        {
            89.625,
            46.56564586688345,
            0.8873762376237624,
            0.46104599868201435,
            -0.13563829787234044,
            0.990758422699648
        }
    
        {
            90.68229166666667,
            46.69820101547377,
            0.8890420751633987,
            0.45782550015170365,
            -0.11314273049645385,
            0.9935787450100807
        }
    
        {
            91.75,
            46.80745132988977,
            0.8907766990291263,
            0.4544412750474735,
            -0.09042553191489362,
            0.9959032197848888
        }
    
        {
            92.828125,
            46.8928481645589,
            0.892578125,
            0.45089277081306633,
            -0.06748670212765957,
            0.9977201737140191
        }
    
        {
            93.91666666666667,
            46.95380412940171,
            0.8944444444444445,
            0.44717908694668296,
            -0.04432624113475168,
            0.9990171091362068
        }
    
        {
            95.015625,
            46.98969042097825,
            0.8963738207547169,
            0.44329896623564385,
            -0.020944148936170214,
            0.9997806472548564
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            48.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            48.505208333333336,
            6.945845127839391,
            0.9899022108843538,
            0.14175194138447736,
            -0.989474826388889,
            0.14470510682998733
        }
    
        {
            49.020833333333336,
            9.846720230896945,
            0.9804166666666667,
            0.1969344046179389,
            -0.978732638888889,
            0.20514000481035305
        }
    
        {
            49.546875,
            12.087480206162697,
            0.9715073529411765,
            0.2370094158071117,
            -0.9677734375,
            0.2518225042950562
        }
    
        {
            50.083333333333336,
            13.98784194299543,
            0.9631410256410257,
            0.2689969604422198,
            -0.9565972222222223,
            0.29141337381240484
        }
    
        {
            50.630208333333336,
            15.671056254230718,
            0.9552869496855346,
            0.29568030668359846,
            -0.9452039930555557,
            0.3264803386298067
        }
    
        {
            51.1875,
            17.19999545784824,
            0.9479166666666666,
            0.31851843440459704,
            -0.93359375,
            0.35833323870517164
        }
    
        {
            51.755208333333336,
            18.611781493808262,
            0.9410037878787879,
            0.3383960271601502,
            -0.9217664930555557,
            0.38774544778767217
        }
    
        {
            52.333333333333336,
            19.93043457183566,
            0.9345238095238095,
            0.35590061735420825,
            -0.9097222222222222,
            0.41521738691324295
        }
    
        {
            52.921875,
            21.172509215593106,
            0.928453947368421,
            0.37144753009812465,
            -0.8974609375,
            0.441093941991523
        }
    
        {
            53.520833333333336,
            22.349953004549143,
            0.9227729885057472,
            0.3853440173198128,
            -0.884982638888889,
            0.46562402092810723
        }
    
        {
            54.130208333333336,
            23.471696696019446,
            0.9174611581920904,
            0.3978253677291432,
            -0.872287326388889,
            0.48899368116707187
        }
    
        {
            54.75,
            24.544602257930357,
            0.9125,
            0.4090767042988393,
            -0.859375,
            0.5113458803735491
        }
    
        {
            55.380208333333336,
            25.574059610405953,
            0.9078722677595629,
            0.419246878859114,
            -0.8462456597222223,
            0.5327929085501241
        }
    
        {
            56.020833333333336,
            26.564379018506884,
            0.9035618279569892,
            0.42845772610494975,
            -0.8328993055555556,
            0.5534245628855602
        }
    
        {
            56.671875,
            27.51905855919448,
            0.8995535714285714,
            0.4368104533205473,
            -0.8193359375,
            0.5733137199832183
        }
    
        {
            57.333333333333336,
            28.44097201026872,
            0.8958333333333334,
            0.44439018766044874,
            -0.8055555555555556,
            0.5925202502139317
        }
    
        {
            58.005208333333336,
            29.33250426074455,
            0.8923878205128205,
            0.4512692963191469,
            -0.7915581597222222,
            0.6110938387655115
        }
    
        {
            58.6875,
            30.195651073457583,
            0.8892045454545454,
            0.45750986474935734,
            -0.77734375,
            0.6290760640303663
        }
    
        {
            59.380208333333336,
            31.03209400427129,
            0.8862717661691543,
            0.46316558215330283,
            -0.762912326388889,
            0.6465019584223186
        }
    
        {
            60.083333333333336,
            31.843257615318745,
            0.8835784313725491,
            0.46828320022527564,
            -0.748263888888889,
            0.6634012003191406
        }
    
        {
            60.796875,
            32.63035381718033,
            0.8811141304347826,
            0.4729036785098598,
            -0.7333984375,
            0.6797990378579235
        }
    
        {
            61.520833333333336,
            33.394416688605624,
            0.8788690476190476,
            0.4770630955515089,
            -0.7183159722222223,
            0.6957170143459506
        }
    
        {
            62.255208333333336,
            34.13633013921186,
            0.8768339201877935,
            0.4807933822424205,
            -0.7030164930555555,
            0.7111735445669137
        }
    
        {
            63.0,
            34.85685011586675,
            0.875,
            0.48412291827592707,
            -0.6875,
            0.7261843774138906
        }
    
        {
            63.755208333333336,
            35.55662259514061,
            0.8733590182648402,
            0.48707702185124124,
            -0.6717664930555556,
            0.7407629707320962
        }
    
        {
            64.52083333333333,
            36.23619828254922,
            0.8719031531531531,
            0.489678355169584,
            -0.6558159722222222,
            0.7549207975531086
        }
    
        {
            65.296875,
            36.896044709892344,
            0.870625,
            0.4919472627985646,
            -0.6396484375,
            0.7686675981227572
        }
    
        {
            66.08333333333333,
            37.53655625594277,
            0.8695175438596491,
            0.49390205599924697,
            -0.623263888888889,
            0.7820115886654743
        }
    
        {
            66.88020833333333,
            38.15806249392036,
            0.8685741341991341,
            0.4955592531677969,
            -0.6066623263888888,
            0.7949596352900073
        }
    
        {
            67.6875,
            38.760835178695515,
            0.8677884615384616,
            0.4969337843422502,
            -0.58984375,
            0.8075173995561565
        }
    
        {
            68.50520833333333,
            39.34509411866488,
            0.8671545358649788,
            0.49803916605904913,
            -0.5728081597222222,
            0.8196894608055183
        }
    
        {
            69.33333333333333,
            39.91101212558872,
            0.8666666666666666,
            0.498887651569859,
            -0.5555555555555556,
            0.8314794192830982
        }
    
        {
            70.171875,
            40.45871919604444,
            0.8663194444444444,
            0.4994903604449931,
            -0.5380859375,
            0.8428899832509259
        }
    
        {
            71.02083333333333,
            40.98830604744345,
            0.8661077235772358,
            0.4998573908224811,
            -0.5203993055555556,
            0.8539230426550718
        }
    
        {
            71.88020833333333,
            41.49982710755067,
            0.8660266064257027,
            0.4999979169584418,
            -0.5024956597222222,
            0.8645797314073056
        }
    
        {
            72.75,
            41.993303037508255,
            0.8660714285714286,
            0.4999202742560507,
            -0.484375,
            0.8748604799480887
        }
    
        {
            73.63020833333333,
            42.468722853294416,
            0.8662377450980392,
            0.4996320335681696,
            -0.4660373263888889,
            0.8847650594436335
        }
    
        {
            74.52083333333333,
            42.92604569845162,
            0.8665213178294573,
            0.49914006626106533,
            -0.44748263888888884,
            0.8942926187177418
        }
    
        {
            75.421875,
            43.365202311120086,
            0.8669181034482759,
            0.4984506012772424,
            -0.4287109375,
            0.9034417148150018
        }
    
        {
            76.33333333333333,
            43.78609622040109,
            0.8674242424242423,
            0.4975692752318306,
            -0.40972222222222227,
            0.9122103379250226
        }
    
        {
            77.25520833333333,
            44.18860470045716,
            0.8680360486891385,
            0.49650117640963104,
            -0.3905164930555556,
            0.9205959312595241
        }
    
        {
            78.1875,
            44.57257950522945,
            0.86875,
            0.4952508833914383,
            -0.37109375,
            0.9285954063589469
        }
    
        {
            79.13020833333333,
            44.937847401975816,
            0.8695627289377289,
            0.49382249892281116,
            -0.3514539930555556,
            0.9362051542078293
        }
    
        {
            80.08333333333333,
            45.284210517819815,
            0.8704710144927535,
            0.49221967954151974,
            -0.33159722222222227,
            0.9434210524545793
        }
    
        {
            81.046875,
            45.61144650999763,
            0.8714717741935484,
            0.490445661397824,
            -0.31152343750000006,
            0.950238468958284
        }
    
        {
            82.02083333333333,
            45.91930856737236,
            0.8725620567375886,
            0.48850328263162085,
            -0.29123263888888895,
            0.9566522618202574
        }
    
        {
            83.00520833333333,
            46.207525247949945,
            0.8737390350877192,
            0.4863950026099994,
            -0.27072482638888895,
            0.962656775998957
        }
    
        {
            84.0,
            46.475800154489,
            0.875,
            0.48412291827592707,
            -0.25,
            0.9682458365518541
        }
    
        {
            85.00520833333333,
            46.723811447768234,
            0.87634235395189,
            0.48168877781204367,
            -0.2290581597222223,
            0.9734127384951714
        }
    
        {
            86.02083333333333,
            46.95121119458889,
            0.8777636054421768,
            0.47909399178151935,
            -0.20789930555555564,
            0.9781502332206018
        }
    
        {
            87.046875,
            47.15762454507622,
            0.8792613636363636,
            0.47633964186945676,
            -0.1865234375,
            0.9824505113557546
        }
    
        {
            88.08333333333333,
            47.34264873123271,
            0.8808333333333332,
            0.47342648731232706,
            -0.1649305555555556,
            0.9863051819006811
        }
    
        {
            89.13020833333333,
            47.50585187591732,
            0.882477310231023,
            0.47035496906848834,
            -0.14312065972222232,
            0.9897052474149443
        }
    
        {
            90.1875,
            47.646771598398985,
            0.8841911764705882,
            0.4671252117490097,
            -0.12109375,
            0.9926410749666456
        }
    
        {
            91.25520833333333,
            47.76491339927177,
            0.8859728964401294,
            0.46373702329390065,
            -0.09884982638888896,
            0.9951023624848282
        }
    
        {
            92.33333333333333,
            47.85974880372395,
            0.8878205128205128,
            0.46018989234349955,
            -0.07638888888888898,
            0.9970781000775822
        }
    
        {
            93.421875,
            47.930713237801655,
            0.8897321428571429,
            0.45648298321715863,
            -0.0537109375,
            0.9985565257875345
        }
    
        {
            94.52083333333333,
            47.977203607257294,
            0.8917059748427673,
            0.45261512837035184,
            -0.03081597222222232,
            0.9995250751511936
        }
    
        {
            95.63020833333333,
            47.99857554264778,
            0.8937402647975078,
            0.4485848181555867,
            -0.0077039930555556505,
            0.9999703238051616
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            47.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            47.494791666666664,
            6.945845127839424,
            0.9894748263888888,
            0.144705106829988,
            -0.9899022108843536,
            0.14175194138447803
        }
    
        {
            48.0,
            9.848857801796104,
            0.9795918367346939,
            0.20099709799583887,
            -0.9795918367346939,
            0.20099709799583887
        }
    
        {
            48.515625,
            12.09273049643359,
            0.9703125,
            0.2418546099286718,
            -0.9690688775510204,
            0.24679041829456308
        }
    
        {
            49.041666666666664,
            13.996961475818802,
            0.9616013071895424,
            0.2744502250160549,
            -0.9583333333333333,
            0.2856522750167102
        }
    
        {
            49.578125,
            15.684690672256657,
            0.9534254807692307,
            0.3016286667741665,
            -0.9473852040816326,
            0.3200957280052379
        }
    
        {
            50.125,
            17.218721642444887,
            0.9457547169811321,
            0.32488154042348844,
            -0.9362244897959183,
            0.35140248249887523
        }
    
        {
            50.682291666666664,
            18.63612919613219,
            0.9385609567901234,
            0.3451135036320776,
            -0.9248511904761904,
            0.38032916726800386
        }
    
        {
            51.25,
            19.96089927833914,
            0.9318181818181818,
            0.362925441424348,
            -0.9132653061224489,
            0.40736529139467637
        }
    
        {
            51.828125,
            21.20956055613541,
            0.9255022321428571,
            0.37874215278813234,
            -0.9014668367346939,
            0.4328481746150084
        }
    
        {
            52.416666666666664,
            22.39404062592447,
            0.9195906432748537,
            0.3928779057179732,
            -0.8894557823129251,
            0.45702123726376465
        }
    
        {
            53.015625,
            23.523254576256555,
            0.9140625,
            0.40557335476304407,
            -0.8772321428571429,
            0.48006641992360316
        }
    
        {
            53.625,
            24.60405200368427,
            0.9088983050847458,
            0.41701783057091985,
            -0.8647959183673469,
            0.5021235102792708
        }
    
        {
            54.244791666666664,
            25.641813060700887,
            0.904079861111111,
            0.42736355101168144,
            -0.8521471088435375,
            0.5233023073612426
        }
    
        {
            54.875,
            26.640840358367075,
            0.8995901639344263,
            0.4367350878420832,
            -0.8392857142857143,
            0.5436906195585117
        }
    
        {
            55.515625,
            27.604626077151906,
            0.8954133064516129,
            0.445235904470192,
            -0.8262117346938775,
            0.563359715860243
        }
    
        {
            56.166666666666664,
            28.53603959128799,
            0.8915343915343915,
            0.4529530093855237,
            -0.8129251700680271,
            0.5823681549242447
        }
    
        {
            56.828125,
            29.437462679116468,
            0.887939453125,
            0.4599603543611948,
            -0.7994260204081632,
            0.6007645444717646
        }
    
        {
            57.5,
            30.31088913245535,
            0.8846153846153846,
            0.46632137126854384,
            -0.7857142857142857,
            0.6185895741317419
        }
    
        {
            58.182291666666664,
            31.157999557335685,
            0.8815498737373737,
            0.472090902383874,
            -0.7717899659863945,
            0.6358775419864424
        }
    
        {
            58.875,
            31.980218495188552,
            0.878731343283582,
            0.4773166939580381,
            -0.7576530612244898,
            0.6526575203099705
        }
    
        {
            59.578125,
            32.77875869346451,
            0.8761488970588235,
            0.4820405690215369,
            -0.7433035714285714,
            0.6689542590502962
        }
    
        {
            60.291666666666664,
            33.554655870021314,
            0.873792270531401,
            0.48629936043509153,
            -0.7287414965986394,
            0.6847888953065573
        }
    
        {
            61.015625,
            34.30879633358441,
            0.8716517857142857,
            0.4901256619083487,
            -0.7139668367346939,
            0.7001795170119267
        }
    
        {
            61.75,
            35.041939158671,
            0.8697183098591549,
            0.4935484388545211,
            -0.6989795918367347,
            0.7151416154830816
        }
    
        {
            62.494791666666664,
            35.754734155632185,
            0.8679832175925926,
            0.4965935299393359,
            -0.6837797619047619,
            0.7296884521557587
        }
    
        {
            63.25,
            36.447736555237555,
            0.8664383561643836,
            0.49928406240051443,
            -0.6683673469387755,
            0.7438313582701541
        }
    
        {
            64.015625,
            37.12141909813491,
            0.8650760135135135,
            0.5016407986234447,
            -0.6527423469387755,
            0.75757998159459
        }
    
        {
            64.79166666666667,
            37.776182053716795,
            0.8638888888888889,
            0.5036824273828906,
            -0.6369047619047619,
            0.7709424908921796
        }
    
        {
            65.578125,
            38.41236157130117,
            0.8628700657894737,
            0.5054258101486996,
            -0.6208545918367347,
            0.7839257463530851
        }
    
        {
            66.375,
            39.030236676197596,
            0.862012987012987,
            0.5068861905999688,
            -0.6045918367346939,
            0.7965354423713795
        }
    
        {
            67.18229166666667,
            39.630035155358236,
            0.8613114316239316,
            0.5080773737866441,
            -0.5881164965986394,
            0.8087762276603723
        }
    
        {
            68.0,
            40.2119385257662,
            0.8607594936708861,
            0.5090118800729899,
            -0.5714285714285714,
            0.8206518066482898
        }
    
        {
            68.828125,
            40.77608623917179,
            0.8603515625,
            0.5097010779896474,
            -0.5545280612244898,
            0.8321650252892202
        }
    
        {
            69.66666666666667,
            41.322579246164615,
            0.860082304526749,
            0.5101552993353656,
            -0.5374149659863946,
            0.8433179437992782
        }
    
        {
            70.515625,
            41.85148301863836,
            0.8599466463414634,
            0.5103839392516873,
            -0.5200892857142857,
            0.8541118983395584
        }
    
        {
            71.375,
            42.36283011084127,
            0.8599397590361446,
            0.5103955435041118,
            -0.5025510204081632,
            0.8645475532824749
        }
    
        {
            72.24479166666667,
            42.856622324209475,
            0.8600570436507937,
            0.5101978848120176,
            -0.48480017006802717,
            0.8746249453920303
        }
    
        {
            73.125,
            43.33283252915738,
            0.8602941176470589,
            0.5097980297547927,
            -0.46683673469387754,
            0.8843435210032118
        }
    
        {
            74.015625,
            43.791406187280344,
            0.8606468023255814,
            0.5092023975265156,
            -0.4486607142857143,
            0.893702167087354
        }
    
        {
            74.91666666666667,
            44.232262609497546,
            0.8611111111111112,
            0.5084168116034201,
            -0.4302721088435374,
            0.9026992369285215
        }
    
        {
            75.828125,
            44.65529597913751,
            0.8616832386363636,
            0.5074465452174718,
            -0.4116709183673469,
            0.9113325710028064
        }
    
        {
            76.75,
            45.06037616354306,
            0.8623595505617978,
            0.5062963613881243,
            -0.39285714285714285,
            0.9195995135416951
        }
    
        {
            77.68229166666667,
            45.44734933321117,
            0.8631365740740742,
            0.5049705481467908,
            -0.3738307823129251,
            0.9274969251675751
        }
    
        {
            78.625,
            45.81603840359836,
            0.864010989010989,
            0.5034729494900919,
            -0.35459183673469385,
            0.9350211919101706
        }
    
        {
            79.578125,
            46.166243311367396,
            0.8649796195652174,
            0.501806992514863,
            -0.335140306122449,
            0.9421682308442325
        }
    
        {
            80.54166666666667,
            46.49774113390407,
            0.8660394265232976,
            0.4999757111172481,
            -0.3154761904761904,
            0.9489334925286547
        }
    
        {
            81.515625,
            46.81028605829466,
            0.8671875,
            0.49798176657760274,
            -0.2955994897959184,
            0.9553119603733604
        }
    
        {
            82.5,
            47.10360920354193,
            0.868421052631579,
            0.49582746530044136,
            -0.2755102040816326,
            0.9612981470110598
        }
    
        {
            83.49479166666667,
            47.37741829753843,
            0.8697374131944445,
            0.493514773932692,
            -0.25520833333333326,
            0.9668860877048662
        }
    
        {
            84.5,
            47.63139720814412,
            0.8711340206185567,
            0.4910453320427229,
            -0.23469387755102045,
            0.9720693307784516
        }
    
        {
            85.515625,
            47.86520532557418,
            0.8726084183673469,
            0.48842046250585897,
            -0.21396683673469388,
            0.9768409250117179
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            46.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            46.484375,
            6.9428294563077815,
            0.989029255319149,
            0.14771977566612302,
            -0.9903125,
            0.13885658912615562
        }
    
        {
            46.979166666666664,
            9.846720230896969,
            0.9787326388888888,
            0.20514000481035352,
            -0.9804166666666666,
            0.19693440461793935
        }
    
        {
            47.484375,
            12.09273049643359,
            0.9690688775510204,
            0.24679041829456308,
            -0.9703125,
            0.2418546099286718
        }
    
        {
            48.0,
            14.0,
            0.96,
            0.28,
            -0.96,
            0.28
        }
    
        {
            48.526041666666664,
            15.69150343864254,
            0.9514910130718954,
            0.3076765380125988,
            -0.9494791666666665,
            0.31383006877285075
        }
    
        {
            49.0625,
            17.229947584075816,
            0.9435096153846154,
            0.3313451458476119,
            -0.93875,
            0.34459895168151633
        }
    
        {
            49.609375,
            18.65234334096858,
            0.9360259433962265,
            0.35193100643336944,
            -0.9278125,
            0.3730468668193716
        }
    
        {
            50.166666666666664,
            19.982631347136333,
            0.9290123456790123,
            0.37004872865067284,
            -0.9166666666666666,
            0.39965262694272663
        }
    
        {
            50.734375,
            21.237306640894342,
            0.9224431818181819,
            0.38613284801626074,
            -0.9053125,
            0.42474613281788687
        }
    
        {
            51.3125,
            22.428271082497645,
            0.9162946428571429,
            0.40050484075888654,
            -0.89375,
            0.4485654216499529
        }
    
        {
            51.901041666666664,
            23.56441966004957,
            0.9105445906432749,
            0.4134108712289398,
            -0.8819791666666668,
            0.4712883932009914
        }
    
        {
            52.5,
            24.6525860712421,
            0.9051724137931034,
            0.4250445874352086,
            -0.87,
            0.49305172142484205
        }
    
        {
            53.109375,
            25.698137814039658,
            0.9001588983050848,
            0.43556165786507894,
            -0.8578125,
            0.5139627562807931
        }
    
        {
            53.729166666666664,
            26.705367425024424,
            0.8954861111111111,
            0.44508945708374037,
            -0.8454166666666667,
            0.5341073485004885
        }
    
        {
            54.359375,
            27.67775911466416,
            0.8911372950819673,
            0.45373375597810095,
            -0.8328125,
            0.5535551822932832
        }
    
        {
            55.0,
            28.61817604250837,
            0.8870967741935484,
            0.4615834845565866,
            -0.82,
            0.5723635208501674
        }
    
        {
            55.651041666666664,
            29.52899526592347,
            0.8833498677248677,
            0.4687142105702138,
            -0.8069791666666667,
            0.5905799053184694
        }
    
        {
            56.3125,
            30.41220715025465,
            0.8798828125,
            0.4751907367227289,
            -0.79375,
            0.608244143005093
        }
    
        {
            56.984375,
            31.269490015978434,
            0.8766826923076924,
            0.48106907716889896,
            -0.7803125,
            0.6253898003195687
        }
    
        {
            57.666666666666664,
            32.10226714043037,
            0.8737373737373737,
            0.4863979869762177,
            -0.7666666666666667,
            0.6420453428086074
        }
    
        {
            58.359375,
            32.91175093502889,
            0.871035447761194,
            0.49122016320938644,
            -0.7528125,
            0.6582350187005779
        }
    
        {
            59.0625,
            33.69897763656933,
            0.8685661764705882,
            0.4955732005377843,
            -0.73875,
            0.6739795527313867
        }
    
        {
            59.776041666666664,
            34.46483487070453,
            0.8663194444444444,
            0.4994903604449932,
            -0.7244791666666666,
            0.6892966974140905
        }
    
        {
            60.5,
            35.210083782916506,
            0.8642857142857143,
            0.5030011968988072,
            -0.71,
            0.7042016756583301
        }
    
        {
            61.234375,
            35.93537697533414,
            0.862455985915493,
            0.5061320700751287,
            -0.6953125,
            0.7187075395066828
        }
    
        {
            61.979166666666664,
            36.64127316709336,
            0.8608217592592592,
            0.5089065717651855,
            -0.6804166666666667,
            0.732825463341867
        }
    
        {
            62.734375,
            37.328249267269086,
            0.859375,
            0.5113458803735491,
            -0.6653125,
            0.7465649853453817
        }
    
        {
            63.5,
            37.99671038392666,
            0.8581081081081081,
            0.5134690592422522,
            -0.65,
            0.7599342076785333
        }
    
        {
            64.27604166666667,
            38.646998171461256,
            0.857013888888889,
            0.5152933089528168,
            -0.6344791666666667,
            0.7729399634292252
        }
    
        {
            65.0625,
            39.27939782825088,
            0.8560855263157895,
            0.5168341819506694,
            -0.61875,
            0.7855879565650176
        }
    
        {
            65.859375,
            39.89414398892869,
            0.8553165584415584,
            0.5181057660899829,
            -0.6028125,
            0.7978828797785738
        }
    
        {
            66.66666666666667,
            40.49142570416056,
            0.8547008547008548,
            0.5191208423610328,
            -0.5866666666666667,
            0.8098285140832113
        }
    
        {
            67.484375,
            41.071390661376135,
            0.8542325949367089,
            0.5198910210300777,
            -0.5703125,
            0.8214278132275227
        }
    
        {
            68.3125,
            41.634148769369595,
            0.85390625,
            0.52042685961712,
            -0.55375,
            0.8326829753873919
        }
    
        {
            69.15104166666667,
            42.179775205836854,
            0.8537165637860082,
            0.5207379655041587,
            -0.5369791666666667,
            0.8435955041167373
        }
    
        {
            70.0,
            42.708313008125245,
            0.8536585365853658,
            0.520833085464942,
            -0.52,
            0.8541662601625049
        }
    
        {
            70.859375,
            43.21977527254596,
            0.8537274096385542,
            0.5207201840065778,
            -0.5028125,
            0.8643955054509191
        }
    
        {
            71.72916666666667,
            43.71414701564649,
            0.8539186507936508,
            0.5204065120910296,
            -0.48541666666666666,
            0.8742829403129299
        }
    
        {
            72.609375,
            44.191386741189454,
            0.8542279411764706,
            0.5198986675434053,
            -0.4678125,
            0.8838277348237891
        }
    
        {
            73.5,
            44.65142774872938,
            0.8546511627906976,
            0.5192026482410393,
            -0.45,
            0.8930285549745877
        }
    
        {
            74.40104166666667,
            45.09417921323028,
            0.8551843869731801,
            0.5183238990026469,
            -0.4319791666666667,
            0.9018835842646058
        }
    
        {
            75.3125,
            45.51952705982346,
            0.8558238636363636,
            0.5172673529525393,
            -0.41375,
            0.9103905411964692
        }
    
        {
            76.234375,
            45.92733465333445,
            0.8565660112359551,
            0.5160374680149938,
            -0.39531249999999996,
            0.9185466930666888
        }
    
        {
            77.16666666666667,
            46.317443318425454,
            0.8574074074074075,
            0.5146382590936162,
            -0.37666666666666665,
            0.9263488663685092
        }
    
        {
            78.109375,
            46.68967270295836,
            0.8583447802197802,
            0.5130733264061358,
            -0.3578125,
            0.9337934540591672
        }
    
        {
            79.0625,
            47.04382099436652,
            0.859375,
            0.5113458803735491,
            -0.33875,
            0.9408764198873304
        }
    
        {
            80.02604166666667,
            47.379664996334974,
            0.8604950716845878,
            0.5094587634014514,
            -0.3194791666666666,
            0.9475932999266996
        }
    
        {
            81.0,
            47.69696007084728,
            0.8617021276595744,
            0.5074144688388009,
            -0.3,
            0.9539392014169457
        }
    
        {
            81.984375,
            47.99543994859694,
            0.8629934210526315,
            0.505215157353652,
            -0.2803125,
            0.9599087989719388
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            45.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            45.473958333333336,
            6.936794180186095,
            0.988564311594203,
            0.15079987348230642,
            -0.9907066993464053,
            0.1360155721605117
        }
    
        {
            45.958333333333336,
            9.84030473218295,
            0.9778368794326242,
            0.2093681857911266,
            -0.9812091503267975,
            0.19294715161143042
        }
    
        {
            46.453125,
            12.087480206162697,
            0.9677734375,
            0.2518225042950562,
            -0.9715073529411765,
            0.2370094158071117
        }
    
        {
            46.958333333333336,
            13.996961475818786,
            0.9583333333333334,
            0.2856522750167099,
            -0.9616013071895426,
            0.27445022501605465
        }
    
        {
            47.473958333333336,
            15.691503438642526,
            0.9494791666666668,
            0.3138300687728505,
            -0.9514910130718955,
            0.3076765380125986
        }
    
        {
            48.0,
            17.233687939614086,
            0.9411764705882353,
            0.3379154497963546,
            -0.9411764705882353,
            0.3379154497963546
        }
    
        {
            48.536458333333336,
            18.660445130183717,
            0.9333934294871795,
            0.35885471404199454,
            -0.9306576797385622,
            0.36589108098399453
        }
    
        {
            49.083333333333336,
            19.995659251169705,
            0.9261006289308177,
            0.37727658964471145,
            -0.9199346405228759,
            0.39207175002293543
        }
    
        {
            49.640625,
            21.25578390954742,
            0.9192708333333334,
            0.3936256279545819,
            -0.9090073529411765,
            0.4167800766577926
        }
    
        {
            50.208333333333336,
            22.45268945781081,
            0.912878787878788,
            0.408230717414742,
            -0.8978758169934641,
            0.44024881289825124
        }
    
        {
            50.786458333333336,
            23.595246342358816,
            0.9069010416666667,
            0.42134368468497885,
            -0.8865400326797387,
            0.4626518890658592
        }
    
        {
            51.375,
            24.69026883207228,
            0.9013157894736842,
            0.4331626110889874,
            -0.875,
            0.48412291827592707
        }
    
        {
            51.973958333333336,
            25.743108886941574,
            0.8961027298850575,
            0.4438467049472685,
            -0.8632557189542485,
            0.5047668409204231
        }
    
        {
            52.583333333333336,
            26.75804655716772,
            0.8912429378531074,
            0.4535262128333512,
            -0.8513071895424837,
            0.5246675795523084
        }
    
        {
            53.203125,
            27.738556022878605,
            0.88671875,
            0.46230926704797676,
            -0.8391544117647058,
            0.5438932553505609
        }
    
        {
            53.833333333333336,
            28.687492435244707,
            0.8825136612021859,
            0.47028676123351976,
            -0.826797385620915,
            0.5624998516714649
        }
    
        {
            54.473958333333336,
            29.607226541813464,
            0.8786122311827957,
            0.4775359119647333,
            -0.8142361111111112,
            0.5805338537610484
        }
    
        {
            55.125,
            30.499743851383407,
            0.875,
            0.48412291827592707,
            -0.8014705882352942,
            0.5980341931643806
        }
    
        {
            55.786458333333336,
            31.366719092427626,
            0.8716634114583334,
            0.49010498581918166,
            -0.7885008169934641,
            0.6150337076946594
        }
    
        {
            56.458333333333336,
            32.20957306799055,
            0.8685897435897436,
            0.49553189335370074,
            -0.7753267973856209,
            0.6315602562351088
        }
    
        {
            57.140625,
            33.0295167177689,
            0.8657670454545454,
            0.5004472229964985,
            -0.7619485294117647,
            0.647637582701351
        }
    
        {
            57.833333333333336,
            33.827585718693484,
            0.8631840796019901,
            0.5048893390849774,
            -0.7483660130718954,
            0.663285994484186
        }
    
        {
            58.536458333333336,
            34.60466797687749,
            0.8608302696078431,
            0.5088921761305513,
            -0.7345792483660132,
            0.6785229015074018
        }
    
        {
            59.25,
            35.36152570237885,
            0.8586956521739131,
            0.512485879744621,
            -0.7205882352941176,
            0.6933632490662519
        }
    
        {
            59.973958333333336,
            36.0988133022624,
            0.8567708333333334,
            0.5156973328894628,
            -0.7063929738562092,
            0.7078198686718119
        }
    
        {
            60.708333333333336,
            36.81709200750229,
            0.8550469483568075,
            0.5185505916549619,
            -0.6919934640522876,
            0.721903764852986
        }
    
        {
            61.453125,
            37.51684192112091,
            0.853515625,
            0.521067248904457,
            -0.6773897058823529,
            0.7356243513945276
        }
    
        {
            62.208333333333336,
            38.198472009870876,
            0.8521689497716896,
            0.5232667398612448,
            -0.6625816993464053,
            0.7489896472523703
        }
    
        {
            62.973958333333336,
            38.862328440684,
            0.8509994369369369,
            0.5251666005497838,
            -0.6475694444444445,
            0.7620064400134119
        }
    
        {
            63.75,
            39.50870157319777,
            0.85,
            0.5267826876426369,
            -0.6323529411764706,
            0.7746804230038778
        }
    
        {
            64.53645833333333,
            40.13783185213087,
            0.8491639254385964,
            0.5281293664754062,
            -0.6169321895424836,
            0.7870163108260954
        }
    
        {
            65.33333333333333,
            40.749914792003636,
            0.8484848484848484,
            0.5292196726234238,
            -0.6013071895424836,
            0.7990179370981103
        }
    
        {
            66.140625,
            41.345105207380655,
            0.8479567307692307,
            0.530065451376675,
            -0.5854779411764706,
            0.8106883373996207
        }
    
        {
            66.95833333333333,
            41.92352081138013,
            0.8475738396624471,
            0.530677478625065,
            -0.5694444444444444,
            0.8220298198309828
        }
    
        {
            67.78645833333333,
            42.48524528142993,
            0.8473307291666666,
            0.5310655660178741,
            -0.5532066993464052,
            0.833044025126077
        }
    
        {
            68.625,
            43.03033087253687,
            0.8472222222222222,
            0.5312386527473688,
            -0.5367647058823529,
            0.8437319778928799
        }
    
        {
            69.47395833333333,
            43.55880064347806,
            0.847243394308943,
            0.5312048858960738,
            -0.5201184640522876,
            0.8540941302642755
        }
    
        {
            70.33333333333333,
            44.070650349435766,
            0.8473895582329317,
            0.5309716909570574,
            -0.5032679738562091,
            0.8641303990085443
        }
    
        {
            71.203125,
            44.56585004501064,
            0.84765625,
            0.5305458338691743,
            -0.48621323529411764,
            0.873840196960993
        }
    
        {
            72.08333333333333,
            45.04434543375624,
            0.8480392156862745,
            0.5299334756912499,
            -0.468954248366013,
            0.8832224594854162
        }
    
        {
            72.97395833333333,
            45.50605899399476,
            0.8485343992248061,
            0.5291402208604042,
            -0.4514910130718954,
            0.8922756665489167
        }
    
        {
            73.875,
            45.9508909054003,
            0.8491379310344828,
            0.5281711598321873,
            -0.4338235294117647,
            0.900997860890202
        }
    
        {
            74.78645833333333,
            46.37871979643894,
            0.8498461174242423,
            0.5270309067777152,
            -0.41595179738562094,
            0.9093866626752732
        }
    
        {
            75.70833333333333,
            46.789403329054004,
            0.8506554307116104,
            0.5257236329107191,
            -0.397875816993464,
            0.9174392809618429
        }
    
        {
            76.640625,
            47.18277863383393,
            0.8515625,
            0.5242530959314881,
            -0.37959558823529405,
            0.9251525222320377
        }
    
        {
            77.58333333333333,
            47.55866260618448,
            0.8525641025641025,
            0.5226226660020272,
            -0.36111111111111116,
            0.9325227961996955
        }
    
        {
            78.53645833333333,
            47.91685207165218,
            0.8536571557971014,
            0.520835348604915,
            -0.3424223856209151,
            0.9395461190520034
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            44.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            44.463541666666664,
            6.927731407654124,
            0.9880787037037037,
            0.15394958683675833,
            -0.9910857371794872,
            0.13322560399334854
        }
    
        {
            44.9375,
            9.829602929416835,
            0.9769021739130435,
            0.2136870202047138,
            -0.9819711538461539,
            0.18903082556570835
        }
    
        {
            45.421875,
            12.076972778158234,
            0.9664228723404256,
            0.25695686762038794,
            -0.97265625,
            0.23224947650304298
        }
    
        {
            45.916666666666664,
            13.987841942995447,
            0.9565972222222222,
            0.2914133738124051,
            -0.9631410256410255,
            0.2689969604422201
        }
    
        {
            46.421875,
            15.684690672256657,
            0.9473852040816326,
            0.3200957280052379,
            -0.9534254807692307,
            0.3016286667741665
        }
    
        {
            46.9375,
            17.229947584075816,
            0.93875,
            0.34459895168151633,
            -0.9435096153846154,
            0.3313451458476119
        }
    
        {
            47.463541666666664,
            18.660445130183728,
            0.9306576797385621,
            0.36589108098399464,
            -0.9333934294871794,
            0.3588547140419947
        }
    
        {
            48.0,
            20.0,
            0.9230769230769231,
            0.38461538461538464,
            -0.9230769230769231,
            0.38461538461538464
        }
    
        {
            48.546875,
            21.26501652325657,
            0.9159787735849056,
            0.40122672685389754,
            -0.9125600961538461,
            0.40894262544724175
        }
    
        {
            49.104166666666664,
            22.46732774435408,
            0.9093364197530863,
            0.4160616248954459,
            -0.9018429487179487,
            0.4320639950837322
        }
    
        {
            49.671875,
            23.615775108693235,
            0.903125,
            0.4293777292489679,
            -0.8909254807692307,
            0.45414952132102376
        }
    
        {
            50.25,
            24.717149916606484,
            0.8973214285714286,
            0.44137767708225867,
            -0.8798076923076923,
            0.4753298060885862
        }
    
        {
            50.838541666666664,
            25.776785703547244,
            0.8919042397660818,
            0.4522243105885481,
            -0.8684895833333333,
            0.49570741737590845
        }
    
        {
            51.4375,
            26.798947623927326,
            0.8868534482758621,
            0.46205082110219525,
            -0.8569711538461539,
            0.5153643773832178
        }
    
        {
            52.046875,
            27.78709777458551,
            0.8821504237288136,
            0.47096775889127984,
            -0.8452524038461539,
            0.5343672648958753
        }
    
        {
            52.666666666666664,
            28.744081516413473,
            0.8777777777777778,
            0.4790680252735579,
            -0.8333333333333333,
            0.5527707983925667
        }
    
        {
            53.296875,
            29.67226171417297,
            0.873719262295082,
            0.4864305199044749,
            -0.8212139423076923,
            0.5706204175802494
        }
    
        {
            53.9375,
            30.57361760979554,
            0.8699596774193549,
            0.49312286467412164,
            -0.8088942307692307,
            0.5879541848037604
        }
    
        {
            54.588541666666664,
            31.44981905681808,
            0.8664847883597884,
            0.49920347709235047,
            -0.7963741987179487,
            0.6048042126311168
        }
    
        {
            55.25,
            32.30228320103704,
            0.86328125,
            0.5047231750162038,
            -0.7836538461538461,
            0.621197753866097
        }
    
        {
            55.921875,
            33.132218405720664,
            0.8603365384615385,
            0.5097264370110871,
            -0.7707331730769231,
            0.637158046263859
        }
    
        {
            56.604166666666664,
            33.94065874393458,
            0.8576388888888888,
            0.5142524052111299,
            -0.7576121794871794,
            0.6527049758448956
        }
    
        {
            57.296875,
            34.728491404528,
            0.8551772388059702,
            0.5183356926048955,
            -0.7442908653846154,
            0.6678556039332307
        }
    
        {
            58.0,
            35.4964786985977,
            0.8529411764705882,
            0.5220070396852603,
            -0.7307692307692307,
            0.682624590357648
        }
    
        {
            58.713541666666664,
            36.24527589847534,
            0.8509208937198067,
            0.5252938536010919,
            -0.7170472756410255,
            0.6970245365091411
        }
    
        {
            59.4375,
            36.97544582219395,
            0.8491071428571428,
            0.5282206546027707,
            -0.703125,
            0.7110662658114221
        }
    
        {
            60.171875,
            37.687470848869324,
            0.8474911971830986,
            0.5308094485756243,
            -0.6890024038461539,
            0.7247590547859486
        }
    
        {
            60.916666666666664,
            38.38176288580584,
            0.8460648148148148,
            0.5330800400806367,
            -0.6746794871794871,
            0.7381108247270353
        }
    
        {
            61.671875,
            39.05867168740349,
            0.844820205479452,
            0.535050297087719,
            -0.66015625,
            0.7511283016808363
        }
    
        {
            62.4375,
            39.718491836297105,
            0.84375,
            0.5367363761661771,
            -0.6454326923076923,
            0.7638171506980213
        }
    
        {
            63.213541666666664,
            40.361468629828096,
            0.8428472222222222,
            0.5381529150643746,
            -0.6305088141025641,
            0.7761820890351557
        }
    
        {
            64.0,
            40.98780306383839,
            0.8421052631578947,
            0.5393131982083998,
            -0.6153846153846154,
            0.7882269819968921
        }
    
        {
            64.796875,
            41.59765606659076,
            0.8415178571428571,
            0.5402292995661138,
            -0.6000600961538461,
            0.7999549243575146
        }
    
        {
            65.60416666666667,
            42.191152105295984,
            0.8410790598290598,
            0.5409122064781536,
            -0.5845352564102564,
            0.8113683097172306
        }
    
        {
            66.421875,
            42.768382264055475,
            0.8407832278481012,
            0.5413719273931072,
            -0.5688100961538461,
            0.8224688896933745
        }
    
        {
            67.25,
            43.32940687339258,
            0.840625,
            0.5416175859174073,
            -0.5528846153846154,
            0.8332578244883189
        }
    
        {
            68.08854166666667,
            43.87425775675979,
            0.840599279835391,
            0.5416575031698739,
            -0.5367588141025641,
            0.8437357260915345
        }
    
        {
            68.9375,
            44.40294014758482,
            0.8407012195121951,
            0.5414992700924979,
            -0.5204326923076923,
            0.8539026951458619
        }
    
        {
            69.796875,
            44.91543432089213,
            0.8409262048192772,
            0.541149811095086,
            -0.50390625,
            0.8637583523248487
        }
    
        {
            70.66666666666667,
            45.41169697580373,
            0.8412698412698413,
            0.5406154401881397,
            -0.48717948717948717,
            0.8733018649193026
        }
    
        {
            71.546875,
            45.89166239889742,
            0.8417279411764705,
            0.5399019105752637,
            -0.47025240384615385,
            0.8825319692095657
        }
    
        {
            72.4375,
            46.355243433186715,
            0.842296511627907,
            0.539014458525427,
            -0.453125,
            0.8914469890997445
        }
    
        {
            73.33854166666667,
            46.802332273152764,
            0.8429717432950192,
            0.5379578422201468,
            -0.4357972756410256,
            0.900044851406784
        }
    
        {
            74.25,
            47.23280110262359,
            0.84375,
            0.5367363761661772,
            -0.4182692307692308,
            0.9083230981273768
        }
    
        {
            75.171875,
            47.64650258921818,
            0.844627808988764,
            0.5353539616766088,
            -0.4005408653846154,
            0.9162788959465036
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            43.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            43.453125,
            6.915629236329475,
            0.9875710227272727,
            0.1571733917347608,
            -0.9914504716981132,
            0.13048357049678255
        }
    
        {
            43.916666666666664,
            9.814600801300537,
            0.9759259259259259,
            0.21810224002890083,
            -0.9827044025157232,
            0.18518114719434975
        }
    
        {
            44.390625,
            12.061194472745019,
            0.9650135869565217,
            0.262199879842283,
            -0.9737617924528302,
            0.22756970703292487
        }
    
        {
            44.875,
            13.972629494837397,
            0.9547872340425532,
            0.2972899892518595,
            -0.964622641509434,
            0.2636345187705169
        }
    
        {
            45.369791666666664,
            15.671056254230733,
            0.9452039930555555,
            0.3264803386298069,
            -0.9552869496855345,
            0.2956803066835987
        }
    
        {
            45.875,
            17.218721642444887,
            0.9362244897959183,
            0.35140248249887523,
            -0.9457547169811321,
            0.32488154042348844
        }
    
        {
            46.390625,
            18.65234334096858,
            0.9278125,
            0.3730468668193716,
            -0.9360259433962265,
            0.35193100643336944
        }
    
        {
            46.916666666666664,
            19.99565925116972,
            0.9199346405228758,
            0.39207175002293565,
            -0.9261006289308176,
            0.3772765896447116
        }
    
        {
            47.453125,
            21.26501652325657,
            0.9125600961538461,
            0.40894262544724175,
            -0.9159787735849056,
            0.40122672685389754
        }
    
        {
            48.0,
            22.47220505424423,
            0.9056603773584906,
            0.42400386894800435,
            -0.9056603773584906,
            0.42400386894800435
        }
    
        {
            48.557291666666664,
            23.626032802784817,
            0.8992091049382716,
            0.4375191259774966,
            -0.8951454402515723,
            0.44577420382612853
        }
    
        {
            49.125,
            24.733264543929497,
            0.8931818181818182,
            0.4496957189805363,
            -0.8844339622641509,
            0.4666653687533867
        }
    
        {
            49.703125,
            25.79921249252339,
            0.8875558035714286,
            0.46070022308077485,
            -0.8735259433962265,
            0.48677759419855454
        }
    
        {
            50.291666666666664,
            26.82812449443474,
            0.8823099415204678,
            0.47066885077955684,
            -0.8624213836477986,
            0.5061910281968818
        }
    
        {
            50.890625,
            27.82344851217,
            0.8774245689655172,
            0.4797146295201724,
            -0.8511202830188679,
            0.524970726644717
        }
    
        {
            51.5,
            28.788018340969565,
            0.8728813559322034,
            0.4879325142537214,
            -0.839622641509434,
            0.5431701573767842
        }
    
        {
            52.119791666666664,
            29.724187400554186,
            0.8686631944444444,
            0.49540312334256975,
            -0.8279284591194968,
            0.5608337245387581
        }
    
        {
            52.75,
            30.633927270266867,
            0.8647540983606558,
            0.5021955290207682,
            -0.8160377358490566,
            0.5779986277408843
        }
    
        {
            53.390625,
            31.51890166407096,
            0.8611391129032258,
            0.5083693816785638,
            -0.8039504716981132,
            0.5946962578126597
        }
    
        {
            54.041666666666664,
            32.38052290944186,
            0.8578042328042328,
            0.5139765541181247,
            -0.7916666666666667,
            0.6109532624422992
        }
    
        {
            54.703125,
            33.21999571394276,
            0.854736328125,
            0.5190624330303556,
            -0.7791863207547169,
            0.6267923719611841
        }
    
        {
            55.375,
            34.038351531764874,
            0.8519230769230769,
            0.5236669466425365,
            -0.7665094339622641,
            0.6422330477691486
        }
    
        {
            56.057291666666664,
            34.836475869385296,
            0.849352904040404,
            0.5278253919603833,
            -0.7536360062893082,
            0.6572919975355715
        }
    
        {
            56.75,
            35.6151302117513,
            0.8470149253731343,
            0.5315691076380791,
            -0.7405660377358491,
            0.6719835889009679
        }
    
        {
            57.453125,
            36.374969797023546,
            0.8448988970588235,
            0.5349260264268169,
            -0.7272995283018868,
            0.6863201848495009
        }
    
        {
            58.166666666666664,
            37.11655814981892,
            0.8429951690821256,
            0.5379211326060713,
            -0.7138364779874213,
            0.7003124179211117
        }
    
        {
            58.890625,
            37.84037905610057,
            0.8412946428571428,
            0.5405768436585796,
            -0.7001768867924528,
            0.713969416152841
        }
    
        {
            59.625,
            38.54684649877341,
            0.8397887323943662,
            0.5429133309686396,
            -0.6863207547169812,
            0.7272989905428946
        }
    
        {
            60.369791666666664,
            39.236312952713384,
            0.8384693287037037,
            0.5449487910099081,
            -0.6722680817610063,
            0.7403077915606298
        }
    
        {
            61.125,
            39.909076348620246,
            0.8373287671232876,
            0.5466996760084966,
            -0.6580188679245284,
            0.7530014405400046
        }
    
        {
            61.890625,
            40.56538594798988,
            0.8363597972972973,
            0.5481808911890524,
            -0.6435731132075472,
            0.765384640528111
        }
    
        {
            62.666666666666664,
            41.20544732057752,
            0.8355555555555555,
            0.5494059642743669,
            -0.6289308176100629,
            0.7774612701995758
        }
    
        {
            63.453125,
            41.82942657668612,
            0.8349095394736842,
            0.5503871917985016,
            -0.6140919811320755,
            0.7892344637110588
        }
    
        {
            64.25,
            42.43745397641098,
            0.8344155844155844,
            0.5511357659274153,
            -0.5990566037735849,
            0.8007066788002072
        }
    
        {
            65.05729166666667,
            43.02962701439862,
            0.8340678418803419,
            0.5516618847999823,
            -0.5838246855345912,
            0.8118797549886533
        }
    
        {
            65.875,
            43.60601306012738,
            0.8338607594936709,
            0.5519748488623719,
            -0.5683962264150944,
            0.8227549633986299
        }
    
        {
            66.703125,
            44.16665161900294,
            0.8337890625,
            0.5520831452375368,
            -0.5527712264150944,
            0.8333330494151499
        }
    
        {
            67.54166666666667,
            44.71155626780272,
            0.8338477366255145,
            0.551994521824725,
            -0.5369496855345912,
            0.843614269203825
        }
    
        {
            68.390625,
            45.24071630853533,
            0.8340320121951219,
            0.5517160525431138,
            -0.5209316037735849,
            0.853598420915761
        }
    
        {
            69.25,
            45.75409817710322,
            0.8343373493975904,
            0.551254194904858,
            -0.5047169811320755,
            0.8632848712660984
        }
    
        {
            70.11979166666667,
            46.251646636884864,
            0.8347594246031746,
            0.550614840915296,
            -0.4883058176100629,
            0.8726725780544317
        }
    
        {
            71.0,
            46.73328578219169,
            0.8352941176470589,
            0.5498033621434317,
            -0.4716981132075471,
            0.8817601090979563
        }
    
        {
            71.890625,
            47.19891987227435,
            0.8359375,
            0.5488246496776088,
            -0.45489386792452835,
            0.8905456579674408
        }
    
        {
            72.79166666666667,
            47.64843401297558,
            0.8366858237547893,
            0.547683149574432,
            -0.43789308176100633,
            0.8990270568485961
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            42.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            42.442708333333336,
            6.900471674573916,
            0.9870397286821706,
            0.16047608545520736,
            -0.9918016975308643,
            0.12778651249210957
        }
    
        {
            42.895833333333336,
            9.795278589141233,
            0.9749053030303031,
            0.22261996793502803,
            -0.9834104938271606,
            0.1813940479470599
        }
    
        {
            43.359375,
            12.04012456785124,
            0.9635416666666666,
            0.2675583237300276,
            -0.9748263888888888,
            0.22296526977502296
        }
    
        {
            43.833333333333336,
            13.951304200284957,
            0.9528985507246377,
            0.30328922174532513,
            -0.9660493827160495,
            0.2583574851904622
        }
    
        {
            44.317708333333336,
            15.650582355989087,
            0.9429299645390071,
            0.33299111395721465,
            -0.957079475308642,
            0.28982559918498313
        }
    
        {
            44.8125,
            17.19999545784824,
            0.93359375,
            0.35833323870517164,
            -0.9479166666666666,
            0.31851843440459704
        }
    
        {
            45.317708333333336,
            18.636129196132178,
            0.9248511904761906,
            0.38032916726800364,
            -0.9385609567901235,
            0.34511350363207743
        }
    
        {
            45.833333333333336,
            19.982631347136323,
            0.9166666666666667,
            0.39965262694272646,
            -0.9290123456790125,
            0.3700487286506727
        }
    
        {
            46.359375,
            21.25578390954742,
            0.9090073529411765,
            0.4167800766577926,
            -0.9192708333333334,
            0.3936256279545819
        }
    
        {
            46.895833333333336,
            22.46732774435407,
            0.9018429487179488,
            0.4320639950837321,
            -0.9093364197530865,
            0.4160616248954458
        }
    
        {
            47.442708333333336,
            23.626032802784806,
            0.8951454402515724,
            0.4457742038261284,
            -0.8992091049382717,
            0.4375191259774965
        }
    
        {
            48.0,
            24.73863375370596,
            0.8888888888888888,
            0.4581228472908511,
            -0.8888888888888888,
            0.4581228472908511
        }
    
        {
            48.567708333333336,
            25.81041857948576,
            0.8830492424242424,
            0.469280337808832,
            -0.8783757716049383,
            0.4779707144349215
        }
    
        {
            49.145833333333336,
            26.84561539566978,
            0.8776041666666667,
            0.4793859892083889,
            -0.8676697530864198,
            0.4971410258457367
        }
    
        {
            49.734375,
            27.847655976031,
            0.8725328947368421,
            0.48855536800054383,
            -0.8567708333333334,
            0.515697332889463
        }
    
        {
            50.333333333333336,
            28.81936077631763,
            0.867816091954023,
            0.496885530626166,
            -0.8456790123456791,
            0.5336918662281044
        }
    
        {
            50.942708333333336,
            29.76307221482571,
            0.8634357344632769,
            0.5044588510987408,
            -0.8343942901234569,
            0.5511680039782539
        }
    
        {
            51.5625,
            30.68075282241295,
            0.859375,
            0.5113458803735491,
            -0.8229166666666666,
            0.5681620893039435
        }
    
        {
            52.192708333333336,
            31.574058922343152,
            0.8556181693989071,
            0.5176075233171008,
            -0.8112461419753086,
            0.5847047948582065
        }
    
        {
            52.833333333333336,
            32.4443968797216,
            0.8521505376344086,
            0.5232967238664774,
            -0.7993827160493828,
            0.600822164439289
        }
    
        {
            53.484375,
            33.29296668756594,
            0.8489583333333334,
            0.5284597886915228,
            -0.7873263888888888,
            0.6165364201401099
        }
    
        {
            54.145833333333336,
            34.12079618999077,
            0.8460286458333334,
            0.5331374404686058,
            -0.7750771604938272,
            0.6318665961109403
        }
    
        {
            54.817708333333336,
            34.92876827318131,
            0.843349358974359,
            0.537365665741251,
            -0.7626350308641975,
            0.6468290420959503
        }
    
        {
            55.5,
            35.71764269937197,
            0.8409090909090909,
            0.541176404535939,
            -0.75,
            0.6614378277661476
        }
    
        {
            56.192708333333336,
            36.488073807272016,
            0.8386971393034827,
            0.544598116526448,
            -0.7371720679012346,
            0.6757050705050375
        }
    
        {
            56.895833333333336,
            37.24062498543164,
            0.8367034313725491,
            0.5476562497857593,
            -0.7241512345679013,
            0.6896412034339193
        }
    
        {
            57.609375,
            37.97578059907887,
            0.8349184782608695,
            0.5503736318707082,
            -0.7109375,
            0.7032551962792383
        }
    
        {
            58.333333333333336,
            38.69395588747967,
            0.8333333333333334,
            0.5527707983925667,
            -0.6975308641975309,
            0.7165547386570309
        }
    
        {
            59.067708333333336,
            39.39550522900124,
            0.8319395539906104,
            0.5548662708310034,
            -0.6839313271604938,
            0.7295463931296525
        }
    
        {
            59.8125,
            40.08072908206636,
            0.8307291666666666,
            0.5566767928064773,
            -0.6701388888888888,
            0.7422357237419697
        }
    
        {
            60.567708333333336,
            40.74987984335983,
            0.8296946347031964,
            0.5582175321008196,
            -0.6561535493827161,
            0.7546274045066635
        }
    
        {
            61.333333333333336,
            41.40316681393129,
            0.8288288288288289,
            0.5595022542423148,
            -0.6419753086419754,
            0.7667253113690982
        }
    
        {
            62.109375,
            42.04076042496585,
            0.828125,
            0.560543472332878,
            -0.6276041666666666,
            0.7785326004623306
        }
    
        {
            62.895833333333336,
            42.66279584492272,
            0.8275767543859649,
            0.5613525769068779,
            -0.6130401234567902,
            0.7900517749059763
        }
    
        {
            63.692708333333336,
            43.269376066277296,
            0.8271780303030304,
            0.5619399489126922,
            -0.5982831790123456,
            0.8012847419680981
        }
    
        {
            64.5,
            43.86057455164034,
            0.8269230769230769,
            0.5623150583543634,
            -0.5833333333333334,
            0.8122328620674137
        }
    
        {
            65.31770833333333,
            44.43643750439045,
            0.826806434599156,
            0.5624865506884866,
            -0.5681905864197531,
            0.8228969908220453
        }
    
        {
            66.14583333333333,
            44.996985817262136,
            0.8268229166666666,
            0.5624623227157767,
            -0.5528549382716049,
            0.8332775151344838
        }
    
        {
            66.984375,
            45.54221674292299,
            0.8269675925925926,
            0.5622495894188023,
            -0.5373263888888888,
            0.8433743841282035
        }
    
        {
            67.83333333333333,
            46.07210532294883,
            0.8272357723577235,
            0.5618549429627906,
            -0.5216049382716049,
            0.8531871356101632
        }
    
        {
            68.69270833333333,
            46.586605605384015,
            0.8276229919678715,
            0.5612844048841448,
            -0.5056905864197532,
            0.8627149186182225
        }
    
        {
            69.5625,
            47.085651675961756,
            0.828125,
            0.560543472332878,
            -0.4895833333333333,
            0.8719565125178103
        }
    
        {
            70.44270833333333,
            47.56915852382646,
            0.8287377450980392,
            0.5596371591038407,
            -0.4732831790123456,
            0.8809103430338231
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            41.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            41.432291666666664,
            6.882238534682167,
            0.9864831349206349,
            0.16386282225433732,
            -0.9921401515151514,
            0.12513160972149392
        }
    
        {
            41.875,
            9.771610665596537,
            0.9738372093023255,
            0.22724675966503574,
            -0.9840909090909091,
            0.17766564846539157
        }
    
        {
            42.328125,
            12.013735222002149,
            0.9620028409090909,
            0.2730394368636852,
            -0.9758522727272727,
            0.21843154949094815
        }
    
        {
            42.791666666666664,
            13.92383797266002,
            0.9509259259259258,
            0.30941862161466716,
            -0.9674242424242423,
            0.25316069041200034
        }
    
        {
            43.265625,
            15.623242088611923,
            0.9405570652173914,
            0.3396356975785201,
            -0.9588068181818182,
            0.2840589470656713
        }
    
        {
            43.75,
            17.173744495595596,
            0.9308510638297872,
            0.3653988190552254,
            -0.95,
            0.3122498999199199
        }
    
        {
            44.244791666666664,
            18.611781493808273,
            0.9217664930555555,
            0.38774544778767234,
            -0.9410037878787878,
            0.3383960271601504
        }
    
        {
            44.75,
            19.96089927833914,
            0.9132653061224489,
            0.40736529139467637,
            -0.9318181818181818,
            0.362925441424348
        }
    
        {
            45.265625,
            21.237306640894342,
            0.9053125,
            0.42474613281788687,
            -0.9224431818181819,
            0.38613284801626074
        }
    
        {
            45.791666666666664,
            22.45268945781082,
            0.897875816993464,
            0.44024881289825135,
            -0.9128787878787878,
            0.40823071741474215
        }
    
        {
            46.328125,
            23.615775108693235,
            0.8909254807692307,
            0.45414952132102376,
            -0.903125,
            0.4293777292489679
        }
    
        {
            46.875,
            24.733264543929497,
            0.8844339622641509,
            0.4666653687533867,
            -0.8931818181818182,
            0.4496957189805363
        }
    
        {
            47.432291666666664,
            25.81041857948577,
            0.8783757716049382,
            0.4779707144349217,
            -0.8830492424242423,
            0.4692803378088321
        }
    
        {
            48.0,
            26.851443164195103,
            0.8727272727272727,
            0.4882080575308201,
            -0.8727272727272727,
            0.4882080575308201
        }
    
        {
            48.578125,
            27.859751820222215,
            0.8674665178571429,
            0.49749556821825386,
            -0.8622159090909091,
            0.5065409421858584
        }
    
        {
            49.166666666666664,
            28.838149886719314,
            0.8625730994152047,
            0.5059324541529704,
            -0.8515151515151514,
            0.5243299979403511
        }
    
        {
            49.765625,
            29.788967225457398,
            0.8580280172413793,
            0.5136028831975413,
            -0.840625,
            0.5416175859174073
        }
    
        {
            50.375,
            30.714155938264035,
            0.8538135593220338,
            0.520578914207865,
            -0.8295454545454546,
            0.5584391988775279
        }
    
        {
            50.994791666666664,
            31.61536371565673,
            0.8499131944444444,
            0.5269227285942788,
            -0.8182765151515151,
            0.5748247948301223
        }
    
        {
            51.625,
            32.493989828889895,
            0.8463114754098361,
            0.532688357850654,
            -0.8068181818181818,
            0.5907998150707253
        }
    
        {
            52.265625,
            33.351228513495194,
            0.8429939516129032,
            0.5379230405402451,
            -0.7951704545454545,
            0.6063859729726399
        }
    
        {
            52.916666666666664,
            34.18810303144778,
            0.8399470899470899,
            0.5426683020864728,
            -0.7833333333333333,
            0.6216018732990506
        }
    
        {
            53.578125,
            35.005492733060834,
            0.837158203125,
            0.5469608239540755,
            -0.7713068181818182,
            0.6364635042374697
        }
    
        {
            54.25,
            35.80415478684003,
            0.8346153846153846,
            0.5508331505667697,
            -0.759090909090909,
            0.6509846324880005
        }
    
        {
            54.932291666666664,
            36.584741795566416,
            0.8323074494949495,
            0.5543142696297941,
            -0.746685606060606,
            0.6651771235557529
        }
    
        {
            55.625,
            37.347816201218514,
            0.8302238805970149,
            0.5574300925555002,
            -0.7340909090909091,
            0.6790512036585185
        }
    
        {
            56.328125,
            38.093862156315616,
            0.8283547794117647,
            0.5602038552399355,
            -0.7213068181818182,
            0.6926156755693749
        }
    
        {
            57.041666666666664,
            38.82329537647325,
            0.8266908212560387,
            0.5626564547314963,
            -0.7083333333333334,
            0.7058780977540591
        }
    
        {
            57.765625,
            39.536471369602204,
            0.8252232142857143,
            0.5648067338514601,
            -0.6951704545454546,
            0.7188449339927674
        }
    
        {
            58.5,
            40.233692348577705,
            0.823943661971831,
            0.5666717232194043,
            -0.6818181818181818,
            0.7315216790650492
        }
    
        {
            59.244791666666664,
            40.91521306767526,
            0.8228443287037037,
            0.5682668481621564,
            -0.6682765151515151,
            0.7439129648668228
        }
    
        {
            60.0,
            41.58124577258358,
            0.821917808219178,
            0.5696061064737477,
            -0.6545454545454545,
            0.7560226504106106
        }
    
        {
            60.765625,
            42.23196441511305,
            0.8211570945945946,
            0.570702221825852,
            -0.640625,
            0.7678538984566009
        }
    
        {
            61.541666666666664,
            42.86750825379158,
            0.8205555555555555,
            0.571566776717221,
            -0.6265151515151516,
            0.7794092409780287
        }
    
        {
            62.328125,
            43.48798493819155,
            0.8201069078947368,
            0.5722103281340993,
            -0.6122159090909091,
            0.7906906352398464
        }
    
        {
            63.125,
            44.09347315646614,
            0.8198051948051948,
            0.5726425085255342,
            -0.5977272727272728,
            0.801699511935748
        }
    
        {
            63.932291666666664,
            44.68402491101562,
            0.8196447649572649,
            0.57287211424379,
            -0.5830492424242424,
            0.8124368165639202
        }
    
        {
            64.75,
            45.25966747557918,
            0.819620253164557,
            0.5729071832351794,
            -0.5681818181818182,
            0.8229030450105306
        }
    
        {
            65.578125,
            45.82040507769846,
            0.8197265625,
            0.5727550634712307,
            -0.553125,
            0.833098274139972
        }
    
        {
            66.41666666666667,
            46.366220342927335,
            0.8199588477366255,
            0.5724224733694733,
            -0.5378787878787878,
            0.8430221880532244
        }
    
        {
            67.265625,
            46.89707553098994,
            0.8203125,
            0.5719155552559748,
            -0.5224431818181818,
            0.8526741005634534
        }
    
        {
            68.125,
            47.412913589021294,
            0.8207831325301205,
            0.5712399227592927,
            -0.5068181818181818,
            0.8620529743458417
        }
    
        {
            68.99479166666667,
            47.91365904283729,
            0.8213665674603176,
            0.5704007028909202,
            -0.49100378787878785,
            0.8711574371424963
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            40.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            40.421875,
            6.860905296269218,
            0.9858993902439024,
            0.1673391535675419,
            -0.9924665178571429,
            0.12251616600480746
        }
    
        {
            40.854166666666664,
            9.743565362444201,
            0.972718253968254,
            0.2319896514867667,
            -0.9847470238095238,
            0.173992238615075
        }
    
        {
            41.296875,
            11.981991288361671,
            0.9603924418604651,
            0.27865096019445745,
            -0.9768415178571429,
            0.21396413014931556
        }
    
        {
            41.75,
            13.890194383089101,
            0.9488636363636364,
            0.31568623597929774,
            -0.96875,
            0.24803918541230538
        }
    
        {
            42.213541666666664,
            15.588999325056031,
            0.9380787037037036,
            0.34642220722346734,
            -0.9604724702380952,
            0.27837498794742915
        }
    
        {
            42.6875,
            17.13993418161225,
            0.9279891304347826,
            0.3726072648176576,
            -0.9520089285714286,
            0.3060702532430759
        }
    
        {
            43.171875,
            18.579268257506133,
            0.9185505319148937,
            0.395303579946939,
            -0.943359375,
            0.33177264745546664
        }
    
        {
            43.666666666666664,
            19.93043457183567,
            0.9097222222222222,
            0.4152173869132431,
            -0.9345238095238094,
            0.3559006173542083
        }
    
        {
            44.171875,
            21.20956055613541,
            0.9014668367346939,
            0.4328481746150084,
            -0.9255022321428571,
            0.37874215278813234
        }
    
        {
            44.6875,
            22.428271082497645,
            0.89375,
            0.4485654216499529,
            -0.9162946428571429,
            0.40050484075888654
        }
    
        {
            45.213541666666664,
            23.595246342358823,
            0.8865400326797385,
            0.4626518890658593,
            -0.9069010416666667,
            0.421343684684979
        }
    
        {
            45.75,
            24.717149916606484,
            0.8798076923076923,
            0.4753298060885862,
            -0.8973214285714286,
            0.44137767708225867
        }
    
        {
            46.296875,
            25.79921249252339,
            0.8735259433962265,
            0.48677759419855454,
            -0.8875558035714286,
            0.46070022308077485
        }
    
        {
            46.854166666666664,
            26.845615395669785,
            0.8676697530864197,
            0.4971410258457368,
            -0.8776041666666666,
            0.479385989208389
        }
    
        {
            47.421875,
            27.859751820222215,
            0.8622159090909091,
            0.5065409421858584,
            -0.8674665178571429,
            0.49749556821825386
        }
    
        {
            48.0,
            28.844410203711913,
            0.8571428571428571,
            0.5150787536377127,
            -0.8571428571428571,
            0.5150787536377127
        }
    
        {
            48.588541666666664,
            29.801906293165167,
            0.8524305555555555,
            0.5228404612835994,
            -0.8466331845238094,
            0.5321768980922351
        }
    
        {
            49.1875,
            30.734180381946093,
            0.8480603448275862,
            0.5298996617576912,
            -0.8359375,
            0.5488246496776088
        }
    
        {
            49.796875,
            31.642870290704902,
            0.8440148305084746,
            0.5363198354356763,
            -0.8250558035714286,
            0.565051255191159
        }
    
        {
            50.416666666666664,
            32.52936707380306,
            0.8402777777777778,
            0.5421561178967177,
            -0.8139880952380951,
            0.5808815548893402
        }
    
        {
            51.046875,
            33.39485817808447,
            0.8368340163934426,
            0.5474566914440077,
            -0.802734375,
            0.5963367531800798
        }
    
        {
            51.6875,
            34.240361326218505,
            0.8336693548387096,
            0.5522638923583629,
            -0.7912946428571429,
            0.6114350236824733
        }
    
        {
            52.338541666666664,
            35.066751435035975,
            0.8307705026455026,
            0.5566151021434281,
            -0.7796688988095237,
            0.6261919899113566
        }
    
        {
            53.0,
            35.874782229304195,
            0.828125,
            0.560543472332878,
            -0.7678571428571429,
            0.6406211112375749
        }
    
        {
            53.671875,
            36.66510376344754,
            0.8257211538461539,
            0.5640785194376544,
            -0.755859375,
            0.6547339957758489
        }
    
        {
            54.354166666666664,
            37.438276749500936,
            0.8235479797979798,
            0.5672466174166808,
            -0.7436755952380952,
            0.668540656241088
        }
    
        {
            55.046875,
            38.19478436559598,
            0.8215951492537313,
            0.570071408441731,
            -0.7313058035714286,
            0.6820497208142139
        }
    
        {
            55.75,
            38.93504205725223,
            0.8198529411764706,
            0.5725741479007681,
            -0.71875,
            0.6952686081652184
        }
    
        {
            56.463541666666664,
            39.65940572495505,
            0.8183121980676328,
            0.5747739960138413,
            -0.7060081845238094,
            0.7082036736599115
        }
    
        {
            57.1875,
            40.36817860332567,
            0.8169642857142857,
            0.5766882657617952,
            -0.6930803571428571,
            0.7208603322022441
        }
    
        {
            57.921875,
            41.06161707098705,
            0.8158010563380281,
            0.5783326348026344,
            -0.6799665178571429,
            0.7332431619819115
        }
    
        {
            58.666666666666664,
            41.73993557999608,
            0.8148148148148148,
            0.5797213274999455,
            -0.6666666666666666,
            0.7453559924999299
        }
    
        {
            59.421875,
            42.40331085521949,
            0.8139982876712328,
            0.5808672719893081,
            -0.6531808035714286,
            0.7572019795574908
        }
    
        {
            60.1875,
            43.051885484261895,
            0.8133445945945946,
            0.5817822362738094,
            -0.6395089285714286,
            0.7687836693618195
        }
    
        {
            60.963541666666664,
            43.68577099533208,
            0.8128472222222222,
            0.5824769466044277,
            -0.6256510416666666,
            0.7801030534880727
        }
    
        {
            61.75,
            44.30505050217187,
            0.8125,
            0.582961190818051,
            -0.6116071428571429,
            0.7911616161102121
        }
    
        {
            62.546875,
            44.90978098069924,
            0.812297077922078,
            0.5832439088402499,
            -0.5973772321428571,
            0.8019603746553435
        }
    
        {
            63.354166666666664,
            45.49999523046373,
            0.812232905982906,
            0.5833332721854324,
            -0.5829613095238095,
            0.8124999148297095
        }
    
        {
            64.171875,
            46.0757035647246,
            0.8123022151898734,
            0.5832367539838557,
            -0.568359375,
            0.8227804207986535
        }
    
        {
            65.0,
            46.636895265444075,
            0.8125,
            0.582961190818051,
            -0.5535714285714286,
            0.8328017011686442
        }
    
        {
            65.83854166666667,
            47.18353983336346,
            0.8128215020576133,
            0.5825128374489317,
            -0.5385974702380953,
            0.8425632113100621
        }
    
        {
            66.6875,
            47.71558805830648,
            0.8132621951219512,
            0.581897415345201,
            -0.5234375,
            0.8520640724697586
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            39.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            39.411458333333336,
            6.836442937663594,
            0.9852864583333334,
            0.17091107344158984,
            -0.9927814327485379,
            0.11993759539760691
        }
    
        {
            39.833333333333336,
            9.711104754638137,
            0.9715447154471545,
            0.23685621352775946,
            -0.9853801169590642,
            0.17037025885330065
        }
    
        {
            40.265625,
            11.94485007688983,
            0.9587053571428571,
            0.2844011923069007,
            -0.977796052631579,
            0.20955877327876896
        }
    
        {
            40.708333333333336,
            13.85032841568105,
            0.9467054263565892,
            0.32210066082979183,
            -0.9700292397660819,
            0.24298821781896582
        }
    
        {
            41.161458333333336,
            15.547808458855663,
            0.9354876893939394,
            0.3533592831558105,
            -0.9620796783625731,
            0.27276856945360817
        }
    
        {
            41.625,
            17.098519672766997,
            0.925,
            0.37996710383926663,
            -0.9539473684210527,
            0.2999740293467894
        }
    
        {
            42.098958333333336,
            18.53854652469453,
            0.9151947463768116,
            0.4030118809716203,
            -0.9456323099415206,
            0.3252376583279743
        }
    
        {
            42.583333333333336,
            19.89119710380001,
            0.9060283687943262,
            0.42321695965531936,
            -0.9371345029239767,
            0.3489683702421055
        }
    
        {
            43.078125,
            21.172509215593106,
            0.8974609375,
            0.441093941991523,
            -0.928453947368421,
            0.37144753009812465
        }
    
        {
            43.583333333333336,
            22.394040625924465,
            0.8894557823129252,
            0.4570212372637646,
            -0.9195906432748538,
            0.3928779057179731
        }
    
        {
            44.098958333333336,
            23.564419660049566,
            0.8819791666666668,
            0.4712883932009913,
            -0.9105445906432749,
            0.41341087122893977
        }
    
        {
            44.625,
            24.69026883207228,
            0.875,
            0.48412291827592707,
            -0.9013157894736842,
            0.4331626110889874
        }
    
        {
            45.161458333333336,
            25.776785703547233,
            0.8684895833333334,
            0.49570741737590834,
            -0.8919042397660819,
            0.452224310588548
        }
    
        {
            45.708333333333336,
            26.82812449443473,
            0.8624213836477987,
            0.5061910281968817,
            -0.8823099415204679,
            0.4706688507795567
        }
    
        {
            46.265625,
            27.847655976031,
            0.8567708333333334,
            0.515697332889463,
            -0.8725328947368421,
            0.48855536800054383
        }
    
        {
            46.833333333333336,
            28.838149886719304,
            0.8515151515151516,
            0.524329997940351,
            -0.8625730994152048,
            0.5059324541529703
        }
    
        {
            47.411458333333336,
            29.80190629316516,
            0.8466331845238095,
            0.532176898092235,
            -0.8524305555555556,
            0.5228404612835994
        }
    
        {
            48.0,
            30.740852297878796,
            0.8421052631578947,
            0.5393131982084,
            -0.8421052631578947,
            0.5393131982084
        }
    
        {
            48.598958333333336,
            31.65661461551014,
            0.8379130747126438,
            0.5458037002674162,
            -0.8315972222222223,
            0.5553792037808797
        }
    
        {
            49.208333333333336,
            32.55057496505331,
            0.8340395480225989,
            0.5517046604246323,
            -0.820906432748538,
            0.5710627186851458
        }
    
        {
            49.828125,
            33.42391298134279,
            0.83046875,
            0.5570652163557132,
            -0.8100328947368421,
            0.5863844382691717
        }
    
        {
            50.458333333333336,
            34.27763990157756,
            0.8271857923497268,
            0.5619285229766813,
            -0.7989766081871346,
            0.6013621035364485
        }
    
        {
            51.098958333333336,
            35.11262532549031,
            0.824176747311828,
            0.5663326665401663,
            -0.7877375730994153,
            0.6160109706226371
        }
    
        {
            51.75,
            35.929618701010455,
            0.8214285714285714,
            0.5703114079525469,
            -0.7763157894736842,
            0.6303441877370255
        }
    
        {
            52.411458333333336,
            36.72926674156814,
            0.8189290364583334,
            0.5738947928370022,
            -0.7647112573099416,
            0.6443731007292657
        }
    
        {
            53.083333333333336,
            37.512127668558364,
            0.8166666666666667,
            0.5771096564393594,
            -0.7529239766081872,
            0.6581075029571644
        }
    
        {
            53.765625,
            38.278682949644114,
            0.8146306818181818,
            0.5799800446915775,
            -0.740953947368421,
            0.6715558412218265
        }
    
        {
            54.458333333333336,
            39.02934704239305,
            0.8128109452736318,
            0.5825275677969112,
            -0.7288011695906433,
            0.68472538670865
        }
    
        {
            55.161458333333336,
            39.76447553457646,
            0.8111979166666667,
            0.5847716990378892,
            -0.7164656432748538,
            0.6976223777995871
        }
    
        {
            55.875,
            40.48437198475481,
            0.8097826086956522,
            0.5867300287645625,
            -0.7039473684210527,
            0.7102521400834177
        }
    
        {
            56.598958333333336,
            41.18929370093152,
            0.8085565476190476,
            0.5884184814418789,
            -0.6912463450292398,
            0.7226191877356407
        }
    
        {
            57.333333333333336,
            41.87945664510093,
            0.8075117370892019,
            0.5898515020436751,
            -0.6783625730994153,
            0.7347273095631743
        }
    
        {
            58.078125,
            42.55503961323941,
            0.806640625,
            0.5910422168505474,
            -0.665296052631579,
            0.7465796423375335
        }
    
        {
            58.833333333333336,
            43.21618781069067,
            0.8059360730593608,
            0.5920025727491872,
            -0.652046783625731,
            0.7581787335208889
        }
    
        {
            59.598958333333336,
            43.86301591981104,
            0.8053913288288289,
            0.5927434583758249,
            -0.6386147660818714,
            0.7695265950844044
        }
    
        {
            60.375,
            44.49561073858859,
            0.805,
            0.5932748098478479,
            -0.625,
            0.7806247497997998
        }
    
        {
            61.161458333333336,
            45.11403345456855,
            0.8047560307017544,
            0.5936057033495862,
            -0.611202485380117,
            0.7914742711327817
        }
    
        {
            61.958333333333336,
            45.71832160693955,
            0.8046536796536797,
            0.5937444364537604,
            -0.5972222222222222,
            0.8020758176656061
        }
    
        {
            62.765625,
            46.308490780410615,
            0.8046875,
            0.5936985997488541,
            -0.5830592105263158,
            0.8124296628142214
        }
    
        {
            63.583333333333336,
            46.8845360670469,
            0.8048523206751055,
            0.5934751400892013,
            -0.5687134502923977,
            0.8225357204745072
        }
    
        {
            64.41145833333333,
            47.446433326154924,
            0.8051432291666666,
            0.5930804165769366,
            -0.5541849415204678,
            0.8323935671255249
        }
    
        {
            65.25,
            47.99414026732847,
            0.8055555555555556,
            0.5925202502139317,
            -0.5394736842105263,
            0.842002460830324
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            38.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            38.401041666666664,
            6.808817732538495,
            0.9846420940170939,
            0.1745850700650896,
            -0.9930854885057471,
            0.11739340918169817
        }
    
        {
            38.8125,
            9.674184397146872,
            0.9703125,
            0.2418546099286718,
            -0.9859913793103449,
            0.16679628270942884
        }
    
        {
            39.234375,
            11.90226106079744,
            0.9569359756097561,
            0.2902990502633522,
            -0.9787176724137931,
            0.20521139759995585
        }
    
        {
            39.666666666666664,
            13.804186160565774,
            0.9444444444444444,
            0.3286710990610898,
            -0.9712643678160918,
            0.2380032096649271
        }
    
        {
            40.109375,
            15.499614095498474,
            0.9327761627906976,
            0.36045614175577845,
            -0.9636314655172413,
            0.26723472578445645
        }
    
        {
            40.5625,
            17.04944555550121,
            0.921875,
            0.3874873989886639,
            -0.9558189655172413,
            0.2939559578534692
        }
    
        {
            41.026041666666664,
            18.489562059846918,
            0.9116898148148148,
            0.41087915688548704,
            -0.9478268678160919,
            0.3187855527559813
        }
    
        {
            41.5,
            19.84313483298443,
            0.9021739130434783,
            0.4313724963692267,
            -0.9396551724137931,
            0.3421230143618005
        }
    
        {
            41.984375,
            21.126103660149333,
            0.8932845744680851,
            0.44949156723721984,
            -0.9313038793103449,
            0.36424316655429884
        }
    
        {
            42.479166666666664,
            22.349953004549153,
            0.8849826388888888,
            0.46562402092810734,
            -0.9227729885057471,
            0.38534401731981294
        }
    
        {
            42.984375,
            23.523254576256555,
            0.8772321428571429,
            0.48006641992360316,
            -0.9140625,
            0.40557335476304407
        }
    
        {
            43.5,
            24.6525860712421,
            0.87,
            0.49305172142484205,
            -0.9051724137931034,
            0.4250445874352086
        }
    
        {
            44.026041666666664,
            25.74310888694158,
            0.8632557189542484,
            0.5047668409204231,
            -0.8961027298850573,
            0.4438467049472686
        }
    
        {
            44.5625,
            26.798947623927326,
            0.8569711538461539,
            0.5153643773832178,
            -0.8868534482758621,
            0.46205082110219525
        }
    
        {
            45.109375,
            27.82344851217,
            0.8511202830188679,
            0.524970726644717,
            -0.8774245689655172,
            0.4797146295201724
        }
    
        {
            45.666666666666664,
            28.81936077631764,
            0.845679012345679,
            0.5336918662281045,
            -0.8678160919540229,
            0.49688553062616614
        }
    
        {
            46.234375,
            29.788967225457398,
            0.840625,
            0.5416175859174073,
            -0.8580280172413793,
            0.5136028831975413
        }
    
        {
            46.8125,
            30.734180381946093,
            0.8359375,
            0.5488246496776088,
            -0.8480603448275862,
            0.5298996617576912
        }
    
        {
            47.401041666666664,
            31.656614615510147,
            0.8315972222222222,
            0.5553792037808798,
            -0.8379130747126436,
            0.5458037002674163
        }
    
        {
            48.0,
            32.55764119219941,
            0.8275862068965517,
            0.5613386412448175,
            -0.8275862068965517,
            0.5613386412448175
        }
    
        {
            48.609375,
            33.43843091577975,
            0.8238877118644068,
            0.5667530663691482,
            -0.8170797413793104,
            0.5765246709617198
        }
    
        {
            49.229166666666664,
            34.29998759920411,
            0.820486111111111,
            0.5716664599867352,
            -0.8063936781609194,
            0.5913790965380018
        }
    
        {
            49.859375,
            35.143174651834954,
            0.8173668032786885,
            0.576117617243196,
            -0.7955280172413793,
            0.6059168043419819
        }
    
        {
            50.5,
            35.968736424845396,
            0.8145161290322581,
            0.5801409100781515,
            -0.7844827586206896,
            0.6201506280145758
        }
    
        {
            51.151041666666664,
            36.777315513981314,
            0.8119212962962963,
            0.5837669129203383,
            -0.7732579022988506,
            0.6340916467927813
        }
    
        {
            51.8125,
            37.5694669079826,
            0.8095703125,
            0.5870229204372281,
            -0.7618534482758621,
            0.6477494294479759
        }
    
        {
            52.484375,
            38.3456696493799,
            0.807451923076923,
            0.5899333792212292,
            -0.7502693965517241,
            0.6611322353341362
        }
    
        {
            53.166666666666664,
            39.1063365141195,
            0.8055555555555555,
            0.5925202502139317,
            -0.7385057471264367,
            0.6742471812779223
        }
    
        {
            53.859375,
            39.85182209898783,
            0.8038712686567164,
            0.5948033149102662,
            -0.7265625,
            0.6871003810170315
        }
    
        {
            54.5625,
            40.58242961861697,
            0.8023897058823529,
            0.5968004355678966,
            -0.7144396551724138,
            0.6996970623899478
        }
    
        {
            55.276041666666664,
            41.29841664840107,
            0.8011020531400966,
            0.5985277775130591,
            -0.7021372126436781,
            0.7120416663517426
        }
    
        {
            56.0,
            42.0,
            0.8,
            0.6,
            -0.6896551724137931,
            0.7241379310344828
        }
    
        {
            56.734375,
            42.68735987806431,
            0.7990757042253521,
            0.6012304208178072,
            -0.6769935344827587,
            0.7359889634149019
        }
    
        {
            57.479166666666664,
            43.36064343740249,
            0.7983217592592592,
            0.6022311588528123,
            -0.6641522988505748,
            0.7475973006448705
        }
    
        {
            58.234375,
            44.01996783687347,
            0.7977311643835616,
            0.6030132580393626,
            -0.6511314655172413,
            0.758964962704715
        }
    
        {
            59.0,
            44.66542286825459,
            0.7972972972972973,
            0.6035867955169539,
            -0.6379310344827587,
            0.7700934977285274
        }
    
        {
            59.776041666666664,
            45.29707322404982,
            0.7970138888888889,
            0.6039609763206643,
            -0.6245510057471264,
            0.7809840211043071
        }
    
        {
            60.5625,
            45.91496045680536,
            0.796875,
            0.6041442165369126,
            -0.6109913793103449,
            0.7916372492552648
        }
    
        {
            61.359375,
            46.51910467334228,
            0.796875,
            0.6041442165369126,
            -0.5972521551724137,
            0.8020535288507288
        }
    
        {
            62.166666666666664,
            47.10950599990999,
            0.797008547008547,
            0.6039680256398717,
            -0.5833333333333334,
            0.8122328620674136
        }
    
        {
            62.984375,
            47.686145848237466,
            0.7972705696202531,
            0.6036220993447781,
            -0.5692349137931034,
            0.8221749284178872
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            37.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            37.390625,
            6.777991008357491,
            0.9839638157894737,
            0.1783681844304603,
            -0.9933792372881356,
            0.1148812035314829
        }
    
        {
            37.791666666666664,
            9.632753010201998,
            0.9690170940170939,
            0.24699366692825636,
            -0.9865819209039547,
            0.1632670001729152
        }
    
        {
            38.203125,
            11.854165522480905,
            0.955078125,
            0.2963541380620226,
            -0.9796080508474576,
            0.20091805970306617
        }
    
        {
            38.625,
            13.751704439813997,
            0.9420731707317073,
            0.335407425361317,
            -0.972457627118644,
            0.23307973626803385
        }
    
        {
            39.057291666666664,
            15.444350671521631,
            0.9299355158730158,
            0.3677226350362293,
            -0.965130649717514,
            0.26176865544951916
        }
    
        {
            39.5,
            16.99264546796643,
            0.9186046511627907,
            0.39517780158061466,
            -0.9576271186440678,
            0.2880109401350242
        }
    
        {
            39.953125,
            18.43224898742351,
            0.9080255681818182,
            0.4189147497141707,
            -0.949947033898305,
            0.31241099978683917
        }
    
        {
            40.416666666666664,
            19.786183450972946,
            0.8981481481481481,
            0.4396929655771766,
            -0.9420903954802259,
            0.3353590415419143
        }
    
        {
            40.890625,
            21.070282084238336,
            0.8889266304347826,
            0.45804961052692034,
            -0.9340572033898306,
            0.35712342515658196
        }
    
        {
            41.375,
            22.295949744292123,
            0.8803191489361702,
            0.4743819094530239,
            -0.9258474576271186,
            0.3778974532930868
        }
    
        {
            41.869791666666664,
            23.471696696019457,
            0.8722873263888888,
            0.48899368116707204,
            -0.9174611581920903,
            0.3978253677291433
        }
    
        {
            42.375,
            24.60405200368427,
            0.8647959183673469,
            0.5021235102792708,
            -0.9088983050847458,
            0.41701783057091985
        }
    
        {
            42.890625,
            25.698137814039658,
            0.8578125,
            0.5139627562807931,
            -0.9001588983050848,
            0.43556165786507894
        }
    
        {
            43.416666666666664,
            26.758046557167727,
            0.8513071895424836,
            0.5246675795523084,
            -0.8912429378531073,
            0.45352621283335126
        }
    
        {
            43.953125,
            27.78709777458551,
            0.8452524038461539,
            0.5343672648958753,
            -0.8821504237288136,
            0.47096775889127984
        }
    
        {
            44.5,
            28.788018340969565,
            0.839622641509434,
            0.5431701573767842,
            -0.8728813559322034,
            0.4879325142537214
        }
    
        {
            45.057291666666664,
            29.76307221482572,
            0.8343942901234568,
            0.551168003978254,
            -0.8634357344632768,
            0.5044588510987409
        }
    
        {
            45.625,
            30.714155938264035,
            0.8295454545454546,
            0.5584391988775279,
            -0.8538135593220338,
            0.520578914207865
        }
    
        {
            46.203125,
            31.642870290704902,
            0.8250558035714286,
            0.565051255191159,
            -0.8440148305084746,
            0.5363198354356763
        }
    
        {
            46.791666666666664,
            32.550574965053315,
            0.8209064327485379,
            0.5710627186851459,
            -0.8340395480225988,
            0.5517046604246324
        }
    
        {
            47.390625,
            33.43843091577975,
            0.8170797413793104,
            0.5765246709617198,
            -0.8238877118644068,
            0.5667530663691482
        }
    
        {
            48.0,
            34.307433596816885,
            0.8135593220338984,
            0.5814819253697777,
            -0.8135593220338984,
            0.5814819253697777
        }
    
        {
            48.619791666666664,
            35.15843936084096,
            0.810329861111111,
            0.5859739893473493,
            -0.8030543785310734,
            0.5959057518786602
        }
    
        {
            49.25,
            35.99218665210548,
            0.8073770491803278,
            0.5900358467558275,
            -0.7923728813559322,
            0.6100370619000929
        }
    
        {
            49.890625,
            36.80931318442895,
            0.8046875,
            0.5936985997488541,
            -0.7815148305084746,
            0.6238866641428635
        }
    
        {
            50.541666666666664,
            37.610369986953806,
            0.8022486772486772,
            0.5969899997929176,
            -0.7704802259887005,
            0.6374638980839628
        }
    
        {
            51.203125,
            38.39583298008229,
            0.800048828125,
            0.5999348903137858,
            -0.7592690677966102,
            0.6507768301708863
        }
    
        {
            51.875,
            39.16611258473325,
            0.7980769230769231,
            0.6025555782266654,
            -0.7478813559322034,
            0.6638324166903941
        }
    
        {
            52.557291666666664,
            39.921561751325946,
            0.796322601010101,
            0.6048721477473629,
            -0.7363170903954802,
            0.6766366398529822
        }
    
        {
            53.25,
            40.662482708265614,
            0.7947761194029851,
            0.606902726989039,
            -0.7245762711864406,
            0.6891946221739934
        }
    
        {
            53.953125,
            41.38913266467872,
            0.7934283088235294,
            0.60866371565704,
            -0.7126588983050848,
            0.7015107231301477
        }
    
        {
            54.666666666666664,
            42.101728652818466,
            0.7922705314009661,
            0.61016998047563,
            -0.7005649717514125,
            0.7135886212342113
        }
    
        {
            55.390625,
            42.80045165777313,
            0.7912946428571429,
            0.6114350236824733,
            -0.6882944915254238,
            0.725431384030053
        }
    
        {
            56.125,
            43.48545015289597,
            0.7904929577464789,
            0.6124711289140278,
            -0.6758474576271186,
            0.737041528015186
        }
    
        {
            56.869791666666664,
            44.15684313659583,
            0.7898582175925926,
            0.6132894880082754,
            -0.6632238700564972,
            0.7484210701117937
        }
    
        {
            57.625,
            44.814722748221925,
            0.7893835616438356,
            0.6139003116194784,
            -0.6504237288135594,
            0.7595715720037615
        }
    
        {
            58.390625,
            45.459156526594015,
            0.7890625,
            0.6143129260350543,
            -0.637447033898305,
            0.7704941784168478
        }
    
        {
            59.166666666666664,
            46.09018936341611,
            0.7888888888888889,
            0.6145358581788815,
            -0.6242937853107345,
            0.7811896502273916
        }
    
        {
            59.953125,
            46.70784519472478,
            0.7888569078947368,
            0.614576910456905,
            -0.6109639830508474,
            0.7916583931309286
        }
    
        {
            60.75,
            47.31212846617662,
            0.788961038961039,
            0.6144432268334625,
            -0.5974576271186441,
            0.8019004824775698
        }
    
        {
            61.557291666666664,
            47.903025402002854,
            0.789196047008547,
            0.6141413513077288,
            -0.5837747175141244,
            0.8119156847797094
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            36.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        }
    
        {
            36.380208333333336,
            6.743918862446647,
            0.9832488738738739,
            0.1822680773634229,
            -0.9936631944444445,
            0.11239864770744414
        }
    
        {
            36.770833333333336,
            9.586752107581688,
            0.9676535087719299,
            0.25228295019951813,
            -0.9871527777777779,
            0.15977920179302815
        }
    
        {
            37.171875,
            11.800496132975724,
            0.953125,
            0.30257682392245444,
            -0.98046875,
            0.1966749355495954
        }
    
        {
            37.583333333333336,
            13.692810360023081,
            0.9395833333333334,
            0.34232025900057705,
            -0.9736111111111111,
            0.22821350600038467
        }
    
        {
            38.005208333333336,
            15.381941995077554,
            0.9269563008130082,
            0.37516931695311106,
            -0.966579861111111,
            0.2563656999179592
        }
    
        {
            38.4375,
            16.928041639539998,
            0.9151785714285714,
            0.40304861046523804,
            -0.959375,
            0.2821340273256666
        }
    
        {
            38.880208333333336,
            18.36652933889789,
            0.9041908914728682,
            0.4271285892766951,
            -0.9519965277777779,
            0.3061088223149649
        }
    
        {
            39.333333333333336,
            19.72026594366538,
            0.893939393939394,
            0.4481878623560314,
            -0.9444444444444445,
            0.3286710990610897
        }
    
        {
            39.796875,
            21.004969417601515,
            0.884375,
            0.46677709816892254,
            -0.93671875,
            0.3500828236266919
        }
    
        {
            40.270833333333336,
            22.231958587557884,
            0.8754528985507247,
            0.48330344755560617,
            -0.9288194444444445,
            0.3705326431259648
        }
    
        {
            40.755208333333336,
            23.40967735161245,
            0.8671320921985816,
            0.4980782415236692,
            -0.9207465277777779,
            0.3901612891935409
        }
    
        {
            41.25,
            24.544602257930357,
            0.859375,
            0.5113458803735491,
            -0.9125,
            0.4090767042988393
        }
    
        {
            41.755208333333336,
            25.641813060700883,
            0.8521471088435375,
            0.5233023073612425,
            -0.904079861111111,
            0.4273635510116814
        }
    
        {
            42.270833333333336,
            26.70536742502442,
            0.8454166666666667,
            0.5341073485004884,
            -0.8954861111111111,
            0.4450894570837403
        }
    
        {
            42.796875,
            27.738556022878605,
            0.8391544117647058,
            0.5438932553505609,
            -0.88671875,
            0.46230926704797676
        }
    
        {
            43.333333333333336,
            28.74408151641346,
            0.8333333333333334,
            0.5527707983925665,
            -0.8777777777777779,
            0.4790680252735577
        }
    
        {
            43.880208333333336,
            29.72418740055418,
            0.8279284591194969,
            0.5608337245387581,
            -0.8686631944444445,
            0.4954031233425697
        }
    
        {
            44.4375,
            30.68075282241295,
            0.8229166666666666,
            0.5681620893039435,
            -0.859375,
            0.5113458803735491
        }
    
        {
            45.005208333333336,
            31.615363715656724,
            0.8182765151515152,
            0.5748247948301223,
            -0.8499131944444445,
            0.5269227285942788
        }
    
        {
            45.583333333333336,
            32.52936707380305,
            0.8139880952380952,
            0.5808815548893402,
            -0.8402777777777778,
            0.5421561178967176
        }
    
        {
            46.171875,
            33.42391298134279,
            0.8100328947368421,
            0.5863844382691717,
            -0.83046875,
            0.5570652163557132
        }
    
        {
            46.770833333333336,
            34.2999875992041,
            0.8063936781609196,
            0.5913790965380017,
            -0.8204861111111111,
            0.571666459986735
        }
    
        {
            47.380208333333336,
            35.15843936084095,
            0.8030543785310735,
            0.5959057518786602,
            -0.8103298611111112,
            0.5859739893473492
        }
    
        {
            48.0,
            36.0,
            0.8,
            0.6,
            -0.8,
            0.6
        }
    
        {
            48.630208333333336,
            36.825301593559246,
            0.7972165300546449,
            0.6036934687468729,
            -0.7894965277777778,
            0.6137550265593208
        }
    
        {
            49.270833333333336,
            37.6348904959067,
            0.7946908602150538,
            0.6070143628372049,
            -0.7788194444444445,
            0.6272481749317784
        }
    
        {
            49.921875,
            38.429238822599324,
            0.7924107142857143,
            0.6099879178190368,
            -0.76796875,
            0.6404873137099887
        }
    
        {
            50.583333333333336,
            39.20875398286572,
            0.7903645833333334,
            0.6126367809822769,
            -0.7569444444444445,
            0.6534792330477621
        }
    
        {
            51.255208333333336,
            39.97378664458244,
            0.7885416666666667,
            0.614981332993576,
            -0.7457465277777777,
            0.6662297774097073
        }
    
        {
            51.9375,
            40.72463742932526,
            0.7869318181818182,
            0.6170399610503827,
            -0.734375,
            0.678743957155421
        }
    
        {
            52.630208333333336,
            41.461562570529466,
            0.7855254975124378,
            0.6188292920974547,
            -0.7228298611111111,
            0.6910260428421579
        }
    
        {
            53.333333333333336,
            42.18477871881699,
            0.7843137254901961,
            0.6203643929237793,
            -0.7111111111111111,
            0.7030796453136167
        }
    
        {
            54.046875,
            42.89446704103427,
            0.7832880434782609,
            0.621658942623685,
            -0.69921875,
            0.7149077840172378
        }
    
        {
            54.770833333333336,
            43.59077673054499,
            0.7824404761904762,
            0.6227253818649284,
            -0.6871527777777777,
            0.7265129455090832
        }
    
        {
            55.505208333333336,
            44.273828023712426,
            0.7817634976525822,
            0.623575042587499,
            -0.6749131944444445,
            0.7378971337285405
        }
    
        {
            56.25,
            44.9437147997359,
            0.78125,
            0.624218261107443,
            -0.6625,
            0.7490619133289317
        }
    
        {
            57.005208333333336,
            45.6005068269341,
            0.7808932648401827,
            0.624664477081289,
            -0.6499131944444445,
            0.7600084471155685
        }
    
        {
            57.770833333333336,
            46.24425170734436,
            0.7806869369369369,
            0.6249223203695184,
            -0.6371527777777778,
            0.7707375284557394
        }
    
        {
            58.546875,
            46.87497656249414,
            0.780625,
            0.6249996874999219,
            -0.62421875,
            0.7812496093749023
        }
    
        {
            59.333333333333336,
            47.492689495916686,
            0.7807017543859649,
            0.6249038091567986,
            -0.6111111111111112,
            0.7915448249319449
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
    },

    {
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        }
    
        {
            NAN,
        }
