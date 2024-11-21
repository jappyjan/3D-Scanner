#define STEPPER_ROTATE_PIN_DIR 7
#define STEPPER_ROTATE_PIN_STEP 4
#define STEPPER_ROTATE_PIN_ENABLE 8
// Uncomment line to use enable/disable functionality
// #define STEPPER_ROTATE_PIN_SLEEP 13
#define STEPPER_ROTATE_STEPS_PER_REVOLUTION 800
#define STEPPER_ROTATE_RPM 120
// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
#define STEPPER_ROTATE_USE_MICROSTEPS 2

// rot = GND
// gelb = focus
// weiss = shutter
#define SHUTTER_PIN 11

#define ROTATION_DEGREES_PER_PICTURE 30
#define SHUTTER_DELAY_MS 10000