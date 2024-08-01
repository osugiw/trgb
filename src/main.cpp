#include <TRGBSuppport.h>
#include <stdio.h>

#include "ui/ui.h"
#include "WiFi.h"

TRGBSuppport trgb;

void setup() {  
  delay(100);   // Rumors say it helps avoid sporadical crashes after wakeup from deep-sleep
  trgb.init();
  
  // Print some info to Serial
  TRGBSuppport::print_chip_info();
  TRGBSuppport::scan_iic();

  // Initialize SD Card. It can be accessed by SD_MMC object.
//   trgb.SD_init();

//   // Connect to WiFi
//   WiFi.mode(WIFI_MODE_STA);
//   WiFi.begin(ssid, password);
//   configTime(3600, 3600, ntpServer);   // Configure Timezone and NTP

  // load UI
  ui_init();

  printf("Setup done!\n");
}

void loop() {
  TRGBSuppport::print_chip_info();
	// static uint32_t Millis = 0;
	// static bool wifiInitialized = false;
	// static uint16_t time_counter = 0;
	lv_timer_handler();
}