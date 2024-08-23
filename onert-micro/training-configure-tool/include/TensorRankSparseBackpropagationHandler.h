/*
 * Copyright (c) 2024 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef ONERT_MICRO_TRAINING_CONFIG_TOOL_TENSOR_RANK_SPARSE_BACKPROPAGATION_HANDLER
#define ONERT_MICRO_TRAINING_CONFIG_TOOL_TENSOR_RANK_SPARSE_BACKPROPAGATION_HANDLER

#include "OMStatus.h"
#include "OMConfig.h"
#include "TrainConfigData.h"
#include "TrainingConfigureFileHandler.h"

#include <vector>
#include <unordered_map>

namespace training_configure_tool
{

/*
 * Method to find the most trainable (which gets the best metric result and less peak memory) train
 * ranks for every operation in selected operators indexes. Note: Train rank - this is an indicator
 * of how much data of the current operation we will train (for example, the entire operation, only
 * the bias, only the upper half, and so on)
 */
onert_micro::OMStatus findBestSparseBackpropagationTensorsRanks(
  onert_micro::OMConfig &config, TrainData &train_data,
  const std::unordered_set<uint16_t> &selected_op_indexes,
  std::unordered_map<uint16_t, OpTrainableRank> &best_train_ranks);

} // namespace training_configure_tool

#endif // ONERT_MICRO_TRAINING_CONFIG_TOOL_TENSOR_RANK_SPARSE_BACKPROPAGATION_HANDLER
