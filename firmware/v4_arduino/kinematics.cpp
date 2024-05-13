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

const LocalKinematics lookupTable[108][108] = {

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            0.0,
            0.0,
            NAN,
            NAN,
            -1.0,
            0.0
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            1.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            0.005208333333333333,
            0.9999864365399607,
            0.005208333333333334,
            0.9999864365399608,
            -0.9999457465277778,
            0.01041652538062459
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            2.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            1.015625,
            1.7229352452646036,
            0.5078125,
            0.8614676226323018,
            -0.9998355263157894,
            0.01813616047646951
        },
    
        {
            true,
            0.020833333333333332,
            1.9998914901119567,
            0.010416666666666666,
            0.9999457450559783,
            -0.999782986111111,
            0.020832203021999545
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            3.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            2.0260416666666665,
            2.2124997547865526,
            0.6753472222222222,
            0.7374999182621842,
            -0.9997229609929079,
            0.0235372314338995
        },
    
        {
            true,
            1.0416666666666667,
            2.8133486373991325,
            0.34722222222222227,
            0.9377828791330441,
            -0.999561403508772,
            0.02961419618314877
        },
    
        {
            true,
            0.046875,
            2.9996337667080293,
            0.015625,
            0.9998779222360098,
            -0.99951171875,
            0.031246185069875306
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            4.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            3.0364583333333335,
            2.6038281029919306,
            0.7591145833333334,
            0.6509570257479826,
            -0.9996079749103943,
            0.027998151645074524
        },
    
        {
            true,
            2.0625,
            3.427257467713799,
            0.515625,
            0.8568143669284497,
            -0.9993351063829787,
            0.03646018582674254
        },
    
        {
            true,
            1.078125,
            3.8519665736315782,
            0.26953125,
            0.9629916434078946,
            -0.9991776315789473,
            0.04054701656454293
        },
    
        {
            true,
            0.08333333333333333,
            3.9991318502339426,
            0.020833333333333332,
            0.9997829625584856,
            -0.9991319444444445,
            0.041657623439936904
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            5.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            4.046875,
            2.936460919946833,
            0.809375,
            0.5872921839893666,
            -0.9994904891304348,
            0.031918053477682964
        },
    
        {
            true,
            3.0833333333333335,
            3.936121892873181,
            0.6166666666666667,
            0.7872243785746362,
            -0.9991039426523298,
            0.042323891321217
        },
    
        {
            true,
            2.109375,
            4.533270023876253,
            0.421875,
            0.9066540047752506,
            -0.9988364361702128,
            0.04822627684974737
        },
    
        {
            true,
            1.125,
            4.871793817476269,
            0.225,
            0.9743587634952539,
            -0.9986842105263158,
            0.05128204018396073
        },
    
        {
            true,
            0.13020833333333334,
            4.9983042914503075,
            0.026041666666666668,
            0.9996608582900615,
            -0.9986436631944445,
            0.05206566970260737
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            6.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            5.057291666666667,
            3.2285911785582093,
            0.8428819444444445,
            0.5380985297597015,
            -0.9993704212454213,
            0.03547902394020011
        },
    
        {
            true,
            4.104166666666667,
            4.376735766781246,
            0.6840277777777778,
            0.7294559611302076,
            -0.9988677536231884,
            0.04757321485631789
        },
    
        {
            true,
            3.140625,
            5.112384434818551,
            0.5234375,
            0.8520640724697586,
            -0.9984879032258065,
            0.05497187564321023
        },
    
        {
            true,
            2.1666666666666665,
            5.595136777198173,
            0.3611111111111111,
            0.9325227961996955,
            -0.9982269503546101,
            0.05952273167232099
        },
    
        {
            true,
            1.1822916666666667,
            5.882362315849862,
            0.19704861111111113,
            0.9803937193083104,
            -0.9980811403508772,
            0.0619196033247354
        },
    
        {
            true,
            0.1875,
            5.997069596894804,
            0.03125,
            0.9995115994824673,
            -0.998046875,
            0.062469474967654204
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            7.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            6.067708333333333,
            3.4904033551435325,
            0.8668154761904762,
            0.49862905073479036,
            -0.9992476851851853,
            0.03878225950159481
        },
    
        {
            true,
            5.125,
            4.768057780690163,
            0.7321428571428571,
            0.6811511115271661,
            -0.9986263736263736,
            0.05239623934824355
        },
    
        {
            true,
            4.171875,
            5.620983809296643,
            0.5959821428571429,
            0.8029976870423775,
            -0.9981317934782609,
            0.06109765010105046
        },
    
        {
            true,
            3.2083333333333335,
            6.221462627246283,
            0.45833333333333337,
            0.8887803753208976,
            -0.9977598566308242,
            0.06689744760479874
        },
    
        {
            true,
            2.234375,
            6.6338200427336735,
            0.31919642857142855,
            0.947688577533382,
            -0.9975066489361702,
            0.0705725536461029
        },
    
        {
            true,
            1.25,
            6.887488656977955,
            0.1785714285714286,
            0.9839269509968508,
            -0.9973684210526316,
            0.07249988059976795
        },
    
        {
            true,
            0.2552083333333333,
            6.995346217779161,
            0.03645833333333333,
            0.9993351739684516,
            -0.997341579861111,
            0.07286818976853292
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            8.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            7.078125,
            3.7282900214944386,
            0.884765625,
            0.4660362526868048,
            -0.999122191011236,
            0.04189089911791504
        },
    
        {
            true,
            6.145833333333333,
            5.121399480502268,
            0.7682291666666666,
            0.6401749350627834,
            -0.9983796296296297,
            0.05690443867224742
        },
    
        {
            true,
            5.203125,
            6.076799341295959,
            0.650390625,
            0.7595999176619949,
            -0.9977678571428571,
            0.06677801473951603
        },
    
        {
            true,
            4.25,
            6.777720855862979,
            0.5312500000000001,
            0.8472151069828725,
            -0.9972826086956522,
            0.07367087886807586
        },
    
        {
            true,
            3.2864583333333335,
            7.293777596229809,
            0.4108072916666667,
            0.9117221995287261,
            -0.9969198028673836,
            0.07842771608849257
        },
    
        {
            true,
            2.3125,
            7.658481817566717,
            0.2890625,
            0.9573102271958396,
            -0.9966755319148937,
            0.08147321082517783
        },
    
        {
            true,
            1.328125,
            7.888984978080196,
            0.16601562500000003,
            0.9861231222600246,
            -0.9965460526315789,
            0.08304194713768627
        },
    
        {
            true,
            0.3333333333333333,
            7.993052538854532,
            0.041666666666666664,
            0.9991315673568165,
            -0.9965277777777778,
            0.08326096394640138
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            9.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            8.088541666666666,
            3.946580001291907,
            0.8987268518518517,
            0.4385088890324341,
            -0.9989938446969696,
            0.04484750001468076
        },
    
        {
            true,
            7.166666666666667,
            5.444160990353692,
            0.7962962962962963,
            0.6049067767059657,
            -0.99812734082397,
            0.061170348206221255
        },
    
        {
            true,
            6.234375,
            6.4909605113091695,
            0.6927083333333334,
            0.7212178345899077,
            -0.9973958333333334,
            0.07212178345899077
        },
    
        {
            true,
            5.291666666666667,
            7.279990651703399,
            0.587962962962963,
            0.8088878501892666,
            -0.9967948717948719,
            0.07999989727146593
        },
    
        {
            true,
            4.338541666666667,
            7.88524293897133,
            0.48206018518518523,
            0.8761381043301477,
            -0.9963201992753623,
            0.08570916238012315
        },
    
        {
            true,
            3.375,
            8.34322329798262,
            0.375,
            0.9270248108869578,
            -0.9959677419354839,
            0.0897120784729314
        },
    
        {
            true,
            2.4010416666666665,
            8.673811095183625,
            0.2667824074074074,
            0.9637567883537361,
            -0.9957335992907802,
            0.09227458611897475
        },
    
        {
            true,
            1.4166666666666667,
            8.887803753208976,
            0.1574074074074074,
            0.9875337503565529,
            -0.9956140350877194,
            0.09355582898114713
        },
    
        {
            true,
            0.421875,
            8.990106867238843,
            0.046875,
            0.9989007630265382,
            -0.99560546875,
            0.09364694653373795
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            10.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            9.098958333333334,
            4.148368022278625,
            0.9098958333333333,
            0.41483680222786246,
            -0.9988625478927203,
            0.047682391060673845
        },
    
        {
            true,
            8.1875,
            5.741501872332709,
            0.81875,
            0.5741501872332708,
            -0.9978693181818182,
            0.06524433945832624
        },
    
        {
            true,
            7.265625,
            6.871003810170316,
            0.7265625,
            0.6871003810170315,
            -0.9970154494382022,
            0.07720229000191366
        },
    
        {
            true,
            6.333333333333333,
            7.7387911774959335,
            0.6333333333333333,
            0.7738791177495934,
            -0.9962962962962963,
            0.0859865686388437
        },
    
        {
            true,
            5.390625,
            8.422657663076127,
            0.5390625,
            0.8422657663076126,
            -0.9957074175824175,
            0.09255667761622118
        },
    
        {
            true,
            4.4375,
            8.961506221054583,
            0.44375,
            0.8961506221054583,
            -0.9952445652173914,
            0.09740767631581068
        },
    
        {
            true,
            3.4739583333333335,
            9.377185798429286,
            0.34739583333333335,
            0.9377185798429286,
            -0.9949036738351255,
            0.10082995482182028
        },
    
        {
            true,
            2.5,
            9.682458365518542,
            0.25,
            0.9682458365518543,
            -0.9946808510638298,
            0.10300487622892066
        },
    
        {
            true,
            1.515625,
            9.88447676204335,
            0.1515625,
            0.988447676204335,
            -0.9945723684210527,
            0.10404712381098263
        },
    
        {
            true,
            0.5208333333333334,
            9.98642742119968,
            0.052083333333333336,
            0.9986427421199681,
            -0.9945746527777778,
            0.10402528563749668
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            11.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            10.109375,
            4.335958614813453,
            0.9190340909090909,
            0.3941780558921321,
            -0.9987281976744186,
            0.050418123428063406
        },
    
        {
            true,
            9.208333333333334,
            6.017191805337621,
            0.8371212121212122,
            0.5470174368488746,
            -0.9976053639846744,
            0.069163124199283
        },
    
        {
            true,
            8.296875,
            7.2223171651745535,
            0.7542613636363636,
            0.6565742877431412,
            -0.9966264204545454,
            0.08207178596789265
        },
    
        {
            true,
            7.375,
            8.161456671452713,
            0.6704545454545454,
            0.7419506064957012,
            -0.9957865168539326,
            0.09170176035340127
        },
    
        {
            true,
            6.442708333333333,
            8.91580110430898,
            0.5857007575757576,
            0.8105273731189981,
            -0.9950810185185186,
            0.09906445671454421
        },
    
        {
            true,
            5.5,
            9.526279441628825,
            0.5,
            0.8660254037844386,
            -0.9945054945054945,
            0.10468438946844863
        },
    
        {
            true,
            4.546875,
            10.016283129703103,
            0.4133522727272727,
            0.910571193609373,
            -0.9940557065217391,
            0.10887264271416416
        },
    
        {
            true,
            3.5833333333333335,
            10.399986645290571,
            0.32575757575757575,
            0.9454533313900519,
            -0.9937275985663081,
            0.11182781339022119
        },
    
        {
            true,
            2.609375,
            10.686026488333958,
            0.2372159090909091,
            0.9714569534849052,
            -0.9935172872340425,
            0.11368113285461658
        },
    
        {
            true,
            1.625,
            10.879309490955757,
            0.14772727272727273,
            0.9890281355414324,
            -0.993421052631579,
            0.1145190472732185
        },
    
        {
            true,
            0.6302083333333334,
            10.9819323188862,
            0.05729166666666667,
            0.9983574835351091,
            -0.993435329861111,
            0.11439512832173122
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            12.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            11.119791666666666,
            4.511123284718627,
            0.9266493055555555,
            0.3759269403932189,
            -0.9985906862745098,
            0.05307203864374855
        },
    
        {
            true,
            10.229166666666666,
            6.274085535403193,
            0.8524305555555555,
            0.5228404612835994,
            -0.9973352713178294,
            0.07295448296980457
        },
    
        {
            true,
            9.328125,
            7.548912768364396,
            0.77734375,
            0.6290760640303663,
            -0.9962284482758621,
            0.08676911228005052
        },
    
        {
            true,
            8.416666666666666,
            8.553345674192188,
            0.7013888888888888,
            0.7127788061826824,
            -0.9952651515151515,
            0.09719710993400214
        },
    
        {
            true,
            7.494791666666667,
            9.371664626589231,
            0.6245659722222222,
            0.7809720522157693,
            -0.994440543071161,
            0.10529960254594642
        },
    
        {
            true,
            6.5625,
            10.04657124346411,
            0.546875,
            0.8372142702886758,
            -0.99375,
            0.11162856937182344
        },
    
        {
            true,
            5.619791666666667,
            10.602732743178237,
            0.46831597222222227,
            0.8835610619315197,
            -0.9931891025641025,
            0.11651354662833227
        },
    
        {
            true,
            4.666666666666667,
            11.055415967851333,
            0.3888888888888889,
            0.9212846639876111,
            -0.9927536231884058,
            0.12016756486794927
        },
    
        {
            true,
            3.703125,
            11.41432719148943,
            0.30859375,
            0.9511939326241192,
            -0.9924395161290323,
            0.12273470098375731
        },
    
        {
            true,
            2.7291666666666665,
            11.685531622718564,
            0.22743055555555555,
            0.9737943018932137,
            -0.9922429078014185,
            0.12431416619913367
        },
    
        {
            true,
            1.7447916666666667,
            11.872476659902539,
            0.14539930555555555,
            0.9893730549918782,
            -0.9921600877192983,
            0.1249734385252899
        },
    
        {
            true,
            0.75,
            11.976539567003485,
            0.06249999999999999,
            0.998044963916957,
            -0.9921875,
            0.12475562048961963
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            13.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            12.130208333333334,
            4.675258900845016,
            0.9330929487179488,
            0.3596353000650012,
            -0.9984499007936508,
            0.05565784405767876
        },
    
        {
            true,
            11.25,
            6.514407110397691,
            0.8653846153846154,
            0.5011082392613608,
            -0.9970588235294118,
            0.07664008365173755
        },
    
        {
            true,
            10.359375,
            7.853874814979864,
            0.796875,
            0.6041442165369126,
            -0.9958212209302325,
            0.09132412575557981
        },
    
        {
            true,
            9.458333333333334,
            8.918516163328714,
            0.7275641025641026,
            0.6860397048714396,
            -0.9947318007662835,
            0.10251168003826108
        },
    
        {
            true,
            8.546875,
            9.79545444246335,
            0.6574519230769231,
            0.7534964955741039,
            -0.9937855113636364,
            0.1113119823007199
        },
    
        {
            true,
            7.625,
            10.52897787061973,
            0.5865384615384616,
            0.8099213746630561,
            -0.9929775280898876,
            0.11830312214179473
        },
    
        {
            true,
            6.692708333333333,
            11.144848817499973,
            0.514823717948718,
            0.8572960628846134,
            -0.9923032407407408,
            0.12383165352777747
        },
    
        {
            true,
            5.75,
            11.659223816361019,
            0.4423076923076923,
            0.8968633704893091,
            -0.9917582417582418,
            0.12812333864132988
        },
    
        {
            true,
            4.796875,
            12.082631759446077,
            0.36899038461538464,
            0.9294332122650828,
            -0.9913383152173914,
            0.13133295390702257
        },
    
        {
            true,
            3.8333333333333335,
            12.421978729476056,
            0.2948717948717948,
            0.9555368253443118,
            -0.9910394265232976,
            0.13356966375780704
        },
    
        {
            true,
            2.859375,
            12.681639271378721,
            0.21995192307692304,
            0.9755107131829784,
            -0.9908577127659575,
            0.13491105607849704
        },
    
        {
            true,
            1.875,
            12.864073033063828,
            0.14423076923076922,
            0.9895440794664483,
            -0.9907894736842106,
            0.1354112950848824
        },
    
        {
            true,
            0.8802083333333334,
            12.970167049422708,
            0.06770833333333334,
            0.9977051576479006,
            -0.9908311631944445,
            0.13510590676481987
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            14.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            13.140625,
            4.82949009827901,
            0.9386160714285714,
            0.3449635784485007,
            -0.9983057228915663,
            0.05818662769010855
        },
    
        {
            true,
            12.270833333333334,
            6.739929473336909,
            0.8764880952380952,
            0.48142353380977926,
            -0.9967757936507937,
            0.0802372556349632
        },
    
        {
            true,
            11.390625,
            8.139635256531768,
            0.8136160714285714,
            0.5814025183236977,
            -0.9954044117647058,
            0.09576041478272669
        },
    
        {
            true,
            10.5,
            9.260129588726068,
            0.75,
            0.6614378277661477,
            -0.9941860465116279,
            0.10767592545030312
        },
    
        {
            true,
            9.598958333333334,
            10.191172597642066,
            0.685639880952381,
            0.7279408998315761,
            -0.9931154214559388,
            0.11713991491542604
        },
    
        {
            true,
            8.6875,
            10.978494603086528,
            0.6205357142857143,
            0.784178185934752,
            -0.9921875,
            0.12475562048961963
        },
    
        {
            true,
            7.765625,
            11.648822616873131,
            0.5546875000000001,
            0.832058758348081,
            -0.9913974719101124,
            0.130885647380597
        },
    
        {
            true,
            6.833333333333333,
            12.219065248845983,
            0.4880952380952381,
            0.8727903749175702,
            -0.9907407407407408,
            0.13576739165384424
        },
    
        {
            true,
            5.890625,
            12.7004148400505,
            0.4207589285714286,
            0.9071724885750359,
            -0.9902129120879121,
            0.1395649982423132
        },
    
        {
            true,
            4.9375,
            13.10042341872964,
            0.35267857142857145,
            0.93574452990926,
            -0.9898097826086957,
            0.14239590672532218
        },
    
        {
            true,
            3.9739583333333335,
            13.424144485401316,
            0.2838541666666667,
            0.9588674632429511,
            -0.989527329749104,
            0.14434563962797115
        },
    
        {
            true,
            3.0,
            13.674794331177344,
            0.21428571428571427,
            0.9767710236555246,
            -0.9893617021276596,
            0.14547653543805686
        },
    
        {
            true,
            2.015625,
            13.85414219139442,
            0.1439732142857143,
            0.9895815850996016,
            -0.9893092105263158,
            0.14583307569888862
        },
    
        {
            true,
            1.0208333333333333,
            13.962732515720393,
            0.07291666666666666,
            0.9973380368371709,
            -0.9893663194444445,
            0.14544513037208742
        },
    
        {
            true,
            0.015625,
            13.99999128068925,
            0.0011160714285714285,
            0.9999993771920892,
            -0.9895296391752577,
            0.14432980701741494
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            15.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            14.151041666666666,
            4.974738158764128,
            0.9434027777777777,
            0.3316492105842752,
            -0.9981580284552845,
            0.06066753852151376
        },
    
        {
            true,
            13.291666666666666,
            6.952093010182058,
            0.8861111111111111,
            0.46347286734547055,
            -0.9964859437751004,
            0.08376015674918143
        },
    
        {
            true,
            12.421875,
            8.408152084993171,
            0.828125,
            0.560543472332878,
            -0.9949776785714286,
            0.10009704863087109
        },
    
        {
            true,
            11.541666666666666,
            9.58070616163316,
            0.7694444444444444,
            0.6387137441088773,
            -0.9936274509803921,
            0.1127141901368607
        },
    
        {
            true,
            10.651041666666666,
            10.561974787648879,
            0.7100694444444444,
            0.7041316525099253,
            -0.9924297480620154,
            0.1228136603214986
        },
    
        {
            true,
            9.75,
            11.399013115177997,
            0.65,
            0.7599342076785333,
            -0.9913793103448276,
            0.1310231392549195
        },
    
        {
            true,
            8.838541666666666,
            12.119413401918314,
            0.5892361111111111,
            0.8079608934612209,
            -0.9904711174242423,
            0.13772060683998083
        },
    
        {
            true,
            7.916666666666667,
            12.74073737618388,
            0.5277777777777778,
            0.849382491745592,
            -0.9897003745318351,
            0.14315435254139192
        },
    
        {
            true,
            6.984375,
            13.274731856402035,
            0.465625,
            0.8849821237601356,
            -0.9890625,
            0.14749702062668926
        },
    
        {
            true,
            6.041666666666667,
            13.729466992162838,
            0.4027777777777778,
            0.9152977994775225,
            -0.9885531135531135,
            0.15087326365014106
        },
    
        {
            true,
            5.088541666666667,
            14.110518902811378,
            0.3392361111111111,
            0.9407012601874253,
            -0.9881680253623187,
            0.15337520546534106
        },
    
        {
            true,
            4.125,
            14.421663392272057,
            0.275,
            0.9614442261514706,
            -0.9879032258064516,
            0.15507164937926943
        },
    
        {
            true,
            3.1510416666666665,
            14.665297010798334,
            0.21006944444444445,
            0.9776864673865556,
            -0.9877548758865249,
            0.15601379798721635
        },
    
        {
            true,
            2.1666666666666665,
            14.842693675864753,
            0.14444444444444443,
            0.9895129117243169,
            -0.9877192982456141,
            0.15623888079857637
        },
    
        {
            true,
            1.171875,
            14.954153569639942,
            0.07812499999999999,
            0.9969435713093293,
            -0.98779296875,
            0.15577243301708274
        },
    
        {
            true,
            0.16666666666666666,
            14.99907404549435,
            0.01111111111111111,
            0.9999382696996233,
            -0.9879725085910652,
            0.1546296293349933
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            16.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            15.161458333333334,
            5.1117688921348154,
            0.9475911458333334,
            0.31948555575842597,
            -0.9980066872427984,
            0.06310825792759031
        },
    
        {
            true,
            14.3125,
            7.152086671035244,
            0.89453125,
            0.44700541693970275,
            -0.9961890243902439,
            0.0872205691589664
        },
    
        {
            true,
            13.453125,
            8.661029253753563,
            0.8408203125,
            0.5413143283595977,
            -0.9945406626506024,
            0.10434975004522365
        },
    
        {
            true,
            12.583333333333334,
            9.882293368556825,
            0.7864583333333334,
            0.6176433355348016,
            -0.9930555555555556,
            0.11764634962567648
        },
    
        {
            true,
            11.703125,
            10.91040169903817,
            0.7314453125,
            0.6819001061898856,
            -0.9917279411764706,
            0.12835766704750787
        },
    
        {
            true,
            10.8125,
            11.79363573076598,
            0.67578125,
            0.7371022331728737,
            -0.9905523255813954,
            0.13713529919495324
        },
    
        {
            true,
            9.911458333333334,
            12.56037394772135,
            0.6194661458333334,
            0.7850233717325844,
            -0.9895234674329503,
            0.14437211434162472
        },
    
        {
            true,
            9.0,
            13.228756555322953,
            0.5625,
            0.8267972847076845,
            -0.9886363636363636,
            0.15032677903776082
        },
    
        {
            true,
            8.078125,
            13.81100635306403,
            0.5048828125,
            0.8631878970665019,
            -0.9878862359550562,
            0.1551798466636408
        },
    
        {
            true,
            7.145833333333333,
            14.31562314299389,
            0.4466145833333333,
            0.8947264464371181,
            -0.9872685185185186,
            0.15906247936659876
        },
    
        {
            true,
            6.203125,
            14.748601297559542,
            0.3876953125,
            0.9217875810974714,
            -0.9867788461538461,
            0.16207254173142355
        },
    
        {
            true,
            5.25,
            15.11414900019184,
            0.328125,
            0.94463431251199,
            -0.9864130434782609,
            0.1642842282629548
        },
    
        {
            true,
            4.286458333333333,
            15.415131363585497,
            0.2679036458333333,
            0.9634457102240935,
            -0.9861671146953404,
            0.165754100683715
        },
    
        {
            true,
            3.3125,
            15.653349282182392,
            0.20703125,
            0.9783343301363995,
            -0.9860372340425532,
            0.16652499236364246
        },
    
        {
            true,
            2.328125,
            15.829713641894315,
            0.1455078125,
            0.9893571026183947,
            -0.9860197368421053,
            0.16662856465151912
        },
    
        {
            true,
            1.3333333333333333,
            15.944347657468532,
            0.08333333333333333,
            0.9965217285917832,
            -0.986111111111111,
            0.16608695476529717
        },
    
        {
            true,
            0.328125,
            15.99663508317843,
            0.0205078125,
            0.9997896926986519,
            -0.9863079896907216,
            0.16491376374410754
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            17.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            16.171875,
            5.241226858701596,
            0.9512867647058824,
            0.30830746227656447,
            -0.9978515625,
            0.06551533573376996
        },
    
        {
            true,
            15.333333333333334,
            7.340905181848411,
            0.9019607843137255,
            0.43181795187343597,
            -0.9958847736625515,
            0.09062845903516557
        },
    
        {
            true,
            14.484375,
            8.899600039292496,
            0.8520220588235294,
            0.5235058846642645,
            -0.9940929878048781,
            0.10853170779624995
        },
    
        {
            true,
            13.625,
            10.16658128379447,
            0.8014705882352942,
            0.5980341931643806,
            -0.9924698795180723,
            0.12248893113005385
        },
    
        {
            true,
            12.755208333333334,
            11.238534618590801,
            0.7503063725490197,
            0.6610902716818119,
            -0.9910094246031746,
            0.13379207879274763
        },
    
        {
            true,
            11.875,
            12.16488286010186,
            0.6985294117647058,
            0.7155813447118742,
            -0.9897058823529412,
            0.14311626894237484
        },
    
        {
            true,
            10.984375,
            12.974725656420446,
            0.6461397058823529,
            0.7632191562600262,
            -0.9885537790697675,
            0.1508689029816331
        },
    
        {
            true,
            10.083333333333334,
            13.686723088047367,
            0.5931372549019608,
            0.8051013581204334,
            -0.9875478927203065,
            0.1573186561844525
        },
    
        {
            true,
            9.171875,
            14.313514906701812,
            0.5395220588235294,
            0.8419714651001066,
            -0.9866832386363636,
            0.16265357848524786
        },
    
        {
            true,
            8.25,
            14.863966496194749,
            0.4852941176470588,
            0.874350970364397,
            -0.9859550561797753,
            0.16701085950780617
        },
    
        {
            true,
            7.317708333333333,
            15.344417380541493,
            0.430453431372549,
            0.902612787090676,
            -0.9853587962962963,
            0.17049352645046104
        },
    
        {
            true,
            6.375,
            15.759421785078283,
            0.375,
            0.9270248108869579,
            -0.9848901098901099,
            0.17318045917668443
        },
    
        {
            true,
            5.421875,
            16.112208771126788,
            0.31893382352941174,
            0.9477769865368699,
            -0.9845448369565217,
            0.1751327040339868
        },
    
        {
            true,
            4.458333333333333,
            16.40497680244897,
            0.26225490196078427,
            0.9649986354381748,
            -0.9843189964157707,
            0.176397600026333
        },
    
        {
            true,
            3.484375,
            16.63908443573068,
            0.20496323529411764,
            0.97876967269004,
            -0.9842087765957447,
            0.1770115365503264
        },
    
        {
            true,
            2.5,
            16.815171720800237,
            0.14705882352941177,
            0.9891277482823668,
            -0.9842105263157894,
            0.1770018075873709
        },
    
        {
            true,
            1.5052083333333333,
            16.93323205632238,
            0.08854166666666666,
            0.9960724739013166,
            -0.9843207465277778,
            0.1763878339200248
        },
    
        {
            true,
            0.5,
            16.99264546796643,
            0.029411764705882353,
            0.9995673804686135,
            -0.9845360824742269,
            0.17518191204089104
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            18.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            17.182291666666668,
            5.363660418184318,
            0.9545717592592593,
            0.2979811343435732,
            -0.9976925105485231,
            0.0678944356732192
        },
    
        {
            true,
            16.354166666666668,
            7.519390443306483,
            0.9085648148148149,
            0.41774391351702683,
            -0.9955729166666666,
            0.09399238054133104
        },
    
        {
            true,
            15.515625,
            9.124986622421702,
            0.8619791666666666,
            0.5069437012456501,
            -0.9936342592592593,
            0.11265415583236668
        },
    
        {
            true,
            14.666666666666666,
            10.43498389499902,
            0.8148148148148148,
            0.5797213274999455,
            -0.991869918699187,
            0.12725590115852464
        },
    
        {
            true,
            13.807291666666666,
            11.548103603258728,
            0.7670717592592592,
            0.6415613112921515,
            -0.99027359437751,
            0.13913377835251478
        },
    
        {
            true,
            12.9375,
            12.51483494697393,
            0.71875,
            0.6952686081652184,
            -0.9888392857142857,
            0.14898613032111824
        },
    
        {
            true,
            12.057291666666666,
            13.364943608744879,
            0.669849537037037,
            0.7424968671524933,
            -0.9875612745098039,
            0.15723463069111623
        },
    
        {
            true,
            11.166666666666666,
            14.11756195508118,
            0.6203703703703703,
            0.78430899750451,
            -0.9864341085271318,
            0.16415769715210676
        },
    
        {
            true,
            10.265625,
            14.78570063809541,
            0.5703125,
            0.8214278132275228,
            -0.9854525862068966,
            0.16995058204707367
        },
    
        {
            true,
            9.354166666666666,
            15.378542387762964,
            0.5196759259259259,
            0.8543634659868313,
            -0.9846117424242423,
            0.1747561634973064
        },
    
        {
            true,
            8.432291666666666,
            15.902718548986016,
            0.46846064814814814,
            0.8834843638325565,
            -0.9839068352059924,
            0.17868223088748333
        },
    
        {
            true,
            7.5,
            16.36306817195357,
            0.4166666666666667,
            0.9090593428863095,
            -0.9833333333333333,
            0.1818118685772619
        },
    
        {
            true,
            6.557291666666667,
            16.76311206185367,
            0.3642939814814814,
            0.9312840034363147,
            -0.9828869047619047,
            0.18421002265773262
        },
    
        {
            true,
            5.604166666666667,
            17.105359276326887,
            0.3113425925925926,
            0.9502977375737159,
            -0.9825634057971014,
            0.18592781822094442
        },
    
        {
            true,
            4.640625,
            17.391509411473606,
            0.2578125,
            0.9661949673040893,
            -0.9823588709677419,
            0.18700547754272695
        },
    
        {
            true,
            3.6666666666666665,
            17.622586517181738,
            0.2037037037037037,
            0.9790325842878743,
            -0.9822695035460994,
            0.18747432465086958
        },
    
        {
            true,
            2.6822916666666665,
            17.79902557487152,
            0.1490162037037037,
            0.9888347541595289,
            -0.9822916666666668,
            0.18735816394601604
        },
    
        {
            true,
            1.6875,
            17.92072386233324,
            0.09375,
            0.9955957701296244,
            -0.982421875,
            0.18667420689930458
        },
    
        {
            true,
            0.6822916666666666,
            17.987064187398598,
            0.03790509259259259,
            0.9992813437443666,
            -0.9826567869415808,
            0.18543365141648038
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            19.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            18.192708333333332,
            5.479540445900907,
            0.9575109649122806,
            0.28839686557373195,
            -0.9975293803418804,
            0.07025051853719112
        },
    
        {
            true,
            17.375,
            7.6882621573408905,
            0.9144736842105263,
            0.4046453767021521,
            -0.995253164556962,
            0.09731977414355558
        },
    
        {
            true,
            16.546875,
            9.3381436985289,
            0.8708881578947368,
            0.4914812472909947,
            -0.9931640625,
            0.11672679623161124
        },
    
        {
            true,
            15.708333333333334,
            10.68869795105507,
            0.8267543859649124,
            0.56256305005553,
            -0.9912551440329219,
            0.13195923396364284
        },
    
        {
            true,
            14.859375,
            11.840564792668253,
            0.7820723684210527,
            0.6231876206667502,
            -0.9895198170731707,
            0.14439713161790552
        },
    
        {
            true,
            14.0,
            12.84523257866513,
            0.7368421052631579,
            0.6760648725613226,
            -0.9879518072289156,
            0.15476183829717025
        },
    
        {
            true,
            13.130208333333334,
            13.733085200466205,
            0.6910635964912281,
            0.7227939579192739,
            -0.986545138888889,
            0.16348910952935958
        },
    
        {
            true,
            12.25,
            14.523687548277813,
            0.6447368421052632,
            0.7644046078040955,
            -0.9852941176470589,
            0.17086691233268014
        },
    
        {
            true,
            11.359375,
            15.230384092641097,
            0.5978618421052632,
            0.8015991627705841,
            -0.9841933139534884,
            0.17709748944931508
        },
    
        {
            true,
            10.458333333333334,
            15.862637356029069,
            0.5504385964912281,
            0.8348756503173194,
            -0.9832375478927203,
            0.1823291650118284
        },
    
        {
            true,
            9.546875,
            16.4273302071388,
            0.5024671052631579,
            0.8645963266915159,
            -0.982421875,
            0.18667420689930456
        },
    
        {
            true,
            8.625,
            16.929541488179765,
            0.45394736842105265,
            0.8910284993778824,
            -0.9817415730337079,
            0.19021956728291872
        },
    
        {
            true,
            7.692708333333333,
            17.373031931653838,
            0.40487938596491224,
            0.9143701016659914,
            -0.9811921296296297,
            0.1930336881294871
        },
    
        {
            true,
            6.75,
            17.760560238911385,
            0.35526315789473684,
            0.9347663283637571,
            -0.9807692307692307,
            0.19517099163638885
        },
    
        {
            true,
            5.796875,
            18.094094070562775,
            0.3050986842105263,
            0.9523207405559355,
            -0.98046875,
            0.1966749355495954
        },
    
        {
            true,
            4.833333333333333,
            18.374952758820605,
            0.25438596491228066,
            0.9671027767800319,
            -0.9802867383512546,
            0.1975801371916194
        },
    
        {
            true,
            3.859375,
            18.603903477748293,
            0.203125,
            0.9791528146183313,
            -0.980219414893617,
            0.1979138667845563
        },
    
        {
            true,
            2.875,
            18.7812240016459,
            0.1513157894736842,
            0.9884854737708368,
            -0.9802631578947368,
            0.19769709475416736
        },
    
        {
            true,
            1.8802083333333333,
            18.906739978728854,
            0.09895833333333333,
            0.9950915778278344,
            -0.9804144965277778,
            0.1969452081117589
        },
    
        {
            true,
            0.875,
            18.979841279631398,
            0.046052631578947366,
            0.998939014717442,
            -0.9806701030927835,
            0.19566846680032368
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            20.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            19.203125,
            5.5892745713889385,
            0.96015625,
            0.2794637285694469,
            -0.997362012987013,
            0.07258798144660959
        },
    
        {
            true,
            18.395833333333332,
            7.848140924589867,
            0.9197916666666666,
            0.39240704622949335,
            -0.9949252136752137,
            0.10061719134089572
        },
    
        {
            true,
            17.578125,
            9.5398910625004,
            0.87890625,
            0.47699455312502004,
            -0.9926819620253164,
            0.12075811471519494
        },
    
        {
            true,
            16.75,
            10.928746497197197,
            0.8375,
            0.5464373248598599,
            -0.990625,
            0.13660933121496496
        },
    
        {
            true,
            15.911458333333334,
            12.11715699768709,
            0.7955729166666667,
            0.6058578498843545,
            -0.9887474279835392,
            0.14959453083564309
        },
    
        {
            true,
            15.0625,
            13.157548926376828,
            0.753125,
            0.6578774463188414,
            -0.9870426829268293,
            0.16045791373630278
        },
    
        {
            true,
            14.203125,
            14.080882082965363,
            0.71015625,
            0.7040441041482681,
            -0.9855045180722891,
            0.16964918172247426
        },
    
        {
            true,
            13.333333333333334,
            14.907119849998598,
            0.6666666666666667,
            0.7453559924999299,
            -0.9841269841269842,
            0.1774657124999833
        },
    
        {
            true,
            12.453125,
            15.649909831509413,
            0.62265625,
            0.7824954915754707,
            -0.9829044117647059,
            0.1841165862530519
        },
    
        {
            true,
            11.5625,
            16.318964236433633,
            0.578125,
            0.8159482118216816,
            -0.9818313953488372,
            0.1897553980980655
        },
    
        {
            true,
            10.661458333333334,
            16.921386060444256,
            0.5330729166666667,
            0.8460693030222128,
            -0.9809027777777778,
            0.19449869034993397
        },
    
        {
            true,
            9.75,
            17.46245973510032,
            0.4875,
            0.8731229867550161,
            -0.9801136363636364,
            0.19843704244432184
        },
    
        {
            true,
            8.828125,
            17.946147469147103,
            0.44140625,
            0.8973073734573551,
            -0.9794592696629213,
            0.20164210639491129
        },
    
        {
            true,
            7.895833333333333,
            18.37541335513904,
            0.39479166666666665,
            0.918770667756952,
            -0.9789351851851852,
            0.2041712595015449
        },
    
        {
            true,
            6.953125,
            18.752441247324974,
            0.34765625,
            0.9376220623662487,
            -0.9785370879120879,
            0.2060707829376371
        },
    
        {
            true,
            6.0,
            19.078784028338912,
            0.3,
            0.9539392014169457,
            -0.9782608695652174,
            0.2073780872645534
        },
    
        {
            true,
            5.036458333333333,
            19.355466603949314,
            0.2518229166666667,
            0.9677733301974657,
            -0.9781025985663081,
            0.20812329681665925
        },
    
        {
            true,
            4.0625,
            19.583056292366624,
            0.203125,
            0.9791528146183313,
            -0.9780585106382979,
            0.20833038608900664
        },
    
        {
            true,
            3.078125,
            19.76170909826311,
            0.15390625,
            0.9880854549131556,
            -0.978125,
            0.20801799050803274
        },
    
        {
            true,
            2.0833333333333335,
            19.891197103800017,
            0.10416666666666667,
            0.9945598551900009,
            -0.978298611111111,
            0.20719996983125016
        },
    
        {
            true,
            1.078125,
            19.97092002097988,
            0.05390625,
            0.9985460010489939,
            -0.9785760309278351,
            0.2058857734121637
        },
    
        {
            true,
            0.0625,
            19.99990234351158,
            0.003125,
            0.999995117175579,
            -0.9789540816326531,
            0.20408063615828143
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            21.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            20.213541666666668,
            5.693218183938719,
            0.9625496031746033,
            0.2711056278066057,
            -0.9971902412280701,
            0.07491076557814104
        },
    
        {
            true,
            19.416666666666668,
            7.999565960447822,
            0.9246031746031746,
            0.38093171240227724,
            -0.9945887445887446,
            0.10389046701880289
        },
    
        {
            true,
            18.609375,
            9.73093839819033,
            0.8861607142857143,
            0.4633780189614443,
            -0.9921875,
            0.12475562048961962
        },
    
        {
            true,
            17.791666666666668,
            11.156011707694743,
            0.8472222222222223,
            0.5312386527473687,
            -0.9899789029535865,
            0.14121533807208536
        },
    
        {
            true,
            16.963541666666668,
            12.37894398255618,
            0.8077876984126985,
            0.5894735229788657,
            -0.9879557291666666,
            0.15473679978195226
        },
    
        {
            true,
            16.125,
            13.453043335989072,
            0.7678571428571429,
            0.6406211112375748,
            -0.9861111111111112,
            0.1660869547652972
        },
    
        {
            true,
            15.276041666666666,
            14.409807458750583,
            0.7274305555555556,
            0.6861813075595515,
            -0.9844385162601625,
            0.17572935925305588
        },
    
        {
            true,
            14.416666666666666,
            15.269568501507246,
            0.6865079365079365,
            0.7271223095955831,
            -0.9829317269076304,
            0.1839707048374367
        },
    
        {
            true,
            13.546875,
            16.04625120501281,
            0.6450892857142857,
            0.7641072002387052,
            -0.9815848214285714,
            0.1910268000596763
        },
    
        {
            true,
            12.666666666666666,
            16.74979270186815,
            0.6031746031746033,
            0.7976091762794358,
            -0.9803921568627451,
            0.19705638472786058
        },
    
        {
            true,
            11.776041666666666,
            17.387490982454327,
            0.5607638888888888,
            0.8279757610692536,
            -0.9793483527131782,
            0.2021801277029573
        },
    
        {
            true,
            10.875,
            17.964809350505227,
            0.5178571428571429,
            0.8554671119288203,
            -0.978448275862069,
            0.20649206150006008
        },
    
        {
            true,
            9.963541666666666,
            18.48588211194146,
            0.47445436507936506,
            0.880280100568641,
            -0.9776870265151515,
            0.21006684218115296
        },
    
        {
            true,
            9.041666666666666,
            18.953845622693272,
            0.4305555555555555,
            0.9025640772711082,
            -0.9770599250936329,
            0.21296455755835136
        },
    
        {
            true,
            8.109375,
            19.3710618477505,
            0.3861607142857143,
            0.9224315165595476,
            -0.9765625,
            0.21523402053056112
        },
    
        {
            true,
            7.166666666666667,
            19.73927275481265,
            0.3412698412698412,
            0.9399653692767926,
            -0.9761904761904762,
            0.21691508521772143
        },
    
        {
            true,
            6.213541666666667,
            20.059708371673732,
            0.2958829365079365,
            0.9552242081749396,
            -0.9759397644927535,
            0.21804030838775795
        },
    
        {
            true,
            5.25,
            20.33316256758894,
            0.25,
            0.9682458365518543,
            -0.9758064516129032,
            0.2186361566407413
        },
    
        {
            true,
            4.276041666666667,
            20.56004541981682,
            0.20362103174603177,
            0.9790497818960391,
            -0.975786790780142,
            0.21872388744485982
        },
    
        {
            true,
            3.2916666666666665,
            20.740417800891947,
            0.15674603174603174,
            0.9876389428996165,
            -0.9758771929824562,
            0.21832018737781
        },
    
        {
            true,
            2.296875,
            20.87401171874671,
            0.109375,
            0.9940005580355576,
            -0.97607421875,
            0.21743762207027825
        },
    
        {
            true,
            1.2916666666666667,
            20.96023848199782,
            0.06150793650793651,
            0.9981065943808486,
            -0.9763745704467354,
            0.21608493280410124
        },
    
        {
            true,
            0.2760416666666667,
            20.998185659676977,
            0.01314484126984127,
            0.9999136028417608,
            -0.9767750850340137,
            0.21426720060894877
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            22.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            21.223958333333332,
            5.791683059778962,
            0.9647253787878788,
            0.2632583208990437,
            -0.997013888888889,
            0.07722244079705283
        },
    
        {
            true,
            20.4375,
            8.143008887997114,
            0.9289772727272727,
            0.37013676763623243,
            -0.9942434210526315,
            0.10714485378943571
        },
    
        {
            true,
            19.640625,
            9.911904439076025,
            0.8927556818181818,
            0.45054111086709203,
            -0.9916801948051948,
            0.12872603167631202
        },
    
        {
            true,
            18.833333333333332,
            11.371260068943792,
            0.856060606060606,
            0.5168754576792632,
            -0.9893162393162394,
            0.14578538549927939
        },
    
        {
            true,
            18.015625,
            12.626846631656496,
            0.8188920454545454,
            0.5739475741662043,
            -0.9871439873417721,
            0.15983350166653792
        },
    
        {
            true,
            17.1875,
            13.732801744363748,
            0.78125,
            0.624218261107443,
            -0.98515625,
            0.17166002180454684
        },
    
        {
            true,
            16.348958333333332,
            14.72112636366289,
            0.7431344696969696,
            0.6691421074392223,
            -0.9833461934156379,
            0.1817423007859616
        },
    
        {
            true,
            15.5,
            15.612494995995995,
            0.7045454545454546,
            0.7096588634543634,
            -0.9817073170731707,
            0.19039628043897555
        },
    
        {
            true,
            14.640625,
            16.421087041038877,
            0.6654829545454546,
            0.746413047319949,
            -0.9802334337349398,
            0.1978444221811913
        },
    
        {
            true,
            13.770833333333334,
            17.15704372278498,
            0.6259469696969697,
            0.7798656237629537,
            -0.9789186507936508,
            0.204250520509345
        },
    
        {
            true,
            12.890625,
            17.82783742099347,
            0.5859375,
            0.810356246408794,
            -0.9777573529411765,
            0.20973926377639374
        },
    
        {
            true,
            12.0,
            18.439088914585774,
            0.5454545454545454,
            0.8381404052084442,
            -0.9767441860465116,
            0.21440801063471832
        },
    
        {
            true,
            11.098958333333334,
            18.99508157168404,
            0.5044981060606061,
            0.8634127987129109,
            -0.9758740421455939,
            0.218334270938897
        },
    
        {
            true,
            10.1875,
            19.49909853685549,
            0.4630681818181818,
            0.8863226607661587,
            -0.9751420454545454,
            0.22158066519153968
        },
    
        {
            true,
            9.265625,
            19.953651128537228,
            0.4211647727272727,
            0.9069841422062376,
            -0.9745435393258427,
            0.22419832728693515
        },
    
        {
            true,
            8.333333333333334,
            20.360637405433934,
            0.37878787878787884,
            0.9254835184288152,
            -0.9740740740740741,
            0.22622930450482148
        },
    
        {
            true,
            7.390625,
            20.721454150454186,
            0.3359375,
            0.9418842795660993,
            -0.9737293956043956,
            0.2277082873676284
        },
    
        {
            true,
            6.4375,
            21.037076644581585,
            0.29261363636363635,
            0.9562307565718903,
            -0.9735054347826086,
            0.22866387657153897
        },
    
        {
            true,
            5.473958333333333,
            21.30811535929282,
            0.24881628787878787,
            0.9685506981496737,
            -0.9733982974910395,
            0.2291195199923959
        },
    
        {
            true,
            4.5,
            21.534855467358028,
            0.20454545454545456,
            0.9788570666980921,
            -0.973404255319149,
            0.2290942070995535
        },
    
        {
            true,
            3.515625,
            21.71728299901659,
            0.15980113636363635,
            0.9871492272280268,
            -0.9735197368421052,
            0.22860297893701673
        },
    
        {
            true,
            2.5208333333333335,
            21.855100075395573,
            0.11458333333333334,
            0.9934136397907078,
            -0.9737413194444445,
            0.22765729245203722
        },
    
        {
            true,
            1.515625,
            21.947730653973657,
            0.06889204545454546,
            0.9976241206351663,
            -0.9740657216494846,
            0.22626526447395523
        },
    
        {
            true,
            0.5,
            21.99431744792277,
            0.022727272727272728,
            0.9997417021783078,
            -0.9744897959183674,
            0.2244318106930895
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            23.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            22.234375,
            5.88494421038764,
            0.9667119565217391,
            0.2558671395820713,
            -0.9968327702702703,
            0.07952627311334648
        },
    
        {
            true,
            21.458333333333332,
            8.278884620258674,
            0.9329710144927535,
            0.359951505228638,
            -0.9938888888888889,
            0.11038512827011565
        },
    
        {
            true,
            20.671875,
            10.083331988205833,
            0.8987771739130435,
            0.4384057386176449,
            -0.9911595394736842,
            0.13267542089744516
        },
    
        {
            true,
            19.875,
            11.575161985907584,
            0.8641304347826086,
            0.5032679124307645,
            -0.9886363636363636,
            0.15032677903776084
        },
    
        {
            true,
            19.067708333333332,
            12.86166781233797,
            0.8290307971014492,
            0.5592029483625204,
            -0.9863114316239316,
            0.16489317708125603
        },
    
        {
            true,
            18.25,
            13.997767679169419,
            0.7934782608695652,
            0.6085985947464965,
            -0.9841772151898734,
            0.17718693264771415
        },
    
        {
            true,
            17.421875,
            15.01593391981914,
            0.7574728260869565,
            0.6528666921660495,
            -0.9822265625,
            0.18769917399773925
        },
    
        {
            true,
            16.583333333333332,
            15.937159582421065,
            0.7210144927536232,
            0.6929199818443942,
            -0.9804526748971194,
            0.19675505657309958
        },
    
        {
            true,
            15.734375,
            16.775858945501867,
            0.6841032608695652,
            0.7293851715435594,
            -0.9788490853658537,
            0.20458364567685203
        },
    
        {
            true,
            14.875,
            17.5423594479192,
            0.6467391304347826,
            0.762711280344313,
            -0.9774096385542169,
            0.21135372828818313
        },
    
        {
            true,
            14.005208333333334,
            18.24429060116974,
            0.6089221014492754,
            0.7932300261378148,
            -0.9761284722222223,
            0.2171939357282112
        },
    
        {
            true,
            13.125,
            18.887413136795626,
            0.5706521739130435,
            0.8211918755128533,
            -0.975,
            0.22220486043288973
        },
    
        {
            true,
            12.234375,
            19.476141002759633,
            0.5319293478260869,
            0.8467887392504189,
            -0.9740188953488372,
            0.22646675584604223
        },
    
        {
            true,
            11.333333333333334,
            20.0138840697041,
            0.4927536231884058,
            0.8701688725958305,
            -0.9731800766283526,
            0.2300446444793575
        },
    
        {
            true,
            10.421875,
            20.503280749294124,
            0.453125,
            0.8914469890997445,
            -0.9724786931818182,
            0.23299182669652413
        },
    
        {
            true,
            9.5,
            20.946360065653412,
            0.41304347826086957,
            0.9107113072023223,
            -0.9719101123595506,
            0.23535236028824058
        },
    
        {
            true,
            8.567708333333334,
            21.344656800120507,
            0.3725090579710145,
            0.9280285565269786,
            -0.9714699074074075,
            0.2371628533346723
        },
    
        {
            true,
            7.625,
            21.699294343365178,
            0.33152173913043476,
            0.9434475801463121,
            -0.9711538461538461,
            0.23845378399302394
        },
    
        {
            true,
            6.671875,
            22.01104459094059,
            0.29008152173913043,
            0.9570019387365474,
            -0.9709578804347826,
            0.23925048468413684
        },
    
        {
            true,
            5.708333333333333,
            22.280370969881886,
            0.24818840579710147,
            0.9687117812992126,
            -0.970878136200717,
            0.23957388139657942
        },
    
        {
            true,
            4.734375,
            22.5074586161871,
            0.20584239130434784,
            0.9785851572255261,
            -0.9709109042553191,
            0.2394410491083734
        },
    
        {
            true,
            3.75,
            22.692234354509914,
            0.16304347826086957,
            0.9866188849786919,
            -0.9710526315789474,
            0.2388656247843149
        },
    
        {
            true,
            2.7552083333333335,
            22.83437818378093,
            0.11979166666666667,
            0.9927990514687361,
            -0.9712999131944445,
            0.23785810608105137
        },
    
        {
            true,
            1.75,
            22.93332727713098,
            0.07608695652173914,
            0.9971011859622168,
            -0.9716494845360825,
            0.2364260544034122
        },
    
        {
            true,
            0.734375,
            22.988272952950926,
            0.03192934782608695,
            0.9994901283891705,
            -0.9720982142857143,
            0.23457421380562168
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            24.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            23.244791666666668,
            5.973245380299038,
            0.9685329861111112,
            0.2488852241791266,
            -0.9966466894977168,
            0.0818252791821786
        },
    
        {
            true,
            22.479166666666668,
            8.407560048683695,
            0.9366319444444445,
            0.3503150020284873,
            -0.9935247747747747,
            0.11361567633356345
        },
    
        {
            true,
            21.703125,
            10.245699841122372,
            0.904296875,
            0.4269041600467655,
            -0.990625,
            0.13660933121496496
        },
    
        {
            true,
            20.916666666666668,
            11.768307251068672,
            0.8715277777777778,
            0.49034613546119465,
            -0.9879385964912281,
            0.15484614804037725
        },
    
        {
            true,
            20.119791666666668,
            13.08411186477441,
            0.8383246527777778,
            0.5451713276989337,
            -0.985457251082251,
            0.169923530711356
        },
    
        {
            true,
            19.3125,
            14.248766393972497,
            0.8046875,
            0.5936985997488541,
            -0.9831730769230769,
            0.18267649223041663
        },
    
        {
            true,
            18.494791666666668,
            15.295184902661267,
            0.7706163194444445,
            0.6372993709442195,
            -0.9810785864978903,
            0.1936099354767249
        },
    
        {
            true,
            17.666666666666668,
            16.24465724134827,
            0.7361111111111112,
            0.6768607183895113,
            -0.9791666666666666,
            0.20305821551685338
        },
    
        {
            true,
            16.828125,
            17.111814894521707,
            0.701171875,
            0.7129922872717378,
            -0.9774305555555556,
            0.21125697400644083
        },
    
        {
            true,
            15.979166666666666,
            17.907155905918977,
            0.665798611111111,
            0.7461314960799573,
            -0.9758638211382114,
            0.21837995007218264
        },
    
        {
            true,
            15.119791666666666,
            18.6384521877917,
            0.6299913194444444,
            0.7766021744913209,
            -0.9744603413654618,
            0.22455966491315302
        },
    
        {
            true,
            14.25,
            19.3115897843756,
            0.59375,
            0.8046495743489833,
            -0.9732142857142857,
            0.2298998783854238
        },
    
        {
            true,
            13.369791666666666,
            19.93109808289374,
            0.5570746527777778,
            0.8304624201205725,
            -0.9721200980392156,
            0.2344835068575734
        },
    
        {
            true,
            12.479166666666666,
            20.50049753800028,
            0.5199652777777778,
            0.8541873974166784,
            -0.9711724806201549,
            0.23837787834884044
        },
    
        {
            true,
            11.578125,
            21.02253603836547,
            0.482421875,
            0.8759390015985612,
            -0.9703663793103449,
            0.24163834526856862
        },
    
        {
            true,
            10.666666666666666,
            21.499353995462798,
            0.4444444444444444,
            0.8958064164776166,
            -0.9696969696969696,
            0.2443108408575318
        },
    
        {
            true,
            9.744791666666666,
            21.93260211131511,
            0.40603298611111105,
            0.9138584213047961,
            -0.9691596441947565,
            0.2464337315878102
        },
    
        {
            true,
            8.8125,
            22.32352668710748,
            0.3671875,
            0.9301469452961451,
            -0.96875,
            0.24803918541230535
        },
    
        {
            true,
            7.869791666666667,
            22.673031979055292,
            0.3279079861111111,
            0.9447096657939705,
            -0.9684638278388278,
            0.24915419757203616
        },
    
        {
            true,
            6.916666666666667,
            22.981725832108914,
            0.2881944444444445,
            0.9575719096712048,
            -0.9682971014492753,
            0.24980136774031428
        },
    
        {
            true,
            5.953125,
            23.24995274692779,
            0.24804687499999997,
            0.968748031121991,
            -0.9682459677419355,
            0.24999949190244936
        },
    
        {
            true,
            4.979166666666667,
            23.47781717506028,
            0.2074652777777778,
            0.9782423822941784,
            -0.9683067375886526,
            0.2497640125006413
        },
    
        {
            true,
            3.9947916666666665,
            23.66519891190291,
            0.16644965277777773,
            0.986049954662621,
            -0.9684758771929824,
            0.24910735696739905
        },
    
        {
            true,
            3.0,
            23.811761799581316,
            0.125,
            0.9921567416492215,
            -0.96875,
            0.24803918541230538
        },
    
        {
            true,
            1.9947916666666667,
            23.916956457848002,
            0.08311631944444443,
            0.9965398524103333,
            -0.9691258591065292,
            0.2465665614211134
        },
    
        {
            true,
            0.9791666666666666,
            23.980017361104828,
            0.04079861111111111,
            0.9991673900460345,
            -0.9696003401360546,
            0.24469405470515135
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            25.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            24.255208333333332,
            6.056803505694838,
            0.9702083333333333,
            0.24227214022779353,
            -0.9964554398148149,
            0.08412227091242831
        },
    
        {
            true,
            23.5,
            8.52936105461599,
            0.94,
            0.3411744421846396,
            -0.9931506849315068,
            0.11684056239199986
        },
    
        {
            true,
            22.734375,
            10.399432357555627,
            0.909375,
            0.4159772943022251,
            -0.9900760135135135,
            0.14053286969669765
        },
    
        {
            true,
            21.958333333333332,
            11.951217394986266,
            0.8783333333333333,
            0.47804869579945064,
            -0.9872222222222223,
            0.15934956526648356
        },
    
        {
            true,
            21.171875,
            13.294800073125394,
            0.846875,
            0.5317920029250157,
            -0.9845805921052632,
            0.17493157990954467
        },
    
        {
            true,
            20.375,
            14.486523910172515,
            0.815,
            0.5794609564069007,
            -0.9821428571428571,
            0.1881366741580846
        },
    
        {
            true,
            19.567708333333332,
            15.559716918427446,
            0.7827083333333333,
            0.6223886767370979,
            -0.9799011752136753,
            0.1994835502362493
        },
    
        {
            true,
            18.75,
            16.535945694153693,
            0.75,
            0.6614378277661477,
            -0.9778481012658228,
            0.2093157682804265
        },
    
        {
            true,
            17.921875,
            17.430042928357206,
            0.716875,
            0.6972017171342882,
            -0.9759765625,
            0.21787553660446507
        },
    
        {
            true,
            17.083333333333332,
            18.252663428174593,
            0.6833333333333332,
            0.7301065371269837,
            -0.9742798353909465,
            0.2253415238046246
        },
    
        {
            true,
            16.234375,
            19.01170871750814,
            0.649375,
            0.7604683487003255,
            -0.9727515243902439,
            0.23185010631107486
        },
    
        {
            true,
            15.375,
            19.71317769919401,
            0.615,
            0.7885271079677604,
            -0.9713855421686747,
            0.23750816505053024
        },
    
        {
            true,
            14.505208333333334,
            20.361702561588437,
            0.5802083333333334,
            0.8144681024635376,
            -0.9701760912698413,
            0.2424012209712909
        },
    
        {
            true,
            13.625,
            20.96090110181335,
            0.545,
            0.8384360440725339,
            -0.9691176470588235,
            0.24659883649192174
        },
    
        {
            true,
            12.734375,
            21.51361646398334,
            0.509375,
            0.8605446585593336,
            -0.9682049418604651,
            0.25015833097655044
        },
    
        {
            true,
            11.833333333333334,
            22.02208487455768,
            0.4733333333333334,
            0.8808833949823073,
            -0.9674329501915709,
            0.2531274123512377
        },
    
        {
            true,
            10.921875,
            22.488055640369957,
            0.436875,
            0.8995222256147983,
            -0.966796875,
            0.2555460868223859
        },
    
        {
            true,
            10.0,
            22.9128784747792,
            0.4000000000000001,
            0.9165151389911681,
            -0.9662921348314607,
            0.25744807275032805
        },
    
        {
            true,
            9.067708333333334,
            23.29756780399184,
            0.36270833333333335,
            0.9319027121596736,
            -0.9659143518518519,
            0.2588618644887982
        },
    
        {
            true,
            8.125,
            23.642850399222173,
            0.325,
            0.9457140159688869,
            -0.9656593406593407,
            0.2598115428485953
        },
    
        {
            true,
            7.171875,
            23.949200591760366,
            0.28687499999999994,
            0.9579680236704146,
            -0.9655230978260869,
            0.26031739773652574
        },
    
        {
            true,
            6.208333333333333,
            24.2168659661448,
            0.24833333333333332,
            0.968674638645792,
            -0.9655017921146954,
            0.2603964082381161
        },
    
        {
            true,
            5.234375,
            24.445885509823018,
            0.209375,
            0.9778354203929207,
            -0.965591755319149,
            0.2600626118066279
        },
    
        {
            true,
            4.25,
            24.63610155848526,
            0.17,
            0.9854440623394106,
            -0.9657894736842105,
            0.25932738482616063
        },
    
        {
            true,
            3.2552083333333335,
            24.787166411403245,
            0.13020833333333334,
            0.9914866564561298,
            -0.966091579861111,
            0.25819965011878376
        },
    
        {
            true,
            2.25,
            24.898544134145673,
            0.09000000000000001,
            0.9959417653658271,
            -0.9664948453608248,
            0.2566860220015018
        },
    
        {
            true,
            1.234375,
            24.969507771667725,
            0.04937500000000001,
            0.9987803108667092,
            -0.9669961734693877,
            0.2547908956292625
        },
    
        {
            true,
            0.20833333333333334,
            24.99913192937351,
            0.008333333333333333,
            0.9999652771749404,
            -0.9675925925925924,
            0.25251648413508593
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            26.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            25.265625,
            6.135812363442595,
            0.9717548076923077,
            0.23599278320933056,
            -0.9962588028169014,
            0.08641989244285345
        },
    
        {
            true,
            24.520833333333332,
            8.644578222151091,
            0.9431089743589743,
            0.33248377777504196,
            -0.9927662037037037,
            0.12006358641876516
        },
    
        {
            true,
            23.765625,
            10.544907223839147,
            0.9140625,
            0.4055733547630441,
            -0.9895119863013698,
            0.14445078388820748
        },
    
        {
            true,
            23.0,
            12.12435565298214,
            0.8846153846153846,
            0.4663213712685439,
            -0.9864864864864865,
            0.16384264395921813
        },
    
        {
            true,
            22.223958333333332,
            13.494283085746494,
            0.8547676282051282,
            0.5190108879133267,
            -0.9836805555555557,
            0.17992377447661992
        },
    
        {
            true,
            21.4375,
            14.711682220262915,
            0.8245192307692307,
            0.5658339315485736,
            -0.9810855263157895,
            0.193574766056091
        },
    
        {
            true,
            20.640625,
            15.81026880256547,
            0.7938701923076923,
            0.6080872616371334,
            -0.9786931818181818,
            0.20532816626708403
        },
    
        {
            true,
            19.833333333333332,
            16.81186750152668,
            0.7628205128205128,
            0.6466102885202569,
            -0.9764957264957266,
            0.21553676284008566
        },
    
        {
            true,
            19.015625,
            17.73149756392209,
            0.7313701923076923,
            0.681980675535465,
            -0.9744857594936709,
            0.22444933625217836
        },
    
        {
            true,
            18.1875,
            18.579958120243436,
            0.6995192307692307,
            0.7146137738555167,
            -0.97265625,
            0.23224947650304295
        },
    
        {
            true,
            17.348958333333332,
            19.365269033717656,
            0.6672676282051282,
            0.7448180397583714,
            -0.9710005144032923,
            0.23907739547799575
        },
    
        {
            true,
            16.5,
            20.09353129741012,
            0.6346153846153846,
            0.7728281268234661,
            -0.9695121951219512,
            0.24504306460256245
        },
    
        {
            true,
            15.640625,
            20.769469170139494,
            0.6015625,
            0.7988257373130575,
            -0.9681852409638554,
            0.2502345683149337
        },
    
        {
            true,
            14.770833333333334,
            21.39678673630433,
            0.5681089743589743,
            0.822953336011705,
            -0.967013888888889,
            0.2547236516226706
        },
    
        {
            true,
            13.890625,
            21.97841070481155,
            0.5342548076923077,
            0.8453234886465981,
            -0.9659926470588235,
            0.2585695377036653
        },
    
        {
            true,
            13.0,
            22.516660498395403,
            0.5,
            0.8660254037844386,
            -0.9651162790697675,
            0.2618216337022721
        },
    
        {
            true,
            12.098958333333334,
            23.013370184487624,
            0.4653445512820513,
            0.8851296224802933,
            -0.9643797892720307,
            0.264521496373421
        },
    
        {
            true,
            11.1875,
            23.469977497858835,
            0.43028846153846145,
            0.9026914422253397,
            -0.9637784090909091,
            0.26670428974839583
        },
    
        {
            true,
            10.265625,
            23.88758973524485,
            0.3948317307692308,
            0.9187534513555711,
            -0.9633075842696629,
            0.26839988466567244
        },
    
        {
            true,
            9.333333333333334,
            24.267032964268395,
            0.358974358974359,
            0.9333474217026306,
            -0.962962962962963,
            0.26963369960298217
        },
    
        {
            true,
            8.390625,
            24.608888884087698,
            0.32271634615384615,
            0.9464957263110653,
            -0.9627403846153846,
            0.2704273503745901
        },
    
        {
            true,
            7.4375,
            24.913522307172865,
            0.2860576923076923,
            0.9582123964297256,
            -0.9626358695652174,
            0.2707991555127485
        },
    
        {
            true,
            6.473958333333333,
            25.18110131623047,
            0.2489983974358974,
            0.968503896778095,
            -0.9626456093189963,
            0.27076453028204805
        },
    
        {
            true,
            5.5,
            25.411611519146124,
            0.21153846153846154,
            0.9773696738133124,
            -0.9627659574468085,
            0.27033629275687365
        },
    
        {
            true,
            4.515625,
            25.604865374755928,
            0.1736778846153846,
            0.9848025144136895,
            -0.9629934210526315,
            0.26952489868164137
        },
    
        {
            true,
            3.5208333333333335,
            25.760507227903897,
            0.13541666666666669,
            0.9907887395347653,
            -0.9633246527777778,
            0.26833861695733224
        },
    
        {
            true,
            2.515625,
            25.878014430388106,
            0.0967548076923077,
            0.9953082473226195,
            -0.963756443298969,
            0.26678365392152686
        },
    
        {
            true,
            1.5,
            25.95669470483482,
            0.057692307692307696,
            0.9983344117244162,
            -0.9642857142857143,
            0.26486423168198797
        },
    
        {
            true,
            0.4739583333333333,
            25.995679708333537,
            0.018229166666666664,
            0.9998338349359052,
            -0.9649095117845118,
            0.2625826233165004
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            27.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            26.276041666666668,
            6.2104455823714595,
            0.9731867283950618,
            0.2300165030507948,
            -0.9960565476190476,
            0.08872065117673514
        },
    
        {
            true,
            25.541666666666668,
            8.753471533562488,
            0.9459876543209877,
            0.32420264939120325,
            -0.9923708920187793,
            0.12328833145862658
        },
    
        {
            true,
            24.796875,
            10.682461805893574,
            0.9184027777777778,
            0.39564673355161384,
            -0.9889322916666666,
            0.1483675250818552
        },
    
        {
            true,
            24.041666666666668,
            12.288135085882185,
            0.8904320987654322,
            0.45511611429193277,
            -0.9857305936073059,
            0.16833061761482446
        },
    
        {
            true,
            23.276041666666668,
            13.683050987685355,
            0.8620756172839507,
            0.5067796662105687,
            -0.9827561936936936,
            0.18490609442818048
        },
    
        {
            true,
            22.5,
            14.9248115565993,
            0.8333333333333334,
            0.5527707983925667,
            -0.98,
            0.198997487421324
        },
    
        {
            true,
            21.713541666666668,
            16.0474953899333,
            0.8042052469135803,
            0.5943516811086407,
            -0.9774533991228069,
            0.21115125513070132
        },
    
        {
            true,
            20.916666666666668,
            17.07316770712323,
            0.7746913580246914,
            0.6323395447082677,
            -0.975108225108225,
            0.22172945074186012
        },
    
        {
            true,
            20.109375,
            18.017020761196203,
            0.7447916666666666,
            0.6672970652294891,
            -0.9729567307692307,
            0.2309874456563616
        },
    
        {
            true,
            19.291666666666668,
            18.889986691954608,
            0.7145061728395062,
            0.6996291367390596,
            -0.9709915611814346,
            0.23911375559436213
        },
    
        {
            true,
            18.463541666666668,
            19.700193631618543,
            0.68383487654321,
            0.7296368011710571,
            -0.9692057291666666,
            0.2462524203952318
        },
    
        {
            true,
            17.625,
            20.453835214941964,
            0.6527777777777778,
            0.757549452405258,
            -0.9675925925925926,
            0.252516484135086
        },
    
        {
            true,
            16.776041666666668,
            21.155718517655313,
            0.62133487654321,
            0.7835451302835301,
            -0.9661458333333333,
            0.2579965672884794
        },
    
        {
            true,
            15.916666666666666,
            21.80962453189468,
            0.5895061728395061,
            0.8077638715516549,
            -0.9648594377510039,
            0.2627665606252371
        },
    
        {
            true,
            15.046875,
            22.418553760989468,
            0.5572916666666666,
            0.8303168059625728,
            -0.9637276785714286,
            0.26688754477368415
        },
    
        {
            true,
            14.166666666666666,
            22.984898423868565,
            0.5246913580246912,
            0.8512925342173542,
            -0.9627450980392156,
            0.2704105696925713
        },
    
        {
            true,
            13.276041666666666,
            23.510566085590764,
            0.49170524691358014,
            0.8707617068737319,
            -0.9619064922480619,
            0.2733786754138461
        },
    
        {
            true,
            12.375,
            23.997070133664234,
            0.4583333333333333,
            0.8887803753208976,
            -0.9612068965517241,
            0.27582839234096823
        },
    
        {
            true,
            11.463541666666666,
            24.445596995299525,
            0.4245756172839506,
            0.9053924813073898,
            -0.9606415719696969,
            0.2777908749465855
        },
    
        {
            true,
            10.541666666666666,
            24.857056621589148,
            0.39043209876543206,
            0.920631726725524,
            -0.9602059925093632,
            0.27929277102909156
        },
    
        {
            true,
            9.609375,
            25.232120642335534,
            0.3559027777777778,
            0.9345229867531679,
            -0.9598958333333333,
            0.2803568960259504
        },
    
        {
            true,
            8.666666666666666,
            25.57125121868089,
            0.3209876543209877,
            0.9470833784696626,
            -0.9597069597069596,
            0.2810027606448449
        },
    
        {
            true,
            7.713541666666667,
            25.87472270298944,
            0.28568672839506176,
            0.958323063073683,
            -0.9596354166666666,
            0.28124698590205915
        },
    
        {
            true,
            6.75,
            26.142637586900065,
            0.24999999999999997,
            0.9682458365518541,
            -0.9596774193548387,
            0.2811036299666674
        },
    
        {
            true,
            5.776041666666667,
            26.374937775565094,
            0.2139274691358025,
            0.9768495472431517,
            -0.9598293439716313,
            0.2805844444209053
        },
    
        {
            true,
            4.791666666666667,
            26.571411903689942,
            0.17746913580246915,
            0.9841263668033312,
            -0.9600877192982457,
            0.2796990726704205
        },
    
        {
            true,
            3.796875,
            26.731699164743997,
            0.14062500000000003,
            0.9900629320275556,
            -0.96044921875,
            0.27845519963274995
        },
    
        {
            true,
            2.7916666666666665,
            26.855289929960207,
            0.10339506172839506,
            0.9946403677763039,
            -0.9609106529209621,
            0.2768586590717547
        },
    
        {
            true,
            1.7760416666666667,
            26.94152326796434,
            0.06577932098765432,
            0.9978341951097903,
            -0.9614689625850341,
            0.27491350273433
        },
    
        {
            true,
            0.75,
            26.989581323169872,
            0.027777777777777776,
            0.9996141230803657,
            -0.9621212121212122,
            0.27262203356737247
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            28.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            27.286458333333332,
            6.2808591469052955,
            0.974516369047619,
            0.22431639810376056,
            -0.9958484299516909,
            0.09102694415804775
        },
    
        {
            true,
            26.5625,
            8.856274258964659,
            0.9486607142857143,
            0.3162955092487378,
            -0.9919642857142857,
            0.12651820369949512
        },
    
        {
            true,
            25.828125,
            10.81239839186362,
            0.9224330357142857,
            0.38615708542370075,
            -0.9883362676056338,
            0.15228730129385382
        },
    
        {
            true,
            25.083333333333332,
            12.442925254492566,
            0.8958333333333333,
            0.4443901876604488,
            -0.9849537037037037,
            0.17281840631239676
        },
    
        {
            true,
            24.328125,
            13.861541544300728,
            0.8688616071428571,
            0.49505505515359743,
            -0.981806506849315,
            0.18988413074384558
        },
    
        {
            true,
            23.5625,
            15.126420387851185,
            0.8415178571428571,
            0.5402292995661138,
            -0.9788851351351351,
            0.2044110863223133
        },
    
        {
            true,
            22.786458333333332,
            16.27197949308147,
            0.8138020833333333,
            0.5811421247529097,
            -0.9761805555555556,
            0.21695972657441961
        },
    
        {
            true,
            22.0,
            17.320508075688775,
            0.7857142857142857,
            0.618589574131742,
            -0.9736842105263158,
            0.2279014220485365
        },
    
        {
            true,
            21.203125,
            18.2873587550082,
            0.7572544642857143,
            0.6531199555360071,
            -0.971387987012987,
            0.23749816564945714
        },
    
        {
            true,
            20.395833333333332,
            19.183586281998707,
            0.728422619047619,
            0.6851280814999539,
            -0.9692841880341881,
            0.2459434138717783
        },
    
        {
            true,
            19.578125,
            20.017417952482656,
            0.69921875,
            0.7149077840172378,
            -0.9673655063291139,
            0.2533850373731982
        },
    
        {
            true,
            18.75,
            20.79513164180501,
            0.6696428571428571,
            0.7426832729216075,
            -0.965625,
            0.25993914552256264
        },
    
        {
            true,
            17.911458333333332,
            21.521609149254243,
            0.6396949404761905,
            0.7686288981876516,
            -0.9640560699588478,
            0.2656988783858548
        },
    
        {
            true,
            17.0625,
            22.20070029863923,
            0.609375,
            0.7928821535228296,
            -0.9626524390243902,
            0.27074024754438086
        },
    
        {
            true,
            16.203125,
            22.83547109727266,
            0.5786830357142857,
            0.8155525391883093,
            -0.9614081325301205,
            0.2751261577984658
        },
    
        {
            true,
            15.333333333333334,
            23.42837785440744,
            0.5476190476190477,
            0.8367277805145514,
            -0.9603174603174603,
            0.2789092601715171
        },
    
        {
            true,
            14.453125,
            23.981392322681664,
            0.5161830357142857,
            0.8564782972386308,
            -0.959375,
            0.2821340273256666
        },
    
        {
            true,
            13.5625,
            24.49609343854648,
            0.484375,
            0.8748604799480886,
            -0.9585755813953488,
            0.2848382957970521
        },
    
        {
            true,
            12.661458333333334,
            24.97373566115538,
            0.45219494047619047,
            0.8919191307555492,
            -0.9579142720306514,
            0.28705443288684346
        },
    
        {
            true,
            11.75,
            25.415300509732322,
            0.41964285714285715,
            0.9076893039190115,
            -0.9573863636363636,
            0.28881023306514003
        },
    
        {
            true,
            10.828125,
            25.82153575960142,
            0.38671875000000006,
            0.9221977057000509,
            -0.9569873595505618,
            0.29012961527642045
        },
    
        {
            true,
            9.895833333333334,
            26.192985370875327,
            0.35342261904761907,
            0.9354637632455474,
            -0.956712962962963,
            0.2910331707875036
        },
    
        {
            true,
            8.953125,
            26.53001230181349,
            0.31975446428571425,
            0.9475004393504817,
            -0.9565590659340659,
            0.29153859672322513
        },
    
        {
            true,
            8.0,
            26.832815729997478,
            0.2857142857142857,
            0.9583148474999098,
            -0.9565217391304348,
            0.2916610405434508
        },
    
        {
            true,
            7.036458333333333,
            27.10144376455365,
            0.2513020833333333,
            0.9679087058769161,
            -0.9565972222222221,
            0.2914133738124048
        },
    
        {
            true,
            6.0625,
            27.335802416428166,
            0.21651785714285715,
            0.9762786577295773,
            -0.956781914893617,
            0.290806408685406
        },
    
        {
            true,
            5.078125,
            27.535661359124372,
            0.18136160714285712,
            0.9834164771115846,
            -0.9570723684210526,
            0.28984906693815127
        },
    
        {
            true,
            4.083333333333333,
            27.70065683136212,
            0.14583333333333331,
            0.9893091725486471,
            -0.9574652777777778,
            0.2885485086600221
        },
    
        {
            true,
            3.078125,
            27.830291886438687,
            0.10993303571428571,
            0.9939389959442388,
            -0.9579574742268041,
            0.2869102256333885
        },
    
        {
            true,
            2.0625,
            27.923934066495715,
            0.0736607142857143,
            0.9972833595177042,
            -0.9585459183673469,
            0.28493810271934406
        },
    
        {
            true,
            1.0364583333333333,
            27.98081046223043,
            0.03701636904761905,
            0.9993146593653724,
            -0.9592276936026937,
            0.2826344491134387
        },
    
        {
            true,
            0.0,
            28.0,
            0.0,
            1.0,
            -0.96,
            0.28
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            29.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            28.296875,
            6.3471934927474045,
            0.9757543103448276,
            0.21886874112922083,
            -0.9956341911764706,
            0.09334108077569712
        },
    
        {
            true,
            27.583333333333332,
            8.953196201481473,
            0.9511494252873562,
            0.30873090349936116,
            -0.9915458937198068,
            0.12975646668813728
        },
    
        {
            true,
            26.859375,
            10.93498855094851,
            0.9261853448275862,
            0.37706857072236244,
            -0.9877232142857143,
            0.1562141221564073
        },
    
        {
            true,
            26.125,
            12.58905774869589,
            0.9008620689655172,
            0.4341054396102031,
            -0.9841549295774648,
            0.17731067251684351
        },
    
        {
            true,
            25.380208333333332,
            14.0301470040979,
            0.8751795977011494,
            0.4837981725551,
            -0.9808304398148149,
            0.19486315283469305
        },
    
        {
            true,
            24.625,
            15.316963635133433,
            0.8491379310344828,
            0.5281711598321873,
            -0.9777397260273972,
            0.2098214196593621
        },
    
        {
            true,
            23.859375,
            16.48424170562222,
            0.8227370689655172,
            0.5684221277800766,
            -0.9748733108108109,
            0.22276002304894893
        },
    
        {
            true,
            23.083333333333332,
            17.554478694117417,
            0.7959770114942528,
            0.6053268515212903,
            -0.9722222222222223,
            0.23405971592156558
        },
    
        {
            true,
            22.296875,
            18.54317570521228,
            0.7688577586206896,
            0.6394198519038717,
            -0.9697779605263158,
            0.24398915401595106
        },
    
        {
            true,
            21.5,
            19.461500456028563,
            0.7413793103448276,
            0.6710862226216746,
            -0.9675324675324676,
            0.25274675916920214
        },
    
        {
            true,
            20.692708333333332,
            20.317771084240448,
            0.7135416666666666,
            0.7006127960082913,
            -0.9654780982905984,
            0.26048424466974934
        },
    
        {
            true,
            19.875,
            21.118342146106073,
            0.6853448275862069,
            0.7282186946933129,
            -0.9636075949367089,
            0.26732078665957054
        },
    
        {
            true,
            19.046875,
            21.86816299405085,
            0.6567887931034483,
            0.7540745860017534,
            -0.9619140625,
            0.27335203742563563
        },
    
        {
            true,
            18.208333333333332,
            22.57114523506112,
            0.6278735632183907,
            0.7783153529331421,
            -0.9603909465020577,
            0.27865611401310025
        },
    
        {
            true,
            17.359375,
            23.23041324663371,
            0.5985991379310346,
            0.8010487326425418,
            -0.9590320121951219,
            0.2832977225199233
        },
    
        {
            true,
            16.5,
            23.84848003542364,
            0.5689655172413793,
            0.8223613805318497,
            -0.9578313253012049,
            0.28733108476414027
        },
    
        {
            true,
            15.630208333333334,
            24.427373732282337,
            0.5389727011494253,
            0.8423232321476668,
            -0.9567832341269842,
            0.2908020682414564
        },
    
        {
            true,
            14.75,
            24.968730444297723,
            0.5086206896551724,
            0.8609907049757836,
            -0.9558823529411765,
            0.2937497699329144
        },
    
        {
            true,
            13.859375,
            25.47386355874144,
            0.47790948275862066,
            0.8784090882324634,
            -0.9551235465116279,
            0.29620771579931904
        },
    
        {
            true,
            12.958333333333334,
            25.94381616536438,
            0.4468390804597701,
            0.8946143505298063,
            -0.9545019157088123,
            0.2982047835099354
        },
    
        {
            true,
            12.046875,
            26.379401106438618,
            0.41540948275862066,
            0.9096345209116765,
            -0.9540127840909091,
            0.2997659216640752
        },
    
        {
            true,
            11.125,
            26.781231767788427,
            0.38362068965517243,
            0.923490750613394,
            -0.9536516853932584,
            0.3009127164920048
        },
    
        {
            true,
            10.192708333333334,
            27.14974579681359,
            0.3514727011494253,
            0.9361981309246066,
            -0.9534143518518519,
            0.3016638421868177
        },
    
        {
            true,
            9.25,
            27.48522330271304,
            0.31896551724137934,
            0.9477663207832083,
            -0.9532967032967034,
            0.30203542090893454
        },
    
        {
            true,
            8.296875,
            27.78780065486247,
            0.2860991379310345,
            0.9582000225814643,
            -0.9532948369565217,
            0.3020413114658964
        },
    
        {
            true,
            7.333333333333333,
            28.057480682025286,
            0.25287356321839083,
            0.9674993338629411,
            -0.953405017921147,
            0.30169334066693854
        },
    
        {
            true,
            6.359375,
            28.294139845723794,
            0.21928879310344832,
            0.975659994680131,
            -0.953623670212766,
            0.3010014877204659
        },
    
        {
            true,
            5.375,
            28.497532787944994,
            0.1853448275862069,
            0.9826735444118964,
            -0.9539473684210527,
            0.2999740293467894
        },
    
        {
            true,
            4.380208333333333,
            28.66729451756125,
            0.15104166666666663,
            0.9885273971572843,
            -0.954372829861111,
            0.2986176512245963
        },
    
        {
            true,
            3.375,
            28.802940388092324,
            0.11637931034482758,
            0.9932048409687009,
            -0.9548969072164949,
            0.29693752977414767
        },
    
        {
            true,
            2.359375,
            28.90386392179037,
            0.08135775862068964,
            0.9966849628203576,
            -0.9555165816326531,
            0.29493738695704463
        },
    
        {
            true,
            1.3333333333333333,
            28.96933244350346,
            0.04597701149425287,
            0.9989424980518435,
            -0.9562289562289561,
            0.292619519631348
        },
    
        {
            true,
            0.296875,
            28.998480395261662,
            0.010237068965517241,
            0.9999475998366091,
            -0.95703125,
            0.2899848039526166
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            30.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            29.307291666666668,
            6.409575271804719,
            0.9769097222222223,
            0.21365250906015731,
            -0.9954135572139303,
            0.09566530256424954
        },
    
        {
            true,
            28.604166666666668,
            9.044426422142841,
            0.9534722222222223,
            0.3014808807380947,
            -0.9911151960784313,
            0.1330062709138653
        },
    
        {
            true,
            27.890625,
            11.05047678199339,
            0.9296875,
            0.3683492260664464,
            -0.9870923913043478,
            0.16015183742019407
        },
    
        {
            true,
            27.166666666666668,
            12.726830800408331,
            0.9055555555555556,
            0.4242276933469444,
            -0.9833333333333333,
            0.18181186857726186
        },
    
        {
            true,
            26.432291666666668,
            14.189219754738588,
            0.881076388888889,
            0.4729739918246196,
            -0.9798268779342723,
            0.19984816555969842
        },
    
        {
            true,
            25.6875,
            15.4968494782004,
            0.85625,
            0.5165616492733467,
            -0.9765625,
            0.2152340205305611
        },
    
        {
            true,
            24.932291666666668,
            16.6847484922088,
            0.8310763888888889,
            0.5561582830736267,
            -0.9735302511415524,
            0.22855819852340822
        },
    
        {
            true,
            24.166666666666668,
            17.77560750641795,
            0.8055555555555556,
            0.5925202502139316,
            -0.9707207207207207,
            0.24021091224889118
        },
    
        {
            true,
            23.390625,
            18.785064868383472,
            0.7796875,
            0.6261688289461157,
            -0.968125,
            0.2504675315784463
        },
    
        {
            true,
            22.604166666666668,
            19.7243922417284,
            0.7534722222222222,
            0.6574797413909467,
            -0.9657346491228069,
            0.25953147686484734
        },
    
        {
            true,
            21.807291666666668,
            20.60199092721212,
            0.7269097222222223,
            0.6867330309070707,
            -0.9635416666666666,
            0.2675583237300275
        },
    
        {
            true,
            21.0,
            21.42428528562855,
            0.7,
            0.714142842854285,
            -0.9615384615384616,
            0.274670324174725
        },
    
        {
            true,
            20.182291666666668,
            22.196285794735957,
            0.6727430555555556,
            0.7398761931578652,
            -0.9597178270042194,
            0.28096564297134125
        },
    
        {
            true,
            19.354166666666668,
            22.921959616029536,
            0.6451388888888889,
            0.7640653205343179,
            -0.9580729166666666,
            0.2865244952003692
        },
    
        {
            true,
            18.515625,
            23.604483278804793,
            0.6171875,
            0.7868161092934931,
            -0.9565972222222222,
            0.29141337381240484
        },
    
        {
            true,
            17.666666666666668,
            24.246420125224443,
            0.5888888888888889,
            0.8082140041741481,
            -0.9552845528455284,
            0.29568805030761514
        },
    
        {
            true,
            16.807291666666668,
            24.849848024315907,
            0.5602430555555556,
            0.8283282674771969,
            -0.9541290160642569,
            0.29939575932910734
        },
    
        {
            true,
            15.9375,
            25.416453209486175,
            0.5312499999999999,
            0.8472151069828724,
            -0.953125,
            0.30257682392245444
        },
    
        {
            true,
            15.057291666666666,
            25.947600422099352,
            0.5019097222222222,
            0.8649200140699784,
            -0.952267156862745,
            0.30526588731881593
        },
    
        {
            true,
            14.166666666666666,
            26.44438608770405,
            0.4722222222222222,
            0.8814795362568016,
            -0.9515503875968991,
            0.3074928614849308
        },
    
        {
            true,
            13.265625,
            26.907679077902184,
            0.44218750000000007,
            0.8969226359300729,
            -0.9509698275862069,
            0.3092836675620941
        },
    
        {
            true,
            12.354166666666666,
            27.33815220478923,
            0.41180555555555554,
            0.911271740159641,
            -0.9505208333333333,
            0.3106608205089685
        },
    
        {
            true,
            11.432291666666666,
            27.736306661995645,
            0.38107638888888884,
            0.9245435553998547,
            -0.9501989700374531,
            0.31164389507860274
        },
    
        {
            true,
            10.5,
            28.10249099279279,
            0.35,
            0.9367496997597597,
            -0.95,
            0.3122498999199199
        },
    
        {
            true,
            9.557291666666666,
            28.436915725835387,
            0.3185763888888889,
            0.9478971908611796,
            -0.9499198717948717,
            0.31249357940478445
        },
    
        {
            true,
            8.604166666666666,
            28.73966450695314,
            0.2868055555555556,
            0.9579888168984381,
            -0.9499547101449275,
            0.3123876576842733
        },
    
        {
            true,
            7.640625,
            29.01070232878506,
            0.2546875,
            0.9670234109595021,
            -0.9501008064516129,
            0.3119430357933878
        },
    
        {
            true,
            6.666666666666667,
            29.249881291307073,
            0.22222222222222224,
            0.9749960430435691,
            -0.950354609929078,
            0.3111689499075221
        },
    
        {
            true,
            5.682291666666667,
            29.456944196826164,
            0.18940972222222222,
            0.9818981398942054,
            -0.9507127192982455,
            0.3100730968086965
        },
    
        {
            true,
            4.6875,
            29.631526179898326,
            0.15625000000000003,
            0.9877175393299443,
            -0.951171875,
            0.30866173104060757
        },
    
        {
            true,
            3.6822916666666665,
            29.773154486577287,
            0.12274305555555555,
            0.9924384828859095,
            -0.9517289518900344,
            0.3069397369750236
        },
    
        {
            true,
            2.6666666666666665,
            29.881246441353294,
            0.08888888888888888,
            0.9960415480451098,
            -0.9523809523809524,
            0.3049106779729928
        },
    
        {
            true,
            1.640625,
            29.95510556832299,
            0.05468750000000001,
            0.9985035189440997,
            -0.953125,
            0.30257682392245444
        },
    
        {
            true,
            0.6041666666666666,
            29.993915760348614,
            0.020138888888888887,
            0.9997971920116204,
            -0.9539583333333335,
            0.29993915760348616
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            31.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            30.317708333333332,
            6.468118846691877,
            0.9779905913978494,
            0.20864899505457668,
            -0.9951862373737375,
            0.09800180070745268
        },
    
        {
            true,
            29.625,
            9.130135541162574,
            0.9556451612903226,
            0.294520501327825,
            -0.9906716417910447,
            0.13627067971884438
        },
    
        {
            true,
            28.921875,
            11.159083586225842,
            0.9329637096774194,
            0.35997043826534975,
            -0.9864430147058824,
            0.16410417038567415
        },
    
        {
            true,
            28.208333333333332,
            12.85651315697828,
            0.9099462365591398,
            0.4147262308702671,
            -0.982487922705314,
            0.1863262776373664
        },
    
        {
            true,
            27.484375,
            14.339077057446026,
            0.8865927419354839,
            0.46255087282083956,
            -0.9787946428571429,
            0.20484395796351465
        },
    
        {
            true,
            26.75,
            15.666445033893298,
            0.8629032258064516,
            0.5053691946417193,
            -0.9753521126760564,
            0.22065415540694786
        },
    
        {
            true,
            26.005208333333332,
            16.873918914701786,
            0.838877688172043,
            0.5443199649903802,
            -0.9721498842592593,
            0.2343599849264137
        },
    
        {
            true,
            25.25,
            17.984368212422698,
            0.8145161290322581,
            0.5801409100781515,
            -0.9691780821917808,
            0.24636120838935202
        },
    
        {
            true,
            24.484375,
            19.013557816972998,
            0.7898185483870968,
            0.6133405747410644,
            -0.9664273648648649,
            0.25693997049963513
        },
    
        {
            true,
            23.708333333333332,
            19.97285484239936,
            0.7647849462365591,
            0.6442856400773987,
            -0.9638888888888889,
            0.2663047312319915
        },
    
        {
            true,
            22.921875,
            20.870736606176003,
            0.7394153225806451,
            0.6732495679411614,
            -0.9615542763157895,
            0.2746149553444211
        },
    
        {
            true,
            22.125,
            21.713690957550263,
            0.7137096774193549,
            0.700441643791944,
            -0.9594155844155844,
            0.2819959864616917
        },
    
        {
            true,
            21.317708333333332,
            22.506783675481724,
            0.6876680107526881,
            0.7260252798542491,
            -0.9574652777777778,
            0.28854850866002213
        },
    
        {
            true,
            20.5,
            23.25403190846697,
            0.6612903225806451,
            0.7501300615634506,
            -0.9556962025316456,
            0.294354834284392
        },
    
        {
            true,
            19.671875,
            23.958658851955278,
            0.6345766129032258,
            0.7728599629662993,
            -0.9541015625,
            0.29948323564944096
        },
    
        {
            true,
            18.833333333333332,
            24.623272641051507,
            0.6075268817204301,
            0.7942991174532744,
            -0.9526748971193416,
            0.30399102025989516
        },
    
        {
            true,
            17.984375,
            25.249995165531715,
            0.5801411290322581,
            0.8145159730816682,
            -0.9514100609756098,
            0.3079267703113624
        },
    
        {
            true,
            17.125,
            25.840556785797013,
            0.5524193548387096,
            0.8335663479289359,
            -0.9503012048192772,
            0.3113320094674339
        },
    
        {
            true,
            16.255208333333332,
            26.396367212931604,
            0.5243615591397849,
            0.8514957165461808,
            -0.949342757936508,
            0.31424246682061435
        },
    
        {
            true,
            15.375,
            26.918569334197535,
            0.49596774193548393,
            0.8683409462644367,
            -0.9485294117647058,
            0.3166890509905592
        },
    
        {
            true,
            14.484375,
            27.408080575979323,
            0.46723790322580644,
            0.884131631483204,
            -0.9478561046511628,
            0.3186986113485968
        },
    
        {
            true,
            13.583333333333334,
            27.865624980530324,
            0.43817204301075263,
            0.8988911284042039,
            -0.9473180076628352,
            0.3202945400060957
        },
    
        {
            true,
            12.671875,
            28.29175823423449,
            0.40877016129032256,
            0.912637362394661,
            -0.9469105113636364,
            0.32149725266175555
        },
    
        {
            true,
            11.75,
            28.686887248357916,
            0.3790322580645161,
            0.9253834596244489,
            -0.9466292134831461,
            0.32232457582424623
        },
    
        {
            true,
            10.817708333333334,
            29.051285452023127,
            0.34895833333333337,
            0.9371382403878428,
            -0.9464699074074074,
            0.3227920605780347
        },
    
        {
            true,
            9.875,
            29.385104645040826,
            0.31854838709677424,
            0.9479066014529299,
            -0.9464285714285714,
            0.3229132378575915
        },
    
        {
            true,
            8.921875,
            29.688384032890287,
            0.2878024193548387,
            0.9576898075125899,
            -0.9465013586956522,
            0.32269982644445966
        },
    
        {
            true,
            7.958333333333333,
            29.96105689984176,
            0.2567204301075268,
            0.9664857064465083,
            -0.9466845878136201,
            0.32216190214883617
        },
    
        {
            true,
            6.984375,
            30.20295525042831,
            0.22530241935483872,
            0.9742888790460745,
            -0.9469747340425532,
            0.32130803457902457
        },
    
        {
            true,
            6.0,
            30.4138126514911,
            0.1935483870967742,
            0.9810907306932612,
            -0.9473684210526315,
            0.32014539633148525
        },
    
        {
            true,
            5.005208333333333,
            30.593265427867138,
            0.16145833333333331,
            0.9868795299311979,
            -0.9478624131944445,
            0.31867984820694933
        },
    
        {
            true,
            4.0,
            30.740852297878796,
            0.12903225806451613,
            0.9916403967057676,
            -0.9484536082474226,
            0.31691600307091544
        },
    
        {
            true,
            2.984375,
            30.856012475032724,
            0.09627016129032256,
            0.9953552411300878,
            -0.9491390306122449,
            0.31485727015339515
        },
    
        {
            true,
            1.9583333333333333,
            30.938082205520683,
            0.06317204301075269,
            0.9980026517909898,
            -0.9499158249158249,
            0.3125058808638453
        },
    
        {
            true,
            0.921875,
            30.986289653399535,
            0.029737903225806453,
            0.9995577307548237,
            -0.95078125,
            0.30986289653399535
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            32.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            31.328125,
            6.5229275624044,
            0.97900390625,
            0.2038414863251375,
            -0.994951923076923,
            0.10035273172929846
        },
    
        {
            true,
            30.645833333333332,
            9.210477691496552,
            0.9576822916666666,
            0.28782742785926724,
            -0.9902146464646465,
            0.1395526922954023
        },
    
        {
            true,
            29.953125,
            11.261008069190565,
            0.93603515625,
            0.35190650216220515,
            -0.9857742537313433,
            0.16807474730135172
        },
    
        {
            true,
            29.25,
            12.97834735241741,
            0.9140625,
            0.40557335476304407,
            -0.9816176470588235,
            0.19085804930025604
        },
    
        {
            true,
            28.536458333333332,
            14.480005034181813,
            0.8917643229166666,
            0.45250015731818166,
            -0.9777324879227054,
            0.20985514542292483
        },
    
        {
            true,
            27.8125,
            15.826081124207597,
            0.869140625,
            0.4945650351314874,
            -0.9741071428571428,
            0.22608687320296567
        },
    
        {
            true,
            27.078125,
            17.05213026235652,
            0.84619140625,
            0.5328790706986413,
            -0.9707306338028169,
            0.24017084876558478
        },
    
        {
            true,
            26.333333333333332,
            18.181186857726193,
            0.8229166666666666,
            0.5681620893039435,
            -0.9675925925925927,
            0.252516484135086
        },
    
        {
            true,
            25.578125,
            19.229132104293605,
            0.79931640625,
            0.6009103782591751,
            -0.9646832191780822,
            0.2634127685519672
        },
    
        {
            true,
            24.8125,
            20.20742051202973,
            0.775390625,
            0.6314818910009291,
            -0.9619932432432432,
            0.27307325016256395
        },
    
        {
            true,
            24.036458333333332,
            21.124598713110046,
            0.7511393229166666,
            0.660143709784689,
            -0.959513888888889,
            0.2816613161748006
        },
    
        {
            true,
            23.25,
            21.987212192545012,
            0.7265625,
            0.6871003810170316,
            -0.9572368421052632,
            0.2893054235861186
        },
    
        {
            true,
            22.453125,
            22.800376701589276,
            0.70166015625,
            0.7125117719246649,
            -0.9551542207792207,
            0.29610878833232823
        },
    
        {
            true,
            21.645833333333332,
            23.568154346608384,
            0.6764322916666666,
            0.736504823331512,
            -0.9532585470085471,
            0.30215582495651777
        },
    
        {
            true,
            20.828125,
            24.293810096079515,
            0.65087890625,
            0.7591815655024848,
            -0.9515427215189873,
            0.3075165834946774
        },
    
        {
            true,
            20.0,
            24.979991993593593,
            0.625,
            0.7806247497997998,
            -0.95,
            0.3122498999199199
        },
    
        {
            true,
            19.161458333333332,
            25.628860968445917,
            0.5987955729166666,
            0.8009019052639349,
            -0.9486239711934157,
            0.3164056909684681
        },
    
        {
            true,
            18.3125,
            26.242186337079463,
            0.572265625,
            0.8200683230337332,
            -0.9474085365853658,
            0.3200266626473105
        },
    
        {
            true,
            17.453125,
            26.82141733269096,
            0.54541015625,
            0.8381692916465925,
            -0.9463478915662651,
            0.32314960641796336
        },
    
        {
            true,
            16.583333333333332,
            27.367737494275183,
            0.5182291666666666,
            0.8552417966960995,
            -0.945436507936508,
            0.32580639874137124
        },
    
        {
            true,
            15.703125,
            27.882106542267838,
            0.49072265625,
            0.8713158294458699,
            -0.9446691176470589,
            0.32802478285020986
        },
    
        {
            true,
            14.8125,
            28.365292943137394,
            0.462890625,
            0.8864154044730436,
            -0.9440406976744186,
            0.3298289877108999
        },
    
        {
            true,
            13.911458333333334,
            28.817899421018364,
            0.4347330729166667,
            0.9005593569068239,
            -0.9435464559386973,
            0.3312402232300961
        },
    
        {
            true,
            13.0,
            29.24038303442689,
            0.40625,
            0.9137619698258403,
            -0.9431818181818182,
            0.3322770799366692
        },
    
        {
            true,
            12.078125,
            29.633070993138308,
            0.37744140625,
            0.9260334685355721,
            -0.9429424157303371,
            0.3329558538554866
        },
    
        {
            true,
            11.145833333333334,
            29.99617307767035,
            0.34830729166666674,
            0.9373804086771985,
            -0.9428240740740741,
            0.333290811974115
        },
    
        {
            true,
            10.203125,
            30.329791298892495,
            0.31884765625000006,
            0.9478059780903906,
            -0.9428228021978022,
            0.3332944098779395
        },
    
        {
            true,
            9.25,
            30.633927270266867,
            0.2890625,
            0.9573102271958396,
            -0.9429347826086957,
            0.33297747032898767
        },
    
        {
            true,
            8.286458333333334,
            30.908487641583672,
            0.2589518229166667,
            0.9658902387994898,
            -0.9431563620071685,
            0.33234932947939433
        },
    
        {
            true,
            7.3125,
            31.153287848154967,
            0.228515625,
            0.9735402452548427,
            -0.9434840425531915,
            0.3314179558314358
        },
    
        {
            true,
            6.328125,
            31.368054354460288,
            0.19775390625,
            0.980251698576884,
            -0.9439144736842106,
            0.3301900458364241
        },
    
        {
            true,
            5.333333333333333,
            31.55242550986462,
            0.16666666666666666,
            0.9860132971832694,
            -0.9444444444444445,
            0.32867109906108977
        },
    
        {
            true,
            4.328125,
            31.705951081530024,
            0.13525390625000003,
            0.9908109712978134,
            -0.9450708762886598,
            0.32686547506731983
        },
    
        {
            true,
            3.3125,
            31.828090482308234,
            0.103515625,
            0.9946278275721323,
            -0.9457908163265306,
            0.32477643349294116
        },
    
        {
            true,
            2.2864583333333335,
            31.918209666112705,
            0.07145182291666667,
            0.997444052066022,
            -0.946601430976431,
            0.32240615824356267
        },
    
        {
            true,
            1.25,
            31.975576617162044,
            0.0390625,
            0.9992367692863139,
            -0.9475,
            0.31975576617162044
        },
    
        {
            true,
            0.203125,
            31.99935530966796,
            0.00634765625,
            0.9999798534271237,
            -0.9484839108910891,
            0.31682530009572235
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            33.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            32.338541666666664,
            6.574094832998999,
            0.979955808080808,
            0.19921499493936362,
            -0.9947102864583334,
            0.10272023176560936
        },
    
        {
            true,
            31.666666666666668,
            9.28559218478941,
            0.9595959595959597,
            0.28138158135725483,
            -0.9897435897435897,
            0.14285526438137552
        },
    
        {
            true,
            30.984375,
            11.356430154735026,
            0.9389204545454546,
            0.34413424711318263,
            -0.9850852272727273,
            0.17206712355659132
        },
    
        {
            true,
            30.291666666666668,
            13.09255248435367,
            0.9179292929292929,
            0.3967440146773839,
            -0.9807213930348258,
            0.19541123110975625
        },
    
        {
            true,
            29.588541666666668,
            14.612262043911286,
            0.8966224747474748,
            0.4427958195124632,
            -0.9766390931372548,
            0.21488620652810717
        },
    
        {
            true,
            28.875,
            15.976056303105594,
            0.875,
            0.48412291827592707,
            -0.9728260869565217,
            0.23153704787109555
        },
    
        {
            true,
            28.151041666666668,
            17.219722793401676,
            0.8530618686868687,
            0.5218097816182325,
            -0.9692708333333333,
            0.24599603990573823
        },
    
        {
            true,
            27.416666666666668,
            18.36644736711182,
            0.8308080808080809,
            0.5565590111246006,
            -0.9659624413145539,
            0.2586823572832651
        },
    
        {
            true,
            26.671875,
            19.432217680552444,
            0.8082386363636364,
            0.588855081228862,
            -0.962890625,
            0.26989191222989506
        },
    
        {
            true,
            25.916666666666668,
            20.428567959817663,
            0.7853535353535354,
            0.6190475139338686,
            -0.9600456621004566,
            0.279843396709831
        },
    
        {
            true,
            25.151041666666668,
            21.364107823206595,
            0.7621527777777778,
            0.6473972067638362,
            -0.9574183558558558,
            0.2887041597730621
        },
    
        {
            true,
            24.375,
            22.245434924945837,
            0.7386363636363636,
            0.6741040886347224,
            -0.955,
            0.2966057989992778
        },
    
        {
            true,
            23.588541666666668,
            23.077710069240634,
            0.7148042929292929,
            0.6993245475527465,
            -0.9527823464912281,
            0.3036540798584294
        },
    
        {
            true,
            22.791666666666668,
            23.865035733381074,
            0.6906565656565657,
            0.7231829010115477,
            -0.9507575757575757,
            0.30993552900494903
        },
    
        {
            true,
            21.984375,
            24.61071424927312,
            0.6661931818181818,
            0.745779219674943,
            -0.9489182692307693,
            0.31552197755478356
        },
    
        {
            true,
            21.166666666666668,
            25.317429218272185,
            0.6414141414141414,
            0.7671948247961268,
            -0.9472573839662447,
            0.3204737875730656
        },
    
        {
            true,
            20.338541666666668,
            25.98737622141304,
            0.6163194444444445,
            0.7874962491337285,
            -0.9457682291666666,
            0.324842202767663
        },
    
        {
            true,
            19.5,
            26.622359023948274,
            0.5909090909090909,
            0.8067381522408568,
            -0.9444444444444444,
            0.3286710990610898
        },
    
        {
            true,
            18.651041666666668,
            27.223861679568238,
            0.5651830808080809,
            0.8249655054414617,
            -0.9432799796747967,
            0.3319983131654663
        },
    
        {
            true,
            17.791666666666668,
            27.793103411138205,
            0.5391414141414141,
            0.8422152548829759,
            -0.9422690763052208,
            0.33485666760407473
        },
    
        {
            true,
            16.921875,
            28.331080926861492,
            0.5127840909090909,
            0.8585176038442877,
            -0.94140625,
            0.3372747729388273
        },
    
        {
            true,
            16.041666666666668,
            28.838601397355518,
            0.48611111111111116,
            0.8738970120410763,
            -0.9406862745098039,
            0.3392776634983002
        },
    
        {
            true,
            15.151041666666666,
            29.316308369488315,
            0.45912247474747475,
            0.8883729808935853,
            -0.9401041666666666,
            0.34088730662195715
        },
    
        {
            true,
            14.25,
            29.764702249476645,
            0.4318181818181818,
            0.901960674226565,
            -0.9396551724137931,
            0.34212301436180054
        },
    
        {
            true,
            13.338541666666666,
            30.18415654290504,
            0.4041982323232323,
            0.9146714103910618,
            -0.9393347537878788,
            0.3430017788966482
        },
    
        {
            true,
            12.416666666666666,
            30.574930725823222,
            0.37626262626262624,
            0.9265130522976734,
            -0.9391385767790261,
            0.3435385474811598
        },
    
        {
            true,
            11.484375,
            30.937180396076418,
            0.34801136363636365,
            0.9374903150326187,
            -0.9390625,
            0.34374644884529354
        },
    
        {
            true,
            10.541666666666666,
            31.270965189595426,
            0.3194444444444444,
            0.9476050057453159,
            -0.9391025641025641,
            0.34363698010544425
        },
    
        {
            true,
            9.588541666666666,
            31.576254823943216,
            0.2905618686868687,
            0.9568562067861581,
            -0.9392549818840579,
            0.34322016112981757
        },
    
        {
            true,
            8.625,
            31.852933538372884,
            0.26136363636363635,
            0.9652404102537238,
            -0.9395161290322581,
            0.34250466170293425
        },
    
        {
            true,
            7.651041666666667,
            32.10080312725728,
            0.2318497474747475,
            0.9727516099168872,
            -0.9398825354609929,
            0.34149790560911997
        },
    
        {
            true,
            6.666666666666667,
            32.3195847058027,
            0.20202020202020202,
            0.9793813547212938,
            -0.9403508771929824,
            0.3402061547979231
        },
    
        {
            true,
            5.671875,
            32.508919298930486,
            0.171875,
            0.9851187666342571,
            -0.94091796875,
            0.3386345760305259
        },
    
        {
            true,
            4.666666666666667,
            32.66836730267098,
            0.14141414141414144,
            0.9899505243233631,
            -0.9415807560137457,
            0.3367872917801132
        },
    
        {
            true,
            3.6510416666666665,
            32.79740682963005,
            0.11063762626262626,
            0.9938608130190923,
            -0.9423363095238096,
            0.3346674166288781
        },
    
        {
            true,
            2.625,
            32.89543091373025,
            0.07954545454545454,
            0.9968312398100077,
            -0.9431818181818182,
            0.3322770799366692
        },
    
        {
            true,
            1.5885416666666667,
            32.96174351233963,
            0.048137626262626264,
            0.9988407124951403,
            -0.9441145833333334,
            0.32961743512339636
        },
    
        {
            true,
            0.5416666666666666,
            32.99555420389574,
            0.016414141414141412,
            0.9998652789059316,
            -0.9451320132013201,
            0.3266886554841163
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            34.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            33.348958333333336,
            6.621705073589217,
            0.9808517156862746,
            0.19475603157615343,
            -0.994460978835979,
            0.1051064297395114
        },
    
        {
            true,
            32.6875,
            9.35560493768308,
            0.9613970588235294,
            0.27516485110832584,
            -0.9892578125,
            0.1461813271512981
        },
    
        {
            true,
            32.015625,
            11.445512476921905,
            0.9416360294117647,
            0.3366327199094678,
            -0.984375,
            0.1760848073372601
        },
    
        {
            true,
            31.333333333333332,
            13.19932658214889,
            0.9215686274509803,
            0.3882154877102615,
            -0.9797979797979799,
            0.19998979669922562
        },
    
        {
            true,
            30.640625,
            14.73608155546701,
            0.9011948529411765,
            0.4334141633960885,
            -0.9755130597014925,
            0.21994151575323895
        },
    
        {
            true,
            29.9375,
            16.116640274883597,
            0.8805147058823529,
            0.4740188316142234,
            -0.9715073529411765,
            0.2370094158071117
        },
    
        {
            true,
            29.223958333333332,
            17.37700375011749,
            0.8595281862745098,
            0.5110883455916908,
            -0.9677687198067634,
            0.2518406340596737
        },
    
        {
            true,
            28.5,
            18.540496217739157,
            0.8382352941176471,
            0.5453087122864458,
            -0.9642857142857143,
            0.26486423168198797
        },
    
        {
            true,
            27.765625,
            19.62320229624551,
            0.8166360294117647,
            0.5771530087131032,
            -0.9610475352112676,
            0.27638313093303535
        },
    
        {
            true,
            27.020833333333332,
            20.63672856758605,
            0.7947303921568627,
            0.6069626049290014,
            -0.9580439814814815,
            0.28662123010536183
        },
    
        {
            true,
            26.265625,
            21.58974162326578,
            0.7725183823529411,
            0.6349924006842876,
            -0.9552654109589042,
            0.29574988525021617
        },
    
        {
            true,
            25.5,
            22.48888614404902,
            0.75,
            0.6614378277661476,
            -0.9527027027027027,
            0.30390386681147324
        },
    
        {
            true,
            24.723958333333332,
            23.339363408876373,
            0.7271752450980392,
            0.6864518649669522,
            -0.9503472222222222,
            0.31119151211835167
        },
    
        {
            true,
            23.9375,
            24.14531204499126,
            0.7040441176470589,
            0.71015623661739,
            -0.9481907894736842,
            0.3177014742762008
        },
    
        {
            true,
            23.140625,
            24.91006773594514,
            0.6806066176470589,
            0.73264905105721,
            -0.9462256493506493,
            0.32350737319409273
        },
    
        {
            true,
            22.333333333333332,
            25.636345726765004,
            0.6568627450980392,
            0.7540101684342648,
            -0.9444444444444445,
            0.3286710990610898
        },
    
        {
            true,
            21.515625,
            26.326372345224,
            0.6328125,
            0.7743050689771765,
            -0.9428401898734177,
            0.33324521955979747
        },
    
        {
            true,
            20.6875,
            26.981981835106183,
            0.6084558823529411,
            0.7935877010325347,
            -0.94140625,
            0.3372747729388273
        },
    
        {
            true,
            19.848958333333332,
            27.604688969115326,
            0.5837928921568627,
            0.811902616738686,
            -0.940136316872428,
            0.34079862924833737
        },
    
        {
            true,
            19.0,
            28.19574435974337,
            0.5588235294117647,
            0.8292865988159814,
            -0.9390243902439024,
            0.34385054097248013
        },
    
        {
            true,
            18.140625,
            28.756177155689087,
            0.5335477941176471,
            0.8457699163437967,
            -0.9380647590361446,
            0.3464599657311938
        },
    
        {
            true,
            17.270833333333332,
            29.286828369972437,
            0.5079656862745098,
            0.8613773049991893,
            -0.9372519841269842,
            0.3486527186901481
        },
    
        {
            true,
            16.390625,
            29.788377131179452,
            0.4820772058823529,
            0.8761287391523368,
            -0.9365808823529411,
            0.35045149566093475
        },
    
        {
            true,
            15.5,
            30.26136150274802,
            0.45588235294117646,
            0.8900400441984712,
            -0.936046511627907,
            0.3518762965435816
        },
    
        {
            true,
            14.598958333333334,
            30.706195068448274,
            0.4293811274509804,
            0.9031233843661257,
            -0.9356441570881227,
            0.3529447709017043
        },
    
        {
            true,
            13.6875,
            31.123180167682094,
            0.4025735294117647,
            0.9153876519906499,
            -0.9353693181818182,
            0.35367250190547833
        },
    
        {
            true,
            12.765625,
            31.51251843885815,
            0.37545955882352944,
            0.926838777613475,
            -0.9352176966292135,
            0.35407324088604664
        },
    
        {
            true,
            11.833333333333334,
            31.874319164842127,
            0.34803921568627455,
            0.9374799754365332,
            -0.9351851851851852,
            0.35415910183157917
        },
    
        {
            true,
            10.890625,
            32.20860579269731,
            0.3203125,
            0.9473119350793328,
            -0.9352678571428571,
            0.3539407229966738
        },
    
        {
            true,
            9.9375,
            32.51532090799659,
            0.2922794117647059,
            0.9563329678822526,
            -0.9354619565217391,
            0.35342740117387594
        },
    
        {
            true,
            8.973958333333334,
            32.79432987318992,
            0.2639399509803922,
            0.9645391139173507,
            -0.935763888888889,
            0.35262720293752603
        },
    
        {
            true,
            8.0,
            33.04542328371661,
            0.23529411764705882,
            0.9719242142269591,
            -0.9361702127659575,
            0.3515470562097512
        },
    
        {
            true,
            7.015625,
            33.26831835033708,
            0.20634191176470587,
            0.9784799514805025,
            -0.9366776315789473,
            0.3501928247403903
        },
    
        {
            true,
            6.020833333333333,
            33.462659278249575,
            0.17708333333333331,
            0.9841958611249875,
            -0.9372829861111112,
            0.3485693674817664
        },
    
        {
            true,
            5.015625,
            33.628016680431436,
            0.14751838235294118,
            0.9890593141303363,
            -0.9379832474226805,
            0.3466805843343447
        },
    
        {
            true,
            4.0,
            33.76388603226827,
            0.11764705882352941,
            0.993055471537302,
            -0.9387755102040817,
            0.34452944930885987
        },
    
        {
            true,
            2.9739583333333335,
            33.86968514515004,
            0.08746936274509805,
            0.9961672101514717,
            -0.9396569865319865,
            0.34211803176919225
        },
    
        {
            true,
            1.9375,
            33.94475060668439,
            0.05698529411764706,
            0.9983750178436585,
            -0.940625,
            0.3394475060668439
        },
    
        {
            true,
            0.890625,
            33.988333102836556,
            0.02619485294117647,
            0.999656855965781,
            -0.9416769801980198,
            0.3365181495330352
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            35.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            34.359375,
            6.665834502099118,
            0.9816964285714286,
            0.19045241434568908,
            -0.9942036290322581,
            0.1075134597112761
        },
    
        {
            true,
            33.708333333333336,
            9.420629697047257,
            0.9630952380952381,
            0.2691608484870645,
            -0.9887566137566138,
            0.14953380471503586
        },
    
        {
            true,
            33.046875,
            11.528402002635708,
            0.9441964285714286,
            0.32938291436102024,
            -0.983642578125,
            0.18013128129118294
        },
    
        {
            true,
            32.375,
            13.29884863437433,
            0.925,
            0.3799671038392666,
            -0.9788461538461538,
            0.2045976712980666
        },
    
        {
            true,
            31.692708333333332,
            14.851674602490586,
            0.9055059523809523,
            0.42433356007115963,
            -0.9743529040404041,
            0.2250253727650089
        },
    
        {
            true,
            31.0,
            16.24807680927192,
            0.8857142857142857,
            0.46423076597919777,
            -0.9701492537313433,
            0.24250860909361077
        },
    
        {
            true,
            30.296875,
            17.524250775264974,
            0.865625,
            0.500692879293285,
            -0.9662224264705882,
            0.25770957022448493
        },
    
        {
            true,
            29.583333333333332,
            18.703646406219534,
            0.8452380952380952,
            0.5343898973205581,
            -0.96256038647343,
            0.27106733922057297
        },
    
        {
            true,
            28.859375,
            19.802436077649006,
            0.8245535714285714,
            0.5657838879328287,
            -0.9591517857142857,
            0.28289194396641437
        },
    
        {
            true,
            28.125,
            20.832291640623698,
            0.8035714285714286,
            0.5952083325892485,
            -0.9559859154929577,
            0.29341255831864366
        },
    
        {
            true,
            27.380208333333332,
            21.801930915019064,
            0.7822916666666666,
            0.6229123118576876,
            -0.9530526620370371,
            0.30280459604193144
        },
    
        {
            true,
            26.625,
            22.71804073858483,
            0.7607142857142857,
            0.6490868782452809,
            -0.9503424657534246,
            0.31120603751486065
        },
    
        {
            true,
            25.859375,
            23.585858572656942,
            0.7388392857142857,
            0.673881673504484,
            -0.9478462837837838,
            0.3187278185494181
        },
    
        {
            true,
            25.083333333333332,
            24.40955527839229,
            0.7166666666666667,
            0.6974158650969225,
            -0.9455555555555556,
            0.32546073704523054
        },
    
        {
            true,
            24.296875,
            25.192496208878847,
            0.6941964285714286,
            0.719785605967967,
            -0.9434621710526315,
            0.33148021327472166
        },
    
        {
            true,
            23.5,
            25.937424698685874,
            0.6714285714285714,
            0.7410692771053107,
            -0.9415584415584416,
            0.33684967141150485
        },
    
        {
            true,
            22.692708333333332,
            26.646594313312608,
            0.6483630952380952,
            0.761331266094646,
            -0.9398370726495727,
            0.3416230040168283
        },
    
        {
            true,
            21.875,
            27.321866242992993,
            0.625,
            0.7806247497997998,
            -0.9382911392405063,
            0.3458464081391518
        },
    
        {
            true,
            21.046875,
            27.96478236522457,
            0.6013392857142857,
            0.7989937818635591,
            -0.9369140625,
            0.3495597795653071
        },
    
        {
            true,
            20.208333333333332,
            28.576620931959205,
            0.5773809523809523,
            0.816474883770263,
            -0.9356995884773663,
            0.35279778928344696
        },
    
        {
            true,
            19.359375,
            29.158439594899022,
            0.553125,
            0.8330982741399721,
            -0.934641768292683,
            0.35559072676706127
        },
    
        {
            true,
            18.5,
            29.71110903349116,
            0.5285714285714286,
            0.8488888295283188,
            -0.9337349397590361,
            0.35796516907820675
        },
    
        {
            true,
            17.630208333333332,
            30.235339490788984,
            0.503720238095238,
            0.863866842593971,
            -0.9329737103174603,
            0.3599445177474879
        },
    
        {
            true,
            16.75,
            30.731701872821816,
            0.4785714285714286,
            0.8780486249377661,
            -0.9323529411764706,
            0.3615494337979037
        },
    
        {
            true,
            15.859375,
            31.200644618491058,
            0.453125,
            0.8914469890997445,
            -0.9318677325581395,
            0.3627981932382681
        },
    
        {
            true,
            14.958333333333334,
            31.642507231395065,
            0.4273809523809524,
            0.9040716351827162,
            -0.9315134099616859,
            0.36370697967120763
        },
    
        {
            true,
            14.046875,
            32.057531139100135,
            0.40133928571428573,
            0.9159294611171467,
            -0.9312855113636364,
            0.3642901265806833
        },
    
        {
            true,
            13.125,
            32.445868381043525,
            0.375,
            0.9270248108869579,
            -0.9311797752808989,
            0.3645603188881295
        },
    
        {
            true,
            12.192708333333334,
            32.8075885047692,
            0.3483630952380953,
            0.9373596715648342,
            -0.9311921296296295,
            0.36452876116410216
        },
    
        {
            true,
            11.25,
            33.14268395890713,
            0.32142857142857145,
            0.9469338273973466,
            -0.9313186813186813,
            0.36420531822974866
        },
    
        {
            true,
            10.296875,
            33.45107420150173,
            0.2941964285714286,
            0.9557449771857638,
            -0.9315557065217391,
            0.36359863262501885
        },
    
        {
            true,
            9.333333333333334,
            33.73260868786891,
            0.26666666666666666,
            0.9637888196533975,
            -0.9318996415770608,
            0.3627162224502033
        },
    
        {
            true,
            8.359375,
            33.987068858749424,
            0.23883928571428573,
            0.9710591102499836,
            -0.9323470744680851,
            0.36156456232712153
        },
    
        {
            true,
            7.375,
            34.21416921393825,
            0.21071428571428572,
            0.9775476918268071,
            -0.9328947368421052,
            0.3601491496204026
        },
    
        {
            true,
            6.380208333333333,
            34.41355752640613,
            0.18229166666666666,
            0.9832445007544609,
            -0.9335394965277777,
            0.35847455756673047
        },
    
        {
            true,
            5.375,
            34.584814225321495,
            0.15357142857142858,
            0.9881375492948998,
            -0.9342783505154639,
            0.3565444765497061
        },
    
        {
            true,
            4.359375,
            34.72745095179568,
            0.12455357142857143,
            0.9922128843370195,
            -0.9351084183673469,
            0.35436174440607837
        },
    
        {
            true,
            3.3333333333333335,
            34.840908267278124,
            0.09523809523809525,
            0.9954545219222322,
            -0.9360269360269361,
            0.35192836633614266
        },
    
        {
            true,
            2.296875,
            34.92455247006574,
            0.065625,
            0.9978443562875926,
            -0.93703125,
            0.3492455247006574
        },
    
        {
            true,
            1.25,
            34.977671449083054,
            0.03571428571428571,
            0.999362041402373,
            -0.9381188118811881,
            0.3463135787037926
        },
    
        {
            true,
            0.19270833333333334,
            34.99946947452581,
            0.005505952380952381,
            0.9999848421293088,
            -0.9392871732026145,
            0.34313205367182165
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            36.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            35.369791666666664,
            6.706551830605457,
            0.9824942129629629,
            0.18629310640570712,
            -0.9939378415300546,
            0.10994347263287632
        },
    
        {
            true,
            34.729166666666664,
            9.48076909532603,
            0.964699074074074,
            0.26335469709238973,
            -0.9882392473118279,
            0.15291563056977467
        },
    
        {
            true,
            34.078125,
            11.605231427437154,
            0.9466145833333334,
            0.32236753965103204,
            -0.9828869047619048,
            0.1842100226577326
        },
    
        {
            true,
            33.416666666666664,
            13.391280330457171,
            0.9282407407407407,
            0.37198000917936586,
            -0.9778645833333334,
            0.2092387551633933
        },
    
        {
            true,
            32.744791666666664,
            14.95923188892389,
            0.9095775462962963,
            0.41553421913677474,
            -0.9731570512820513,
            0.23014202906036754
        },
    
        {
            true,
            32.0625,
            16.370586237212155,
            0.890625,
            0.45473850658922654,
            -0.96875,
            0.24803918541230538
        },
    
        {
            true,
            31.369791666666668,
            17.661714831519912,
            0.8713831018518519,
            0.490603189764442,
            -0.9646299751243781,
            0.263607684052536
        },
    
        {
            true,
            30.666666666666668,
            18.856180831641264,
            0.8518518518518519,
            0.523782800878924,
            -0.9607843137254901,
            0.27729677693590093
        },
    
        {
            true,
            29.953125,
            19.970235420103965,
            0.83203125,
            0.5547287616695545,
            -0.9572010869565217,
            0.2894237017406372
        },
    
        {
            true,
            29.229166666666668,
            21.015608865132176,
            0.8119212962962963,
            0.5837669129203382,
            -0.9538690476190476,
            0.30022298378760254
        },
    
        {
            true,
            28.494791666666668,
            22.001064698629104,
            0.7915219907407408,
            0.6111406860730306,
            -0.9507775821596244,
            0.30987415068491697
        },
    
        {
            true,
            27.75,
            22.93332727713098,
            0.7708333333333334,
            0.637036868809194,
            -0.9479166666666666,
            0.318518434404597
        },
    
        {
            true,
            26.994791666666668,
            23.81766619283392,
            0.7498553240740741,
            0.661601838689831,
            -0.9452768264840182,
            0.3262693999018345
        },
    
        {
            true,
            26.229166666666668,
            24.6582808803092,
            0.728587962962963,
            0.6849522466752556,
            -0.9428490990990991,
            0.33322001189607026
        },
    
        {
            true,
            25.453125,
            25.45856295501329,
            0.70703125,
            0.7071823043059247,
            -0.940625,
            0.3394475060668439
        },
    
        {
            true,
            24.666666666666668,
            26.221280585729513,
            0.6851851851851852,
            0.7283689051591531,
            -0.9385964912280701,
            0.3450168498122304
        },
    
        {
            true,
            23.869791666666668,
            26.94871139386688,
            0.6630497685185186,
            0.7485753164963023,
            -0.9367559523809523,
            0.34998326485541403
        },
    
        {
            true,
            23.0625,
            27.642740344437634,
            0.640625,
            0.7678538984566009,
            -0.9350961538461539,
            0.35439410697996965
        },
    
        {
            true,
            22.244791666666668,
            28.304933204418575,
            0.6179108796296297,
            0.7862481445671826,
            -0.9336102320675105,
            0.3582902937268174
        },
    
        {
            true,
            21.416666666666668,
            28.936592558366108,
            0.5949074074074074,
            0.8037942377323919,
            -0.9322916666666666,
            0.3617074069795764
        },
    
        {
            true,
            20.578125,
            29.538801117925807,
            0.5716145833333334,
            0.8205222532757168,
            -0.9311342592592593,
            0.3646765570114297
        },
    
        {
            true,
            19.729166666666668,
            30.1124556062585,
            0.5480324074074074,
            0.8364571001738472,
            -0.9301321138211381,
            0.3672250683690061
        },
    
        {
            true,
            18.869791666666668,
            30.658293534647314,
            0.5241608796296297,
            0.8516192648513142,
            -0.9292796184738955,
            0.3693770305379194
        },
    
        {
            true,
            18.0,
            31.176914536239792,
            0.5,
            0.8660254037844387,
            -0.9285714285714286,
            0.37115374447904514
        },
    
        {
            true,
            17.119791666666668,
            31.668797471484933,
            0.47554976851851855,
            0.8796888186523593,
            -0.9280024509803921,
            0.3725740878998227
        },
    
        {
            true,
            16.229166666666668,
            32.13431420313114,
            0.45081018518518523,
            0.892619838975865,
            -0.9275678294573643,
            0.37365481631547837
        },
    
        {
            true,
            15.328125,
            32.573740712180644,
            0.42578125,
            0.9048261308939067,
            -0.9272629310344828,
            0.37441081278368554
        },
    
        {
            true,
            14.416666666666666,
            32.987266061652065,
            0.40046296296296297,
            0.9163129461570018,
            -0.9270833333333333,
            0.3748552961551371
        },
    
        {
            true,
            13.494791666666666,
            33.37499959360695,
            0.37485532407407407,
            0.9270833220446375,
            -0.9270248127340823,
            0.374999995433786
        },
    
        {
            true,
            12.5625,
            33.73697665396234,
            0.3489583333333333,
            0.9371382403878427,
            -0.9270833333333334,
            0.3748552961551371
        },
    
        {
            true,
            11.619791666666666,
            34.073163070417515,
            0.3227719907407407,
            0.9464767519560421,
            -0.9272550366300366,
            0.37443036341118147
        },
    
        {
            true,
            10.666666666666666,
            34.38345855527367,
            0.2962962962962963,
            0.9550960709798242,
            -0.9275362318840579,
            0.37373324516601814
        },
    
        {
            true,
            9.703125,
            34.6676991626842,
            0.26953125,
            0.9629916434078944,
            -0.9279233870967742,
            0.37277095873853977
        },
    
        {
            true,
            8.729166666666666,
            34.92565889579688,
            0.24247685185185183,
            0.9701571915499133,
            -0.9284131205673758,
            0.3715495627212434
        },
    
        {
            true,
            7.744791666666667,
            35.15705053100915,
            0.21513310185185186,
            0.9765847369724763,
            -0.9290021929824561,
            0.37007421611588576
        },
    
        {
            true,
            6.75,
            35.36152570237885,
            0.1875,
            0.9822646028438569,
            -0.9296875,
            0.3683492260664463
        },
    
        {
            true,
            5.744791666666667,
            35.53867426771287,
            0.1595775462962963,
            0.9871853963253575,
            -0.9304660652920962,
            0.36637808523415333
        },
    
        {
            true,
            4.729166666666667,
            35.68802295783403,
            0.13136574074074076,
            0.9913339710509452,
            -0.9313350340136055,
            0.36416349956973504
        },
    
        {
            true,
            3.703125,
            35.80903329097806,
            0.10286458333333333,
            0.9946953691938349,
            -0.9322916666666666,
            0.3617074069795763
        },
    
        {
            true,
            2.6666666666666665,
            35.901098714230024,
            0.07407407407407407,
            0.9972527420619451,
            -0.9333333333333335,
            0.3590109871423003
        },
    
        {
            true,
            1.6197916666666667,
            35.96354091238232,
            0.044994212962962965,
            0.9989872475661756,
            -0.9344575082508251,
            0.35607466249883485
        },
    
        {
            true,
            0.5625,
            35.99560520049635,
            0.015625,
            0.9998779222360097,
            -0.9356617647058824,
            0.3528980902009446
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            37.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            36.380208333333336,
            6.743918862446647,
            0.9832488738738739,
            0.1822680773634229,
            -0.9936631944444445,
            0.11239864770744414
        },
    
        {
            true,
            35.75,
            9.536115561380326,
            0.9662162162162162,
            0.2577328530102791,
            -0.9877049180327869,
            0.15632976330131682
        },
    
        {
            true,
            35.109375,
            11.67612037919167,
            0.948902027027027,
            0.3155708210592343,
            -0.9821068548387096,
            0.1883245222450269
        },
    
        {
            true,
            34.458333333333336,
            13.476767560839235,
            0.9313063063063064,
            0.36423696110376313,
            -0.976851851851852,
            0.2139169454101466
        },
    
        {
            true,
            33.796875,
            15.058925600266939,
            0.9134290540540541,
            0.40699798919640373,
            -0.971923828125,
            0.23529571250417092
        },
    
        {
            true,
            33.125,
            16.484367594785066,
            0.8952702702702703,
            0.4455234485077045,
            -0.9673076923076923,
            0.2536056553043856
        },
    
        {
            true,
            32.442708333333336,
            17.789622705337617,
            0.876829954954955,
            0.48080061365777343,
            -0.9629892676767676,
            0.26953973795966085
        },
    
        {
            true,
            31.75,
            18.99835519196333,
            0.8581081081081081,
            0.5134690592422522,
            -0.9589552238805971,
            0.28355754017855717
        },
    
        {
            true,
            31.046875,
            20.12688631493642,
            0.8391047297297297,
            0.5439699004036871,
            -0.9551930147058824,
            0.2959836222784768
        },
    
        {
            true,
            30.333333333333332,
            21.186998109427606,
            0.8198198198198198,
            0.5726215705250705,
            -0.9516908212560388,
            0.30705794361489286
        },
    
        {
            true,
            29.609375,
            22.187494498238756,
            0.8002533783783784,
            0.5996620134659123,
            -0.9484375,
            0.3169642071176965
        },
    
        {
            true,
            28.875,
            23.13513291511419,
            0.7804054054054054,
            0.6252738625706538,
            -0.9454225352112676,
            0.32584694246639706
        },
    
        {
            true,
            28.130208333333332,
            24.035211235253662,
            0.7602759009009009,
            0.6496003036555044,
            -0.9426359953703705,
            0.33382237826741196
        },
    
        {
            true,
            27.375,
            24.891954021329866,
            0.7398648648648649,
            0.6727555140899963,
            -0.940068493150685,
            0.34098567152506665
        },
    
        {
            true,
            26.609375,
            25.708775974545638,
            0.7191722972972973,
            0.694831783095828,
            -0.9377111486486487,
            0.347415891547914
        },
    
        {
            true,
            25.833333333333332,
            26.488467092092908,
            0.6981981981981982,
            0.715904516002511,
            -0.9355555555555556,
            0.35317956122790545
        },
    
        {
            true,
            25.046875,
            27.233326141593043,
            0.6769425675675675,
            0.7360358416646768,
            -0.93359375,
            0.35833323870517164
        },
    
        {
            true,
            24.25,
            27.945258989674794,
            0.6554054054054054,
            0.7552772699912107,
            -0.9318181818181818,
            0.36292544142434796
        },
    
        {
            true,
            23.442708333333332,
            28.625852406492,
            0.6335867117117117,
            0.773671686661946,
            -0.9302216880341881,
            0.3669981077755385
        },
    
        {
            true,
            22.625,
            29.276430366422748,
            0.6114864864864865,
            0.7912548747681823,
            -0.9287974683544303,
            0.37058772615725
        },
    
        {
            true,
            21.796875,
            29.89809760226184,
            0.5891047297297297,
            0.8080566919530227,
            -0.9275390625,
            0.373726220028273
        },
    
        {
            true,
            20.958333333333332,
            30.491773708475684,
            0.5664414414414414,
            0.8241019921209645,
            -0.926440329218107,
            0.37644165072192204
        },
    
        {
            true,
            20.109375,
            31.05822012140063,
            0.5434966216216216,
            0.8394113546324494,
            -0.9254954268292683,
            0.3787587819683004
        },
    
        {
            true,
            19.25,
            31.598061649411346,
            0.5202702702702703,
            0.8540016662003066,
            -0.9246987951807228,
            0.380699537944715
        },
    
        {
            true,
            18.380208333333332,
            32.11180377405268,
            0.49676238738738737,
            0.8678865884879103,
            -0.9240451388888888,
            0.38228337826253184
        },
    
        {
            true,
            17.5,
            32.59984662540608,
            0.47297297297297297,
            0.8810769358217859,
            -0.9235294117647059,
            0.38352760735771857
        },
    
        {
            true,
            16.609375,
            33.06249630789204,
            0.44890202702702703,
            0.8935809812943795,
            -0.9231468023255814,
            0.38444763148711675
        },
    
        {
            true,
            15.708333333333334,
            33.49997408788384,
            0.42454954954954954,
            0.9054047050779417,
            -0.9228927203065135,
            0.38505717342395224
        },
    
        {
            true,
            14.796875,
            33.91242383307886,
            0.3999155405405405,
            0.9165519954886179,
            -0.9227627840909091,
            0.3853684526486234
        },
    
        {
            true,
            13.875,
            34.29991800281744,
            0.375,
            0.9270248108869579,
            -0.922752808988764,
            0.38539233711030835
        },
    
        {
            true,
            12.942708333333334,
            34.662462419716576,
            0.34980292792792794,
            0.9368233086409885,
            -0.9228587962962963,
            0.3851384713301842
        },
    
        {
            true,
            12.0,
            35.0,
            0.32432432432432434,
            0.9459459459459459,
            -0.9230769230769231,
            0.38461538461538464
        },
    
        {
            true,
            11.046875,
            35.312413578434075,
            0.2985641891891892,
            0.9543895561738939,
            -0.9234035326086957,
            0.3838305823742834
        },
    
        {
            true,
            10.083333333333334,
            35.5995279307028,
            0.2725225225225225,
            0.9621494035325081,
            -0.9238351254480287,
            0.3827906229107828
        },
    
        {
            true,
            9.109375,
            35.86111106908673,
            0.24619932432432431,
            0.9692192180834251,
            -0.9243683510638298,
            0.3815011815860291
        },
    
        {
            true,
            8.125,
            36.096874864730324,
            0.2195945945945946,
            0.975591212560279,
            -0.925,
            0.3799671038392666
        },
    
        {
            true,
            7.130208333333333,
            36.30647503026511,
            0.19270833333333331,
            0.9812560818990571,
            -0.9257269965277777,
            0.3781924482319282
        },
    
        {
            true,
            6.125,
            36.48951047904041,
            0.16554054054054054,
            0.9862029859200111,
            -0.9265463917525774,
            0.37618052040247846
        },
    
        {
            true,
            5.109375,
            36.645522060810855,
            0.13809121621621623,
            0.9904195151570502,
            -0.9274553571428571,
            0.3739338985797026
        },
    
        {
            true,
            4.083333333333333,
            36.77399065764945,
            0.11036036036036036,
            0.9938916393959311,
            -0.9284511784511785,
            0.3714544510873682
        },
    
        {
            true,
            3.046875,
            36.8743346073441,
            0.08234797297297297,
            0.9966036380363271,
            -0.92953125,
            0.36874334607344106
        },
    
        {
            true,
            2.0,
            36.945906403822335,
            0.05405405405405406,
            0.9985380109141172,
            -0.9306930693069307,
            0.3658010535031914
        },
    
        {
            true,
            0.9427083333333334,
            36.98798860438702,
            0.025478603603603604,
            0.9996753676861356,
            -0.9319342320261438,
            0.3626273392586963
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            38.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            37.390625,
            6.777991008357491,
            0.9839638157894737,
            0.1783681844304603,
            -0.9933792372881356,
            0.1148812035314829
        },
    
        {
            true,
            36.770833333333336,
            9.586752107581688,
            0.9676535087719299,
            0.25228295019951813,
            -0.9871527777777779,
            0.15977920179302815
        },
    
        {
            true,
            36.140625,
            11.741176457637241,
            0.9510690789473685,
            0.30897832783255896,
            -0.9813012295081968,
            0.19247830258421708
        },
    
        {
            true,
            35.5,
            13.555441711725958,
            0.9342105263157895,
            0.35672215030857785,
            -0.9758064516129032,
            0.21863615664074126
        },
    
        {
            true,
            34.848958333333336,
            15.150910965403927,
            0.9170778508771931,
            0.3987081833001033,
            -0.9706514550264551,
            0.2404906502445068
        },
    
        {
            true,
            34.1875,
            16.589600469872686,
            0.899671052631579,
            0.43656843341770224,
            -0.9658203125,
            0.2592125073417607
        },
    
        {
            true,
            33.515625,
            17.908179160913456,
            0.8819901315789473,
            0.47126787265561726,
            -0.9612980769230769,
            0.2755104486294378
        },
    
        {
            true,
            32.833333333333336,
            19.13040047208166,
            0.8640350877192983,
            0.50343159137057,
            -0.9570707070707071,
            0.28985455260729787
        },
    
        {
            true,
            32.140625,
            20.272647202804446,
            0.8458059210526315,
            0.5334907158632749,
            -0.953125,
            0.30257682392245444
        },
    
        {
            true,
            31.4375,
            21.346746678358272,
            0.8273026315789473,
            0.561756491535744,
            -0.9494485294117647,
            0.3139227452699746
        },
    
        {
            true,
            30.723958333333332,
            22.361538058273123,
            0.8085252192982456,
            0.5884615278492927,
            -0.9460295893719808,
            0.3240802617141032
        },
    
        {
            true,
            30.0,
            23.323807579381203,
            0.7894736842105263,
            0.6137844099837159,
            -0.9428571428571428,
            0.33319725113401716
        },
    
        {
            true,
            29.265625,
            24.238877724832374,
            0.7701480263157895,
            0.6378652032850625,
            -0.9399207746478874,
            0.3413926440117236
        },
    
        {
            true,
            28.520833333333332,
            25.110994921990294,
            0.7505482456140351,
            0.6608156558418499,
            -0.9372106481481483,
            0.3487638183609763
        },
    
        {
            true,
            27.765625,
            25.94359397538003,
            0.7306743421052632,
            0.6827261572468428,
            -0.9347174657534246,
            0.3553916982928771
        },
    
        {
            true,
            27.0,
            26.739483914241877,
            0.7105263157894737,
            0.7036706293221546,
            -0.9324324324324325,
            0.3613443772194848
        },
    
        {
            true,
            26.223958333333332,
            27.50098197031512,
            0.6901041666666666,
            0.7237100518503979,
            -0.9303472222222223,
            0.3666797596042016
        },
    
        {
            true,
            25.4375,
            28.230012287457473,
            0.6694078947368421,
            0.7428950601962493,
            -0.928453947368421,
            0.37144753009812465
        },
    
        {
            true,
            24.640625,
            28.928180025873992,
            0.6484375,
            0.7612678954177367,
            -0.9267451298701299,
            0.3756906496866752
        },
    
        {
            true,
            23.833333333333332,
            29.59682790810904,
            0.6271929824561403,
            0.7788638923186589,
            -0.9252136752136753,
            0.3794465116424236
        },
    
        {
            true,
            23.015625,
            30.237079982355688,
            0.6056743421052632,
            0.7957126311146233,
            -0.9238528481012658,
            0.3827478478779201
        },
    
        {
            true,
            22.1875,
            30.849875911419804,
            0.5838815789473685,
            0.8118388397742053,
            -0.92265625,
            0.3856234488927476
        },
    
        {
            true,
            21.348958333333332,
            31.435998124468664,
            0.5618146929824561,
            0.827263108538649,
            -0.9216177983539096,
            0.38809874227739094
        },
    
        {
            true,
            20.5,
            31.996093511552314,
            0.5394736842105263,
            0.842002460830324,
            -0.9207317073170732,
            0.3901962623360038
        },
    
        {
            true,
            19.640625,
            32.53069088736627,
            0.516858552631579,
            0.8560708128254282,
            -0.9199924698795181,
            0.3919360347875454
        },
    
        {
            true,
            18.770833333333332,
            33.04021513205116,
            0.49396929824561403,
            0.8694793455802937,
            -0.9193948412698413,
            0.3933358944291805
        },
    
        {
            true,
            17.890625,
            33.52499868917783,
            0.4708059210526316,
            0.8822368076099428,
            -0.9189338235294118,
            0.39441174928444506
        },
    
        {
            true,
            17.0,
            33.98529093593286,
            0.4473684210526316,
            0.8943497614719174,
            -0.9186046511627907,
            0.39517780158061466
        },
    
        {
            true,
            16.098958333333332,
            34.421265818990406,
            0.42365679824561403,
            0.9058227847102739,
            -0.9184027777777778,
            0.39564673355161384
        },
    
        {
            true,
            15.1875,
            34.833028058869644,
            0.3996710526315789,
            0.9166586331281485,
            -0.9183238636363636,
            0.39582986430533684
        },
    
        {
            true,
            14.265625,
            35.22061815697412,
            0.3754111842105263,
            0.9268583725519505,
            -0.9183637640449438,
            0.39573728266263053
        },
    
        {
            true,
            13.333333333333334,
            35.58401638688672,
            0.3508771929824562,
            0.9364214838654399,
            -0.9185185185185186,
            0.39537795985429686
        },
    
        {
            true,
            12.390625,
            35.92314591053204,
            0.3260690789473684,
            0.9453459450140012,
            -0.9187843406593407,
            0.3947598451706818
        },
    
        {
            true,
            11.4375,
            36.237875127413304,
            0.30098684210526316,
            0.9536282928266658,
            -0.9191576086956522,
            0.3938899470371011
        },
    
        {
            true,
            10.473958333333334,
            36.528019339016964,
            0.27563048245614036,
            0.9612636668162359,
            -0.9196348566308244,
            0.3927744014948061
        },
    
        {
            true,
            9.5,
            36.79334178897046,
            0.25,
            0.9682458365518541,
            -0.9202127659574468,
            0.3914185296698985
        },
    
        {
            true,
            8.515625,
            37.03355412135561,
            0.22409539473684212,
            0.9745672137198844,
            -0.9208881578947369,
            0.38982688548795374
        },
    
        {
            true,
            7.520833333333333,
            37.24831628372244,
            0.19791666666666666,
            0.9802188495716431,
            -0.9216579861111112,
            0.38800329462210875
        },
    
        {
            true,
            6.515625,
            37.4372358870066,
            0.17146381578947367,
            0.9851904180791211,
            -0.9225193298969072,
            0.3859508854330577
        },
    
        {
            true,
            5.5,
            37.59986702104145,
            0.14473684210526316,
            0.9894701847642486,
            -0.923469387755102,
            0.3836721124596066
        },
    
        {
            true,
            4.473958333333333,
            37.735708511058824,
            0.11773574561403508,
            0.9930449608173375,
            -0.9245054713804713,
            0.381168772838978
        },
    
        {
            true,
            3.4375,
            37.844201586901,
            0.09046052631578948,
            0.9959000417605527,
            -0.925625,
            0.37844201586901
        },
    
        {
            true,
            2.390625,
            37.92472692201455,
            0.06291118421052631,
            0.9980191295266987,
            -0.926825495049505,
            0.3754923457625203
        },
    
        {
            true,
            1.3333333333333333,
            37.97660098300297,
            0.03508771929824561,
            0.9993842363948149,
            -0.9281045751633986,
            0.3723196174804212
        },
    
        {
            true,
            0.265625,
            37.99907161180882,
            0.0069901315789473685,
            0.9999755687318111,
            -0.9294599514563107,
            0.3689230253573672
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            39.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            38.401041666666664,
            6.808817732538495,
            0.9846420940170939,
            0.1745850700650896,
            -0.9930854885057471,
            0.11739340918169817
        },
    
        {
            true,
            37.791666666666664,
            9.632753010201998,
            0.9690170940170939,
            0.24699366692825636,
            -0.9865819209039547,
            0.1632670001729152
        },
    
        {
            true,
            37.171875,
            11.800496132975724,
            0.953125,
            0.30257682392245444,
            -0.98046875,
            0.1966749355495954
        },
    
        {
            true,
            36.541666666666664,
            13.627420783927617,
            0.9369658119658119,
            0.34942104574173377,
            -0.9747267759562841,
            0.22340034072012485
        },
    
        {
            true,
            35.901041666666664,
            15.235327605544429,
            0.9205395299145298,
            0.39064942578319045,
            -0.9693380376344085,
            0.2457310904120069
        },
    
        {
            true,
            35.25,
            16.68644659596524,
            0.9038461538461539,
            0.42785760502474973,
            -0.9642857142857143,
            0.2648642316819879
        },
    
        {
            true,
            34.588541666666664,
            18.017568797517164,
            0.8868856837606837,
            0.4619889435260811,
            -0.9595540364583334,
            0.2815245124612057
        },
    
        {
            true,
            33.916666666666664,
            19.252525086913206,
            0.8696581196581196,
            0.4936544894080309,
            -0.9551282051282052,
            0.29619269364481854
        },
    
        {
            true,
            33.234375,
            20.407751428302312,
            0.8521634615384616,
            0.5232756776487772,
            -0.9509943181818182,
            0.30920835497427746
        },
    
        {
            true,
            32.541666666666664,
            21.495114108921488,
            0.8344017094017093,
            0.5511567720236279,
            -0.9471393034825871,
            0.32082259864061924
        },
    
        {
            true,
            31.838541666666668,
            22.52348251358858,
            0.8163728632478633,
            0.5775251926561175,
            -0.9435508578431372,
            0.33122768402336145
        },
    
        {
            true,
            31.125,
            23.49966755083995,
            0.7980769230769231,
            0.6025555782266654,
            -0.9402173913043478,
            0.34057489204115865
        },
    
        {
            true,
            30.401041666666668,
            24.429012783606243,
            0.779513888888889,
            0.6263849431693909,
            -0.9371279761904762,
            0.3489858969086606
        },
    
        {
            true,
            29.666666666666668,
            25.315783394730033,
            0.7606837606837608,
            0.6491226511469239,
            -0.9342723004694835,
            0.3565603295032399
        },
    
        {
            true,
            28.921875,
            26.163431473802802,
            0.7415865384615384,
            0.670857217276995,
            -0.931640625,
            0.3633809926917056
        },
    
        {
            true,
            28.166666666666668,
            26.97478246230892,
            0.7222222222222222,
            0.6916610887771518,
            -0.9292237442922374,
            0.3695175679768345
        },
    
        {
            true,
            27.401041666666668,
            27.752169565307813,
            0.702590811965812,
            0.7115940914181491,
            -0.9270129504504504,
            0.37502931845010556
        },
    
        {
            true,
            26.625,
            28.497532787944994,
            0.6826923076923077,
            0.7307059689216665,
            -0.925,
            0.3799671038392666
        },
    
        {
            true,
            25.838541666666668,
            29.2124932955051,
            0.6625267094017094,
            0.749038289628336,
            -0.9231770833333333,
            0.38437491178296185
        },
    
        {
            true,
            25.041666666666668,
            29.89841016769212,
            0.6420940170940171,
            0.7666259017356953,
            -0.9215367965367964,
            0.3882910411388587
        },
    
        {
            true,
            24.234375,
            30.556424338580175,
            0.6213942307692307,
            0.7834980599635942,
            -0.9200721153846154,
            0.3917490299817971
        },
    
        {
            true,
            23.416666666666668,
            31.187493041638056,
            0.6004273504273504,
            0.7996793087599502,
            -0.9187763713080168,
            0.3947783929321273
        },
    
        {
            true,
            22.588541666666668,
            31.79241710492085,
            0.5791933760683761,
            0.8151901821774578,
            -0.9176432291666666,
            0.3974052138115106
        },
    
        {
            true,
            21.75,
            32.37186278236086,
            0.5576923076923077,
            0.8300477636502784,
            -0.9166666666666666,
            0.39965262694272663
        },
    
        {
            true,
            20.901041666666668,
            32.92637935224983,
            0.5359241452991453,
            0.8442661372371751,
            -0.9158409552845528,
            0.4015412116128028
        },
    
        {
            true,
            20.041666666666668,
            33.456413394478226,
            0.513888888888889,
            0.8578567537045699,
            -0.9151606425702811,
            0.40308931800576175
        },
    
        {
            true,
            19.171875,
            33.962320429917256,
            0.49158653846153844,
            0.8708287289722373,
            -0.9146205357142857,
            0.4043133384513959
        },
    
        {
            true,
            18.291666666666668,
            34.44437443989302,
            0.46901709401709407,
            0.8831890882023851,
            -0.9142156862745098,
            0.4052279345869767
        },
    
        {
            true,
            17.401041666666668,
            34.90277566204342,
            0.4461805555555556,
            0.8949429656934209,
            -0.9139413759689922,
            0.40584622862841185
        },
    
        {
            true,
            16.5,
            35.33765696816924,
            0.4230769230769231,
            0.906093768414596,
            -0.9137931034482759,
            0.4061799651513706
        },
    
        {
            true,
            15.588541666666666,
            35.749089061213816,
            0.39970619658119655,
            0.9166433092618927,
            -0.9137665719696969,
            0.4062396484228843
        },
    
        {
            true,
            14.666666666666666,
            36.13708467611754,
            0.37606837606837606,
            0.9265919147722446,
            -0.9138576779026216,
            0.40603465928221955
        },
    
        {
            true,
            13.734375,
            36.50160192867396,
            0.35216346153846156,
            0.93593851099164,
            -0.9140625,
            0.405573354763044
        },
    
        {
            true,
            12.791666666666666,
            36.84254692456656,
            0.327991452991453,
            0.9446806903735016,
            -0.9143772893772893,
            0.404863153017215
        },
    
        {
            true,
            11.838541666666666,
            37.159775715235384,
            0.3035523504273504,
            0.9528147619291124,
            -0.9147984601449275,
            0.4039106056003846
        },
    
        {
            true,
            10.875,
            37.453095666446586,
            0.27884615384615385,
            0.9603357863191432,
            -0.9153225806451613,
            0.40272145877899557
        },
    
        {
            true,
            9.901041666666666,
            37.72226628816104,
            0.25387286324786323,
            0.9672375971323343,
            -0.9159463652482269,
            0.40130070519320254
        },
    
        {
            true,
            8.916666666666666,
            37.96699955955903,
            0.22863247863247863,
            0.9735128092194623,
            -0.9166666666666667,
            0.3996526269427267
        },
    
        {
            true,
            7.921875,
            38.18695977011492,
            0.203125,
            0.9791528146183313,
            -0.91748046875,
            0.39778083093869704
        },
    
        {
            true,
            6.916666666666667,
            38.381762885805834,
            0.17735042735042736,
            0.9841477663027137,
            -0.9183848797250859,
            0.395688277173256
        },
    
        {
            true,
            5.901041666666667,
            38.55097543834999,
            0.1513087606837607,
            0.9884865497012817,
            -0.91937712585034,
            0.3933773003913264
        },
    
        {
            true,
            4.875,
            38.69411292431964,
            0.125,
            0.9921567416492215,
            -0.9204545454545454,
            0.3908496254981782
        },
    
        {
            true,
            3.8385416666666665,
            38.810637689598245,
            0.0984241452991453,
            0.9951445561435447,
            -0.9216145833333335,
            0.3881063768959825
        },
    
        {
            true,
            2.7916666666666665,
            38.89995626247184,
            0.07158119658119658,
            0.9974347759608164,
            -0.9228547854785478,
            0.3851480818066519
        },
    
        {
            true,
            1.734375,
            38.961416085139604,
            0.04447115384615385,
            0.9990106688497334,
            -0.9241727941176471,
            0.38197466750136866
        },
    
        {
            true,
            0.6666666666666666,
            38.99430157799413,
            0.017094017094017092,
            0.9998538866152341,
            -0.9255663430420713,
            0.3785854522135353
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            40.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            39.411458333333336,
            6.836442937663594,
            0.9852864583333334,
            0.17091107344158984,
            -0.9927814327485379,
            0.11993759539760691
        },
    
        {
            true,
            38.8125,
            9.674184397146872,
            0.9703125,
            0.2418546099286718,
            -0.9859913793103449,
            0.16679628270942884
        },
    
        {
            true,
            38.203125,
            11.854165522480905,
            0.955078125,
            0.2963541380620226,
            -0.9796080508474576,
            0.20091805970306617
        },
    
        {
            true,
            37.583333333333336,
            13.692810360023081,
            0.9395833333333334,
            0.34232025900057705,
            -0.9736111111111111,
            0.22821350600038467
        },
    
        {
            true,
            36.953125,
            15.312300700233619,
            0.923828125,
            0.38280751750584047,
            -0.9679815573770492,
            0.2510213229546495
        },
    
        {
            true,
            36.3125,
            16.775051229429973,
            0.9078125,
            0.41937628073574934,
            -0.9627016129032258,
            0.27056534241016084
        },
    
        {
            true,
            35.661458333333336,
            18.11795765366313,
            0.8915364583333334,
            0.45294894134157826,
            -0.9577546296296297,
            0.2875866294232243
        },
    
        {
            true,
            35.0,
            19.364916731037084,
            0.875,
            0.4841229182759271,
            -0.953125,
            0.30257682392245444
        },
    
        {
            true,
            34.328125,
            20.532409356536192,
            0.858203125,
            0.5133102339134048,
            -0.9487980769230769,
            0.3158832208697876
        },
    
        {
            true,
            33.645833333333336,
            21.632334578254735,
            0.8411458333333334,
            0.5408083644563684,
            -0.944760101010101,
            0.32776264512507175
        },
    
        {
            true,
            32.953125,
            22.673587116607177,
            0.823828125,
            0.5668396779151794,
            -0.9409981343283582,
            0.3384117480090623
        },
    
        {
            true,
            32.25,
            23.662998542027594,
            0.80625,
            0.5915749635506898,
            -0.9375,
            0.3479852726768764
        },
    
        {
            true,
            31.536458333333332,
            24.605930093982032,
            0.7884114583333333,
            0.6151482523495508,
            -0.9342542270531402,
            0.35660768252147873
        },
    
        {
            true,
            30.8125,
            25.506662732509717,
            0.7703125,
            0.6376665683127429,
            -0.93125,
            0.3643808961787102
        },
    
        {
            true,
            30.078125,
            26.3686631531516,
            0.751953125,
            0.65921657882879,
            -0.9284771126760564,
            0.37138962187537466
        },
    
        {
            true,
            29.333333333333332,
            27.19477073916152,
            0.7333333333333333,
            0.679869268479038,
            -0.925925925925926,
            0.3777051491550211
        },
    
        {
            true,
            28.578125,
            27.987332339549173,
            0.714453125,
            0.6996833084887293,
            -0.9235873287671232,
            0.38338811424039965
        },
    
        {
            true,
            27.8125,
            28.748301580267313,
            0.6953125,
            0.7187075395066829,
            -0.9214527027027027,
            0.38849056189550424
        },
    
        {
            true,
            27.036458333333332,
            29.47931343823887,
            0.6759114583333333,
            0.7369828359559717,
            -0.919513888888889,
            0.3930575125098516
        },
    
        {
            true,
            26.25,
            30.18174116912409,
            0.65625,
            0.7545435292281023,
            -0.9177631578947368,
            0.3971281732779486
        },
    
        {
            true,
            25.453125,
            30.85674039386492,
            0.636328125,
            0.7714185098466231,
            -0.9161931818181818,
            0.400736888232012
        },
    
        {
            true,
            24.645833333333332,
            31.505283672831066,
            0.6161458333333333,
            0.7876320918207766,
            -0.9147970085470086,
            0.4039138932414239
        },
    
        {
            true,
            23.828125,
            32.128187919401476,
            0.595703125,
            0.8032046979850369,
            -0.9135680379746836,
            0.4066859230303984
        },
    
        {
            true,
            23.0,
            32.72613634390714,
            0.575,
            0.8181534085976786,
            -0.9125,
            0.4090767042988393
        },
    
        {
            true,
            22.161458333333332,
            33.29969616287708,
            0.5540364583333333,
            0.832492404071927,
            -0.9115869341563787,
            0.41110736003551956
        },
    
        {
            true,
            21.3125,
            33.849332988258425,
            0.5328125,
            0.8462333247064606,
            -0.9108231707317073,
            0.4127967437592491
        },
    
        {
            true,
            20.453125,
            34.3754225826298,
            0.511328125,
            0.8593855645657451,
            -0.9102033132530121,
            0.41416171786300965
        },
    
        {
            true,
            19.583333333333332,
            34.878260500712415,
            0.4895833333333333,
            0.8719565125178104,
            -0.9097222222222223,
            0.41521738691324306
        },
    
        {
            true,
            18.703125,
            35.35807001568914,
            0.467578125,
            0.8839517503922284,
            -0.909375,
            0.41597729430222513
        },
    
        {
            true,
            17.8125,
            35.8150086381394,
            0.4453125,
            0.8953752159534851,
            -0.909156976744186,
            0.4164535888155745
        },
    
        {
            true,
            16.911458333333332,
            36.24917346698999,
            0.4227864583333333,
            0.9062293366747497,
            -0.9090636973180077,
            0.41665716628724125
        },
    
        {
            true,
            16.0,
            36.66060555964672,
            0.4,
            0.916515138991168,
            -0.9090909090909091,
            0.4165977904505309
        },
    
        {
            true,
            15.078125,
            37.049293468086205,
            0.376953125,
            0.9262323367021551,
            -0.9092345505617978,
            0.4162841962706315
        },
    
        {
            true,
            14.145833333333334,
            37.41517605605452,
            0.3536458333333333,
            0.935379401401363,
            -0.9094907407407408,
            0.41572417840060577
        },
    
        {
            true,
            13.203125,
            37.75814468739659,
            0.330078125,
            0.9439536171849147,
            -0.9098557692307693,
            0.414924666894468
        },
    
        {
            true,
            12.25,
            38.078044855270605,
            0.30625,
            0.9519511213817651,
            -0.9103260869565217,
            0.41389179190511527
        },
    
        {
            true,
            11.286458333333334,
            38.37467730535243,
            0.28216145833333334,
            0.9593669326338107,
            -0.9108982974910395,
            0.4126309387672304
        },
    
        {
            true,
            10.3125,
            38.64779869216357,
            0.2578125,
            0.9661949673040893,
            -0.9115691489361702,
            0.41114679459748477
        },
    
        {
            true,
            9.328125,
            38.897121795633865,
            0.233203125,
            0.9724280448908467,
            -0.9123355263157895,
            0.4094433873224617
        },
    
        {
            true,
            8.333333333333334,
            39.122315314351674,
            0.20833333333333334,
            0.9780578828587918,
            -0.9131944444444445,
            0.40752411785782994
        },
    
        {
            true,
            7.328125,
            39.32300324217842,
            0.183203125,
            0.9830750810544606,
            -0.9141430412371134,
            0.4053917860018394
        },
    
        {
            true,
            6.3125,
            39.49876382559333,
            0.1578125,
            0.9874690956398332,
            -0.9151785714285714,
            0.40304861046523804
        },
    
        {
            true,
            5.286458333333333,
            39.64912808990799,
            0.13216145833333331,
            0.9912282022476997,
            -0.9162984006734006,
            0.40049624333240386
        },
    
        {
            true,
            4.25,
            39.773577912981374,
            0.10625,
            0.9943394478245343,
            -0.9175,
            0.3977357791298137
        },
    
        {
            true,
            3.203125,
            39.87154361489375,
            0.080078125,
            0.9967885903723438,
            -0.9187809405940595,
            0.3947677585633045
        },
    
        {
            true,
            2.1458333333333335,
            39.94240102078937,
            0.05364583333333334,
            0.9985600255197342,
            -0.920138888888889,
            0.391592166870484
        },
    
        {
            true,
            1.078125,
            39.98546794129556,
            0.026953125,
            0.999636698532389,
            -0.9215716019417476,
            0.38820842661452
        },
    
        {
            true,
            0.0,
            40.0,
            0.0,
            1.0,
            -0.9230769230769231,
            0.38461538461538464
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            41.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            40.421875,
            6.860905296269218,
            0.9858993902439024,
            0.1673391535675419,
            -0.9924665178571429,
            0.12251616600480746
        },
    
        {
            true,
            39.833333333333336,
            9.711104754638137,
            0.9715447154471545,
            0.23685621352775946,
            -0.9853801169590642,
            0.17037025885330065
        },
    
        {
            true,
            39.234375,
            11.90226106079744,
            0.9569359756097561,
            0.2902990502633522,
            -0.9787176724137931,
            0.20521139759995585
        },
    
        {
            true,
            38.625,
            13.751704439813997,
            0.9420731707317073,
            0.335407425361317,
            -0.972457627118644,
            0.23307973626803385
        },
    
        {
            true,
            38.005208333333336,
            15.381941995077554,
            0.9269563008130082,
            0.37516931695311106,
            -0.966579861111111,
            0.2563656999179592
        },
    
        {
            true,
            37.375,
            16.855544340068047,
            0.9115853658536586,
            0.4111108375626353,
            -0.9610655737704918,
            0.276320399017509
        },
    
        {
            true,
            36.734375,
            18.209494593738043,
            0.8959603658536586,
            0.4441340144814157,
            -0.9558971774193549,
            0.2937015257054523
        },
    
        {
            true,
            36.083333333333336,
            19.46774397703944,
            0.8800813008130082,
            0.47482302383023023,
            -0.9510582010582012,
            0.3090118091593562
        },
    
        {
            true,
            35.421875,
            20.646810201199965,
            0.8639481707317073,
            0.5035807366146333,
            -0.946533203125,
            0.32260640939374946
        },
    
        {
            true,
            34.75,
            21.758618981911514,
            0.8475609756097561,
            0.5306980239490613,
            -0.9423076923076923,
            0.33474798433710024
        },
    
        {
            true,
            34.067708333333336,
            22.81208558889192,
            0.8309197154471545,
            0.5563923314363883,
            -0.9383680555555555,
            0.3456376604377564
        },
    
        {
            true,
            33.375,
            23.81405834795909,
            0.8140243902439024,
            0.5808306914136363,
            -0.9347014925373134,
            0.3554337066859566
        },
    
        {
            true,
            32.671875,
            24.769912878013418,
            0.796875,
            0.6041442165369126,
            -0.9312959558823529,
            0.3642634246766679
        },
    
        {
            true,
            31.958333333333332,
            25.683943049219597,
            0.7794715447154471,
            0.6264376353468194,
            -0.9281400966183575,
            0.372231058684342
        },
    
        {
            true,
            31.234375,
            26.559627602046213,
            0.7618140243902439,
            0.6477957951718588,
            -0.9252232142857143,
            0.37942325145780303
        },
    
        {
            true,
            30.5,
            27.399817517640514,
            0.7439024390243902,
            0.6682882321375735,
            -0.9225352112676056,
            0.38591292278366923
        },
    
        {
            true,
            29.755208333333332,
            28.20687109624055,
            0.7257367886178862,
            0.6879724657619647,
            -0.920066550925926,
            0.39176209855889654
        },
    
        {
            true,
            29.0,
            28.982753492378876,
            0.7073170731707317,
            0.7068964266433873,
            -0.9178082191780822,
            0.39702402044354623
        },
    
        {
            true,
            28.234375,
            29.729111462661898,
            0.6886432926829268,
            0.7251002795771194,
            -0.9157516891891891,
            0.40174474949543104
        },
    
        {
            true,
            27.458333333333332,
            30.44733043397328,
            0.6697154471544715,
            0.742617815462763,
            -0.913888888888889,
            0.40596440578631043
        },
    
        {
            true,
            26.671875,
            31.138578708482747,
            0.6505335365853658,
            0.759477529475189,
            -0.9122121710526315,
            0.40971814090108877
        },
    
        {
            true,
            25.875,
            31.80384214210604,
            0.6310975609756098,
            0.7757034668806351,
            -0.9107142857142857,
            0.41303691093644207
        },
    
        {
            true,
            25.067708333333332,
            32.44395165381262,
            0.6114075203252032,
            0.7913158939954297,
            -0.9093883547008548,
            0.4159480981258028
        },
    
        {
            true,
            24.25,
            33.059605260801284,
            0.5914634146341463,
            0.8063318356292997,
            -0.9082278481012658,
            0.41847601595950995
        },
    
        {
            true,
            23.421875,
            33.651385877618395,
            0.571265243902439,
            0.8207655092102047,
            -0.9072265625,
            0.42064232347022995
        },
    
        {
            true,
            22.583333333333332,
            34.21977579639521,
            0.5508130081300813,
            0.8346286779608588,
            -0.9063786008230453,
            0.42246636785673103
        },
    
        {
            true,
            21.734375,
            34.76516853632922,
            0.5301067073170732,
            0.8479309399104688,
            -0.9056783536585366,
            0.4239654699552344
        },
    
        {
            true,
            20.875,
            35.287878584579154,
            0.5091463414634146,
            0.8606799654775403,
            -0.9051204819277109,
            0.42515516366962836
        },
    
        {
            true,
            20.005208333333332,
            35.78814942882533,
            0.4879319105691057,
            0.8728816933859836,
            -0.9046999007936508,
            0.4260493979622063
        },
    
        {
            true,
            19.125,
            36.26616019101002,
            0.46646341463414637,
            0.8845404924636591,
            -0.9044117647058824,
            0.42666070812952966
        },
    
        {
            true,
            18.234375,
            36.722031103404056,
            0.4447408536585366,
            0.895659295204977,
            -0.9042514534883721,
            0.427000361667489
        },
    
        {
            true,
            17.333333333333332,
            37.15582801601326,
            0.4227642276422764,
            0.9062397077076405,
            -0.9042145593869733,
            0.42707848294268114
        },
    
        {
            true,
            16.421875,
            37.56756608411536,
            0.40053353658536583,
            0.9162820996125698,
            -0.904296875,
            0.4269041600467655
        },
    
        {
            true,
            15.5,
            37.957212753309484,
            0.3780487804878049,
            0.9257856769099875,
            -0.9044943820224719,
            0.42648553655403915
        },
    
        {
            true,
            14.567708333333334,
            38.3246901346238,
            0.3553099593495935,
            0.9347485398688731,
            -0.9048032407407408,
            0.4258298903847089
        },
    
        {
            true,
            13.625,
            38.66987684231746,
            0.3323170731707317,
            0.9431677278614014,
            -0.9052197802197802,
            0.4249437015639281
        },
    
        {
            true,
            12.671875,
            38.99260935080358,
            0.3090701219512195,
            0.951039252458624,
            -0.9057404891304348,
            0.42383271033482156
        },
    
        {
            true,
            11.708333333333334,
            39.29268291368707,
            0.2855691056910569,
            0.958358119846026,
            -0.9063620071684588,
            0.42250196681383945
        },
    
        {
            true,
            10.734375,
            39.569852076541494,
            0.2618140243902439,
            0.9651183433302803,
            -0.9070811170212766,
            0.42095587315469674
        },
    
        {
            true,
            9.75,
            39.823830805184976,
            0.23780487804878048,
            0.9713129464679262,
            -0.9078947368421053,
            0.4191982190019471
        },
    
        {
            true,
            8.755208333333334,
            40.054292242404316,
            0.21354166666666669,
            0.9769339571318125,
            -0.9087999131944445,
            0.4172322108583783
        },
    
        {
            true,
            7.75,
            40.260868097943444,
            0.18902439024390244,
            0.9819723926327669,
            -0.9097938144329897,
            0.41506049585508703
        },
    
        {
            true,
            6.734375,
            40.44314766878779,
            0.1642530487804878,
            0.9864182358240924,
            -0.9108737244897959,
            0.41268518029375295
        },
    
        {
            true,
            5.708333333333333,
            40.60067647903857,
            0.13922764227642276,
            0.99026040192777,
            -0.9120370370370371,
            0.4101078432226118
        },
    
        {
            true,
            4.671875,
            40.73295452068724,
            0.11394817073170732,
            0.9934866956265179,
            -0.91328125,
            0.40732954520687237
        },
    
        {
            true,
            3.625,
            40.839434068067106,
            0.08841463414634146,
            0.9960837577577343,
            -0.9146039603960396,
            0.40435083235710007
        },
    
        {
            true,
            2.5677083333333335,
            40.91951702934592,
            0.06262703252032521,
            0.9980370007157541,
            -0.9160028594771242,
            0.40117173558182273
        },
    
        {
            true,
            1.5,
            40.97255178775176,
            0.036585365853658534,
            0.9993305314085795,
            -0.9174757281553398,
            0.39779176492962875
        },
    
        {
            true,
            0.421875,
            40.99782947284374,
            0.010289634146341464,
            0.999947060313262,
            -0.9190204326923077,
            0.39420989877734364
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            42.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            41.432291666666664,
            6.882238534682167,
            0.9864831349206349,
            0.16386282225433732,
            -0.9921401515151514,
            0.12513160972149392
        },
    
        {
            true,
            40.854166666666664,
            9.743565362444201,
            0.972718253968254,
            0.2319896514867667,
            -0.9847470238095238,
            0.173992238615075
        },
    
        {
            true,
            40.265625,
            11.94485007688983,
            0.9587053571428571,
            0.2844011923069007,
            -0.977796052631579,
            0.20955877327876896
        },
    
        {
            true,
            39.666666666666664,
            13.804186160565774,
            0.9444444444444444,
            0.3286710990610898,
            -0.9712643678160918,
            0.2380032096649271
        },
    
        {
            true,
            39.057291666666664,
            15.444350671521631,
            0.9299355158730158,
            0.3677226350362293,
            -0.965130649717514,
            0.26176865544951916
        },
    
        {
            true,
            38.4375,
            16.928041639539998,
            0.9151785714285714,
            0.40304861046523804,
            -0.959375,
            0.2821340273256666
        },
    
        {
            true,
            37.807291666666664,
            18.29231250639452,
            0.900173611111111,
            0.43553125015225047,
            -0.953978825136612,
            0.29987397551466427
        },
    
        {
            true,
            37.166666666666664,
            19.561157657175844,
            0.8849206349206349,
            0.46574184898037724,
            -0.9489247311827956,
            0.3155025428576749
        },
    
        {
            true,
            36.515625,
            20.751123604744276,
            0.8694196428571429,
            0.4940743715415304,
            -0.9441964285714286,
            0.32938291436102024
        },
    
        {
            true,
            35.854166666666664,
            21.87415672977793,
            0.8536706349206349,
            0.5208132554709031,
            -0.9397786458333334,
            0.34178369890278015
        },
    
        {
            true,
            35.182291666666664,
            22.939188152190507,
            0.837673611111111,
            0.5461711464807264,
            -0.9356570512820513,
            0.352910586956777
        },
    
        {
            true,
            34.5,
            23.95307913400697,
            0.8214285714285714,
            0.5703114079525469,
            -0.9318181818181818,
            0.362925441424348
        },
    
        {
            true,
            33.807291666666664,
            24.92121646639527,
            0.8049355158730158,
            0.5933622968189349,
            -0.9282493781094527,
            0.3719584547223174
        },
    
        {
            true,
            33.104166666666664,
            25.847904156924514,
            0.7881944444444444,
            0.6154262894505836,
            -0.9249387254901961,
            0.3801162376018311
        },
    
        {
            true,
            32.390625,
            26.73663053021781,
            0.7712053571428571,
            0.6365864411956621,
            -0.921875,
            0.3874873989886639
        },
    
        {
            true,
            31.666666666666668,
            27.590255928900373,
            0.753968253968254,
            0.6569108554500088,
            -0.919047619047619,
            0.3941465132700053
        },
    
        {
            true,
            30.932291666666668,
            28.411148027636333,
            0.736483134920635,
            0.6764559054199127,
            -0.9164465962441314,
            0.4001570144737512
        },
    
        {
            true,
            30.1875,
            29.201281542939174,
            0.71875,
            0.6952686081652184,
            -0.9140625,
            0.40557335476304407
        },
    
        {
            true,
            29.432291666666668,
            29.962313115783697,
            0.7007688492063492,
            0.7133884075186595,
            -0.9118864155251141,
            0.4104426454216945
        },
    
        {
            true,
            28.666666666666668,
            30.695638488590234,
            0.6825396825396826,
            0.7308485354426246,
            -0.9099099099099098,
            0.41480592552148965
        },
    
        {
            true,
            27.890625,
            31.402436802091888,
            0.6640625,
            0.7476770667164735,
            -0.908125,
            0.41869915736122515
        },
    
        {
            true,
            27.104166666666668,
            32.08370535498597,
            0.6453373015873016,
            0.763897746547285,
            -0.9065241228070174,
            0.42215401782876283
        },
    
        {
            true,
            26.307291666666668,
            32.74028718818652,
            0.6263640873015873,
            0.7795306473377743,
            -0.9051001082251081,
            0.42519853491151327
        },
    
        {
            true,
            25.5,
            33.37289319193048,
            0.6071428571428571,
            0.7945926950459639,
            -0.9038461538461539,
            0.42785760502474973
        },
    
        {
            true,
            24.682291666666668,
            33.982119976269836,
            0.5876736111111112,
            0.8090980946730914,
            -0.9027558016877637,
            0.43015341742113716
        },
    
        {
            true,
            23.854166666666668,
            34.56846442408006,
            0.5679563492063492,
            0.8230586767638111,
            -0.9018229166666666,
            0.4321058053010008
        },
    
        {
            true,
            23.015625,
            35.13233561634317,
            0.5479910714285714,
            0.836484181341504,
            -0.9010416666666666,
            0.43373253847337245
        },
    
        {
            true,
            22.166666666666668,
            35.674064653314865,
            0.5277777777777778,
            0.849382491745592,
            -0.9004065040650406,
            0.43504956894286423
        },
    
        {
            true,
            21.307291666666668,
            36.193912773166666,
            0.5073164682539683,
            0.8617598279325397,
            -0.8999121485943774,
            0.4360712382309237
        },
    
        {
            true,
            20.4375,
            36.692078078925974,
            0.48660714285714285,
            0.8736209066410946,
            -0.8995535714285714,
            0.4368104533205473
        },
    
        {
            true,
            19.557291666666668,
            37.16870111619359,
            0.4656498015873016,
            0.8849690741950854,
            -0.8993259803921568,
            0.43727883666110107
        },
    
        {
            true,
            18.666666666666668,
            37.623869492059896,
            0.4444444444444445,
            0.8958064164776166,
            -0.8992248062015503,
            0.437486854558836
        },
    
        {
            true,
            17.765625,
            38.057621685535935,
            0.42299107142857145,
            0.9061338496556175,
            -0.8992456896551724,
            0.43744392741995325
        },
    
        {
            true,
            16.854166666666668,
            38.46995016856952,
            0.40128968253968256,
            0.9159511944897505,
            -0.8993844696969696,
            0.43715852464283544
        },
    
        {
            true,
            15.932291666666666,
            38.860803932089,
            0.3793402777777778,
            0.9252572364783095,
            -0.8996371722846441,
            0.4366382464279663
        },
    
        {
            true,
            15.0,
            39.230090491866065,
            0.35714285714285715,
            0.9340497736158587,
            -0.9,
            0.4358898943540674
        },
    
        {
            true,
            14.057291666666666,
            39.57767743309685,
            0.33469742063492064,
            0.9423256531689727,
            -0.9004693223443223,
            0.43491953223183355
        },
    
        {
            true,
            13.104166666666666,
            39.90339353955027,
            0.31200396825396826,
            0.9500807985607208,
            -0.9010416666666666,
            0.4337325384733725
        },
    
        {
            true,
            12.140625,
            40.207029542225264,
            0.2890625,
            0.9573102271958396,
            -0.9017137096774194,
            0.4323336509916695
        },
    
        {
            true,
            11.166666666666666,
            40.488338513151604,
            0.26587301587301587,
            0.9640080598369429,
            -0.9024822695035462,
            0.4307270054590597
        },
    
        {
            true,
            10.182291666666666,
            40.747035921830324,
            0.24243551587301587,
            0.9701675219483411,
            -0.903344298245614,
            0.42891616759821394
        },
    
        {
            true,
            9.1875,
            40.98279936448949,
            0.21875,
            0.9757809372497497,
            -0.904296875,
            0.4269041600467655
        },
    
        {
            true,
            8.182291666666666,
            41.19526796953258,
            0.19481646825396823,
            0.9808397135602995,
            -0.9053371993127147,
            0.4246934842219854
        },
    
        {
            true,
            7.166666666666667,
            41.38404147601934,
            0.17063492063492064,
            0.9853343208576033,
            -0.9064625850340136,
            0.42228613751040145
        },
    
        {
            true,
            6.140625,
            41.54867897550264,
            0.14620535714285715,
            0.9892542613214914,
            -0.9076704545454546,
            0.41968362601517817
        },
    
        {
            true,
            5.104166666666667,
            41.68869730081391,
            0.12152777777777779,
            0.9925880309717596,
            -0.9089583333333334,
            0.41688697300813915
        },
    
        {
            true,
            4.057291666666667,
            41.80356903820052,
            0.09660218253968254,
            0.9953230723381077,
            -0.9103238448844884,
            0.4138967231505002
        },
    
        {
            true,
            3.0,
            41.892720131306824,
            0.07142857142857142,
            0.9974457174120672,
            -0.9117647058823529,
            0.41071294246379236
        },
    
        {
            true,
            1.9322916666666667,
            41.95552703655301,
            0.04600694444444445,
            0.9989411199179288,
            -0.913278721682848,
            0.40733521394711664
        },
    
        {
            true,
            0.8541666666666666,
            41.99131337914493,
            0.020337301587301588,
            0.9997931756939268,
            -0.914863782051282,
            0.4037626286456243
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            43.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            42.442708333333336,
            6.900471674573916,
            0.9870397286821706,
            0.16047608545520736,
            -0.9918016975308643,
            0.12778651249210957
        },
    
        {
            true,
            41.875,
            9.771610665596537,
            0.9738372093023255,
            0.22724675966503574,
            -0.9840909090909091,
            0.17766564846539157
        },
    
        {
            true,
            41.296875,
            11.981991288361671,
            0.9603924418604651,
            0.27865096019445745,
            -0.9768415178571429,
            0.21396413014931556
        },
    
        {
            true,
            40.708333333333336,
            13.85032841568105,
            0.9467054263565892,
            0.32210066082979183,
            -0.9700292397660819,
            0.24298821781896582
        },
    
        {
            true,
            40.109375,
            15.499614095498474,
            0.9327761627906976,
            0.36045614175577845,
            -0.9636314655172413,
            0.26723472578445645
        },
    
        {
            true,
            39.5,
            16.99264546796643,
            0.9186046511627907,
            0.39517780158061466,
            -0.9576271186440678,
            0.2880109401350242
        },
    
        {
            true,
            38.880208333333336,
            18.36652933889789,
            0.9041908914728682,
            0.4271285892766951,
            -0.9519965277777779,
            0.3061088223149649
        },
    
        {
            true,
            38.25,
            19.64529205687714,
            0.8895348837209303,
            0.45686725713667764,
            -0.9467213114754098,
            0.3220539681455269
        },
    
        {
            true,
            37.609375,
            20.845501004038617,
            0.8746366279069767,
            0.48477909311717715,
            -0.9417842741935484,
            0.3362177581296551
        },
    
        {
            true,
            36.958333333333336,
            21.97911729852275,
            0.8594961240310078,
            0.511142262756343,
            -0.9371693121693122,
            0.3488748777543294
        },
    
        {
            true,
            36.296875,
            23.055083284047686,
            0.8441133720930233,
            0.5361647275359928,
            -0.932861328125,
            0.3602356763132451
        },
    
        {
            true,
            35.625,
            24.0802694129447,
            0.8284883720930233,
            0.5600062654173186,
            -0.9288461538461539,
            0.37046568327607227
        },
    
        {
            true,
            34.942708333333336,
            25.06007051729099,
            0.8126211240310078,
            0.5827923376114184,
            -0.9251104797979798,
            0.3796980381407726
        },
    
        {
            true,
            34.25,
            25.998798049140657,
            0.7965116279069767,
            0.6046232104451316,
            -0.9216417910447762,
            0.3880417619274725
        },
    
        {
            true,
            33.546875,
            26.899947541479982,
            0.7801598837209303,
            0.6255801753832554,
            -0.9184283088235294,
            0.39558746384529386
        },
    
        {
            true,
            32.833333333333336,
            27.76638655320894,
            0.7635658914728682,
            0.6457299198420684,
            -0.9154589371980676,
            0.4024113993218687
        },
    
        {
            true,
            32.109375,
            28.600490155054597,
            0.7467296511627907,
            0.6651276780245255,
            -0.9127232142857142,
            0.40857843078649425
        },
    
        {
            true,
            31.375,
            29.404240765576656,
            0.7296511627906976,
            0.6838195526878292,
            -0.9102112676056338,
            0.4141442361348825
        },
    
        {
            true,
            30.630208333333332,
            30.179303130731785,
            0.7123304263565892,
            0.7018442588542275,
            -0.9079137731481483,
            0.41915698792683037
        },
    
        {
            true,
            29.875,
            30.927081579095045,
            0.6947674418604651,
            0.7192344553277917,
            -0.9058219178082192,
            0.42365865176842527
        },
    
        {
            true,
            29.109375,
            31.648764385191644,
            0.6769622093023255,
            0.7360177763998057,
            -0.9039273648648649,
            0.4276860052052925
        },
    
        {
            true,
            28.333333333333332,
            32.34535858855521,
            0.6589147286821705,
            0.7522176415943072,
            -0.9022222222222223,
            0.4312714478474028
        },
    
        {
            true,
            27.546875,
            33.017717633633836,
            0.640625,
            0.7678538984566008,
            -0.9006990131578947,
            0.4344436530741294
        },
    
        {
            true,
            26.75,
            33.66656353119516,
            0.622093023255814,
            0.7829433379347711,
            -0.8993506493506493,
            0.4372280978077293
        },
    
        {
            true,
            25.942708333333332,
            34.292504783576206,
            0.6033187984496124,
            0.7975001112459584,
            -0.8981704059829061,
            0.43964749722533597
        },
    
        {
            true,
            25.125,
            34.89605099434605,
            0.5843023255813954,
            0.8115360696359546,
            -0.8971518987341772,
            0.44172216448539303
        },
    
        {
            true,
            24.296875,
            35.477624853340664,
            0.5650436046511628,
            0.8250610431009456,
            -0.8962890625,
            0.4434703106667583
        },
    
        {
            true,
            23.458333333333332,
            36.03757202174173,
            0.5455426356589147,
            0.8380830702730635,
            -0.8955761316872428,
            0.4449082965647127
        },
    
        {
            true,
            22.609375,
            36.576169319782174,
            0.5257994186046512,
            0.8506085888321436,
            -0.8950076219512195,
            0.4460508453631972
        },
    
        {
            true,
            21.75,
            37.09363152887568,
            0.5058139534883721,
            0.8626425936947834,
            -0.8945783132530121,
            0.4469112232394661
        },
    
        {
            true,
            20.880208333333332,
            37.590117051647994,
            0.48558624031007747,
            0.8741887686429766,
            -0.8942832341269842,
            0.4475013934719999
        },
    
        {
            true,
            20.0,
            38.06573262134856,
            0.46511627906976744,
            0.8852495958453154,
            -0.8941176470588236,
            0.44783214848645364
        },
    
        {
            true,
            19.109375,
            38.52053721210771,
            0.44440406976744184,
            0.8958264467932026,
            -0.8940770348837209,
            0.4479132233966013
        },
    
        {
            true,
            18.208333333333332,
            38.954545270381765,
            0.42344961240310075,
            0.9059196574507387,
            -0.8941570881226054,
            0.4477533939124341
        },
    
        {
            true,
            17.296875,
            39.36772936345675,
            0.4022529069767442,
            0.9155285898478315,
            -0.8943536931818182,
            0.4473605609483722
        },
    
        {
            true,
            16.375,
            39.760022321422305,
            0.3808139534883721,
            0.924651681893542,
            -0.8946629213483146,
            0.4467418238362057
        },
    
        {
            true,
            15.442708333333334,
            40.13131893336671,
            0.3591327519379845,
            0.9332864868224816,
            -0.8950810185185186,
            0.44590354370407453
        },
    
        {
            true,
            14.5,
            40.48147724577254,
            0.3372093023255814,
            0.941429703390059,
            -0.8956043956043956,
            0.4448513983051927
        },
    
        {
            true,
            13.546875,
            40.81031950051819,
            0.31504360465116277,
            0.9490771976864696,
            -0.8962296195652174,
            0.4435904293534586
        },
    
        {
            true,
            12.583333333333334,
            41.11763274098136,
            0.2926356589147287,
            0.9562240172321246,
            -0.8969534050179212,
            0.4421250832363587
        },
    
        {
            true,
            11.609375,
            41.40316910707893,
            0.2699854651162791,
            0.9628643978390449,
            -0.8977726063829787,
            0.44045924581998863
        },
    
        {
            true,
            10.625,
            41.666645833328126,
            0.24709302325581395,
            0.9689917635657703,
            -0.8986842105263158,
            0.43859627192976974
        },
    
        {
            true,
            9.630208333333334,
            41.90774495790244,
            0.22395833333333334,
            0.9745987199512195,
            -0.8996853298611112,
            0.43653900997815037
        },
    
        {
            true,
            8.625,
            42.126112744947164,
            0.2005813953488372,
            0.9796770405801666,
            -0.9007731958762887,
            0.4342898221128574
        },
    
        {
            true,
            7.609375,
            42.3213588169068,
            0.1769622093023256,
            0.9842176469048094,
            -0.9019451530612245,
            0.43185060017251836
        },
    
        {
            true,
            6.583333333333333,
            42.49305498810626,
            0.15310077519379844,
            0.9882105811187502,
            -0.9031986531986532,
            0.429222777657639
        },
    
        {
            true,
            5.546875,
            42.640733785130564,
            0.12899709302325582,
            0.9916449717472224,
            -0.90453125,
            0.42640733785130563
        },
    
        {
            true,
            4.5,
            42.7638866334668,
            0.10465116279069768,
            0.994508991475972,
            -0.905940594059406,
            0.4234048181531366
        },
    
        {
            true,
            3.4427083333333335,
            42.861961683194075,
            0.08006298449612403,
            0.9967898065859088,
            -0.9074244281045751,
            0.4202153106195497
        },
    
        {
            true,
            2.375,
            42.934361238988984,
            0.055232558139534885,
            0.9984735171857904,
            -0.9089805825242718,
            0.41683845863096103
        },
    
        {
            true,
            1.296875,
            42.98043875106878,
            0.030159883720930234,
            0.9995450872341577,
            -0.9106069711538461,
            0.4132734495295075
        },
    
        {
            true,
            0.20833333333333334,
            42.99949531357574,
            0.0048449612403100775,
            0.9999882631064126,
            -0.9123015873015872,
            0.40951900298643557
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            44.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            43.453125,
            6.915629236329475,
            0.9875710227272727,
            0.1571733917347608,
            -0.9914504716981132,
            0.13048357049678255
        },
    
        {
            true,
            42.895833333333336,
            9.795278589141233,
            0.9749053030303031,
            0.22261996793502803,
            -0.9834104938271606,
            0.1813940479470599
        },
    
        {
            true,
            42.328125,
            12.013735222002149,
            0.9620028409090909,
            0.2730394368636852,
            -0.9758522727272727,
            0.21843154949094815
        },
    
        {
            true,
            41.75,
            13.890194383089101,
            0.9488636363636364,
            0.31568623597929774,
            -0.96875,
            0.24803918541230538
        },
    
        {
            true,
            41.161458333333336,
            15.547808458855663,
            0.9354876893939394,
            0.3533592831558105,
            -0.9620796783625731,
            0.27276856945360817
        },
    
        {
            true,
            40.5625,
            17.04944555550121,
            0.921875,
            0.3874873989886639,
            -0.9558189655172413,
            0.2939559578534692
        },
    
        {
            true,
            39.953125,
            18.43224898742351,
            0.9080255681818182,
            0.4189147497141707,
            -0.949947033898305,
            0.31241099978683917
        },
    
        {
            true,
            39.333333333333336,
            19.72026594366538,
            0.893939393939394,
            0.4481878623560314,
            -0.9444444444444445,
            0.3286710990610897
        },
    
        {
            true,
            38.703125,
            20.930076809089236,
            0.8796164772727273,
            0.4756835638429372,
            -0.9392930327868853,
            0.34311601326375796
        },
    
        {
            true,
            38.0625,
            22.073651572632926,
            0.8650568181818182,
            0.5016738993780211,
            -0.9344758064516129,
            0.356026638268273
        },
    
        {
            true,
            37.411458333333336,
            23.159939235094374,
            0.8502604166666667,
            0.5263622553430539,
            -0.929976851851852,
            0.36761808309673616
        },
    
        {
            true,
            36.75,
            24.195815753968702,
            0.8352272727272727,
            0.5499049034992887,
            -0.92578125,
            0.37805962115576097
        },
    
        {
            true,
            36.078125,
            25.18668093426315,
            0.8199573863636364,
            0.5724245666877988,
            -0.921875,
            0.38748739898866386
        },
    
        {
            true,
            35.395833333333336,
            26.136851046728808,
            0.8044507575757577,
            0.5940193419711093,
            -0.9182449494949495,
            0.3960128946474062
        },
    
        {
            true,
            34.703125,
            27.04982652872981,
            0.7887073863636364,
            0.6147687847438593,
            -0.9148787313432836,
            0.4037287541601464
        },
    
        {
            true,
            34.0,
            27.92848008753788,
            0.7727272727272727,
            0.6347381838076791,
            -0.9117647058823529,
            0.41071294246379236
        },
    
        {
            true,
            33.286458333333336,
            28.775192295157016,
            0.7565104166666667,
            0.6539816430717503,
            -0.9088919082125604,
            0.4170317723935799
        },
    
        {
            true,
            32.5625,
            29.591951502900244,
            0.7400568181818182,
            0.672544352338642,
            -0.90625,
            0.42274216432714634
        },
    
        {
            true,
            31.828125,
            30.380428880849838,
            0.7233664772727273,
            0.6904642927465873,
            -0.9038292253521126,
            0.4278933645190118
        },
    
        {
            true,
            31.083333333333332,
            31.142035721655848,
            0.7064393939393939,
            0.707773539128542,
            -0.9016203703703705,
            0.43252827391188675
        },
    
        {
            true,
            30.328125,
            31.87796784590221,
            0.6892755681818182,
            0.7244992692250501,
            -0.8996147260273972,
            0.43668449103975626
        },
    
        {
            true,
            29.5625,
            32.58924045985116,
            0.671875,
            0.7406645559057082,
            -0.8978040540540541,
            0.44039514134934005
        },
    
        {
            true,
            28.786458333333332,
            33.276715832895285,
            0.6542376893939393,
            0.7562889962021656,
            -0.8961805555555556,
            0.4436895444386038
        },
    
        {
            true,
            28.0,
            33.94112549695428,
            0.6363636363636364,
            0.77138921583987,
            -0.8947368421052632,
            0.44659375653887207
        },
    
        {
            true,
            27.203125,
            34.5830882113552,
            0.6182528409090909,
            0.7859792775307999,
            -0.8934659090909091,
            0.4491310157318857
        },
    
        {
            true,
            26.395833333333332,
            35.20312461471125,
            0.599905303030303,
            0.8000710139707102,
            -0.892361111111111,
            0.45132211044501597
        },
    
        {
            true,
            25.578125,
            35.80166925555811,
            0.5813210227272727,
            0.8136743012626844,
            -0.8914161392405063,
            0.4531856867792166
        },
    
        {
            true,
            24.75,
            36.37908052713812,
            0.5625,
            0.8267972847076845,
            -0.890625,
            0.45473850658922654
        },
    
        {
            true,
            23.911458333333332,
            36.93564890960038,
            0.5434422348484849,
            0.8394465661272814,
            -0.8899819958847737,
            0.455995665550622
        },
    
        {
            true,
            23.0625,
            37.471603832101984,
            0.5241477272727273,
            0.8516273598204996,
            -0.8894817073170732,
            0.4569707784402681
        },
    
        {
            true,
            22.203125,
            37.98711939900649,
            0.5046164772727273,
            0.8633436227046929,
            -0.8891189759036144,
            0.45767613733742757
        },
    
        {
            true,
            21.333333333333332,
            38.482319172431495,
            0.4848484848484848,
            0.8745981630098068,
            -0.888888888888889,
            0.4581228472908511
        },
    
        {
            true,
            20.453125,
            38.95728016346078,
            0.46484375,
            0.885392730987745,
            -0.8887867647058824,
            0.4583209430995386
        },
    
        {
            true,
            19.5625,
            39.41203615331235,
            0.4446022727272727,
            0.8957280943934625,
            -0.8888081395348837,
            0.45827949015479474
        },
    
        {
            true,
            18.661458333333332,
            39.8465804414038,
            0.424124053030303,
            0.9056041009409955,
            -0.888948754789272,
            0.4580066717402736
        },
    
        {
            true,
            17.75,
            40.260868097943444,
            0.4034090909090909,
            0.9150197294987147,
            -0.8892045454545454,
            0.45750986474935734
        },
    
        {
            true,
            16.828125,
            40.65481778318991,
            0.38245738636363635,
            0.9239731314361344,
            -0.8895716292134831,
            0.45679570542910014
        },
    
        {
            true,
            15.895833333333334,
            41.028313182958044,
            0.3612689393939394,
            0.9324616632490464,
            -0.8900462962962964,
            0.4558701464773116
        },
    
        {
            true,
            14.953125,
            41.38120409961961,
            0.33984375,
            0.9404819113549912,
            -0.890625,
            0.4547385065892265
        },
    
        {
            true,
            14.0,
            41.71330722922842,
            0.3181818181818182,
            0.9480297097551914,
            -0.8913043478260869,
            0.45340551336117846
        },
    
        {
            true,
            13.036458333333334,
            42.02440664808088,
            0.296283143939394,
            0.9551001510927472,
            -0.8920810931899641,
            0.4518753403019448
        },
    
        {
            true,
            12.0625,
            42.314254025682644,
            0.2741477272727273,
            0.9616875914927874,
            -0.8929521276595744,
            0.45015163857109197
        },
    
        {
            true,
            11.078125,
            42.5825685754673,
            0.2517755681818182,
            0.9677856494424386,
            -0.8939144736842105,
            0.44823756395228737
        },
    
        {
            true,
            10.083333333333334,
            42.829036749486775,
            0.22916666666666669,
            0.9733871988519721,
            -0.8949652777777778,
            0.4461357994738206
        },
    
        {
            true,
            9.078125,
            43.05331167848038,
            0.20632102272727273,
            0.9784843563290995,
            -0.8961018041237113,
            0.4438485740049523
        },
    
        {
            true,
            8.0625,
            43.25501235406135,
            0.18323863636363635,
            0.9830684625923034,
            -0.8973214285714286,
            0.44137767708225867
        },
    
        {
            true,
            7.036458333333333,
            43.43372254508314,
            0.15991950757575757,
            0.9871300578427987,
            -0.898621632996633,
            0.438724470152355
        },
    
        {
            true,
            6.0,
            43.58898943540674,
            0.13636363636363635,
            0.9906588508046986,
            -0.9,
            0.4358898943540674
        },
    
        {
            true,
            4.953125,
            43.7203219651271,
            0.11257102272727272,
            0.9936436810256158,
            -0.9014542079207921,
            0.4328744749022485
        },
    
        {
            true,
            3.8958333333333335,
            43.82718885165793,
            0.08854166666666667,
            0.9960724739013166,
            -0.9029820261437909,
            0.4296783220750777
        },
    
        {
            true,
            2.828125,
            43.9090162607223,
            0.06427556818181818,
            0.9979321877436885,
            -0.9045813106796117,
            0.4263011287448767
        },
    
        {
            true,
            1.75,
            43.96518509002322,
            0.03977272727272727,
            0.9992087520459823,
            -0.90625,
            0.42274216432714634
        },
    
        {
            true,
            0.6614583333333334,
            43.99502781989419,
            0.01503314393939394,
            0.9998869959066862,
            -0.9079861111111112,
            0.4190002649513732
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            45.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            44.463541666666664,
            6.927731407654124,
            0.9880787037037037,
            0.15394958683675833,
            -0.9910857371794872,
            0.13322560399334854
        },
    
        {
            true,
            43.916666666666664,
            9.814600801300537,
            0.9759259259259259,
            0.21810224002890083,
            -0.9827044025157232,
            0.18518114719434975
        },
    
        {
            true,
            43.359375,
            12.04012456785124,
            0.9635416666666666,
            0.2675583237300276,
            -0.9748263888888888,
            0.22296526977502296
        },
    
        {
            true,
            42.791666666666664,
            13.92383797266002,
            0.9509259259259258,
            0.30941862161466716,
            -0.9674242424242423,
            0.25316069041200034
        },
    
        {
            true,
            42.213541666666664,
            15.588999325056031,
            0.9380787037037036,
            0.34642220722346734,
            -0.9604724702380952,
            0.27837498794742915
        },
    
        {
            true,
            41.625,
            17.098519672766997,
            0.925,
            0.37996710383926663,
            -0.9539473684210527,
            0.2999740293467894
        },
    
        {
            true,
            41.026041666666664,
            18.489562059846918,
            0.9116898148148148,
            0.41087915688548704,
            -0.9478268678160919,
            0.3187855527559813
        },
    
        {
            true,
            40.416666666666664,
            19.786183450972946,
            0.8981481481481481,
            0.4396929655771766,
            -0.9420903954802259,
            0.3353590415419143
        },
    
        {
            true,
            39.796875,
            21.004969417601515,
            0.884375,
            0.46677709816892254,
            -0.93671875,
            0.3500828236266919
        },
    
        {
            true,
            39.166666666666664,
            22.15789300051389,
            0.8703703703703703,
            0.49239762223364203,
            -0.9316939890710382,
            0.363244147549408
        },
    
        {
            true,
            38.526041666666664,
            23.253905338636436,
            0.8561342592592592,
            0.5167534519696986,
            -0.9269993279569891,
            0.3750629893328457
        },
    
        {
            true,
            37.875,
            24.29988425898362,
            0.8416666666666667,
            0.5399974279774138,
            -0.9226190476190477,
            0.3857124485552956
        },
    
        {
            true,
            37.213541666666664,
            25.30123152384611,
            0.8269675925925926,
            0.5622495894188024,
            -0.9185384114583334,
            0.39533174256009546
        },
    
        {
            true,
            36.541666666666664,
            26.262265652875847,
            0.812037037037037,
            0.583605903397241,
            -0.9147435897435898,
            0.40403485619808993
        },
    
        {
            true,
            35.859375,
            27.18648974416107,
            0.796875,
            0.6041442165369126,
            -0.9112215909090909,
            0.4119165112751677
        },
    
        {
            true,
            35.166666666666664,
            28.076779650728387,
            0.7814814814814814,
            0.623928436682853,
            -0.9079601990049752,
            0.4190564126974386
        },
    
        {
            true,
            34.463541666666664,
            28.93551962190986,
            0.7658564814814814,
            0.6430115471535525,
            -0.9049479166666667,
            0.4255223473810274
        },
    
        {
            true,
            33.75,
            29.764702249476645,
            0.75,
            0.6614378277661477,
            -0.9021739130434783,
            0.43137249636922675
        },
    
        {
            true,
            33.026041666666664,
            30.566003530582755,
            0.733912037037037,
            0.679244522901839,
            -0.8996279761904762,
            0.43665719329403935
        },
    
        {
            true,
            32.291666666666664,
            31.3408401911769,
            0.7175925925925926,
            0.6964631153594867,
            -0.8973004694835681,
            0.4414202843827732
        },
    
        {
            true,
            31.546875,
            32.09041410973649,
            0.7010416666666667,
            0.7131203135496998,
            -0.8951822916666666,
            0.4457001959685624
        },
    
        {
            true,
            30.791666666666668,
            32.815747193822794,
            0.6842592592592592,
            0.7292388265293954,
            -0.8932648401826483,
            0.4495307834770246
        },
    
        {
            true,
            30.026041666666668,
            33.517709077912784,
            0.6672453703703703,
            0.744837979509173,
            -0.8915399774774774,
            0.452942014566389
        },
    
        {
            true,
            29.25,
            34.197039345533994,
            0.65,
            0.7599342076785333,
            -0.89,
            0.45596052460711994
        },
    
        {
            true,
            28.463541666666668,
            34.85436551983023,
            0.6325231481481481,
            0.7745414559962274,
            -0.8886376096491228,
            0.45861007262934517
        },
    
        {
            true,
            27.666666666666668,
            35.490217744549774,
            0.6148148148148148,
            0.7886715054344394,
            -0.8874458874458874,
            0.4609119187603867
        },
    
        {
            true,
            26.859375,
            36.10504084763477,
            0.596875,
            0.8023342410585504,
            -0.8864182692307693,
            0.4628851390722406
        },
    
        {
            true,
            26.041666666666668,
            36.69920431320306,
            0.5787037037037037,
            0.8155378736267347,
            -0.885548523206751,
            0.46454689004054506
        },
    
        {
            true,
            25.213541666666668,
            37.27301056559912,
            0.560300925925926,
            0.8282891236799805,
            -0.8848307291666666,
            0.465912632069989
        },
    
        {
            true,
            24.375,
            37.826701878435024,
            0.5416666666666666,
            0.8405933750763339,
            -0.8842592592592593,
            0.46699631948685216
        },
    
        {
            true,
            23.526041666666668,
            38.360466153297246,
            0.522800925925926,
            0.8524548034066055,
            -0.8838287601626016,
            0.4678105628450884
        },
    
        {
            true,
            22.666666666666668,
            38.87444176090793,
            0.5037037037037038,
            0.8638764835757318,
            -0.8835341365461847,
            0.46836676820371
        },
    
        {
            true,
            21.796875,
            39.36872159766399,
            0.484375,
            0.8748604799480887,
            -0.8833705357142857,
            0.46867525711504754
        },
    
        {
            true,
            20.916666666666668,
            39.84335647953816,
            0.46481481481481485,
            0.8854079217675146,
            -0.8833333333333333,
            0.46874537034750774
        },
    
        {
            true,
            20.026041666666668,
            40.298357971075326,
            0.4450231481481482,
            0.8955190660238961,
            -0.8834181201550388,
            0.46858555780320155
        },
    
        {
            true,
            19.125,
            40.73370072802126,
            0.425,
            0.9051933495115836,
            -0.8836206896551724,
            0.46820345664392254
        },
    
        {
            true,
            18.213541666666668,
            41.14932441677016,
            0.4047453703703704,
            0.9144294314837814,
            -0.8839370265151515,
            0.46760595928147913
        },
    
        {
            true,
            17.291666666666668,
            41.54513526141044,
            0.3842592592592593,
            0.923225228031343,
            -0.8843632958801497,
            0.4667992726001173
        },
    
        {
            true,
            16.359375,
            41.92100725900291,
            0.36354166666666665,
            0.9315779390889536,
            -0.8848958333333333,
            0.4657889695444768
        },
    
        {
            true,
            15.416666666666666,
            42.27678309532182,
            0.34259259259259256,
            0.9394840687849293,
            -0.8855311355311355,
            0.46458003401452547
        },
    
        {
            true,
            14.463541666666666,
            42.612274786223246,
            0.321412037037037,
            0.9469394396938499,
            -0.8862658514492753,
            0.4631768998502527
        },
    
        {
            true,
            13.5,
            42.92726406376256,
            0.3,
            0.9539392014169457,
            -0.8870967741935484,
            0.46158348455658665
        },
    
        {
            true,
            12.526041666666666,
            43.22150252090886,
            0.27835648148148145,
            0.9604778337979746,
            -0.8880208333333333,
            0.459803218307541
        },
    
        {
            true,
            11.541666666666666,
            43.49471152399514,
            0.2564814814814815,
            0.9665491449776699,
            -0.8890350877192982,
            0.4578390686736331
        },
    
        {
            true,
            10.546875,
            43.746581897725164,
            0.234375,
            0.9721462643938925,
            -0.89013671875,
            0.45569356143463713
        },
    
        {
            true,
            9.541666666666666,
            43.976773383483035,
            0.21203703703703702,
            0.9772616307440675,
            -0.8913230240549828,
            0.4533687977678663
        },
    
        {
            true,
            8.526041666666666,
            44.18491386772485,
            0.18946759259259258,
            0.9818869748383301,
            -0.8925914115646258,
            0.45086646803800867
        },
    
        {
            true,
            7.5,
            44.37059837324712,
            0.16666666666666666,
            0.9860132971832694,
            -0.8939393939393939,
            0.44818786235603153
        },
    
        {
            true,
            6.463541666666667,
            44.533387801999346,
            0.14363425925925927,
            0.9896308400444299,
            -0.8953645833333332,
            0.44533387801999347
        },
    
        {
            true,
            5.416666666666667,
            44.67280741370775,
            0.12037037037037038,
            0.99272905363795,
            -0.8968646864686468,
            0.44230502389809656
        },
    
        {
            true,
            4.359375,
            44.78834501976351,
            0.096875,
            0.9952965559947446,
            -0.8984375,
            0.43910142176238737
        },
    
        {
            true,
            3.2916666666666665,
            44.879448866441706,
            0.07314814814814814,
            0.9973210859209268,
            -0.9000809061488673,
            0.43572280452856027
        },
    
        {
            true,
            2.2135416666666665,
            44.945525175371245,
            0.04918981481481481,
            0.9987894483415832,
            -0.9017928685897436,
            0.43216851130164663
        },
    
        {
            true,
            1.125,
            44.98593530204746,
            0.025,
            0.9996874511566102,
            -0.9035714285714286,
            0.42843747906711865
        },
    
        {
            true,
            0.026041666666666668,
            44.99999246479489,
            0.0005787037037037038,
            0.9999998325509977,
            -0.9054147012578616,
            0.42452823079995183
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            46.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            45.473958333333336,
            6.936794180186095,
            0.988564311594203,
            0.15079987348230642,
            -0.9907066993464053,
            0.1360155721605117
        },
    
        {
            true,
            44.9375,
            9.829602929416835,
            0.9769021739130435,
            0.2136870202047138,
            -0.9819711538461539,
            0.18903082556570835
        },
    
        {
            true,
            44.390625,
            12.061194472745019,
            0.9650135869565217,
            0.262199879842283,
            -0.9737617924528302,
            0.22756970703292487
        },
    
        {
            true,
            43.833333333333336,
            13.951304200284957,
            0.9528985507246377,
            0.30328922174532513,
            -0.9660493827160495,
            0.2583574851904622
        },
    
        {
            true,
            43.265625,
            15.623242088611923,
            0.9405570652173914,
            0.3396356975785201,
            -0.9588068181818182,
            0.2840589470656713
        },
    
        {
            true,
            42.6875,
            17.13993418161225,
            0.9279891304347826,
            0.3726072648176576,
            -0.9520089285714286,
            0.3060702532430759
        },
    
        {
            true,
            42.098958333333336,
            18.53854652469453,
            0.9151947463768116,
            0.4030118809716203,
            -0.9456323099415206,
            0.3252376583279743
        },
    
        {
            true,
            41.5,
            19.84313483298443,
            0.9021739130434783,
            0.4313724963692267,
            -0.9396551724137931,
            0.3421230143618005
        },
    
        {
            true,
            40.890625,
            21.070282084238336,
            0.8889266304347826,
            0.45804961052692034,
            -0.9340572033898306,
            0.35712342515658196
        },
    
        {
            true,
            40.270833333333336,
            22.231958587557884,
            0.8754528985507247,
            0.48330344755560617,
            -0.9288194444444445,
            0.3705326431259648
        },
    
        {
            true,
            39.640625,
            23.337113137862083,
            0.8617527173913043,
            0.5073285464752627,
            -0.9239241803278688,
            0.3825756252108538
        },
    
        {
            true,
            39.0,
            24.392621835300936,
            0.8478260869565217,
            0.5302743877239334,
            -0.9193548387096774,
            0.3934293844403377
        },
    
        {
            true,
            38.348958333333336,
            25.403885426215094,
            0.8336730072463768,
            0.5522583788307629,
            -0.9150958994708995,
            0.40323627660658884
        },
    
        {
            true,
            37.6875,
            26.375222155462502,
            0.8192934782608695,
            0.5733743946839674,
            -0.9111328125,
            0.4121128461791016
        },
    
        {
            true,
            37.015625,
            27.310135588447285,
            0.8046875,
            0.593698599748854,
            -0.9074519230769231,
            0.4201559321299582
        },
    
        {
            true,
            36.333333333333336,
            28.211502776153004,
            0.7898550724637682,
            0.6132935386120218,
            -0.904040404040404,
            0.427447011759894
        },
    
        {
            true,
            35.640625,
            29.08170988111557,
            0.774796195652174,
            0.6322110843720776,
            -0.9008861940298507,
            0.4340553713599339
        },
    
        {
            true,
            34.9375,
            29.922752108554455,
            0.7595108695652174,
            0.6504946110555316,
            -0.8979779411764706,
            0.44004047218462433
        },
    
        {
            true,
            34.223958333333336,
            30.73630875688009,
            0.7439990942028986,
            0.6681806251495671,
            -0.8953049516908212,
            0.44545375009971144
        },
    
        {
            true,
            33.5,
            31.523800532296228,
            0.7282608695652174,
            0.6853000115716571,
            -0.8928571428571429,
            0.4503400076042318
        },
    
        {
            true,
            32.765625,
            32.28643396783508,
            0.712296195652174,
            0.7018789993007626,
            -0.890625,
            0.4547385065892265
        },
    
        {
            true,
            32.020833333333336,
            33.025236299516294,
            0.6961050724637682,
            0.717939919554702,
            -0.888599537037037,
            0.45868383749328184
        },
    
        {
            true,
            31.265625,
            33.74108316814051,
            0.6796875,
            0.7335018080030546,
            -0.8867722602739726,
            0.46220661874165087
        },
    
        {
            true,
            30.5,
            34.43472084974699,
            0.6630434782608695,
            0.748580888037978,
            -0.8851351351351351,
            0.4653340655371215
        },
    
        {
            true,
            29.723958333333332,
            35.10678425886176,
            0.6461730072463768,
            0.7631909621491687,
            -0.8836805555555556,
            0.4680904567848234
        },
    
        {
            true,
            28.9375,
            35.75781164654795,
            0.6290760869565217,
            0.7773437314466946,
            -0.8824013157894737,
            0.4704975216651046
        },
    
        {
            true,
            28.140625,
            36.38825668549367,
            0.6117527173913043,
            0.7910490583802973,
            -0.8812905844155844,
            0.47257476214926847
        },
    
        {
            true,
            27.333333333333332,
            36.99849846803095,
            0.5942028985507246,
            0.8043151840876294,
            -0.8803418803418804,
            0.4743397239491148
        },
    
        {
            true,
            26.515625,
            37.588849820915975,
            0.5764266304347826,
            0.8171489091503473,
            -0.8795490506329114,
            0.4758082255812149
        },
    
        {
            true,
            25.6875,
            38.1595642500016,
            0.5584239130434783,
            0.8295557445652522,
            -0.87890625,
            0.47699455312502004
        },
    
        {
            true,
            24.848958333333332,
            38.710841759748185,
            0.5401947463768115,
            0.8415400382553954,
            -0.8784079218106996,
            0.47791162666355785
        },
    
        {
            true,
            24.0,
            39.242833740697165,
            0.5217391304347826,
            0.8531050813195036,
            -0.8780487804878049,
            0.4785711431792337
        },
    
        {
            true,
            23.140625,
            39.755647078237516,
            0.5030570652173914,
            0.8642531973529894,
            -0.8778237951807228,
            0.4789836997378014
        },
    
        {
            true,
            22.270833333333332,
            40.249347605133785,
            0.48414855072463764,
            0.8749858175029084,
            -0.8777281746031746,
            0.4791589000611165
        },
    
        {
            true,
            21.390625,
            40.72396299612029,
            0.46501358695652173,
            0.8853035433939194,
            -0.8777573529411765,
            0.4791054470131799
        },
    
        {
            true,
            20.5,
            41.179485183765955,
            0.44565217391304346,
            0.895206199647086,
            -0.877906976744186,
            0.478831223067046
        },
    
        {
            true,
            19.598958333333332,
            41.615872359572904,
            0.4260643115942029,
            0.9046928773820196,
            -0.8781728927203064,
            0.47834336045486087
        },
    
        {
            true,
            18.6875,
            42.033050611988656,
            0.40625,
            0.9137619698258403,
            -0.8785511363636364,
            0.477648302408962
        },
    
        {
            true,
            17.765625,
            42.43091524300855,
            0.38620923913043476,
            0.9224112009349684,
            -0.8790379213483146,
            0.4767518566630174
        },
    
        {
            true,
            16.833333333333332,
            42.80933179680441,
            0.3659420289855072,
            0.9306376477566175,
            -0.8796296296296297,
            0.4756592421867156
        },
    
        {
            true,
            15.890625,
            43.16813682693955,
            0.3454483695652174,
            0.9384377571073815,
            -0.8803228021978022,
            0.4743751299663687
        },
    
        {
            true,
            14.9375,
            43.50713842290711,
            0.32472826086956524,
            0.9458073570197199,
            -0.8811141304347826,
            0.4729036785098599
        },
    
        {
            true,
            13.973958333333334,
            43.82611651171324,
            0.3037817028985507,
            0.9527416632981138,
            -0.8820004480286738,
            0.4712485646420778
        },
    
        {
            true,
            13.0,
            44.12482294582042,
            0.2826086956521739,
            0.9592352814308787,
            -0.8829787234042553,
            0.4694130100619194
        },
    
        {
            true,
            12.015625,
            44.4029813848054,
            0.26120923913043476,
            0.9652822040175087,
            -0.884046052631579,
            0.4673998040505832
        },
    
        {
            true,
            11.020833333333334,
            44.660286974435,
            0.23958333333333334,
            0.9708758037920653,
            -0.8851996527777778,
            0.46521132265036463
        },
    
        {
            true,
            10.015625,
            44.89640582339944,
            0.21773097826086957,
            0.9760088222478139,
            -0.8864368556701031,
            0.46284954457112826
        },
    
        {
            true,
            9.0,
            45.110974274559844,
            0.1956521739130435,
            0.9806733537947793,
            -0.8877551020408163,
            0.46031606402612085
        },
    
        {
            true,
            7.973958333333333,
            45.30359796416024,
            0.17334692028985507,
            0.9848608253078313,
            -0.8891519360269361,
            0.4576121006480832
        },
    
        {
            true,
            6.9375,
            45.47385065892265,
            0.15081521739130435,
            0.9885619708461446,
            -0.890625,
            0.4547385065892265
        },
    
        {
            true,
            5.890625,
            45.62127285718117,
            0.1280570652173913,
            0.9917668012430688,
            -0.8921720297029703,
            0.45169577086317986
        },
    
        {
            true,
            4.833333333333333,
            45.74537013610108,
            0.10507246376811594,
            0.9944645681761104,
            -0.8937908496732027,
            0.44848402094216744
        },
    
        {
            true,
            3.765625,
            45.84561122244282,
            0.08186141304347826,
            0.9966437222270178,
            -0.8954793689320388,
            0.44510302157711473
        },
    
        {
            true,
            2.6875,
            45.92142575911597,
            0.05842391304347827,
            0.9982918643286082,
            -0.8972355769230769,
            0.4415521707607305
        },
    
        {
            true,
            1.5989583333333333,
            45.972201733746274,
            0.03475996376811594,
            0.9993956898640493,
            -0.8990575396825398,
            0.4378304927023455
        },
    
        {
            true,
            0.5,
            45.9972825284277,
            0.010869565217391304,
            0.9999409245310369,
            -0.9009433962264151,
            0.4339366276266764
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            47.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            46.484375,
            6.9428294563077815,
            0.989029255319149,
            0.14771977566612302,
            -0.9903125,
            0.13885658912615562
        },
    
        {
            true,
            45.958333333333336,
            9.84030473218295,
            0.9778368794326242,
            0.2093681857911266,
            -0.9812091503267975,
            0.19294715161143042
        },
    
        {
            true,
            45.421875,
            12.076972778158234,
            0.9664228723404256,
            0.25695686762038794,
            -0.97265625,
            0.23224947650304298
        },
    
        {
            true,
            44.875,
            13.972629494837397,
            0.9547872340425532,
            0.2972899892518595,
            -0.964622641509434,
            0.2636345187705169
        },
    
        {
            true,
            44.317708333333336,
            15.650582355989087,
            0.9429299645390071,
            0.33299111395721465,
            -0.957079475308642,
            0.28982559918498313
        },
    
        {
            true,
            43.75,
            17.173744495595596,
            0.9308510638297872,
            0.3653988190552254,
            -0.95,
            0.3122498999199199
        },
    
        {
            true,
            43.171875,
            18.579268257506133,
            0.9185505319148937,
            0.395303579946939,
            -0.943359375,
            0.33177264745546664
        },
    
        {
            true,
            42.583333333333336,
            19.89119710380001,
            0.9060283687943262,
            0.42321695965531936,
            -0.9371345029239767,
            0.3489683702421055
        },
    
        {
            true,
            41.984375,
            21.126103660149333,
            0.8932845744680851,
            0.44949156723721984,
            -0.9313038793103449,
            0.36424316655429884
        },
    
        {
            true,
            41.375,
            22.295949744292123,
            0.8803191489361702,
            0.4743819094530239,
            -0.9258474576271186,
            0.3778974532930868
        },
    
        {
            true,
            40.755208333333336,
            23.40967735161245,
            0.8671320921985816,
            0.4980782415236692,
            -0.9207465277777779,
            0.3901612891935409
        },
    
        {
            true,
            40.125,
            24.47415728886288,
            0.8537234042553191,
            0.5207267508268698,
            -0.9159836065573771,
            0.4012156932600472
        },
    
        {
            true,
            39.484375,
            25.494786346611633,
            0.840093085106383,
            0.5424422626938645,
            -0.9115423387096774,
            0.41120623139696183
        },
    
        {
            true,
            38.833333333333336,
            26.475880008457167,
            0.8262411347517731,
            0.5633165959246206,
            -0.9074074074074074,
            0.4202520636263043
        },
    
        {
            true,
            38.171875,
            27.42094015500517,
            0.8121675531914894,
            0.5834242586171313,
            -0.903564453125,
            0.4284521899219558
        },
    
        {
            true,
            37.5,
            28.33284313301438,
            0.7978723404255319,
            0.6028264496386038,
            -0.9,
            0.4358898943540674
        },
    
        {
            true,
            36.817708333333336,
            29.21397530432305,
            0.7833554964539008,
            0.6215739426451713,
            -0.8967013888888888,
            0.44263598945944016
        },
    
        {
            true,
            36.125,
            30.066332915738162,
            0.7686170212765957,
            0.6397092109731524,
            -0.8936567164179104,
            0.4487512375483308
        },
    
        {
            true,
            35.421875,
            30.8915971015481,
            0.753656914893617,
            0.6572680234371936,
            -0.8908547794117647,
            0.454288192669825
        },
    
        {
            true,
            34.708333333333336,
            31.691191161302566,
            0.7384751773049646,
            0.6742806630064375,
            -0.8882850241545893,
            0.45929262552612415
        },
    
        {
            true,
            33.984375,
            32.46632495154595,
            0.7230718085106383,
            0.6907728713094883,
            -0.8859375,
            0.46380464216494216
        },
    
        {
            true,
            33.25,
            33.21802974289715,
            0.7074468085106383,
            0.7067665902744075,
            -0.8838028169014085,
            0.46785957384362187
        },
    
        {
            true,
            32.505208333333336,
            33.947185909977826,
            0.6916001773049646,
            0.722280551276124,
            -0.8818721064814814,
            0.47148869319413644
        },
    
        {
            true,
            31.75,
            34.65454515644377,
            0.675531914893617,
            0.7373307480094419,
            -0.8801369863013698,
            0.47471979666361325
        },
    
        {
            true,
            30.984375,
            35.34074851866291,
            0.6592420212765957,
            0.7519308195460195,
            -0.878589527027027,
            0.47757768268463396
        },
    
        {
            true,
            30.208333333333332,
            36.006341069625805,
            0.6427304964539008,
            0.7660923631835279,
            -0.8772222222222222,
            0.48008454759501074
        },
    
        {
            true,
            29.421875,
            36.65178401502954,
            0.6259973404255319,
            0.7798251918091392,
            -0.8760279605263158,
            0.4822603159872308
        },
    
        {
            true,
            28.625,
            37.27746470724639,
            0.6090425531914894,
            0.7931375469626891,
            -0.875,
            0.4841229182759271
        },
    
        {
            true,
            27.817708333333332,
            37.88370498092283,
            0.5918661347517731,
            0.8060362761898474,
            -0.8741319444444445,
            0.4856885253964465
        },
    
        {
            true,
            27.0,
            38.47076812334269,
            0.574468085106383,
            0.8185269813477167,
            -0.8734177215189873,
            0.4869717483967429
        },
    
        {
            true,
            26.171875,
            39.03886472458408,
            0.5568484042553191,
            0.830614143076257,
            -0.8728515625,
            0.487985809057301
        },
    
        {
            true,
            25.333333333333332,
            39.58815760075508,
            0.5390070921985816,
            0.8423012255479805,
            -0.8724279835390947,
            0.4887426864290751
        },
    
        {
            true,
            24.484375,
            40.11876594387438,
            0.5209441489361702,
            0.8535907647632847,
            -0.872141768292683,
            0.48925324321798025
        },
    
        {
            true,
            23.625,
            40.630768821177874,
            0.5026595744680851,
            0.8644844430037846,
            -0.8719879518072289,
            0.48952733519491415
        },
    
        {
            true,
            22.755208333333332,
            41.124208122547444,
            0.4841533687943262,
            0.8749831515435627,
            -0.8719618055555556,
            0.4895739062208029
        },
    
        {
            true,
            21.875,
            41.599091035742596,
            0.4654255319148936,
            0.8850870433136723,
            -0.8720588235294118,
            0.4894010710087364
        },
    
        {
            true,
            20.984375,
            42.055392113965304,
            0.4464760638297872,
            0.8947955768928788,
            -0.8722747093023255,
            0.48901618737168956
        },
    
        {
            true,
            20.083333333333332,
            42.49305498810626,
            0.42730496453900707,
            0.904107552938431,
            -0.8726053639846744,
            0.4884259194035202
        },
    
        {
            true,
            19.171875,
            42.91199376612994,
            0.40791223404255317,
            0.9130211439602115,
            -0.873046875,
            0.4876362927969311
        },
    
        {
            true,
            18.25,
            43.31209415394273,
            0.3882978723404255,
            0.9215339181689942,
            -0.8735955056179775,
            0.4866527433027273
        },
    
        {
            true,
            17.317708333333332,
            43.693214325357175,
            0.3684618794326241,
            0.9296428579863228,
            -0.8742476851851853,
            0.4854801591706353
        },
    
        {
            true,
            16.375,
            44.05518556310937,
            0.3484042553191489,
            0.937344373683178,
            -0.875,
            0.4841229182759271
        },
    
        {
            true,
            15.421875,
            44.39781268806353,
            0.328125,
            0.94463431251199,
            -0.8758491847826086,
            0.4825849205224297
        },
    
        {
            true,
            14.458333333333334,
            44.720874289555454,
            0.3076241134751774,
            0.951507963607563,
            -0.8767921146953406,
            0.4808696160167253
        },
    
        {
            true,
            13.484375,
            45.0241227661281,
            0.2869015957446808,
            0.9579600588537894,
            -0.8778257978723404,
            0.4789800294268947
        },
    
        {
            true,
            12.5,
            45.30728418256826,
            0.26595744680851063,
            0.9639847698418779,
            -0.8789473684210526,
            0.4769187808691396
        },
    
        {
            true,
            11.505208333333334,
            45.57005794605266,
            0.2447916666666667,
            0.9695757009798439,
            -0.8801540798611112,
            0.4746881036047152
        },
    
        {
            true,
            10.5,
            45.81211630125812,
            0.22340425531914893,
            0.9747258787501728,
            -0.8814432989690721,
            0.47228985877585694
        },
    
        {
            true,
            9.484375,
            46.03310364139458,
            0.20179521276595744,
            0.9794277370509485,
            -0.8828125,
            0.4697255473611692
        },
    
        {
            true,
            8.458333333333334,
            46.23263562919836,
            0.17996453900709225,
            0.9836730984935823,
            -0.8842592592592593,
            0.46699631948685216
        },
    
        {
            true,
            7.421875,
            46.410298118891404,
            0.1579122340425532,
            0.9874531514657746,
            -0.88578125,
            0.464102981188914
        },
    
        {
            true,
            6.375,
            46.56564586688345,
            0.13563829787234044,
            0.990758422699648,
            -0.8873762376237624,
            0.46104599868201435
        },
    
        {
            true,
            5.317708333333333,
            46.698201015473785,
            0.11314273049645392,
            0.9935787450100807,
            -0.8890420751633987,
            0.45782550015170376
        },
    
        {
            true,
            4.25,
            46.80745132988977,
            0.09042553191489362,
            0.9959032197848888,
            -0.8907766990291263,
            0.4544412750474735
        },
    
        {
            true,
            3.171875,
            46.8928481645589,
            0.06748670212765957,
            0.9977201737140191,
            -0.892578125,
            0.45089277081306633
        },
    
        {
            true,
            2.0833333333333335,
            46.953804129401725,
            0.04432624113475177,
            0.9990171091362068,
            -0.8944444444444444,
            0.447179086946683
        },
    
        {
            true,
            0.984375,
            46.98969042097825,
            0.020944148936170214,
            0.9997806472548564,
            -0.8963738207547169,
            0.44329896623564385
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            48.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            47.494791666666664,
            6.945845127839424,
            0.9894748263888888,
            0.144705106829988,
            -0.9899022108843536,
            0.14175194138447803
        },
    
        {
            true,
            46.979166666666664,
            9.846720230896969,
            0.9787326388888888,
            0.20514000481035352,
            -0.9804166666666666,
            0.19693440461793935
        },
    
        {
            true,
            46.453125,
            12.087480206162697,
            0.9677734375,
            0.2518225042950562,
            -0.9715073529411765,
            0.2370094158071117
        },
    
        {
            true,
            45.916666666666664,
            13.987841942995447,
            0.9565972222222222,
            0.2914133738124051,
            -0.9631410256410255,
            0.2689969604422201
        },
    
        {
            true,
            45.369791666666664,
            15.671056254230733,
            0.9452039930555555,
            0.3264803386298069,
            -0.9552869496855345,
            0.2956803066835987
        },
    
        {
            true,
            44.8125,
            17.19999545784824,
            0.93359375,
            0.35833323870517164,
            -0.9479166666666666,
            0.31851843440459704
        },
    
        {
            true,
            44.244791666666664,
            18.611781493808273,
            0.9217664930555555,
            0.38774544778767234,
            -0.9410037878787878,
            0.3383960271601504
        },
    
        {
            true,
            43.666666666666664,
            19.93043457183567,
            0.9097222222222222,
            0.4152173869132431,
            -0.9345238095238094,
            0.3559006173542083
        },
    
        {
            true,
            43.078125,
            21.172509215593106,
            0.8974609375,
            0.441093941991523,
            -0.928453947368421,
            0.37144753009812465
        },
    
        {
            true,
            42.479166666666664,
            22.349953004549153,
            0.8849826388888888,
            0.46562402092810734,
            -0.9227729885057471,
            0.38534401731981294
        },
    
        {
            true,
            41.869791666666664,
            23.471696696019457,
            0.8722873263888888,
            0.48899368116707204,
            -0.9174611581920903,
            0.3978253677291433
        },
    
        {
            true,
            41.25,
            24.544602257930357,
            0.859375,
            0.5113458803735491,
            -0.9125,
            0.4090767042988393
        },
    
        {
            true,
            40.619791666666664,
            25.57405961040596,
            0.8462456597222222,
            0.5327929085501242,
            -0.9078722677595628,
            0.41924687885911405
        },
    
        {
            true,
            39.979166666666664,
            26.56437901850689,
            0.8328993055555555,
            0.5534245628855602,
            -0.9035618279569891,
            0.4284577261049498
        },
    
        {
            true,
            39.328125,
            27.51905855919448,
            0.8193359375,
            0.5733137199832183,
            -0.8995535714285714,
            0.4368104533205473
        },
    
        {
            true,
            38.666666666666664,
            28.440972010268727,
            0.8055555555555555,
            0.5925202502139318,
            -0.8958333333333334,
            0.44439018766044885
        },
    
        {
            true,
            37.994791666666664,
            29.332504260744553,
            0.7915581597222222,
            0.6110938387655115,
            -0.8923878205128205,
            0.451269296319147
        },
    
        {
            true,
            37.3125,
            30.195651073457583,
            0.77734375,
            0.6290760640303663,
            -0.8892045454545454,
            0.45750986474935734
        },
    
        {
            true,
            36.619791666666664,
            31.032094004271297,
            0.7629123263888888,
            0.6465019584223187,
            -0.8862717661691543,
            0.46316558215330295
        },
    
        {
            true,
            35.916666666666664,
            31.843257615318752,
            0.7482638888888888,
            0.6634012003191406,
            -0.8835784313725491,
            0.46828320022527575
        },
    
        {
            true,
            35.203125,
            32.63035381718033,
            0.7333984375,
            0.6797990378579235,
            -0.8811141304347826,
            0.4729036785098598
        },
    
        {
            true,
            34.479166666666664,
            33.39441668860563,
            0.7183159722222222,
            0.6957170143459507,
            -0.8788690476190476,
            0.477063095551509
        },
    
        {
            true,
            33.744791666666664,
            34.136330139211864,
            0.7030164930555555,
            0.7111735445669138,
            -0.8768339201877935,
            0.48079338224242063
        },
    
        {
            true,
            33.0,
            34.85685011586675,
            0.6875,
            0.7261843774138906,
            -0.875,
            0.48412291827592707
        },
    
        {
            true,
            32.244791666666664,
            35.55662259514062,
            0.6717664930555555,
            0.7407629707320962,
            -0.8733590182648402,
            0.4870770218512413
        },
    
        {
            true,
            31.479166666666668,
            36.23619828254921,
            0.6558159722222222,
            0.7549207975531086,
            -0.8719031531531531,
            0.4896783551695839
        },
    
        {
            true,
            30.703125,
            36.896044709892344,
            0.6396484375,
            0.7686675981227572,
            -0.870625,
            0.4919472627985646
        },
    
        {
            true,
            29.916666666666668,
            37.536556255942756,
            0.623263888888889,
            0.782011588665474,
            -0.8695175438596492,
            0.49390205599924686
        },
    
        {
            true,
            29.119791666666668,
            38.15806249392035,
            0.606662326388889,
            0.7949596352900072,
            -0.8685741341991341,
            0.4955592531677967
        },
    
        {
            true,
            28.3125,
            38.760835178695515,
            0.58984375,
            0.8075173995561565,
            -0.8677884615384616,
            0.4969337843422502
        },
    
        {
            true,
            27.494791666666668,
            39.345094118664875,
            0.5728081597222222,
            0.8196894608055182,
            -0.8671545358649788,
            0.498039166059049
        },
    
        {
            true,
            26.666666666666668,
            39.911012125588705,
            0.5555555555555556,
            0.831479419283098,
            -0.8666666666666666,
            0.4988876515698588
        },
    
        {
            true,
            25.828125,
            40.45871919604444,
            0.5380859375,
            0.8428899832509259,
            -0.8663194444444444,
            0.4994903604449931
        },
    
        {
            true,
            24.979166666666668,
            40.988306047443444,
            0.5203993055555556,
            0.8539230426550718,
            -0.8661077235772358,
            0.49985739082248104
        },
    
        {
            true,
            24.119791666666668,
            41.499827107550665,
            0.5024956597222222,
            0.8645797314073055,
            -0.8660266064257027,
            0.49999791695844176
        },
    
        {
            true,
            23.25,
            41.993303037508255,
            0.484375,
            0.8748604799480887,
            -0.8660714285714286,
            0.4999202742560507
        },
    
        {
            true,
            22.369791666666668,
            42.4687228532944,
            0.466037326388889,
            0.8847650594436335,
            -0.8662377450980393,
            0.49963203356816954
        },
    
        {
            true,
            21.479166666666668,
            42.9260456984516,
            0.4474826388888889,
            0.8942926187177417,
            -0.8665213178294573,
            0.49914006626106516
        },
    
        {
            true,
            20.578125,
            43.365202311120086,
            0.4287109375,
            0.9034417148150018,
            -0.8669181034482759,
            0.4984506012772424
        },
    
        {
            true,
            19.666666666666668,
            43.786096220401085,
            0.40972222222222227,
            0.9122103379250226,
            -0.8674242424242423,
            0.49756927523183053
        },
    
        {
            true,
            18.744791666666668,
            44.188604700457155,
            0.3905164930555555,
            0.9205959312595239,
            -0.8680360486891385,
            0.496501176409631
        },
    
        {
            true,
            17.8125,
            44.57257950522945,
            0.37109375,
            0.9285954063589469,
            -0.86875,
            0.4952508833914383
        },
    
        {
            true,
            16.869791666666668,
            44.93784740197581,
            0.3514539930555556,
            0.9362051542078293,
            -0.8695627289377289,
            0.4938224989228111
        },
    
        {
            true,
            15.916666666666666,
            45.28421051781981,
            0.3315972222222222,
            0.9434210524545793,
            -0.8704710144927535,
            0.49221967954151963
        },
    
        {
            true,
            14.953125,
            45.61144650999763,
            0.31152343750000006,
            0.950238468958284,
            -0.8714717741935484,
            0.490445661397824
        },
    
        {
            true,
            13.979166666666666,
            45.91930856737235,
            0.2912326388888889,
            0.9566522618202572,
            -0.8725620567375886,
            0.48850328263162074
        },
    
        {
            true,
            12.994791666666666,
            46.20752524794993,
            0.2707248263888889,
            0.962656775998957,
            -0.8737390350877193,
            0.48639500260999935
        },
    
        {
            true,
            12.0,
            46.475800154489,
            0.25,
            0.9682458365518541,
            -0.875,
            0.48412291827592707
        },
    
        {
            true,
            10.994791666666666,
            46.72381144776823,
            0.2290581597222222,
            0.9734127384951714,
            -0.87634235395189,
            0.48168877781204356
        },
    
        {
            true,
            9.979166666666666,
            46.951211194588886,
            0.20789930555555555,
            0.9781502332206018,
            -0.8777636054421768,
            0.47909399178151924
        },
    
        {
            true,
            8.953125,
            47.15762454507622,
            0.1865234375,
            0.9824505113557546,
            -0.8792613636363636,
            0.47633964186945676
        },
    
        {
            true,
            7.916666666666667,
            47.34264873123269,
            0.16493055555555555,
            0.9863051819006811,
            -0.8808333333333332,
            0.47342648731232695
        },
    
        {
            true,
            6.869791666666667,
            47.50585187591732,
            0.14312065972222224,
            0.9897052474149443,
            -0.882477310231023,
            0.47035496906848834
        },
    
        {
            true,
            5.8125,
            47.646771598398985,
            0.12109375,
            0.9926410749666456,
            -0.8841911764705882,
            0.4671252117490097
        },
    
        {
            true,
            4.744791666666667,
            47.764913399271755,
            0.0988498263888889,
            0.9951023624848282,
            -0.8859728964401294,
            0.46373702329390054
        },
    
        {
            true,
            3.6666666666666665,
            47.859748803723946,
            0.07638888888888888,
            0.9970781000775822,
            -0.8878205128205128,
            0.4601898923434995
        },
    
        {
            true,
            2.578125,
            47.930713237801655,
            0.0537109375,
            0.9985565257875345,
            -0.8897321428571429,
            0.45648298321715863
        },
    
        {
            true,
            1.4791666666666667,
            47.977203607257294,
            0.030815972222222224,
            0.9995250751511936,
            -0.8917059748427673,
            0.45261512837035184
        },
    
        {
            true,
            0.3697916666666667,
            47.99857554264776,
            0.007703993055555557,
            0.9999703238051617,
            -0.8937402647975079,
            0.4485848181555866
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            49.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            48.505208333333336,
            6.945845127839391,
            0.9899022108843538,
            0.14175194138447736,
            -0.989474826388889,
            0.14470510682998733
        },
    
        {
            true,
            48.0,
            9.848857801796104,
            0.9795918367346939,
            0.20099709799583887,
            -0.9795918367346939,
            0.20099709799583887
        },
    
        {
            true,
            47.484375,
            12.09273049643359,
            0.9690688775510204,
            0.24679041829456308,
            -0.9703125,
            0.2418546099286718
        },
    
        {
            true,
            46.958333333333336,
            13.996961475818786,
            0.9583333333333334,
            0.2856522750167099,
            -0.9616013071895426,
            0.27445022501605465
        },
    
        {
            true,
            46.421875,
            15.684690672256657,
            0.9473852040816326,
            0.3200957280052379,
            -0.9534254807692307,
            0.3016286667741665
        },
    
        {
            true,
            45.875,
            17.218721642444887,
            0.9362244897959183,
            0.35140248249887523,
            -0.9457547169811321,
            0.32488154042348844
        },
    
        {
            true,
            45.317708333333336,
            18.636129196132178,
            0.9248511904761906,
            0.38032916726800364,
            -0.9385609567901235,
            0.34511350363207743
        },
    
        {
            true,
            44.75,
            19.96089927833914,
            0.9132653061224489,
            0.40736529139467637,
            -0.9318181818181818,
            0.362925441424348
        },
    
        {
            true,
            44.171875,
            21.20956055613541,
            0.9014668367346939,
            0.4328481746150084,
            -0.9255022321428571,
            0.37874215278813234
        },
    
        {
            true,
            43.583333333333336,
            22.394040625924465,
            0.8894557823129252,
            0.4570212372637646,
            -0.9195906432748538,
            0.3928779057179731
        },
    
        {
            true,
            42.984375,
            23.523254576256555,
            0.8772321428571429,
            0.48006641992360316,
            -0.9140625,
            0.40557335476304407
        },
    
        {
            true,
            42.375,
            24.60405200368427,
            0.8647959183673469,
            0.5021235102792708,
            -0.9088983050847458,
            0.41701783057091985
        },
    
        {
            true,
            41.755208333333336,
            25.641813060700883,
            0.8521471088435375,
            0.5233023073612425,
            -0.904079861111111,
            0.4273635510116814
        },
    
        {
            true,
            41.125,
            26.640840358367075,
            0.8392857142857143,
            0.5436906195585117,
            -0.8995901639344263,
            0.4367350878420832
        },
    
        {
            true,
            40.484375,
            27.604626077151906,
            0.8262117346938775,
            0.563359715860243,
            -0.8954133064516129,
            0.445235904470192
        },
    
        {
            true,
            39.833333333333336,
            28.536039591287988,
            0.8129251700680272,
            0.5823681549242447,
            -0.8915343915343915,
            0.45295300938552363
        },
    
        {
            true,
            39.171875,
            29.437462679116468,
            0.7994260204081632,
            0.6007645444717646,
            -0.887939453125,
            0.4599603543611948
        },
    
        {
            true,
            38.5,
            30.31088913245535,
            0.7857142857142857,
            0.6185895741317419,
            -0.8846153846153846,
            0.46632137126854384
        },
    
        {
            true,
            37.817708333333336,
            31.15799955733568,
            0.7717899659863946,
            0.6358775419864424,
            -0.8815498737373737,
            0.4720909023838739
        },
    
        {
            true,
            37.125,
            31.980218495188552,
            0.7576530612244898,
            0.6526575203099705,
            -0.878731343283582,
            0.4773166939580381
        },
    
        {
            true,
            36.421875,
            32.77875869346451,
            0.7433035714285714,
            0.6689542590502962,
            -0.8761488970588235,
            0.4820405690215369
        },
    
        {
            true,
            35.708333333333336,
            33.55465587002131,
            0.7287414965986395,
            0.6847888953065573,
            -0.873792270531401,
            0.4862993604350914
        },
    
        {
            true,
            34.984375,
            34.30879633358441,
            0.7139668367346939,
            0.7001795170119267,
            -0.8716517857142857,
            0.4901256619083487
        },
    
        {
            true,
            34.25,
            35.041939158671,
            0.6989795918367347,
            0.7151416154830816,
            -0.8697183098591549,
            0.4935484388545211
        },
    
        {
            true,
            33.505208333333336,
            35.75473415563218,
            0.683779761904762,
            0.7296884521557587,
            -0.8679832175925926,
            0.4965935299393358
        },
    
        {
            true,
            32.75,
            36.447736555237555,
            0.6683673469387755,
            0.7438313582701541,
            -0.8664383561643836,
            0.49928406240051443
        },
    
        {
            true,
            31.984375,
            37.12141909813491,
            0.6527423469387755,
            0.75757998159459,
            -0.8650760135135135,
            0.5016407986234447
        },
    
        {
            true,
            31.208333333333332,
            37.77618205371681,
            0.6369047619047619,
            0.7709424908921798,
            -0.8638888888888889,
            0.5036824273828908
        },
    
        {
            true,
            30.421875,
            38.41236157130117,
            0.6208545918367347,
            0.7839257463530851,
            -0.8628700657894737,
            0.5054258101486996
        },
    
        {
            true,
            29.625,
            39.030236676197596,
            0.6045918367346939,
            0.7965354423713795,
            -0.862012987012987,
            0.5068861905999688
        },
    
        {
            true,
            28.817708333333332,
            39.63003515535825,
            0.5881164965986394,
            0.8087762276603725,
            -0.8613114316239316,
            0.5080773737866442
        },
    
        {
            true,
            28.0,
            40.2119385257662,
            0.5714285714285714,
            0.8206518066482898,
            -0.8607594936708861,
            0.5090118800729899
        },
    
        {
            true,
            27.171875,
            40.77608623917179,
            0.5545280612244898,
            0.8321650252892202,
            -0.8603515625,
            0.5097010779896474
        },
    
        {
            true,
            26.333333333333332,
            41.32257924616463,
            0.5374149659863945,
            0.8433179437992782,
            -0.860082304526749,
            0.5101552993353657
        },
    
        {
            true,
            25.484375,
            41.85148301863836,
            0.5200892857142857,
            0.8541118983395584,
            -0.8599466463414634,
            0.5103839392516873
        },
    
        {
            true,
            24.625,
            42.36283011084127,
            0.5025510204081632,
            0.8645475532824749,
            -0.8599397590361446,
            0.5103955435041118
        },
    
        {
            true,
            23.755208333333332,
            42.85662232420948,
            0.48480017006802717,
            0.8746249453920303,
            -0.8600570436507937,
            0.5101978848120177
        },
    
        {
            true,
            22.875,
            43.33283252915738,
            0.46683673469387754,
            0.8843435210032118,
            -0.8602941176470589,
            0.5097980297547927
        },
    
        {
            true,
            21.984375,
            43.791406187280344,
            0.4486607142857143,
            0.893702167087354,
            -0.8606468023255814,
            0.5092023975265156
        },
    
        {
            true,
            21.083333333333332,
            44.23226260949756,
            0.43027210884353734,
            0.9026992369285215,
            -0.8611111111111112,
            0.5084168116034202
        },
    
        {
            true,
            20.171875,
            44.65529597913751,
            0.4116709183673469,
            0.9113325710028064,
            -0.8616832386363636,
            0.5074465452174718
        },
    
        {
            true,
            19.25,
            45.06037616354306,
            0.39285714285714285,
            0.9195995135416951,
            -0.8623595505617978,
            0.5062963613881243
        },
    
        {
            true,
            18.317708333333332,
            45.44734933321118,
            0.37383078231292516,
            0.9274969251675751,
            -0.8631365740740742,
            0.5049705481467909
        },
    
        {
            true,
            17.375,
            45.81603840359836,
            0.35459183673469385,
            0.9350211919101706,
            -0.864010989010989,
            0.5034729494900919
        },
    
        {
            true,
            16.421875,
            46.166243311367396,
            0.335140306122449,
            0.9421682308442325,
            -0.8649796195652174,
            0.501806992514863
        },
    
        {
            true,
            15.458333333333334,
            46.49774113390408,
            0.3154761904761905,
            0.9489334925286548,
            -0.8660394265232976,
            0.49997571111724814
        },
    
        {
            true,
            14.484375,
            46.81028605829466,
            0.2955994897959184,
            0.9553119603733604,
            -0.8671875,
            0.49798176657760274
        },
    
        {
            true,
            13.5,
            47.10360920354193,
            0.2755102040816326,
            0.9612981470110598,
            -0.868421052631579,
            0.49582746530044136
        },
    
        {
            true,
            12.505208333333334,
            47.37741829753845,
            0.2552083333333333,
            0.9668860877048662,
            -0.8697374131944444,
            0.4935147739326921
        },
    
        {
            true,
            11.5,
            47.63139720814412,
            0.23469387755102045,
            0.9720693307784516,
            -0.8711340206185567,
            0.4910453320427229
        },
    
        {
            true,
            10.484375,
            47.86520532557418,
            0.21396683673469388,
            0.9768409250117179,
            -0.8726084183673469,
            0.48842046250585897
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            50.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            49.515625,
            6.9428294563077815,
            0.9903125,
            0.13885658912615562,
            -0.989029255319149,
            0.14771977566612302
        },
    
        {
            true,
            49.020833333333336,
            9.846720230896945,
            0.9804166666666667,
            0.1969344046179389,
            -0.978732638888889,
            0.20514000481035305
        },
    
        {
            true,
            48.515625,
            12.09273049643359,
            0.9703125,
            0.2418546099286718,
            -0.9690688775510204,
            0.24679041829456308
        },
    
        {
            true,
            48.0,
            14.0,
            0.96,
            0.28,
            -0.96,
            0.28
        },
    
        {
            true,
            47.473958333333336,
            15.691503438642526,
            0.9494791666666668,
            0.3138300687728505,
            -0.9514910130718955,
            0.3076765380125986
        },
    
        {
            true,
            46.9375,
            17.229947584075816,
            0.93875,
            0.34459895168151633,
            -0.9435096153846154,
            0.3313451458476119
        },
    
        {
            true,
            46.390625,
            18.65234334096858,
            0.9278125,
            0.3730468668193716,
            -0.9360259433962265,
            0.35193100643336944
        },
    
        {
            true,
            45.833333333333336,
            19.982631347136323,
            0.9166666666666667,
            0.39965262694272646,
            -0.9290123456790125,
            0.3700487286506727
        },
    
        {
            true,
            45.265625,
            21.237306640894342,
            0.9053125,
            0.42474613281788687,
            -0.9224431818181819,
            0.38613284801626074
        },
    
        {
            true,
            44.6875,
            22.428271082497645,
            0.89375,
            0.4485654216499529,
            -0.9162946428571429,
            0.40050484075888654
        },
    
        {
            true,
            44.098958333333336,
            23.564419660049566,
            0.8819791666666668,
            0.4712883932009913,
            -0.9105445906432749,
            0.41341087122893977
        },
    
        {
            true,
            43.5,
            24.6525860712421,
            0.87,
            0.49305172142484205,
            -0.9051724137931034,
            0.4250445874352086
        },
    
        {
            true,
            42.890625,
            25.698137814039658,
            0.8578125,
            0.5139627562807931,
            -0.9001588983050848,
            0.43556165786507894
        },
    
        {
            true,
            42.270833333333336,
            26.70536742502442,
            0.8454166666666667,
            0.5341073485004884,
            -0.8954861111111111,
            0.4450894570837403
        },
    
        {
            true,
            41.640625,
            27.67775911466416,
            0.8328125,
            0.5535551822932832,
            -0.8911372950819673,
            0.45373375597810095
        },
    
        {
            true,
            41.0,
            28.61817604250837,
            0.82,
            0.5723635208501674,
            -0.8870967741935484,
            0.4615834845565866
        },
    
        {
            true,
            40.348958333333336,
            29.528995265923466,
            0.8069791666666667,
            0.5905799053184694,
            -0.8833498677248677,
            0.46871421057021373
        },
    
        {
            true,
            39.6875,
            30.41220715025465,
            0.79375,
            0.608244143005093,
            -0.8798828125,
            0.4751907367227289
        },
    
        {
            true,
            39.015625,
            31.269490015978434,
            0.7803125,
            0.6253898003195687,
            -0.8766826923076924,
            0.48106907716889896
        },
    
        {
            true,
            38.333333333333336,
            32.10226714043037,
            0.7666666666666667,
            0.6420453428086074,
            -0.8737373737373737,
            0.4863979869762177
        },
    
        {
            true,
            37.640625,
            32.91175093502889,
            0.7528125,
            0.6582350187005779,
            -0.871035447761194,
            0.49122016320938644
        },
    
        {
            true,
            36.9375,
            33.69897763656933,
            0.73875,
            0.6739795527313867,
            -0.8685661764705882,
            0.4955732005377843
        },
    
        {
            true,
            36.223958333333336,
            34.46483487070452,
            0.7244791666666667,
            0.6892966974140904,
            -0.8663194444444444,
            0.49949036044499306
        },
    
        {
            true,
            35.5,
            35.210083782916506,
            0.71,
            0.7042016756583301,
            -0.8642857142857143,
            0.5030011968988072
        },
    
        {
            true,
            34.765625,
            35.93537697533414,
            0.6953125,
            0.7187075395066828,
            -0.862455985915493,
            0.5061320700751287
        },
    
        {
            true,
            34.020833333333336,
            36.64127316709335,
            0.6804166666666667,
            0.732825463341867,
            -0.8608217592592592,
            0.5089065717651855
        },
    
        {
            true,
            33.265625,
            37.328249267269086,
            0.6653125,
            0.7465649853453817,
            -0.859375,
            0.5113458803735491
        },
    
        {
            true,
            32.5,
            37.99671038392666,
            0.65,
            0.7599342076785333,
            -0.8581081081081081,
            0.5134690592422522
        },
    
        {
            true,
            31.723958333333332,
            38.64699817146127,
            0.6344791666666666,
            0.7729399634292254,
            -0.857013888888889,
            0.5152933089528169
        },
    
        {
            true,
            30.9375,
            39.27939782825088,
            0.61875,
            0.7855879565650176,
            -0.8560855263157895,
            0.5168341819506694
        },
    
        {
            true,
            30.140625,
            39.89414398892869,
            0.6028125,
            0.7978828797785738,
            -0.8553165584415584,
            0.5181057660899829
        },
    
        {
            true,
            29.333333333333332,
            40.49142570416058,
            0.5866666666666667,
            0.8098285140832115,
            -0.8547008547008548,
            0.5191208423610331
        },
    
        {
            true,
            28.515625,
            41.071390661376135,
            0.5703125,
            0.8214278132275227,
            -0.8542325949367089,
            0.5198910210300777
        },
    
        {
            true,
            27.6875,
            41.634148769369595,
            0.55375,
            0.8326829753873919,
            -0.85390625,
            0.52042685961712
        },
    
        {
            true,
            26.848958333333332,
            42.17977520583687,
            0.5369791666666667,
            0.8435955041167373,
            -0.8537165637860082,
            0.5207379655041589
        },
    
        {
            true,
            26.0,
            42.708313008125245,
            0.52,
            0.8541662601625049,
            -0.8536585365853658,
            0.520833085464942
        },
    
        {
            true,
            25.140625,
            43.21977527254596,
            0.5028125,
            0.8643955054509191,
            -0.8537274096385542,
            0.5207201840065778
        },
    
        {
            true,
            24.270833333333332,
            43.714147015646496,
            0.48541666666666666,
            0.87428294031293,
            -0.8539186507936508,
            0.5204065120910297
        },
    
        {
            true,
            23.390625,
            44.191386741189454,
            0.4678125,
            0.8838277348237891,
            -0.8542279411764706,
            0.5198986675434053
        },
    
        {
            true,
            22.5,
            44.65142774872938,
            0.45,
            0.8930285549745877,
            -0.8546511627906976,
            0.5192026482410393
        },
    
        {
            true,
            21.598958333333332,
            45.09417921323029,
            0.4319791666666666,
            0.9018835842646057,
            -0.8551843869731801,
            0.518323899002647
        },
    
        {
            true,
            20.6875,
            45.51952705982346,
            0.41375,
            0.9103905411964692,
            -0.8558238636363636,
            0.5172673529525393
        },
    
        {
            true,
            19.765625,
            45.92733465333445,
            0.39531249999999996,
            0.9185466930666888,
            -0.8565660112359551,
            0.5160374680149938
        },
    
        {
            true,
            18.833333333333332,
            46.31744331842546,
            0.3766666666666667,
            0.9263488663685093,
            -0.8574074074074075,
            0.5146382590936163
        },
    
        {
            true,
            17.890625,
            46.68967270295836,
            0.3578125,
            0.9337934540591672,
            -0.8583447802197802,
            0.5130733264061358
        },
    
        {
            true,
            16.9375,
            47.04382099436652,
            0.33875,
            0.9408764198873304,
            -0.859375,
            0.5113458803735491
        },
    
        {
            true,
            15.973958333333334,
            47.37966499633499,
            0.31947916666666665,
            0.9475932999266996,
            -0.8604950716845877,
            0.5094587634014514
        },
    
        {
            true,
            15.0,
            47.69696007084728,
            0.3,
            0.9539392014169457,
            -0.8617021276595744,
            0.5074144688388009
        },
    
        {
            true,
            14.015625,
            47.99543994859694,
            0.2803125,
            0.9599087989719388,
            -0.8629934210526315,
            0.505215157353652
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            51.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            50.526041666666664,
            6.936794180186128,
            0.9907066993464052,
            0.13601557216051233,
            -0.9885643115942028,
            0.1507998734823071
        },
    
        {
            true,
            50.041666666666664,
            9.840304732182974,
            0.9812091503267973,
            0.19294715161143086,
            -0.977836879432624,
            0.20936818579112706
        },
    
        {
            true,
            49.546875,
            12.087480206162697,
            0.9715073529411765,
            0.2370094158071117,
            -0.9677734375,
            0.2518225042950562
        },
    
        {
            true,
            49.041666666666664,
            13.996961475818802,
            0.9616013071895424,
            0.2744502250160549,
            -0.9583333333333333,
            0.2856522750167102
        },
    
        {
            true,
            48.526041666666664,
            15.69150343864254,
            0.9514910130718954,
            0.3076765380125988,
            -0.9494791666666665,
            0.31383006877285075
        },
    
        {
            true,
            48.0,
            17.233687939614086,
            0.9411764705882353,
            0.3379154497963546,
            -0.9411764705882353,
            0.3379154497963546
        },
    
        {
            true,
            47.463541666666664,
            18.660445130183728,
            0.9306576797385621,
            0.36589108098399464,
            -0.9333934294871794,
            0.3588547140419947
        },
    
        {
            true,
            46.916666666666664,
            19.99565925116972,
            0.9199346405228758,
            0.39207175002293565,
            -0.9261006289308176,
            0.3772765896447116
        },
    
        {
            true,
            46.359375,
            21.25578390954742,
            0.9090073529411765,
            0.4167800766577926,
            -0.9192708333333334,
            0.3936256279545819
        },
    
        {
            true,
            45.791666666666664,
            22.45268945781082,
            0.897875816993464,
            0.44024881289825135,
            -0.9128787878787878,
            0.40823071741474215
        },
    
        {
            true,
            45.213541666666664,
            23.595246342358823,
            0.8865400326797385,
            0.4626518890658593,
            -0.9069010416666667,
            0.421343684684979
        },
    
        {
            true,
            44.625,
            24.69026883207228,
            0.875,
            0.48412291827592707,
            -0.9013157894736842,
            0.4331626110889874
        },
    
        {
            true,
            44.026041666666664,
            25.74310888694158,
            0.8632557189542484,
            0.5047668409204231,
            -0.8961027298850573,
            0.4438467049472686
        },
    
        {
            true,
            43.416666666666664,
            26.758046557167727,
            0.8513071895424836,
            0.5246675795523084,
            -0.8912429378531073,
            0.45352621283335126
        },
    
        {
            true,
            42.796875,
            27.738556022878605,
            0.8391544117647058,
            0.5438932553505609,
            -0.88671875,
            0.46230926704797676
        },
    
        {
            true,
            42.166666666666664,
            28.68749243524471,
            0.826797385620915,
            0.5624998516714649,
            -0.8825136612021858,
            0.4702867612335198
        },
    
        {
            true,
            41.526041666666664,
            29.60722654181347,
            0.814236111111111,
            0.5805338537610485,
            -0.8786122311827956,
            0.47753591196473333
        },
    
        {
            true,
            40.875,
            30.499743851383407,
            0.8014705882352942,
            0.5980341931643806,
            -0.875,
            0.48412291827592707
        },
    
        {
            true,
            40.213541666666664,
            31.366719092427633,
            0.788500816993464,
            0.6150337076946595,
            -0.8716634114583334,
            0.49010498581918177
        },
    
        {
            true,
            39.541666666666664,
            32.209573067990554,
            0.7753267973856208,
            0.6315602562351089,
            -0.8685897435897436,
            0.49553189335370085
        },
    
        {
            true,
            38.859375,
            33.0295167177689,
            0.7619485294117647,
            0.647637582701351,
            -0.8657670454545454,
            0.5004472229964985
        },
    
        {
            true,
            38.166666666666664,
            33.82758571869349,
            0.7483660130718954,
            0.6632859944841861,
            -0.8631840796019901,
            0.5048893390849775
        },
    
        {
            true,
            37.463541666666664,
            34.604667976877494,
            0.7345792483660131,
            0.6785229015074018,
            -0.8608302696078431,
            0.5088921761305514
        },
    
        {
            true,
            36.75,
            35.36152570237885,
            0.7205882352941176,
            0.6933632490662519,
            -0.8586956521739131,
            0.512485879744621
        },
    
        {
            true,
            36.026041666666664,
            36.09881330226241,
            0.7063929738562091,
            0.7078198686718119,
            -0.8567708333333334,
            0.515697332889463
        },
    
        {
            true,
            35.291666666666664,
            36.81709200750229,
            0.6919934640522876,
            0.721903764852986,
            -0.8550469483568075,
            0.5185505916549619
        },
    
        {
            true,
            34.546875,
            37.51684192112091,
            0.6773897058823529,
            0.7356243513945276,
            -0.853515625,
            0.521067248904457
        },
    
        {
            true,
            33.791666666666664,
            38.19847200987088,
            0.6625816993464052,
            0.7489896472523703,
            -0.8521689497716896,
            0.523266739861245
        },
    
        {
            true,
            33.026041666666664,
            38.86232844068401,
            0.6475694444444444,
            0.762006440013412,
            -0.8509994369369369,
            0.5251666005497839
        },
    
        {
            true,
            32.25,
            39.50870157319777,
            0.6323529411764706,
            0.7746804230038778,
            -0.85,
            0.5267826876426369
        },
    
        {
            true,
            31.463541666666668,
            40.13783185213086,
            0.6169321895424836,
            0.7870163108260952,
            -0.8491639254385964,
            0.528129366475406
        },
    
        {
            true,
            30.666666666666668,
            40.74991479200362,
            0.6013071895424836,
            0.7990179370981102,
            -0.8484848484848484,
            0.5292196726234236
        },
    
        {
            true,
            29.859375,
            41.345105207380655,
            0.5854779411764706,
            0.8106883373996207,
            -0.8479567307692307,
            0.530065451376675
        },
    
        {
            true,
            29.041666666666668,
            41.92352081138012,
            0.5694444444444444,
            0.8220298198309828,
            -0.8475738396624471,
            0.5306774786250649
        },
    
        {
            true,
            28.213541666666668,
            42.485245281429926,
            0.5532066993464052,
            0.833044025126077,
            -0.8473307291666666,
            0.531065566017874
        },
    
        {
            true,
            27.375,
            43.03033087253687,
            0.5367647058823529,
            0.8437319778928799,
            -0.8472222222222222,
            0.5312386527473688
        },
    
        {
            true,
            26.526041666666668,
            43.55880064347805,
            0.5201184640522876,
            0.8540941302642755,
            -0.847243394308943,
            0.5312048858960738
        },
    
        {
            true,
            25.666666666666668,
            44.07065034943576,
            0.5032679738562091,
            0.8641303990085443,
            -0.8473895582329317,
            0.5309716909570573
        },
    
        {
            true,
            24.796875,
            44.56585004501064,
            0.48621323529411764,
            0.873840196960993,
            -0.84765625,
            0.5305458338691743
        },
    
        {
            true,
            23.916666666666668,
            45.04434543375623,
            0.46895424836601307,
            0.8832224594854162,
            -0.8480392156862745,
            0.5299334756912497
        },
    
        {
            true,
            23.026041666666668,
            45.50605899399475,
            0.4514910130718955,
            0.8922756665489168,
            -0.8485343992248063,
            0.5291402208604041
        },
    
        {
            true,
            22.125,
            45.9508909054003,
            0.4338235294117647,
            0.900997860890202,
            -0.8491379310344828,
            0.5281711598321873
        },
    
        {
            true,
            21.213541666666668,
            46.378719796438936,
            0.415951797385621,
            0.9093866626752733,
            -0.8498461174242423,
            0.5270309067777151
        },
    
        {
            true,
            20.291666666666668,
            46.78940332905399,
            0.3978758169934641,
            0.9174392809618429,
            -0.8506554307116104,
            0.525723632910719
        },
    
        {
            true,
            19.359375,
            47.18277863383393,
            0.37959558823529405,
            0.9251525222320377,
            -0.8515625,
            0.5242530959314881
        },
    
        {
            true,
            18.416666666666668,
            47.55866260618447,
            0.3611111111111111,
            0.9325227961996954,
            -0.8525641025641025,
            0.5226226660020271
        },
    
        {
            true,
            17.463541666666668,
            47.91685207165217,
            0.34242238562091504,
            0.9395461190520034,
            -0.8536571557971014,
            0.5208353486049149
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            52.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            51.536458333333336,
            6.927731407654108,
            0.9910857371794872,
            0.13322560399334823,
            -0.9880787037037037,
            0.15394958683675797
        },
    
        {
            true,
            51.0625,
            9.829602929416835,
            0.9819711538461539,
            0.18903082556570835,
            -0.9769021739130435,
            0.2136870202047138
        },
    
        {
            true,
            50.578125,
            12.076972778158234,
            0.97265625,
            0.23224947650304298,
            -0.9664228723404256,
            0.25695686762038794
        },
    
        {
            true,
            50.083333333333336,
            13.98784194299543,
            0.9631410256410257,
            0.2689969604422198,
            -0.9565972222222223,
            0.29141337381240484
        },
    
        {
            true,
            49.578125,
            15.684690672256657,
            0.9534254807692307,
            0.3016286667741665,
            -0.9473852040816326,
            0.3200957280052379
        },
    
        {
            true,
            49.0625,
            17.229947584075816,
            0.9435096153846154,
            0.3313451458476119,
            -0.93875,
            0.34459895168151633
        },
    
        {
            true,
            48.536458333333336,
            18.660445130183717,
            0.9333934294871795,
            0.35885471404199454,
            -0.9306576797385622,
            0.36589108098399453
        },
    
        {
            true,
            48.0,
            20.0,
            0.9230769230769231,
            0.38461538461538464,
            -0.9230769230769231,
            0.38461538461538464
        },
    
        {
            true,
            47.453125,
            21.26501652325657,
            0.9125600961538461,
            0.40894262544724175,
            -0.9159787735849056,
            0.40122672685389754
        },
    
        {
            true,
            46.895833333333336,
            22.46732774435407,
            0.9018429487179488,
            0.4320639950837321,
            -0.9093364197530865,
            0.4160616248954458
        },
    
        {
            true,
            46.328125,
            23.615775108693235,
            0.8909254807692307,
            0.45414952132102376,
            -0.903125,
            0.4293777292489679
        },
    
        {
            true,
            45.75,
            24.717149916606484,
            0.8798076923076923,
            0.4753298060885862,
            -0.8973214285714286,
            0.44137767708225867
        },
    
        {
            true,
            45.161458333333336,
            25.776785703547233,
            0.8684895833333334,
            0.49570741737590834,
            -0.8919042397660819,
            0.452224310588548
        },
    
        {
            true,
            44.5625,
            26.798947623927326,
            0.8569711538461539,
            0.5153643773832178,
            -0.8868534482758621,
            0.46205082110219525
        },
    
        {
            true,
            43.953125,
            27.78709777458551,
            0.8452524038461539,
            0.5343672648958753,
            -0.8821504237288136,
            0.47096775889127984
        },
    
        {
            true,
            43.333333333333336,
            28.74408151641346,
            0.8333333333333334,
            0.5527707983925665,
            -0.8777777777777779,
            0.4790680252735577
        },
    
        {
            true,
            42.703125,
            29.67226171417297,
            0.8212139423076923,
            0.5706204175802494,
            -0.873719262295082,
            0.4864305199044749
        },
    
        {
            true,
            42.0625,
            30.57361760979554,
            0.8088942307692307,
            0.5879541848037604,
            -0.8699596774193549,
            0.49312286467412164
        },
    
        {
            true,
            41.411458333333336,
            31.449819056818068,
            0.7963741987179488,
            0.6048042126311167,
            -0.8664847883597884,
            0.49920347709235036
        },
    
        {
            true,
            40.75,
            32.30228320103704,
            0.7836538461538461,
            0.621197753866097,
            -0.86328125,
            0.5047231750162038
        },
    
        {
            true,
            40.078125,
            33.132218405720664,
            0.7707331730769231,
            0.637158046263859,
            -0.8603365384615385,
            0.5097264370110871
        },
    
        {
            true,
            39.395833333333336,
            33.94065874393457,
            0.7576121794871795,
            0.6527049758448956,
            -0.8576388888888888,
            0.5142524052111298
        },
    
        {
            true,
            38.703125,
            34.728491404528,
            0.7442908653846154,
            0.6678556039332307,
            -0.8551772388059702,
            0.5183356926048955
        },
    
        {
            true,
            38.0,
            35.4964786985977,
            0.7307692307692307,
            0.682624590357648,
            -0.8529411764705882,
            0.5220070396852603
        },
    
        {
            true,
            37.286458333333336,
            36.245275898475334,
            0.7170472756410257,
            0.6970245365091411,
            -0.8509208937198067,
            0.5252938536010918
        },
    
        {
            true,
            36.5625,
            36.97544582219395,
            0.703125,
            0.7110662658114221,
            -0.8491071428571428,
            0.5282206546027707
        },
    
        {
            true,
            35.828125,
            37.687470848869324,
            0.6890024038461539,
            0.7247590547859486,
            -0.8474911971830986,
            0.5308094485756243
        },
    
        {
            true,
            35.083333333333336,
            38.381762885805834,
            0.6746794871794872,
            0.7381108247270353,
            -0.8460648148148148,
            0.5330800400806366
        },
    
        {
            true,
            34.328125,
            39.05867168740349,
            0.66015625,
            0.7511283016808363,
            -0.844820205479452,
            0.535050297087719
        },
    
        {
            true,
            33.5625,
            39.718491836297105,
            0.6454326923076923,
            0.7638171506980213,
            -0.84375,
            0.5367363761661771
        },
    
        {
            true,
            32.786458333333336,
            40.36146862982809,
            0.6305088141025641,
            0.7761820890351555,
            -0.8428472222222222,
            0.5381529150643746
        },
    
        {
            true,
            32.0,
            40.98780306383839,
            0.6153846153846154,
            0.7882269819968921,
            -0.8421052631578947,
            0.5393131982083998
        },
    
        {
            true,
            31.203125,
            41.59765606659076,
            0.6000600961538461,
            0.7999549243575146,
            -0.8415178571428571,
            0.5402292995661138
        },
    
        {
            true,
            30.395833333333332,
            42.19115210529599,
            0.5845352564102564,
            0.8113683097172306,
            -0.8410790598290598,
            0.5409122064781537
        },
    
        {
            true,
            29.578125,
            42.768382264055475,
            0.5688100961538461,
            0.8224688896933745,
            -0.8407832278481012,
            0.5413719273931072
        },
    
        {
            true,
            28.75,
            43.32940687339258,
            0.5528846153846154,
            0.8332578244883189,
            -0.840625,
            0.5416175859174073
        },
    
        {
            true,
            27.911458333333332,
            43.874257756759796,
            0.5367588141025641,
            0.8437357260915346,
            -0.840599279835391,
            0.541657503169874
        },
    
        {
            true,
            27.0625,
            44.40294014758482,
            0.5204326923076923,
            0.8539026951458619,
            -0.8407012195121951,
            0.5414992700924979
        },
    
        {
            true,
            26.203125,
            44.91543432089213,
            0.50390625,
            0.8637583523248487,
            -0.8409262048192772,
            0.541149811095086
        },
    
        {
            true,
            25.333333333333332,
            45.411696975803736,
            0.48717948717948717,
            0.8733018649193026,
            -0.8412698412698413,
            0.5406154401881397
        },
    
        {
            true,
            24.453125,
            45.89166239889742,
            0.47025240384615385,
            0.8825319692095657,
            -0.8417279411764705,
            0.5399019105752637
        },
    
        {
            true,
            23.5625,
            46.355243433186715,
            0.453125,
            0.8914469890997445,
            -0.842296511627907,
            0.539014458525427
        },
    
        {
            true,
            22.661458333333332,
            46.80233227315277,
            0.43579727564102555,
            0.9000448514067839,
            -0.8429717432950192,
            0.5379578422201468
        },
    
        {
            true,
            21.75,
            47.23280110262359,
            0.4182692307692308,
            0.9083230981273768,
            -0.84375,
            0.5367363761661772
        },
    
        {
            true,
            20.828125,
            47.64650258921818,
            0.4005408653846154,
            0.9162788959465036,
            -0.844627808988764,
            0.5353539616766088
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            53.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            52.546875,
            6.915629236329475,
            0.9914504716981132,
            0.13048357049678255,
            -0.9875710227272727,
            0.1571733917347608
        },
    
        {
            true,
            52.083333333333336,
            9.814600801300514,
            0.9827044025157233,
            0.18518114719434933,
            -0.975925925925926,
            0.21810224002890036
        },
    
        {
            true,
            51.609375,
            12.061194472745019,
            0.9737617924528302,
            0.22756970703292487,
            -0.9650135869565217,
            0.262199879842283
        },
    
        {
            true,
            51.125,
            13.972629494837397,
            0.964622641509434,
            0.2636345187705169,
            -0.9547872340425532,
            0.2972899892518595
        },
    
        {
            true,
            50.630208333333336,
            15.671056254230718,
            0.9552869496855346,
            0.29568030668359846,
            -0.9452039930555557,
            0.3264803386298067
        },
    
        {
            true,
            50.125,
            17.218721642444887,
            0.9457547169811321,
            0.32488154042348844,
            -0.9362244897959183,
            0.35140248249887523
        },
    
        {
            true,
            49.609375,
            18.65234334096858,
            0.9360259433962265,
            0.35193100643336944,
            -0.9278125,
            0.3730468668193716
        },
    
        {
            true,
            49.083333333333336,
            19.995659251169705,
            0.9261006289308177,
            0.37727658964471145,
            -0.9199346405228759,
            0.39207175002293543
        },
    
        {
            true,
            48.546875,
            21.26501652325657,
            0.9159787735849056,
            0.40122672685389754,
            -0.9125600961538461,
            0.40894262544724175
        },
    
        {
            true,
            48.0,
            22.47220505424423,
            0.9056603773584906,
            0.42400386894800435,
            -0.9056603773584906,
            0.42400386894800435
        },
    
        {
            true,
            47.442708333333336,
            23.626032802784806,
            0.8951454402515724,
            0.4457742038261284,
            -0.8992091049382717,
            0.4375191259774965
        },
    
        {
            true,
            46.875,
            24.733264543929497,
            0.8844339622641509,
            0.4666653687533867,
            -0.8931818181818182,
            0.4496957189805363
        },
    
        {
            true,
            46.296875,
            25.79921249252339,
            0.8735259433962265,
            0.48677759419855454,
            -0.8875558035714286,
            0.46070022308077485
        },
    
        {
            true,
            45.708333333333336,
            26.82812449443473,
            0.8624213836477987,
            0.5061910281968817,
            -0.8823099415204679,
            0.4706688507795567
        },
    
        {
            true,
            45.109375,
            27.82344851217,
            0.8511202830188679,
            0.524970726644717,
            -0.8774245689655172,
            0.4797146295201724
        },
    
        {
            true,
            44.5,
            28.788018340969565,
            0.839622641509434,
            0.5431701573767842,
            -0.8728813559322034,
            0.4879325142537214
        },
    
        {
            true,
            43.880208333333336,
            29.72418740055418,
            0.8279284591194969,
            0.5608337245387581,
            -0.8686631944444445,
            0.4954031233425697
        },
    
        {
            true,
            43.25,
            30.633927270266867,
            0.8160377358490566,
            0.5779986277408843,
            -0.8647540983606558,
            0.5021955290207682
        },
    
        {
            true,
            42.609375,
            31.51890166407096,
            0.8039504716981132,
            0.5946962578126597,
            -0.8611391129032258,
            0.5083693816785638
        },
    
        {
            true,
            41.958333333333336,
            32.38052290944185,
            0.7916666666666667,
            0.6109532624422991,
            -0.8578042328042329,
            0.5139765541181247
        },
    
        {
            true,
            41.296875,
            33.21999571394276,
            0.7791863207547169,
            0.6267923719611841,
            -0.854736328125,
            0.5190624330303556
        },
    
        {
            true,
            40.625,
            34.038351531764874,
            0.7665094339622641,
            0.6422330477691486,
            -0.8519230769230769,
            0.5236669466425365
        },
    
        {
            true,
            39.942708333333336,
            34.83647586938529,
            0.7536360062893083,
            0.6572919975355715,
            -0.849352904040404,
            0.5278253919603831
        },
    
        {
            true,
            39.25,
            35.6151302117513,
            0.7405660377358491,
            0.6719835889009679,
            -0.8470149253731343,
            0.5315691076380791
        },
    
        {
            true,
            38.546875,
            36.374969797023546,
            0.7272995283018868,
            0.6863201848495009,
            -0.8448988970588235,
            0.5349260264268169
        },
    
        {
            true,
            37.833333333333336,
            37.116558149818914,
            0.7138364779874214,
            0.7003124179211115,
            -0.8429951690821256,
            0.5379211326060712
        },
    
        {
            true,
            37.109375,
            37.84037905610057,
            0.7001768867924528,
            0.713969416152841,
            -0.8412946428571428,
            0.5405768436585796
        },
    
        {
            true,
            36.375,
            38.54684649877341,
            0.6863207547169812,
            0.7272989905428946,
            -0.8397887323943662,
            0.5429133309686396
        },
    
        {
            true,
            35.630208333333336,
            39.23631295271338,
            0.6722680817610064,
            0.7403077915606298,
            -0.8384693287037037,
            0.544948791009908
        },
    
        {
            true,
            34.875,
            39.909076348620246,
            0.6580188679245284,
            0.7530014405400046,
            -0.8373287671232876,
            0.5466996760084966
        },
    
        {
            true,
            34.109375,
            40.56538594798988,
            0.6435731132075472,
            0.765384640528111,
            -0.8363597972972973,
            0.5481808911890524
        },
    
        {
            true,
            33.333333333333336,
            41.20544732057751,
            0.628930817610063,
            0.7774612701995757,
            -0.8355555555555555,
            0.5494059642743668
        },
    
        {
            true,
            32.546875,
            41.82942657668612,
            0.6140919811320755,
            0.7892344637110588,
            -0.8349095394736842,
            0.5503871917985016
        },
    
        {
            true,
            31.75,
            42.43745397641098,
            0.5990566037735849,
            0.8007066788002072,
            -0.8344155844155844,
            0.5511357659274153
        },
    
        {
            true,
            30.942708333333332,
            43.02962701439863,
            0.5838246855345912,
            0.8118797549886534,
            -0.8340678418803419,
            0.5516618847999825
        },
    
        {
            true,
            30.125,
            43.60601306012738,
            0.5683962264150944,
            0.8227549633986299,
            -0.8338607594936709,
            0.5519748488623719
        },
    
        {
            true,
            29.296875,
            44.16665161900294,
            0.5527712264150944,
            0.8333330494151499,
            -0.8337890625,
            0.5520831452375368
        },
    
        {
            true,
            28.458333333333332,
            44.71155626780272,
            0.5369496855345912,
            0.8436142692038249,
            -0.8338477366255145,
            0.551994521824725
        },
    
        {
            true,
            27.609375,
            45.24071630853533,
            0.5209316037735849,
            0.853598420915761,
            -0.8340320121951219,
            0.5517160525431138
        },
    
        {
            true,
            26.75,
            45.75409817710322,
            0.5047169811320755,
            0.8632848712660984,
            -0.8343373493975904,
            0.551254194904858
        },
    
        {
            true,
            25.880208333333332,
            46.25164663688487,
            0.48830581761006286,
            0.8726725780544315,
            -0.8347594246031746,
            0.5506148409152961
        },
    
        {
            true,
            25.0,
            46.73328578219169,
            0.4716981132075471,
            0.8817601090979563,
            -0.8352941176470589,
            0.5498033621434317
        },
    
        {
            true,
            24.109375,
            47.19891987227435,
            0.45489386792452835,
            0.8905456579674408,
            -0.8359375,
            0.5488246496776088
        },
    
        {
            true,
            23.208333333333332,
            47.648434012975585,
            0.4378930817610063,
            0.899027056848596,
            -0.8366858237547893,
            0.547683149574432
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
    },

    {
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            false,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN,
            NAN
        },
    
        {
            true,
            54.0,
            0.0,
            1.0,
            0.0,
            -1.0,
            0.0
        },
    
        {
            true,
            53.557291666666664,
            6.900471674573965,
            0.9918016975308641,
            0.12778651249211045,
            -0.9870397286821704,
            0.16047608545520847
        },
    
        {
            true,
            53.104166666666664,
            9.795278589141258,
            0.9834104938271605,
            0.18139404794706035,
            -0.9749053030303029,
            0.22261996793502856
        },
    
        {
            true,
            52.640625,
            12.04012456785124,
            0.9748263888888888,
            0.22296526977502296,
            -0.9635416666666666,
            0.2675583237300276
        },
    
        {
            true,
            52.166666666666664,
            13.951304200284973,
            0.9660493827160493,
    