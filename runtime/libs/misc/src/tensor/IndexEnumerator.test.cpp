/*
 * Copyright (c) 2022 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include "misc/tensor/IndexEnumerator.h"

#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

using nnfw::misc::tensor::Shape;
using nnfw::misc::tensor::Index;
using nnfw::misc::tensor::IndexEnumerator;

TEST(MiscIndexEnumeratorTest, iterate_full_range)
{
  const uint32_t H = 3;
  const uint32_t W = 4;

  const Shape shape{H, W};

  std::vector<uint32_t> count;

  count.resize(H * W, 0);

  for (IndexEnumerator e{shape}; e.valid(); e.advance())
  {
    const auto &ind = e.curr();

    ASSERT_EQ(2, ind.rank());
    count.at(ind.at(0) * W + ind.at(1)) += 1;
  }

  ASSERT_TRUE(std::all_of(count.begin(), count.end(), [](uint32_t n) { return n == 1; }));
}

TEST(MiscIndexEnumeratorTest, neg_zero_rank_shape)
{
  // Test abnormal case of empty shape
  // It is expected not to throw any exception, do nothing
  const Shape shape{};
  IndexEnumerator e{shape};
  ASSERT_NO_THROW(e.valid());
  ASSERT_NO_THROW(e.advance());
  SUCCEED();
}
