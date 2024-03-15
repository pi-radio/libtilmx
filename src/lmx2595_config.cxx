#include <piradio/lmx2595_config.hpp>
#include <iostream>
namespace piradio
{
  void LMX2595Config::fill_regs(std::map<int, uint16_t> &reg_vals)
  {
    reg_vals[0] = 0x2410 | (powerdown & 0x3) | ((reset & 0x3) << 1) | ((muxout_ld_sel & 0x3) << 2) | ((fcal_en & 0x3) << 3) | ((fcal_lpfd_adj & 0x7) << 5) | ((fcal_hpfd_adj & 0x7) << 7) | ((out_mute & 0x3) << 9) | ((vco_phase_sync & 0x3) << 14) | ((ramp_en & 0x3) << 15);
    reg_vals[1] = 0x0808 | (cal_clk_div & 0xf);
    reg_vals[4] = 0x0043 | ((acal_cmp_dly & 0x1ff) << 8);
    reg_vals[7] = 0x00b2 | ((out_force & 0x3) << 14);
    reg_vals[8] = 0x2000 | ((vco_capctrl_force & 0x3) << 11) | ((vco_daciset_force & 0x3) << 14);
    reg_vals[9] = 0x0604 | ((osc_2x & 0x3) << 12);
    reg_vals[10] = 0x1058 | ((mult & 0x3f) << 7);
    reg_vals[11] = 0x0008 | ((pll_r & 0x1ff) << 4);
    reg_vals[12] = 0x5000 | (pll_r_pre & 0x1ff);
    reg_vals[14] = 0x1e00 | ((cpg & 0xf) << 4);
    reg_vals[16] = 0x0000 | (vco_daciset & 0x3ff);
    reg_vals[17] = 0x0000 | (vco_daciset_strt & 0x3ff);
    reg_vals[19] = 0x2700 | (vco_capctrl & 0x1ff);
    reg_vals[20] = 0xc048 | ((vco_sel_force & 0x3) << 10) | ((vco_sel & 0xf) << 11);
    reg_vals[27] = 0x0002 | (vco2x_en & 0x3);
    reg_vals[31] = 0x03ec | ((seg1_en & 0x3) << 14);
    reg_vals[34] = 0x0000 | ((pll_n >> 16) & 0x7fff);
    reg_vals[36] = 0x0000 | (pll_n & 0x1ffff);
    reg_vals[37] = 0x0004 | ((pfd_dly_sel & 0x7f) << 8) | ((mash_seed_en & 0x3) << 15);
    reg_vals[38] = 0x0000 | ((pll_den >> 16) & 0x3);
    reg_vals[39] = 0x0000 | (pll_den & 0x1ffff);
    reg_vals[40] = 0x0000 | ((mash_seed >> 16) & 0x3);
    reg_vals[41] = 0x0000 | (mash_seed & 0x1ffff);
    reg_vals[42] = 0x0000 | ((pll_num >> 16) & 0x3);
    reg_vals[43] = 0x0000 | (pll_num & 0x1ffff);
    reg_vals[44] = 0x0000 | (mash_order & 0xf) | ((mash_reset_n & 0x3) << 5) | ((outa_pd & 0x3) << 6) | ((outb_pd & 0x3) << 7) | ((outa_pwr & 0x7f) << 8);
    reg_vals[45] = 0xc0c0 | (outb_pwr & 0x7f) | ((out_iset & 0x7) << 9) | ((outa_mux & 0x7) << 11);
    reg_vals[46] = 0x07fc | (outb_mux & 0x7);
    reg_vals[58] = 0x0001 | ((inpin_fmt & 0xf) << 9) | ((inpin_lvl & 0x7) << 12) | ((inpin_hyst & 0x3) << 14) | ((inpin_ignore & 0x3) << 15);
    reg_vals[59] = 0x0000 | (ld_type & 0x3);
    reg_vals[60] = 0x0000 | (ld_dly & 0x1ffff);
    reg_vals[69] = 0x0000 | ((mash_rst_count >> 16) & 0x3);
    reg_vals[70] = 0x0000 | (mash_rst_count & 0x1ffff);
    reg_vals[71] = 0x0001 | ((sysref_repeat & 0x3) << 2) | ((sysref_en & 0x3) << 3) | ((sysref_pulse & 0x3) << 4) | ((sysref_div_pre & 0xf) << 5);
    reg_vals[72] = 0x0000 | (sysref_div & 0xfff);
    reg_vals[73] = 0x0000 | (jesd_dac1_ctrl & 0x7f) | ((jesd_dac2_ctrl & 0x7f) << 6);
    reg_vals[74] = 0x0000 | (jesd_dac3_ctrl & 0x7f) | ((jesd_dac4_ctrl & 0x7f) << 6) | ((sysref_pulse_cnt & 0x1f) << 12);
    reg_vals[75] = 0x0800 | ((chdiv & 0x3f) << 6);
    reg_vals[78] = 0x0001 | ((vco_capctrl_strt & 0x1ff) << 1) | ((quick_recal_en & 0x3) << 9) | ((ramp_thresh >> 32) & 0x1ffff);
    reg_vals[106] = 0x0000 | ((ramp_trig_cal & 0x3) << 4) | (ramp_scale_cnt & 0xf);
    reg_vals[79] = 0x0000 | ((ramp_thresh >> 16) & 0x3);
    reg_vals[80] = 0x0000 | (ramp_thresh & 0x1ffff);
    reg_vals[81] = 0x0000 | ((ramp_limit_high >> 32) & 0x1ffff);
    reg_vals[82] = 0x0000 | ((ramp_limit_high >> 16) & 0x3);
    reg_vals[83] = 0x0000 | (ramp_limit_high & 0x1ffff);
    reg_vals[84] = 0x0000 | ((ramp_limit_low >> 32) & 0x1ffff);
    reg_vals[85] = 0x0000 | ((ramp_limit_low >> 16) & 0x3);
    reg_vals[86] = 0x0000 | (ramp_limit_low & 0x1ffff);
    reg_vals[96] = 0x0000 | ((ramp_burst_count & 0x3fff) << 2) | ((ramp_burst_en & 0x3) << 15);
    reg_vals[97] = 0x0800 | (ramp_burst_trig & 0x7) | ((ramp_triga & 0x1f) << 3) | ((ramp_trigb & 0x1f) << 7) | ((ramp0_rst & 0x3) << 15);
    reg_vals[98] = 0x0000 | (ramp0_dly & 0x3) | ((ramp0_inc >> 16) & 0xf);
    reg_vals[99] = 0x0000 | (ramp0_inc & 0x1ffff);
    reg_vals[100] = 0x0000 | (ramp0_len & 0x1ffff);
    reg_vals[101] = 0x0000 | ((ramp0_next & 0x3) << 4) | (ramp0_next_trig & 0x7) | ((ramp1_dly & 0x3) << 6) | ((ramp1_rst & 0x3) << 5);
    reg_vals[102] = 0x0000 | ((ramp1_inc >> 16) & 0xf);
    reg_vals[103] = 0x0000 | (ramp1_inc & 0x1ffff);
    reg_vals[104] = 0x0000 | (ramp1_len & 0x1ffff);
    reg_vals[105] = 0x0000 | ((ramp1_next & 0x3) << 4) | (ramp1_next_trig & 0x7) | ((ramp_dly_cnt & 0x7ff) << 6) | ((ramp_manual & 0x3) << 5);
    reg_vals[110] = 0x0000 | ((rb_vco_sel & 0xf) << 5) | ((rb_ld_vtune & 0x7) << 9);
    reg_vals[111] = 0x0000 | (rb_vco_capctrl & 0x1ff);
    reg_vals[112] = 0x0000 | (rb_vco_daciset & 0x3ff);
  }
  void LMX2595Config::read_regs(const std::map<int, std::uint16_t> &reg_vals)
  {
    powerdown = reg_vals.at(0) & 0x3;
    reset = (reg_vals.at(0) >> 1) & 0x3;
    muxout_ld_sel = (reg_vals.at(0) >> 2) & 0x3;
    fcal_en = (reg_vals.at(0) >> 3) & 0x3;
    fcal_lpfd_adj = (reg_vals.at(0) >> 5) & 0x7;
    fcal_hpfd_adj = (reg_vals.at(0) >> 7) & 0x7;
    out_mute = (reg_vals.at(0) >> 9) & 0x3;
    vco_phase_sync = (reg_vals.at(0) >> 14) & 0x3;
    ramp_en = (reg_vals.at(0) >> 15) & 0x3;
    cal_clk_div = reg_vals.at(1) & 0xf;
    acal_cmp_dly = (reg_vals.at(4) >> 8) & 0x1ff;
    out_force = (reg_vals.at(7) >> 14) & 0x3;
    vco_capctrl_force = (reg_vals.at(8) >> 11) & 0x3;
    vco_daciset_force = (reg_vals.at(8) >> 14) & 0x3;
    osc_2x = (reg_vals.at(9) >> 12) & 0x3;
    mult = (reg_vals.at(10) >> 7) & 0x3f;
    pll_r = (reg_vals.at(11) >> 4) & 0x1ff;
    pll_r_pre = reg_vals.at(12) & 0x1ff;
    cpg = (reg_vals.at(14) >> 4) & 0xf;
    vco_daciset = reg_vals.at(16) & 0x3ff;
    vco_daciset_strt = reg_vals.at(17) & 0x3ff;
    vco_capctrl = reg_vals.at(19) & 0x1ff;
    vco_sel_force = (reg_vals.at(20) >> 10) & 0x3;
    vco_sel = (reg_vals.at(20) >> 11) & 0xf;
    vco2x_en = reg_vals.at(27) & 0x3;
    seg1_en = (reg_vals.at(31) >> 14) & 0x3;
    pll_n = ((uint32_t)reg_vals.at(31) << 16) & 0x7;
    pll_n = reg_vals.at(36) & 0x1ffff;
    pfd_dly_sel = (reg_vals.at(37) >> 8) & 0x7f;
    mash_seed_en = (reg_vals.at(37) >> 15) & 0x3;
    pll_den = ((uint32_t)reg_vals.at(37) << 16) & 0xffff;
    pll_den = reg_vals.at(39) & 0x1ffff;
    mash_seed = ((uint32_t)reg_vals.at(39) << 16) & 0xffff;
    mash_seed = reg_vals.at(41) & 0x1ffff;
    pll_num = ((uint32_t)reg_vals.at(41) << 16) & 0xffff;
    pll_num = reg_vals.at(43) & 0x1ffff;
    mash_order = reg_vals.at(44) & 0xf;
    mash_reset_n = (reg_vals.at(44) >> 5) & 0x3;
    outa_pd = (reg_vals.at(44) >> 6) & 0x3;
    outb_pd = (reg_vals.at(44) >> 7) & 0x3;
    outa_pwr = (reg_vals.at(44) >> 8) & 0x7f;
    outb_pwr = reg_vals.at(45) & 0x7f;
    out_iset = (reg_vals.at(45) >> 9) & 0x7;
    outa_mux = (reg_vals.at(45) >> 11) & 0x7;
    outb_mux = reg_vals.at(46) & 0x7;
    inpin_fmt = (reg_vals.at(58) >> 9) & 0xf;
    inpin_lvl = (reg_vals.at(58) >> 12) & 0x7;
    inpin_hyst = (reg_vals.at(58) >> 14) & 0x3;
    inpin_ignore = (reg_vals.at(58) >> 15) & 0x3;
    ld_type = reg_vals.at(59) & 0x3;
    ld_dly = reg_vals.at(60) & 0x1ffff;
    mash_rst_count = ((uint32_t)reg_vals.at(60) << 16) & 0xffff;
    mash_rst_count = reg_vals.at(70) & 0x1ffff;
    sysref_repeat = (reg_vals.at(71) >> 2) & 0x3;
    sysref_en = (reg_vals.at(71) >> 3) & 0x3;
    sysref_pulse = (reg_vals.at(71) >> 4) & 0x3;
    sysref_div_pre = (reg_vals.at(71) >> 5) & 0xf;
    sysref_div = reg_vals.at(72) & 0xfff;
    jesd_dac1_ctrl = reg_vals.at(73) & 0x7f;
    jesd_dac2_ctrl = (reg_vals.at(73) >> 6) & 0x7f;
    jesd_dac3_ctrl = reg_vals.at(74) & 0x7f;
    jesd_dac4_ctrl = (reg_vals.at(74) >> 6) & 0x7f;
    sysref_pulse_cnt = (reg_vals.at(74) >> 12) & 0x1f;
    chdiv = (reg_vals.at(75) >> 6) & 0x3f;
    vco_capctrl_strt = (reg_vals.at(78) >> 1) & 0x1ff;
    quick_recal_en = (reg_vals.at(78) >> 9) & 0x3;
    ramp_trig_cal = (reg_vals.at(106) >> 4) & 0x3;
    ramp_thresh = ((uint32_t)reg_vals.at(106) << 21) & 0x1;
    ramp_thresh = ((uint32_t)reg_vals.at(106) << 16) & 0xffff;
    ramp_thresh = reg_vals.at(80) & 0x1ffff;
    ramp_limit_high = ((uint64_t)reg_vals.at(80) << 32) & 0x1;
    ramp_limit_high = ((uint32_t)reg_vals.at(80) << 16) & 0xffff;
    ramp_limit_high = reg_vals.at(83) & 0x1ffff;
    ramp_limit_low = ((uint64_t)reg_vals.at(83) << 32) & 0x1;
    ramp_limit_low = ((uint32_t)reg_vals.at(83) << 16) & 0xffff;
    ramp_limit_low = reg_vals.at(86) & 0x1ffff;
    ramp_burst_count = (reg_vals.at(96) >> 2) & 0x3fff;
    ramp_burst_en = (reg_vals.at(96) >> 15) & 0x3;
    ramp_burst_trig = reg_vals.at(97) & 0x7;
    ramp_triga = (reg_vals.at(97) >> 3) & 0x1f;
    ramp_trigb = (reg_vals.at(97) >> 7) & 0x1f;
    ramp0_dly = reg_vals.at(98) & 0x3;
    ramp0_rst = (reg_vals.at(97) >> 15) & 0x3;
    ramp0_inc = (reg_vals.at(97) << 14) & 0x3fff;
    ramp0_inc = reg_vals.at(99) & 0x1ffff;
    ramp0_len = reg_vals.at(100) & 0x1ffff;
    ramp0_next = (reg_vals.at(101) >> 4) & 0x3;
    ramp0_next_trig = reg_vals.at(101) & 0x7;
    ramp1_dly = (reg_vals.at(101) >> 6) & 0x3;
    ramp1_rst = (reg_vals.at(101) >> 5) & 0x3;
    ramp1_inc = ((uint32_t)reg_vals.at(101) << 16) & 0x3fff;
    ramp1_inc = reg_vals.at(103) & 0x1ffff;
    ramp1_len = reg_vals.at(104) & 0x1ffff;
    ramp1_next = (reg_vals.at(105) >> 4) & 0x3;
    ramp1_next_trig = reg_vals.at(105) & 0x7;
    ramp_dly_cnt = (reg_vals.at(105) >> 6) & 0x7ff;
    ramp_manual = (reg_vals.at(105) >> 5) & 0x3;
    ramp_scale_cnt = reg_vals.at(106) & 0xf;
    rb_vco_sel = (reg_vals.at(110) >> 5) & 0xf;
    rb_ld_vtune = (reg_vals.at(110) >> 9) & 0x7;
    rb_vco_capctrl = reg_vals.at(111) & 0x1ff;
    rb_vco_daciset = reg_vals.at(112) & 0x3ff;
  }

  void LMX2595Config::dump(void)
  {
    std::cout << "powerdown: " << powerdown << std::endl;
    std::cout << "reset: " << reset << std::endl;
    std::cout << "muxout_ld_sel: " << muxout_ld_sel << std::endl;
    std::cout << "fcal_en: " << fcal_en << std::endl;
    std::cout << "fcal_lpfd_adj: " << fcal_lpfd_adj << std::endl;
    std::cout << "fcal_hpfd_adj: " << fcal_hpfd_adj << std::endl;
    std::cout << "out_mute: " << out_mute << std::endl;
    std::cout << "vco_phase_sync: " << vco_phase_sync << std::endl;
    std::cout << "ramp_en: " << ramp_en << std::endl;
    std::cout << "cal_clk_div: " << cal_clk_div << std::endl;
    std::cout << "acal_cmp_dly: " << acal_cmp_dly << std::endl;
    std::cout << "out_force: " << out_force << std::endl;
    std::cout << "vco_capctrl_force: " << vco_capctrl_force << std::endl;
    std::cout << "vco_daciset_force: " << vco_daciset_force << std::endl;
    std::cout << "osc_2x: " << osc_2x << std::endl;
    std::cout << "mult: " << mult << std::endl;
    std::cout << "pll_r: " << pll_r << std::endl;
    std::cout << "pll_r_pre: " << pll_r_pre << std::endl;
    std::cout << "cpg: " << cpg << std::endl;
    std::cout << "vco_daciset: " << vco_daciset << std::endl;
    std::cout << "vco_daciset_strt: " << vco_daciset_strt << std::endl;
    std::cout << "vco_capctrl: " << vco_capctrl << std::endl;
    std::cout << "vco_sel_force: " << vco_sel_force << std::endl;
    std::cout << "vco_sel: " << vco_sel << std::endl;
    std::cout << "vco2x_en: " << vco2x_en << std::endl;
    std::cout << "seg1_en: " << seg1_en << std::endl;
    std::cout << "pll_n: " << pll_n << std::endl;
    std::cout << "pfd_dly_sel: " << pfd_dly_sel << std::endl;
    std::cout << "mash_seed_en: " << mash_seed_en << std::endl;
    std::cout << "pll_den: " << pll_den << std::endl;
    std::cout << "mash_seed: " << mash_seed << std::endl;
    std::cout << "pll_num: " << pll_num << std::endl;
    std::cout << "mash_order: " << mash_order << std::endl;
    std::cout << "mash_reset_n: " << mash_reset_n << std::endl;
    std::cout << "outa_pd: " << outa_pd << std::endl;
    std::cout << "outb_pd: " << outb_pd << std::endl;
    std::cout << "outa_pwr: " << outa_pwr << std::endl;
    std::cout << "outb_pwr: " << outb_pwr << std::endl;
    std::cout << "out_iset: " << out_iset << std::endl;
    std::cout << "outa_mux: " << outa_mux << std::endl;
    std::cout << "outb_mux: " << outb_mux << std::endl;
    std::cout << "inpin_fmt: " << inpin_fmt << std::endl;
    std::cout << "inpin_lvl: " << inpin_lvl << std::endl;
    std::cout << "inpin_hyst: " << inpin_hyst << std::endl;
    std::cout << "inpin_ignore: " << inpin_ignore << std::endl;
    std::cout << "ld_type: " << ld_type << std::endl;
    std::cout << "ld_dly: " << ld_dly << std::endl;
    std::cout << "mash_rst_count: " << mash_rst_count << std::endl;
    std::cout << "sysref_repeat: " << sysref_repeat << std::endl;
    std::cout << "sysref_en: " << sysref_en << std::endl;
    std::cout << "sysref_pulse: " << sysref_pulse << std::endl;
    std::cout << "sysref_div_pre: " << sysref_div_pre << std::endl;
    std::cout << "sysref_div: " << sysref_div << std::endl;
    std::cout << "jesd_dac1_ctrl: " << jesd_dac1_ctrl << std::endl;
    std::cout << "jesd_dac2_ctrl: " << jesd_dac2_ctrl << std::endl;
    std::cout << "jesd_dac3_ctrl: " << jesd_dac3_ctrl << std::endl;
    std::cout << "jesd_dac4_ctrl: " << jesd_dac4_ctrl << std::endl;
    std::cout << "sysref_pulse_cnt: " << sysref_pulse_cnt << std::endl;
    std::cout << "chdiv: " << chdiv << std::endl;
    std::cout << "vco_capctrl_strt: " << vco_capctrl_strt << std::endl;
    std::cout << "quick_recal_en: " << quick_recal_en << std::endl;
    std::cout << "ramp_trig_cal: " << ramp_trig_cal << std::endl;
    std::cout << "ramp_thresh: " << ramp_thresh << std::endl;
    std::cout << "ramp_limit_high: " << ramp_limit_high << std::endl;
    std::cout << "ramp_limit_low: " << ramp_limit_low << std::endl;
    std::cout << "ramp_burst_count: " << ramp_burst_count << std::endl;
    std::cout << "ramp_burst_en: " << ramp_burst_en << std::endl;
    std::cout << "ramp_burst_trig: " << ramp_burst_trig << std::endl;
    std::cout << "ramp_triga: " << ramp_triga << std::endl;
    std::cout << "ramp_trigb: " << ramp_trigb << std::endl;
    std::cout << "ramp0_dly: " << ramp0_dly << std::endl;
    std::cout << "ramp0_rst: " << ramp0_rst << std::endl;
    std::cout << "ramp0_inc: " << ramp0_inc << std::endl;
    std::cout << "ramp0_len: " << ramp0_len << std::endl;
    std::cout << "ramp0_next: " << ramp0_next << std::endl;
    std::cout << "ramp0_next_trig: " << ramp0_next_trig << std::endl;
    std::cout << "ramp1_dly: " << ramp1_dly << std::endl;
    std::cout << "ramp1_rst: " << ramp1_rst << std::endl;
    std::cout << "ramp1_inc: " << ramp1_inc << std::endl;
    std::cout << "ramp1_len: " << ramp1_len << std::endl;
    std::cout << "ramp1_next: " << ramp1_next << std::endl;
    std::cout << "ramp1_next_trig: " << ramp1_next_trig << std::endl;
    std::cout << "ramp_dly_cnt: " << ramp_dly_cnt << std::endl;
    std::cout << "ramp_manual: " << ramp_manual << std::endl;
    std::cout << "ramp_scale_cnt: " << ramp_scale_cnt << std::endl;
    std::cout << "rb_vco_sel: " << rb_vco_sel << std::endl;
    std::cout << "rb_ld_vtune: " << rb_ld_vtune << std::endl;
    std::cout << "rb_vco_capctrl: " << rb_vco_capctrl << std::endl;
    std::cout << "rb_vco_daciset: " << rb_vco_daciset << std::endl;
  }
}
