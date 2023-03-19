/*  Copyright (C) 2020-2021 JF, Adam Pigg, Avamander

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

#include <cstdint>
#include <string>
#define min // workaround: nimble's min/max macros conflict with libstdc++
#define max
#include <host/ble_gap.h>
#include <host/ble_uuid.h>
#undef max
#undef min

namespace Pinetime {
  namespace Controllers {
    class NimbleController;

    class HomeService {
    public:
      explicit HomeService(NimbleController& nimble);

      void Init();

      int OnCommand(struct ble_gatt_access_ctxt* ctxt);

      void event(char event);

      static const char EVENT_BUTTON_1 = 0x01;
      static const char EVENT_BUTTON_2 = 0x02;
      static const char EVENT_BUTTON_3 = 0x03;
      static const char EVENT_BUTTON_4 = 0x04;
      static const char EVENT_BUTTON_5 = 0x05;
      static const char EVENT_BUTTON_6 = 0x06;

    private:
      struct ble_gatt_chr_def characteristicDefinition[3];
      struct ble_gatt_svc_def serviceDefinition[2];

      uint16_t eventHandle {};

      NimbleController& nimble;
    };
  }
}
