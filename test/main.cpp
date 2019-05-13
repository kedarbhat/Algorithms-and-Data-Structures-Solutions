#include <gtest/gtest.h>

#include "TestArraysSolutions.hpp"
#include "TestBitArray.hpp"
#include "TestCountingValleys.hpp"
#include "TestDutchNationalFlag.hpp"
#include "TestFindUnsortedSubarray.hpp"
#include "TestInheritedCode.hpp"
#include "TestLinkedListSolutions.hpp"
#include "TestMakeChange.hpp"
#include "TestMatrixProduct.hpp"
#include "TestMaximumContiguousSum.hpp"
#include "TestMoveAllZerosToTheEnd.hpp"
#include "TestReverseArrayTraversal.hpp"
#include "TestReverseContainer.hpp"
#include "TestReverseSentence.hpp"
#include "TestSortThreeEnumArrays.hpp"
#include "TestTemplateSpecialization.hpp"
#include "TestTwoSumInwardIteration.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}