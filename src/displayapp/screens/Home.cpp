#include "displayapp/screens/Home.h"
#include "components/ble/HomeService.h"
#include "displayapp/DisplayApp.h"

using namespace Pinetime::Applications::Screens;

static void event_handler(lv_obj_t* obj, lv_event_t event) {
  Home* screen = static_cast<Home*>(obj->user_data);
  screen->OnObjectEvent(obj, event);
}

Home::Home(Pinetime::Controllers::HomeService& home) : homeService(home) {

  lv_obj_t* label;

  lv_style_init(&btn_style);
  lv_style_set_radius(&btn_style, LV_STATE_DEFAULT, 20);
  lv_style_set_bg_color(&btn_style, LV_STATE_DEFAULT, LV_COLOR_AQUA);
  lv_style_set_bg_opa(&btn_style, LV_STATE_DEFAULT, LV_OPA_50);

  btn1 = lv_btn_create(lv_scr_act(), nullptr);
  btn1->user_data = this;
  lv_obj_set_event_cb(btn1, event_handler);
  lv_obj_set_size(btn1, 76, 76);
  lv_obj_align(btn1, nullptr, LV_ALIGN_IN_TOP_LEFT, 0, 0);
  lv_obj_add_style(btn1, LV_STATE_DEFAULT, &btn_style);
  label = lv_label_create(btn1, nullptr);
  lv_label_set_text_static(label, "1");

  btn2 = lv_btn_create(lv_scr_act(), nullptr);
  btn2->user_data = this;
  lv_obj_set_event_cb(btn2, event_handler);
  lv_obj_set_size(btn2, 76, 76);
  lv_obj_align(btn2, nullptr, LV_ALIGN_IN_TOP_MID, 0, 0);
  lv_obj_add_style(btn2, LV_STATE_DEFAULT, &btn_style);
  label = lv_label_create(btn2, nullptr);
  lv_label_set_text_static(label, "2");
}

Home::~Home() {
  lv_obj_clean(lv_scr_act());
}


void Home::OnObjectEvent(lv_obj_t* obj, lv_event_t event) {
  if (event == LV_EVENT_CLICKED) {
    if (obj == btn1) {
      homeService.event(Controllers::HomeService::EVENT_BUTTON_1);
    } else if (obj == btn2) {
      homeService.event(Controllers::HomeService::EVENT_BUTTON_2);
    }
  }
}

bool Home::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
  switch (event) {
    case TouchEvents::SwipeUp: {
      return true;
    }
    case TouchEvents::SwipeDown: {
      return true;
    }
    case TouchEvents::SwipeLeft: {
      return false;
    }
    case TouchEvents::SwipeRight: {
      return false;
    }
    default: {
      return false;
    }
  }
}

