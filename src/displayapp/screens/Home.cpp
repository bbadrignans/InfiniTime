/*  Copyright (C) 2023 Benoit Badrignans

    This file is part of InfiniTime.

    InfiniTime is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    InfiniTime is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "displayapp/screens/Home.h"
#include "displayapp/screens/Symbols.h"
#include <cstdint>
#include "displayapp/DisplayApp.h"
#include "components/ble/HomeService.h"




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
  lv_label_set_text_static(label, "p");

  btn2 = lv_btn_create(lv_scr_act(), nullptr);
  btn2->user_data = this;
  lv_obj_set_event_cb(btn2, event_handler);
  lv_obj_set_size(btn2, 76, 76);
  lv_obj_align(btn2, nullptr, LV_ALIGN_IN_TOP_MID, 0, 0);
  lv_obj_add_style(btn2, LV_STATE_DEFAULT, &btn_style);
  label = lv_label_create(btn2, nullptr);
  lv_label_set_text_static(label, "P");

  btn3 = lv_btn_create(lv_scr_act(), nullptr);
  btn3->user_data = this;
  lv_obj_set_event_cb(btn3, event_handler);
  lv_obj_set_size(btn3, 76, 76);
  lv_obj_align(btn3, nullptr, LV_ALIGN_IN_TOP_RIGHT, 0, 0);
  lv_obj_add_style(btn3, LV_STATE_DEFAULT, &btn_style);
  label = lv_label_create(btn3, nullptr);
  lv_label_set_text_static(label, "+");

  btn4 = lv_btn_create(lv_scr_act(), nullptr);
  btn4->user_data = this;
  lv_obj_set_event_cb(btn4, event_handler);
  lv_obj_set_size(btn4, 76, 76);
  lv_obj_align(btn4, nullptr, LV_ALIGN_IN_LEFT_MID, 0, 0);
  lv_obj_add_style(btn4, LV_STATE_DEFAULT, &btn_style);
  label = lv_label_create(btn4, nullptr);
  lv_label_set_text_static(label, "g");

  btn5 = lv_btn_create(lv_scr_act(), nullptr);
  btn5->user_data = this;
  lv_obj_set_event_cb(btn5, event_handler);
  lv_obj_set_size(btn5, 76, 76);
  lv_obj_align(btn5, nullptr, LV_ALIGN_CENTER, 0, 0);
  lv_obj_add_style(btn5, LV_STATE_DEFAULT, &btn_style);
  label = lv_label_create(btn5, nullptr);
  lv_label_set_text_static(label, "G");

  btn6 = lv_btn_create(lv_scr_act(), nullptr);
  btn6->user_data = this;
  lv_obj_set_event_cb(btn6, event_handler);
  lv_obj_set_size(btn6, 76, 76);
  lv_obj_align(btn6, nullptr, LV_ALIGN_IN_RIGHT_MID, 0, 0);
  lv_obj_add_style(btn6, LV_STATE_DEFAULT, &btn_style);
  label = lv_label_create(btn6, nullptr);
  lv_label_set_text_static(label, "-");
}

Home::~Home() {
  lv_style_reset(&btn_style);
  lv_obj_clean(lv_scr_act());
}


void Home::OnObjectEvent(lv_obj_t* obj, lv_event_t event) {
  if (event == LV_EVENT_CLICKED) {
    if (obj == btn1) {
      homeService.event(Controllers::HomeService::EVENT_BUTTON_1);
    } else if (obj == btn2) {
      homeService.event(Controllers::HomeService::EVENT_BUTTON_2);
    } else if (obj == btn3) {
      homeService.event(Controllers::HomeService::EVENT_BUTTON_3);
    } else if (obj == btn4) {
      homeService.event(Controllers::HomeService::EVENT_BUTTON_4);
    } else if (obj == btn5) {
      homeService.event(Controllers::HomeService::EVENT_BUTTON_5);
    } else if (obj == btn6) {
      homeService.event(Controllers::HomeService::EVENT_BUTTON_6);
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
      return true;
    }
    case TouchEvents::SwipeRight: {
      return true;
    }
    default: {
      return false;
    }
  }
}

