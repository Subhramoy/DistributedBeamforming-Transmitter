/* -*- c++ -*- */
/*
 * Copyright 2018 GENESYS Lab..
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_BEAMFORMING_PAYLOAD_GENERATOR_CPP_IMPL_H
#define INCLUDED_BEAMFORMING_PAYLOAD_GENERATOR_CPP_IMPL_H

#include <beamforming/payload_generator_cpp.h>

namespace gr {
  namespace beamforming {

    class payload_generator_cpp_impl : public payload_generator_cpp
    {
     private:
      // Nothing to declare in this block.


     public:
      payload_generator_cpp_impl(std::string file_path ,  int size);
      ~payload_generator_cpp_impl();

      // Created function to calculate payload
      void generate_pdu();
      void generate_pdu(pmt::pmt_t msg);

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

    const unsigned char payload_64QAM[] = {0, 16, 131, 16, 81, 135, 32, 146,
                                    139, 48, 211, 143, 65, 20, 147, 81,
                                    85, 151, 97, 150, 155, 113, 215, 159,
                                    130, 24, 163, 146, 89,167, 162, 154,
                                    171, 178, 219, 175, 195, 28, 179, 211,
                                    93, 183, 227, 158, 187, 243, 223, 191};

     const unsigned char payload_16QAM[] = {1, 35, 69, 103, 137, 171, 205, 239};

     const unsigned char payload_8QAM[] = {5, 57, 119};




  } // namespace beamforming
} // namespace gr

#endif /* INCLUDED_BEAMFORMING_PAYLOAD_GENERATOR_CPP_IMPL_H */