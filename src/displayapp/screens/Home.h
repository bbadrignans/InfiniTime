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
#pragma once


#include <FreeRTOS.h>
#include "displayapp/screens/Screen.h"
#include "components/motor/MotorController.h"
#include <lvgl/lvgl.h>
#include "displayapp/screens/Screen.h"
#include "displayapp/apps/Apps.h"
#include "displayapp/Controllers.h"
#include "Symbols.h"

namespace Pinetime {
  namespace Controllers {
    class HomeService;
  }
  namespace Applications {
    namespace Screens {
      class Home : public Screen {
      public:
        Home(Pinetime::Controllers::HomeService& home, Controllers::MotorController& motor);

        ~Home() override;

        void Refresh() override;

        void OnObjectEvent(lv_obj_t* obj, lv_event_t event);
      private:
        bool OnTouchEvent(TouchEvents event) override;

        Pinetime::Controllers::HomeService& homeService;

        Controllers::MotorController& motor;

        char waitAck = 0;

        lv_style_t btn_style;
        lv_obj_t* btn1;
        lv_obj_t* btn2;
        lv_obj_t* btn3;
        lv_obj_t* btn4;
        lv_obj_t* btn5;
        lv_obj_t* btn6;
        lv_obj_t* btn7;
        lv_obj_t* btn8;
        lv_obj_t* btn9;

        lv_task_t* taskRefresh;
      };
    }

    template <>
    struct AppTraits<Apps::Home> {
      static constexpr Apps app = Apps::Home;
      static constexpr const char* icon = Screens::Symbols::home;

      static Screens::Screen* Create(AppControllers& controllers) {
        return new Screens::Home(*controllers.homeService,
                                  controllers.motorController);
      };
    };

  }
}

