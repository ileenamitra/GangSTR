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

#ifndef SRC_GENOTYPER_H__
#define SRC_GENOTYPER_H__

#include <string>

//#include "src/bam_reader.h"
#include "src/bam_io.h"
#include "src/likelihood_maximizer.h"
#include "src/locus.h"
#include "src/options.h"
#include "src/read_extractor.h"
#include "src/ref_genome.h"

class Genotyper {
 public:
  Genotyper(RefGenome _refgenome,
	    const Options& _options);
  virtual ~Genotyper();

  bool ProcessLocus(BamCramMultiReader* bamreader, Locus* locus);

  void Debug(BamCramMultiReader* bamreader); // For testing member classes. can remove later
 private:
  RefGenome* refgenome;
  const Options* options;
  LikelihoodMaximizer likelihood_maximizer;
  ReadExtractor read_extractor;
};

#endif  // SRC_GENOTYPER_H__