/*
Copyright (C) 2017 Melissa Gymrek <mgymrek@ucsd.edu>
and Nima Mousavi (mousavi@ucsd.edu)

This file is part of GangSTR.

GangSTR is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GangSTR is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GangSTR.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SRC_TESTS_GENOTYPER_H__
#define SRC_TESTS_GENOTYPER_H__

#include <cppunit/extensions/HelperMacros.h>

#include "src/genotyper.h"

#include <string>

class GenotyperTest: public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(GenotyperTest);
  CPPUNIT_TEST(test_SetFlanks);
  CPPUNIT_TEST(test_ProcessLocus);
  CPPUNIT_TEST_SUITE_END();

 public:
  void setUp();
  void tearDown();
 private:
  void test_SetFlanks();
  void test_ProcessLocus();
  Locus locus;
  std::string test_dir;
};

#endif //  SRC_TESTS_GENOTYPER_H_
