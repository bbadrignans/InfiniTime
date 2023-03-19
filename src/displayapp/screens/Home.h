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
        Pinetime::Controllers::HomeService& homeService;
      };
    }
  }
}

