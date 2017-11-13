#define	stepPin  PD7            //Define Step pin
#define dirPin  PD6             //Define Direction pin
#define Enable PD5              //Define Enable pin

void initStepper(void);

void pulseC(int steps);

void pulseCC(int steps);

void stopPulse(void);

