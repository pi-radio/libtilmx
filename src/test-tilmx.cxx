#include <iostream>

#include <piradio/lmx2594.hpp>

std::vector<unsigned int> LMX_regs_4GHz = {
  0x700000, 0x6f0000, 0x6e0000, 0x6d0000, 0x6c0000, 0x6b0000, 0x6a0000,
  0x690021, 0x680000, 0x670000, 0x663f80, 0x650011, 0x640000, 0x630000,
  0x620200, 0x610888, 0x600000, 0x5f0000, 0x5e0000, 0x5d0000, 0x5c0000,
  0x5b0000, 0x5a0000, 0x590000, 0x580000, 0x570000, 0x560000, 0x55d300,
  0x540001, 0x530000, 0x521e00, 0x510000, 0x506666, 0x4f0026, 0x4e0003,
  0x4d0000, 0x4c000c, 0x4b0800, 0x4a0000, 0x49003f, 0x480001, 0x470081,
  0x46c350, 0x450000, 0x4403e8, 0x430000, 0x4201f4, 0x410000, 0x401388,
  0x3f0000, 0x3e0322, 0x3d00a8, 0x3c0000, 0x3b0001, 0x3a8001, 0x390020,
  0x380000, 0x370000, 0x360000, 0x350000, 0x340820, 0x330080, 0x320000,
  0x314180, 0x300300, 0x2f0300, 0x2e07fc, 0x2dc0cc, 0x2c0c23, 0x2b0005,
  0x2a0000, 0x290000, 0x280000, 0x270030, 0x260000, 0x250304, 0x240041,
  0x230004, 0x220000, 0x211e21, 0x200393, 0x1f03ec, 0x1e318c, 0x1d318c,
  0x1c0488, 0x1b0002, 0x1a0db0, 0x190624, 0x18071a, 0x17007c, 0x160001,
  0x150401, 0x14e048, 0x1327b7, 0x120064, 0x11012c, 0x100080, 0x0f064f,
  0x0e1e70, 0x0d4000, 0x0c5001, 0x0b0018, 0x0a10d8, 0x090604, 0x082000,
  0x0740b2, 0x06c802, 0x0500c8, 0x040a43, 0x030642, 0x020500, 0x010808,
  0x002484
};

std::vector<unsigned int> LMX_regs_1_47GHz = {
  7340032, 7274496, 7208960, 7143424, 7077888,
	7012352, 6946816, 6881313, 6815744, 6750208, 6700928, 6619153, 6553600,
	6488064, 6423040, 6359176, 6291456, 6225920, 6160384, 6094848, 6029312,
	5963776, 5898240, 5832704, 5767168, 5701632, 5636096, 5624576, 5505025,
	5439488, 5381632, 5308416, 5269094, 5177382, 5111811, 5046272, 4980748,
	4917376, 4849664, 4784191, 4718593, 4653185, 4637520, 4521984, 4457448,
	4390912, 4325876, 4259840, 4199304, 4128768, 4064034, 3997864, 3932160,
	3866625, 3833857, 3735584, 3670016, 3604480, 3538944, 3473408, 3409952,
	3342464, 3276800, 3228032, 3146496, 3080960, 3016700, 2998476, 2886691,
	2818048, 2752512, 2686976, 2621440, 2555905, 2490368, 2425604, 2359368,
	2293764, 2228224, 2170401, 2098067, 2049004, 1978764, 1913228, 1836168,
	1769474, 1707440, 1639972, 1574682, 1507452, 1441793, 1377281, 1368136,
	1255351, 1179748, 1114412, 1048704, 984655, 925296, 868352, 806913,
	720920, 659672, 591364, 532480, 475314, 444418, 327880, 264771, 198210,
	132352, 67592, 9372 
};

int main(int argc, char **argv)
{
  using namespace piradio;
  
  LMX2594 lmx(MHz(122.88));
  LMX2594 lmx2(MHz(122.88));


  std::map<int, uint16_t> regs;

  for (auto v: LMX_regs_4GHz) {
    regs[v >> 16] = (v & 0xFFFF);
  }

  lmx.config.read_regs(regs);

  lmx.dump();
  
  lmx2.tune(GHz(4), GHz(4));

  lmx2.dump();
  
  std::cout << "=====" << std::endl;
  std::cout << "Old vs new" << std::endl;
  std::cout << "=====" << std::endl;
  
  lmx.config.dump_compare(lmx2.config);


  
  for (auto v: LMX_regs_1_47GHz) {
    regs[v >> 16] = (v & 0xFFFF);
  }
  
  lmx.config.read_regs(regs);


}
