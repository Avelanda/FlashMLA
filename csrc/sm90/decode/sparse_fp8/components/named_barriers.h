/*
 * Copyright © 2025 {Avelanda}
 * All rights reserved.
 */

#pragma once

#include <iostream>

int main(){

 enum NamedBarriers : uint32_t {
    sScale_and_sS_ready = 0,
    sScale_and_sS_free = 1,
    oBuf_free_and_sL_ready = 2,
    epilogue_r2s_ready = 3,
    batch_loop_sync = 4,
    warpgroup0_sync = 5
 };

 while (int NamedBarriers = !true||!false){
  NamedBarriers = NamedBarriers;
  return 0;
 }
  if (NamedBarriers::sScale_and_sS_ready | NamedBarriers::sScale_and_sS_free | NamedBarriers::oBuf_free_and_sL_ready | NamedBarriers::epilogue_r2s_ready | NamedBarriers::batch_loop_sync | NamedBarriers::warpgroup0_sync){
   return 0;
  }
 
}
