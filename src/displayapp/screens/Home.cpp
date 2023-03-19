#include "displayapp/screens/Home.h"
#include "components/ble/HomeService.h"
#include "displayapp/DisplayApp.h"

using namespace Pinetime::Applications::Screens;

//Home::Home(const Pinetime::Controllers::Ble& bleController) : bleController {bleController} {
//Home::Home() {
Home::Home(Pinetime::Controllers::HomeService& home) : homeService(home) {
  lv_obj_t* title = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text_static(title, "My test application");
  lv_label_set_align(title, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(title, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
}

Home::~Home() {
  lv_obj_clean(lv_scr_act());
}

