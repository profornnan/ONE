/*
 * Copyright (c) 2021 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SVDFOptions.h"
#include "DataLookup.h"

#include <cassert>

namespace tflite2circle
{

flatbuffers::Offset<circle::SVDFOptions>
build_circle_SVDFOptions(flatbuffers::FlatBufferBuilder &fb, const tflite::Operator *op)
{
  auto *tflite_builtin_options = op->builtin_options_as_SVDFOptions();
  assert(tflite_builtin_options);

  circle::SVDFOptionsBuilder builtin_options_builder{fb};
  builtin_options_builder.add_rank(tflite_builtin_options->rank());
  builtin_options_builder.add_asymmetric_quantize_inputs(
    tflite_builtin_options->asymmetric_quantize_inputs());
  builtin_options_builder.add_fused_activation_function(
    get_circle_activation_function_type(tflite_builtin_options->fused_activation_function()));

  return builtin_options_builder.Finish();
}

} // namespace tflite2circle
