/*
 * Copyright (c) 2023 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "odc/QuantizeManager.h"

#include <gtest/gtest.h>

using namespace onert::odc;

// Test export model path is not set
TEST(odc_QuantizeManager, neg_export_model_path_not_set)
{
  QuantizeManager manager;
  manager.quantizeType(ODC_QTYPE_WO_I8_SYM);
  ASSERT_EQ(manager.quantize("model_path"), false);
}

// Test invalid model path
TEST(odc_QuantizeManager, neg_invalid_model_path)
{
  QuantizeManager manager;
  manager.exportModelPath("export_model_path.circle");
  manager.quantizeType(ODC_QTYPE_WO_I8_SYM);
  ASSERT_EQ(manager.quantize("invalid_model_path.circle"), false);
}
