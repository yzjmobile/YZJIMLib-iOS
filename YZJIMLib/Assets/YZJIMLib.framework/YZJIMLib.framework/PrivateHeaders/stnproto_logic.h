// Tencent is pleased to support the open source community by making Mars available.
// Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.

// Licensed under the MIT License (the "License"); you may not use this file except in 
// compliance with the License. You may obtain a copy of the License at
// http://opensource.org/licenses/MIT

// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
// either express or implied. See the License for the specific language governing permissions and
// limitations under the License.

/*
*  stnproto_logic.h
*
*  Created on: 2017-7-7
*      Author: chenzihao
*/

#include <stdint.h>

#ifndef STNPROTOCOL_INTERFACE_STNPROTO_LOGIC_H_
#define STNPROTOCOL_INTERFACE_STNPROTO_LOGIC_H_

namespace mars {
namespace stn {

void SetClientVersion(uint32_t _client_version);

////#if (USES_MERC_FUNC==1)
//typedef enum MERC_PARAMETER_TYPE {
//	MERC_PARAMETER_PUBLIC_KEY = 1	/// 
//	, MERC_PARAMETER_OPEN_TOKEN
//	, MERC_PARAMETER_USER_AGENT
//	, MERC_PARAMETER_CLIENT_ID
//}MERC_PARAMETER_TYPE;
//void SetParameter(MERC_PARAMETER_TYPE parameter, const std::string& value);
//
//bool OpenSession();
//void CloseSession();
//uint64_t GetSessionId();
////#endif

}}


#endif /* STNPROTOCOL_INTERFACE_STNPROTO_LOGIC_H_ */
