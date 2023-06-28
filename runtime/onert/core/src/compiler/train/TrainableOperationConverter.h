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

#ifndef __ONERT_COMPILER_TRAIN_TRAINABLE_OPERATION_CONVERTER_H__
#define __ONERT_COMPILER_TRAIN_TRAINABLE_OPERATION_CONVERTER_H__

#include "UntrainableOperationConverter.h"

#include "compiler/train/TrainingInfo.h"

namespace onert
{
namespace compiler
{
namespace train
{

class TrainableOperationConverter : public UntrainableOperationConverter
{
public:
  TrainableOperationConverter(ir::train::TrainableGraph &trainable_graph,
                              const compiler::train::TrainingInfo *training_info);

  using UntrainableOperationConverter::operator();

private:
  void visit(const ir::operation::ElementwiseActivation &) override;
  void visit(const ir::operation::Loss &node) override;
  void visit(const ir::operation::Permute &node) override;

private:
  const compiler::train::TrainingInfo *_training_info;
};

} // namespace train
} // namespace compiler
} // namespace onert

#endif // __ONERT_COMPILER_TRAIN_TRAINABLE_OPERATION_CONVERTER_H__
