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

#ifndef SRC_REALIGNMENT_H__
#define SRC_REALIGNMENT_H__

#include <string>
#include <vector>

#include <stdint.h>

enum SingleReadType {
  SR_PREFLANK = 0,
  SR_POSTFLANK = 1,
  SR_ENCLOSING = 2,
  SR_IRR = 3,
  SR_UNKNOWN = 4
};

bool expansion_aware_realign(const std::string& seq,
			     const std::string& pre_flank,
			     const std::string& post_flank,
			     const std::string& motif,
			     int32_t* nCopy, int32_t* pos, int32_t* score);		      

bool smith_waterman(const std::string& seq1,
		    const std::string& seq2,
		    int32_t* pos, int32_t* score);

bool create_score_matrix(const int32_t& rows, const int32_t& cols,
			 const std::string& seq1,
			 const std::string& seq2,
			 std::vector<std::vector<int32_t> >* score_matrix,
			 int32_t* start_pos, int32_t* current_score);

bool calc_score(const int32_t& i, const int32_t& j,
		  const std::string& seq1, const std::string& seq2,
		  std::vector<std::vector<int32_t> >* score_matrix);

bool classify_realigned_read(const std::string& seq,
			     const std::string& motif,
			     const int32_t& nCopy,
			     const int32_t& score,
			     const int32_t& read_length,
			     SingleReadType* single_read_class);

#endif  // SRC_REALIGNMENT_H__