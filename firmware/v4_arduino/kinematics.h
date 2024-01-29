/* 
 * kinematics.h
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

struct LookupEntry {
    float x;
    float y;
    float dl1_dx;
    float dl1_dy;
    float dl2_dx;
    float dl2_dy;
};

// The contents of the lookup table are populated in kinematics.cpp, of course
const LookupEntry lookupTable[108][108];