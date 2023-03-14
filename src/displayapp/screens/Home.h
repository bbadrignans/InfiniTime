#pragma once


#include <FreeRTOS.h>
#include "displayapp/screens/Screen.h"
#include <lvgl/lvgl.h>

namespace Pinetime {
  namespace Controllers {
    class HomeService;
  }
  namespace Applications {
    namespace Screens {
      class Home : public Screen {
      public:
        Home(Pinetime::Controllers::HomeService& home);
        ~Home() override;
        void OnObjectEvent(lv_obj_t* obj, lv_event_t event);
      private:
        bool OnTouchEvent(TouchEvents event) override;
        Pinetime::Controllers::HomeService& homeService;

        lv_style_t btn_style;
        lv_obj_t* btn1;
        lv_obj_t* btn2;
      };
    }
  }
}

