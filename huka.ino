#include <SwitchControlLibrary.h>

#define CLICK_DELAY 50
long randNumber;

void setup()
{
    SwitchControlLibrary();
}

void loop()
{
    for (int i = 0; i < 20; i++)
    {
        click_button(Button::A);
    }

    SwitchControlLibrary().moveLeftStick(128, 0);
    SwitchControlLibrary().sendReport();
    click_button_DELAY(Button::R, 800);
    delay(500);
    click_button(Button::R);
    randNumber = random(1000);
    delay(7200 + randNumber);

    for (int i = 0; i < 20; i++)
    {
        click_button(Button::A);
    }

    SwitchControlLibrary().moveLeftStick(128, 255);
    SwitchControlLibrary().sendReport();
    click_button_DELAY(Button::R, 800);
    delay(500);
    click_button(Button::R);
    randNumber = random(1000);
    delay(7200 + randNumber);
}

void click_button(uint16_t button)
{
    SwitchControlLibrary().pressButton(button); // Aボタンを押す
    SwitchControlLibrary().sendReport();        // Aボタンを押したことを反映
    delay(CLICK_DELAY);
    SwitchControlLibrary().releaseButton(button); // Aボタンを離す
    SwitchControlLibrary().sendReport();          // Aボタンを離したことを反映
}

void click_button_DELAY(uint16_t button, int DELAY)
{
    SwitchControlLibrary().pressButton(button); // Aボタンを押す
    SwitchControlLibrary().sendReport();        // Aボタンを押したことを反映
    delay(DELAY);
    SwitchControlLibrary().releaseButton(button); // Aボタンを離す
    SwitchControlLibrary().sendReport();          // Aボタンを離したことを反映
}
