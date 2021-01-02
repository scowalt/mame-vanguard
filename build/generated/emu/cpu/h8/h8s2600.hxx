void h8s2600_device::mac_r32ph_r32pl_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read16(r32_r(IR[1]));
	r32_w(IR[1], r32_r(IR[1]) + 2);
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16(r32_r(IR[1] >> 4));
	r32_w(IR[1] >> 4, r32_r(IR[1] >> 4) + 2);
	MAC += int16_t(TMP1)*int16_t(TMP2);
	MACF &= ~(F_Z|F_N);
	if(MAC)
		MACF |= F_Z;
	else if(MAC < 0)
		MACF |= F_N;
	if(mac_saturating) {
		if(MAC < -0x80000000LL) {
			MAC = -0x80000000LL;
			MACF |= F_V;
		} else if(MAC > 0x7fffffffLL) {
			MAC = 0x7fffffffLL;
			MACF |= F_V;
		}
	} else {
		if(MAC < -0x20000000000LL) {
			MAC = -0x20000000000LL;
			MACF |= F_V;
		} else if(MAC > 0x1ffffffffffLL) {
			MAC = 0x1ffffffffffLL;
			MACF |= F_V;
		}
	}
	prefetch_done();
}

void h8s2600_device::mac_r32ph_r32pl_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read16(r32_r(IR[1]));
	r32_w(IR[1], r32_r(IR[1]) + 2);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16(r32_r(IR[1] >> 4));
	r32_w(IR[1] >> 4, r32_r(IR[1] >> 4) + 2);
	MAC += int16_t(TMP1)*int16_t(TMP2);
	MACF &= ~(F_Z|F_N);
	if(MAC)
		MACF |= F_Z;
	else if(MAC < 0)
		MACF |= F_N;
	if(mac_saturating) {
		if(MAC < -0x80000000LL) {
			MAC = -0x80000000LL;
			MACF |= F_V;
		} else if(MAC > 0x7fffffffLL) {
			MAC = 0x7fffffffLL;
			MACF |= F_V;
		}
	} else {
		if(MAC < -0x20000000000LL) {
			MAC = -0x20000000000LL;
			MACF |= F_V;
		} else if(MAC > 0x1ffffffffffLL) {
			MAC = 0x1ffffffffffLL;
			MACF |= F_V;
		}
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2600_device::clrmac_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	MAC = 0;
	MACF &= ~F_V;
	prefetch_done();
}

void h8s2600_device::clrmac_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	MAC = 0;
	MACF &= ~F_V;
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2600_device::stmac_mach_r32l_full()
{
	r32_w(IR[0], MAC >> 32);
	CCR = (CCR & ~(F_V|F_N|F_Z)) | MACF;
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2600_device::stmac_mach_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], MAC >> 32);
	CCR = (CCR & ~(F_V|F_N|F_Z)) | MACF;
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2600_device::stmac_macl_r32l_full()
{
	r32_w(IR[0], MAC);
	CCR = (CCR & ~(F_V|F_N|F_Z)) | MACF;
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2600_device::stmac_macl_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], MAC);
	CCR = (CCR & ~(F_V|F_N|F_Z)) | MACF;
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2600_device::ldmac_r32l_mach_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[0]);
	if(TMP1 & 0x200)
		TMP1 |= 0xfffffc00;
	else
		TMP1 &= ~0xfffffc00;
	MAC = (MAC & 0x00000000ffffffffULL) | (uint64_t(TMP1) << 32);
	MACF &= ~F_V;
	prefetch_done();
}

void h8s2600_device::ldmac_r32l_mach_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[0]);
	if(TMP1 & 0x200)
		TMP1 |= 0xfffffc00;
	else
		TMP1 &= ~0xfffffc00;
	MAC = (MAC & 0x00000000ffffffffULL) | (uint64_t(TMP1) << 32);
	MACF &= ~F_V;
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2600_device::ldmac_r32l_macl_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	MAC = (MAC & 0xffffffff00000000ULL) | r32_r(IR[0]);
	MACF &= ~F_V;
	prefetch_done();
}

void h8s2600_device::ldmac_r32l_macl_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	MAC = (MAC & 0xffffffff00000000ULL) | r32_r(IR[0]);
	MACF &= ~F_V;
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2600_device::do_exec_full()
{
	switch(inst_state >> 16) {
	case 0x00: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0xff) {
			case 0x00: nop_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x01: {
			switch(inst_state & 0xff) {
			case 0x00: dispatch_0100_full(); break;
			case 0x10: dispatch_0110_full(); break;
			case 0x20: dispatch_0120_full(); break;
			case 0x30: dispatch_0130_full(); break;
			case 0x40: dispatch_0140_full(); break;
			case 0x41: dispatch_0141_full(); break;
			case 0x60: dispatch_0160_full(); break;
			case 0x80: sleep_full(); break;
			case 0xa0: clrmac_full(); break;
			case 0xc0: dispatch_01c0_full(); break;
			case 0xd0: dispatch_01d0_full(); break;
			case 0xe0: dispatch_01e0_full(); break;
			case 0xf0: dispatch_01f0_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x02: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: stc_ccr_r8l_full(); break;
			case 0x10: case 0x18: stc_exr_r8l_full(); break;
			case 0x20: stmac_mach_r32l_full(); break;
			case 0x30: stmac_macl_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x03: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: ldc_r8l_ccr_full(); break;
			case 0x10: case 0x18: ldc_r8l_exr_full(); break;
			case 0x20: ldmac_r32l_mach_full(); break;
			case 0x30: ldmac_r32l_macl_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x04: {
			orc_imm8_ccr_full();
			break;
		}
		case 0x05: {
			xorc_imm8_ccr_full();
			break;
		}
		case 0x06: {
			andc_imm8_ccr_full();
			break;
		}
		case 0x07: {
			ldc_imm8_ccr_full();
			break;
		}
		case 0x08: {
			add_b_r8h_r8l_full();
			break;
		}
		case 0x09: {
			add_w_r16h_r16l_full();
			break;
		}
		case 0x0a: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: inc_b_one_r8l_full(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: add_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0b: {
			switch(inst_state & 0xf8) {
			case 0x00: adds_l_one_r32l_full(); break;
			case 0x50: case 0x58: inc_w_one_r16l_full(); break;
			case 0x70: inc_l_one_r32l_full(); break;
			case 0x80: adds_l_two_r32l_full(); break;
			case 0x90: adds_l_four_r32l_full(); break;
			case 0xd0: case 0xd8: inc_w_two_r16l_full(); break;
			case 0xf0: inc_l_two_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0c: {
			mov_b_r8h_r8l_full();
			break;
		}
		case 0x0d: {
			mov_w_r16h_r16l_full();
			break;
		}
		case 0x0e: {
			addx_b_r8h_r8l_full();
			break;
		}
		case 0x0f: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: daa_b_r8l_full(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: mov_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x10: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: shll_b_r8l_full(); break;
			case 0x10: case 0x18: shll_w_r16l_full(); break;
			case 0x30: shll_l_r32l_full(); break;
			case 0x40: case 0x48: shll_b_two_r8l_full(); break;
			case 0x50: case 0x58: shll_w_two_r16l_full(); break;
			case 0x70: shll_l_two_r32l_full(); break;
			case 0x80: case 0x88: shal_b_r8l_full(); break;
			case 0x90: case 0x98: shal_w_r16l_full(); break;
			case 0xb0: shal_l_r32l_full(); break;
			case 0xc0: case 0xc8: shal_b_two_r8l_full(); break;
			case 0xd0: case 0xd8: shal_w_two_r16l_full(); break;
			case 0xf0: shal_l_two_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x11: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: shlr_b_r8l_full(); break;
			case 0x10: case 0x18: shlr_w_r16l_full(); break;
			case 0x30: shlr_l_r32l_full(); break;
			case 0x40: case 0x48: shlr_b_two_r8l_full(); break;
			case 0x50: case 0x58: shlr_w_two_r16l_full(); break;
			case 0x70: shlr_l_two_r32l_full(); break;
			case 0x80: case 0x88: shar_b_r8l_full(); break;
			case 0x90: case 0x98: shar_w_r16l_full(); break;
			case 0xb0: shar_l_r32l_full(); break;
			case 0xc0: case 0xc8: shar_b_two_r8l_full(); break;
			case 0xd0: case 0xd8: shar_w_two_r16l_full(); break;
			case 0xf0: shar_l_two_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x12: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: rotxl_b_r8l_full(); break;
			case 0x10: case 0x18: rotxl_w_r16l_full(); break;
			case 0x30: rotxl_l_r32l_full(); break;
			case 0x40: case 0x48: rotxl_b_two_r8l_full(); break;
			case 0x50: case 0x58: rotxl_w_two_r16l_full(); break;
			case 0x70: rotxl_l_two_r32l_full(); break;
			case 0x80: case 0x88: rotl_b_r8l_full(); break;
			case 0x90: case 0x98: rotl_w_r16l_full(); break;
			case 0xb0: rotl_l_r32l_full(); break;
			case 0xc0: case 0xc8: rotl_b_two_r8l_full(); break;
			case 0xd0: case 0xd8: rotl_w_two_r16l_full(); break;
			case 0xf0: rotl_l_two_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x13: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: rotxr_b_r8l_full(); break;
			case 0x10: case 0x18: rotxr_w_r16l_full(); break;
			case 0x30: rotxr_l_r32l_full(); break;
			case 0x40: case 0x48: rotxr_b_two_r8l_full(); break;
			case 0x50: case 0x58: rotxr_w_two_r16l_full(); break;
			case 0x70: rotxr_l_two_r32l_full(); break;
			case 0x80: case 0x88: rotr_b_r8l_full(); break;
			case 0x90: case 0x98: rotr_w_r16l_full(); break;
			case 0xb0: rotr_l_r32l_full(); break;
			case 0xc0: case 0xc8: rotr_b_two_r8l_full(); break;
			case 0xd0: case 0xd8: rotr_w_two_r16l_full(); break;
			case 0xf0: rotr_l_two_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x14: {
			or_b_r8h_r8l_full();
			break;
		}
		case 0x15: {
			xor_b_r8h_r8l_full();
			break;
		}
		case 0x16: {
			and_b_r8h_r8l_full();
			break;
		}
		case 0x17: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: not_b_r8l_full(); break;
			case 0x10: case 0x18: not_w_r16l_full(); break;
			case 0x30: not_l_r32l_full(); break;
			case 0x50: case 0x58: extu_w_r16l_full(); break;
			case 0x70: extu_l_r32l_full(); break;
			case 0x80: case 0x88: neg_b_r8l_full(); break;
			case 0x90: case 0x98: neg_w_r16l_full(); break;
			case 0xb0: neg_l_r32l_full(); break;
			case 0xd0: case 0xd8: exts_w_r16l_full(); break;
			case 0xf0: exts_l_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x18: {
			sub_b_r8h_r8l_full();
			break;
		}
		case 0x19: {
			sub_w_r16h_r16l_full();
			break;
		}
		case 0x1a: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: dec_b_one_r8l_full(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: sub_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1b: {
			switch(inst_state & 0xf8) {
			case 0x00: subs_l_one_r32l_full(); break;
			case 0x50: case 0x58: dec_w_one_r16l_full(); break;
			case 0x70: dec_l_one_r32l_full(); break;
			case 0x80: subs_l_two_r32l_full(); break;
			case 0x90: subs_l_four_r32l_full(); break;
			case 0xd0: case 0xd8: dec_w_two_r16l_full(); break;
			case 0xf0: dec_l_two_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1c: {
			cmp_b_r8h_r8l_full();
			break;
		}
		case 0x1d: {
			cmp_w_r16h_r16l_full();
			break;
		}
		case 0x1e: {
			subx_b_r8h_r8l_full();
			break;
		}
		case 0x1f: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: das_b_r8l_full(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: cmp_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: {
			mov_b_abs8_r8u_full();
			break;
		}
		case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: {
			mov_b_r8u_abs8_full();
			break;
		}
		case 0x40: {
			bt_rel8_full();
			break;
		}
		case 0x41: {
			bf_rel8_full();
			break;
		}
		case 0x42: {
			bhi_rel8_full();
			break;
		}
		case 0x43: {
			bls_rel8_full();
			break;
		}
		case 0x44: {
			bcc_rel8_full();
			break;
		}
		case 0x45: {
			bcs_rel8_full();
			break;
		}
		case 0x46: {
			bne_rel8_full();
			break;
		}
		case 0x47: {
			beq_rel8_full();
			break;
		}
		case 0x48: {
			bvc_rel8_full();
			break;
		}
		case 0x49: {
			bvs_rel8_full();
			break;
		}
		case 0x4a: {
			bpl_rel8_full();
			break;
		}
		case 0x4b: {
			bmi_rel8_full();
			break;
		}
		case 0x4c: {
			bge_rel8_full();
			break;
		}
		case 0x4d: {
			blt_rel8_full();
			break;
		}
		case 0x4e: {
			bgt_rel8_full();
			break;
		}
		case 0x4f: {
			ble_rel8_full();
			break;
		}
		case 0x50: {
			mulxu_b_r8h_r16l_full();
			break;
		}
		case 0x51: {
			divxu_b_r8h_r16l_full();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x08) {
			case 0x00: mulxu_w_r16h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x53: {
			switch(inst_state & 0x08) {
			case 0x00: divxu_w_r16h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x54: {
			switch(inst_state & 0xff) {
			case 0x70: rts_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x55: {
			bsr_rel8_full();
			break;
		}
		case 0x56: {
			switch(inst_state & 0xff) {
			case 0x70: rte_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x57: {
			switch(inst_state & 0xcf) {
			case 0x00: trapa_imm2_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x58: {
			switch(inst_state & 0xff) {
			case 0x00: bt_rel16_full(); break;
			case 0x10: bf_rel16_full(); break;
			case 0x20: bhi_rel16_full(); break;
			case 0x30: bls_rel16_full(); break;
			case 0x40: bcc_rel16_full(); break;
			case 0x50: bcs_rel16_full(); break;
			case 0x60: bne_rel16_full(); break;
			case 0x70: beq_rel16_full(); break;
			case 0x80: bvc_rel16_full(); break;
			case 0x90: bvs_rel16_full(); break;
			case 0xa0: bpl_rel16_full(); break;
			case 0xb0: bmi_rel16_full(); break;
			case 0xc0: bge_rel16_full(); break;
			case 0xd0: blt_rel16_full(); break;
			case 0xe0: bgt_rel16_full(); break;
			case 0xf0: ble_rel16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x59: {
			switch(inst_state & 0x8f) {
			case 0x00: jmp_r32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5a: {
			jmp_abs24e_full();
			break;
		}
		case 0x5b: {
			jmp_abs8i_full();
			break;
		}
		case 0x5c: {
			switch(inst_state & 0xff) {
			case 0x00: bsr_rel16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5d: {
			switch(inst_state & 0x8f) {
			case 0x00: jsr_r32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5e: {
			jsr_abs24e_full();
			break;
		}
		case 0x5f: {
			jsr_abs8i_full();
			break;
		}
		case 0x60: {
			bset_r8h_r8l_full();
			break;
		}
		case 0x61: {
			bnot_r8h_r8l_full();
			break;
		}
		case 0x62: {
			bclr_r8h_r8l_full();
			break;
		}
		case 0x63: {
			btst_r8h_r8l_full();
			break;
		}
		case 0x64: {
			or_w_r16h_r16l_full();
			break;
		}
		case 0x65: {
			xor_w_r16h_r16l_full();
			break;
		}
		case 0x66: {
			and_w_r16h_r16l_full();
			break;
		}
		case 0x67: {
			switch(inst_state & 0x80) {
			case 0x00: bst_imm3_r8l_full(); break;
			case 0x80: bist_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x68: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32ih_r8l_full(); break;
			case 0x80: mov_b_r8l_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x69: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32ih_r16l_full(); break;
			case 0x80: mov_w_r16l_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6a: {
			switch(inst_state & 0xff) {
			case 0x00: case 0x01: case 0x02: case 0x03: case 0x04: case 0x05: case 0x06: case 0x07: case 0x08: case 0x09: case 0x0a: case 0x0b: case 0x0c: case 0x0d: case 0x0e: case 0x0f: mov_b_abs16_r8l_full(); break;
			case 0x10: dispatch_6a10_full(); break;
			case 0x18: dispatch_6a18_full(); break;
			case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: mov_b_abs32_r8l_full(); break;
			case 0x30: dispatch_6a30_full(); break;
			case 0x38: dispatch_6a38_full(); break;
			case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f: movfpe_abs16_r8l_full(); break;
			case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: mov_b_r8l_abs16_full(); break;
			case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: mov_b_r8l_abs32_full(); break;
			case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: movtpe_r8l_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_abs16_r16l_full(); break;
			case 0x20: mov_w_abs32_r16l_full(); break;
			case 0x80: mov_w_r16l_abs16_full(); break;
			case 0xa0: mov_w_r16l_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6c: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32ph_r8l_full(); break;
			case 0x80: mov_b_r8l_pr32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32ph_r16l_full(); break;
			case 0x80: mov_w_r16l_pr32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6e: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32d16h_r8l_full(); break;
			case 0x80: mov_b_r8l_r32d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32d16h_r16l_full(); break;
			case 0x80: mov_w_r16l_r32d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x80) {
			case 0x00: bset_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x80) {
			case 0x00: bnot_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x80) {
			case 0x00: bclr_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x80) {
			case 0x00: btst_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x80) {
			case 0x00: bor_imm3_r8l_full(); break;
			case 0x80: bior_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x80) {
			case 0x00: bxor_imm3_r8l_full(); break;
			case 0x80: bixor_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x80) {
			case 0x00: band_imm3_r8l_full(); break;
			case 0x80: biand_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x80) {
			case 0x00: bld_imm3_r8l_full(); break;
			case 0x80: bild_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7800_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x79: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_imm16_r16l_full(); break;
			case 0x10: add_w_imm16_r16l_full(); break;
			case 0x20: cmp_w_imm16_r16l_full(); break;
			case 0x30: sub_w_imm16_r16l_full(); break;
			case 0x40: or_w_imm16_r16l_full(); break;
			case 0x50: xor_w_imm16_r16l_full(); break;
			case 0x60: and_w_imm16_r16l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7a: {
			switch(inst_state & 0xf8) {
			case 0x00: mov_l_imm32_r32l_full(); break;
			case 0x10: add_l_imm32_r32l_full(); break;
			case 0x20: cmp_l_imm32_r32l_full(); break;
			case 0x30: sub_l_imm32_r32l_full(); break;
			case 0x40: or_l_imm32_r32l_full(); break;
			case 0x50: xor_l_imm32_r32l_full(); break;
			case 0x60: and_l_imm32_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7b: {
			switch(inst_state & 0xff) {
			case 0x5c: dispatch_7b5c_full(); break;
			case 0xd4: dispatch_7bd4_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7c: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7c00_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7d: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7d00_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7e: {
			dispatch_7e00_full();
			break;
		}
		case 0x7f: {
			dispatch_7f00_full();
			break;
		}
		case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: {
			add_b_imm8_r8u_full();
			break;
		}
		case 0x90: case 0x91: case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: case 0x97: case 0x98: case 0x99: case 0x9a: case 0x9b: case 0x9c: case 0x9d: case 0x9e: case 0x9f: {
			addx_b_imm8_r8u_full();
			break;
		}
		case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: {
			cmp_b_imm8_r8u_full();
			break;
		}
		case 0xb0: case 0xb1: case 0xb2: case 0xb3: case 0xb4: case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xba: case 0xbb: case 0xbc: case 0xbd: case 0xbe: case 0xbf: {
			subx_b_imm8_r8u_full();
			break;
		}
		case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: {
			or_b_imm8_r8u_full();
			break;
		}
		case 0xd0: case 0xd1: case 0xd2: case 0xd3: case 0xd4: case 0xd5: case 0xd6: case 0xd7: case 0xd8: case 0xd9: case 0xda: case 0xdb: case 0xdc: case 0xdd: case 0xde: case 0xdf: {
			xor_b_imm8_r8u_full();
			break;
		}
		case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe4: case 0xe5: case 0xe6: case 0xe7: case 0xe8: case 0xe9: case 0xea: case 0xeb: case 0xec: case 0xed: case 0xee: case 0xef: {
			and_b_imm8_r8u_full();
			break;
		}
		case 0xf0: case 0xf1: case 0xf2: case 0xf3: case 0xf4: case 0xf5: case 0xf6: case 0xf7: case 0xf8: case 0xf9: case 0xfa: case 0xfb: case 0xfc: case 0xfd: case 0xfe: case 0xff: {
			mov_b_imm8_r8u_full();
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x01: {
		switch(inst_state & 0xffff) {
		case 0x00: state_reset_full(); break;
		case 0x01: state_irq_full(); break;
		case 0x02: state_trace_full(); break;
		case 0x03: state_dma_full(); break;
		case 0x04: state_dtc_full(); break;
		case 0x05: state_dtc_vector_full(); break;
		case 0x06: state_dtc_writeback_full(); break;
		}
		break;
	}
	case 0x02: {
		switch((inst_state >> 8) & 0xff) {
		case 0x69: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32ih_r32l_full(); break;
			case 0x80: mov_l_r32l_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf8) {
			case 0x00: mov_l_abs16_r32l_full(); break;
			case 0x20: mov_l_abs32_r32l_full(); break;
			case 0x80: mov_l_r32l_abs16_full(); break;
			case 0xa0: mov_l_r32l_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32ph_r32l_full(); break;
			case 0x80: mov_l_r32l_pr32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32d16h_r32l_full(); break;
			case 0x80: mov_l_r32l_r32d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x0f) {
			case 0x00: dispatch_01007800_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x03: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xf8) {
			case 0x20: mov_l_r32d32hh_r32l_full(); break;
			case 0xa0: mov_l_r32l_r32d32hh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x04: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6d: {
			switch(inst_state & 0xf9) {
			case 0x71: ldm_l_spp_r32n2l_full(); break;
			case 0xf0: stm_l_r32n2l_psp_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x05: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6d: {
			switch(inst_state & 0xfb) {
			case 0x72: ldm_l_spp_r32n3l_full(); break;
			case 0xf0: stm_l_r32n3l_psp_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x06: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6d: {
			switch(inst_state & 0xfb) {
			case 0x73: ldm_l_spp_r32n4l_full(); break;
			case 0xf0: stm_l_r32n4l_psp_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x07: {
		switch((inst_state >> 8) & 0xff) {
		case 0x69: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ih_ccr_full(); break;
			case 0x80: stc_w_ccr_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x00: ldc_w_abs16_ccr_full(); break;
			case 0x20: ldc_w_abs32_ccr_full(); break;
			case 0x80: stc_w_ccr_abs16_full(); break;
			case 0xa0: stc_w_ccr_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ph_ccr_full(); break;
			case 0x80: stc_w_ccr_pr32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32d16h_ccr_full(); break;
			case 0x80: stc_w_ccr_r32d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_01407800_full(); break;
			case 0x80: dispatch_01407880_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x08: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x20: ldc_w_r32d32hh_ccr_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x09: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0xa0: stc_w_ccr_r32d32hh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0a: {
		switch((inst_state >> 8) & 0xff) {
		case 0x04: {
			orc_imm8_exr_full();
			break;
		}
		case 0x05: {
			xorc_imm8_exr_full();
			break;
		}
		case 0x06: {
			andc_imm8_exr_full();
			break;
		}
		case 0x07: {
			ldc_imm8_exr_full();
			break;
		}
		case 0x69: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ih_exr_full(); break;
			case 0x80: stc_w_exr_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x00: ldc_w_abs16_exr_full(); break;
			case 0x20: ldc_w_abs32_exr_full(); break;
			case 0x80: stc_w_exr_abs16_full(); break;
			case 0xa0: stc_w_exr_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ph_exr_full(); break;
			case 0x80: stc_w_exr_pr32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32d16h_exr_full(); break;
			case 0x80: stc_w_exr_r32d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_01417800_full(); break;
			case 0x80: dispatch_01417880_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0b: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x20: ldc_w_r32d32hh_exr_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0c: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0xa0: stc_w_exr_r32d32hh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0d: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6d: {
			switch(inst_state & 0x88) {
			case 0x00: mac_r32ph_r32pl_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0e: {
		switch((inst_state >> 8) & 0xff) {
		case 0x50: {
			mulxs_b_r8h_r16l_full();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x08) {
			case 0x00: mulxs_w_r16h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0f: {
		switch((inst_state >> 8) & 0xff) {
		case 0x51: {
			divxs_b_r8h_r16l_full();
			break;
		}
		case 0x53: {
			switch(inst_state & 0x08) {
			case 0x00: divxs_w_r16h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x10: {
		switch((inst_state >> 8) & 0xff) {
		case 0x7b: {
			switch(inst_state & 0xaf) {
			case 0x0c: tas_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x11: {
		switch((inst_state >> 8) & 0xff) {
		case 0x64: {
			switch(inst_state & 0x88) {
			case 0x00: or_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x65: {
			switch(inst_state & 0x88) {
			case 0x00: xor_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x66: {
			switch(inst_state & 0x88) {
			case 0x00: and_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x12: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs16_full(); break;
			case 0x80: bior_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs16_full(); break;
			case 0x80: bixor_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs16_full(); break;
			case 0x80: biand_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs16_full(); break;
			case 0x80: bild_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x13: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs16_full(); break;
			case 0x80: bist_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x14: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs32_full(); break;
			case 0x80: bior_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs32_full(); break;
			case 0x80: bixor_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs32_full(); break;
			case 0x80: biand_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs32_full(); break;
			case 0x80: bild_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x15: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs32_full(); break;
			case 0x80: bist_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x16: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6a: {
			switch(inst_state & 0xf0) {
			case 0x20: mov_b_r32d32hh_r8l_full(); break;
			case 0xa0: mov_b_r8l_r32d32hh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf0) {
			case 0x20: mov_w_r32d32hh_r16l_full(); break;
			case 0xa0: mov_w_r16l_r32d32hh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x17: {
		switch((inst_state >> 8) & 0xff) {
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x8f: eepmov_b_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x18: {
		switch((inst_state >> 8) & 0xff) {
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x8f: eepmov_w_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x19: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_r32ihh_full(); break;
			case 0x80: bior_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_r32ihh_full(); break;
			case 0x80: bixor_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_r32ihh_full(); break;
			case 0x80: biand_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_r32ihh_full(); break;
			case 0x80: bild_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1a: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_r32ihh_full(); break;
			case 0x80: bist_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1b: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs8_full(); break;
			case 0x80: bior_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs8_full(); break;
			case 0x80: bixor_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs8_full(); break;
			case 0x80: biand_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs8_full(); break;
			case 0x80: bild_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1c: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs8_full(); break;
			case 0x80: bist_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	}
}
void h8s2600_device::do_exec_partial()
{
	switch(inst_state >> 16) {
	case 0x00: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0xff) {
			case 0x00: nop_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x01: {
			switch(inst_state & 0xff) {
			case 0x00: dispatch_0100_partial(); break;
			case 0x10: dispatch_0110_partial(); break;
			case 0x20: dispatch_0120_partial(); break;
			case 0x30: dispatch_0130_partial(); break;
			case 0x40: dispatch_0140_partial(); break;
			case 0x41: dispatch_0141_partial(); break;
			case 0x60: dispatch_0160_partial(); break;
			case 0x80: sleep_partial(); break;
			case 0xa0: clrmac_partial(); break;
			case 0xc0: dispatch_01c0_partial(); break;
			case 0xd0: dispatch_01d0_partial(); break;
			case 0xe0: dispatch_01e0_partial(); break;
			case 0xf0: dispatch_01f0_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x02: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: stc_ccr_r8l_partial(); break;
			case 0x10: case 0x18: stc_exr_r8l_partial(); break;
			case 0x20: stmac_mach_r32l_partial(); break;
			case 0x30: stmac_macl_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x03: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: ldc_r8l_ccr_partial(); break;
			case 0x10: case 0x18: ldc_r8l_exr_partial(); break;
			case 0x20: ldmac_r32l_mach_partial(); break;
			case 0x30: ldmac_r32l_macl_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x04: {
			orc_imm8_ccr_partial();
			break;
		}
		case 0x05: {
			xorc_imm8_ccr_partial();
			break;
		}
		case 0x06: {
			andc_imm8_ccr_partial();
			break;
		}
		case 0x07: {
			ldc_imm8_ccr_partial();
			break;
		}
		case 0x08: {
			add_b_r8h_r8l_partial();
			break;
		}
		case 0x09: {
			add_w_r16h_r16l_partial();
			break;
		}
		case 0x0a: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: inc_b_one_r8l_partial(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: add_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0b: {
			switch(inst_state & 0xf8) {
			case 0x00: adds_l_one_r32l_partial(); break;
			case 0x50: case 0x58: inc_w_one_r16l_partial(); break;
			case 0x70: inc_l_one_r32l_partial(); break;
			case 0x80: adds_l_two_r32l_partial(); break;
			case 0x90: adds_l_four_r32l_partial(); break;
			case 0xd0: case 0xd8: inc_w_two_r16l_partial(); break;
			case 0xf0: inc_l_two_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0c: {
			mov_b_r8h_r8l_partial();
			break;
		}
		case 0x0d: {
			mov_w_r16h_r16l_partial();
			break;
		}
		case 0x0e: {
			addx_b_r8h_r8l_partial();
			break;
		}
		case 0x0f: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: daa_b_r8l_partial(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: mov_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x10: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: shll_b_r8l_partial(); break;
			case 0x10: case 0x18: shll_w_r16l_partial(); break;
			case 0x30: shll_l_r32l_partial(); break;
			case 0x40: case 0x48: shll_b_two_r8l_partial(); break;
			case 0x50: case 0x58: shll_w_two_r16l_partial(); break;
			case 0x70: shll_l_two_r32l_partial(); break;
			case 0x80: case 0x88: shal_b_r8l_partial(); break;
			case 0x90: case 0x98: shal_w_r16l_partial(); break;
			case 0xb0: shal_l_r32l_partial(); break;
			case 0xc0: case 0xc8: shal_b_two_r8l_partial(); break;
			case 0xd0: case 0xd8: shal_w_two_r16l_partial(); break;
			case 0xf0: shal_l_two_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x11: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: shlr_b_r8l_partial(); break;
			case 0x10: case 0x18: shlr_w_r16l_partial(); break;
			case 0x30: shlr_l_r32l_partial(); break;
			case 0x40: case 0x48: shlr_b_two_r8l_partial(); break;
			case 0x50: case 0x58: shlr_w_two_r16l_partial(); break;
			case 0x70: shlr_l_two_r32l_partial(); break;
			case 0x80: case 0x88: shar_b_r8l_partial(); break;
			case 0x90: case 0x98: shar_w_r16l_partial(); break;
			case 0xb0: shar_l_r32l_partial(); break;
			case 0xc0: case 0xc8: shar_b_two_r8l_partial(); break;
			case 0xd0: case 0xd8: shar_w_two_r16l_partial(); break;
			case 0xf0: shar_l_two_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x12: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: rotxl_b_r8l_partial(); break;
			case 0x10: case 0x18: rotxl_w_r16l_partial(); break;
			case 0x30: rotxl_l_r32l_partial(); break;
			case 0x40: case 0x48: rotxl_b_two_r8l_partial(); break;
			case 0x50: case 0x58: rotxl_w_two_r16l_partial(); break;
			case 0x70: rotxl_l_two_r32l_partial(); break;
			case 0x80: case 0x88: rotl_b_r8l_partial(); break;
			case 0x90: case 0x98: rotl_w_r16l_partial(); break;
			case 0xb0: rotl_l_r32l_partial(); break;
			case 0xc0: case 0xc8: rotl_b_two_r8l_partial(); break;
			case 0xd0: case 0xd8: rotl_w_two_r16l_partial(); break;
			case 0xf0: rotl_l_two_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x13: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: rotxr_b_r8l_partial(); break;
			case 0x10: case 0x18: rotxr_w_r16l_partial(); break;
			case 0x30: rotxr_l_r32l_partial(); break;
			case 0x40: case 0x48: rotxr_b_two_r8l_partial(); break;
			case 0x50: case 0x58: rotxr_w_two_r16l_partial(); break;
			case 0x70: rotxr_l_two_r32l_partial(); break;
			case 0x80: case 0x88: rotr_b_r8l_partial(); break;
			case 0x90: case 0x98: rotr_w_r16l_partial(); break;
			case 0xb0: rotr_l_r32l_partial(); break;
			case 0xc0: case 0xc8: rotr_b_two_r8l_partial(); break;
			case 0xd0: case 0xd8: rotr_w_two_r16l_partial(); break;
			case 0xf0: rotr_l_two_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x14: {
			or_b_r8h_r8l_partial();
			break;
		}
		case 0x15: {
			xor_b_r8h_r8l_partial();
			break;
		}
		case 0x16: {
			and_b_r8h_r8l_partial();
			break;
		}
		case 0x17: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: not_b_r8l_partial(); break;
			case 0x10: case 0x18: not_w_r16l_partial(); break;
			case 0x30: not_l_r32l_partial(); break;
			case 0x50: case 0x58: extu_w_r16l_partial(); break;
			case 0x70: extu_l_r32l_partial(); break;
			case 0x80: case 0x88: neg_b_r8l_partial(); break;
			case 0x90: case 0x98: neg_w_r16l_partial(); break;
			case 0xb0: neg_l_r32l_partial(); break;
			case 0xd0: case 0xd8: exts_w_r16l_partial(); break;
			case 0xf0: exts_l_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x18: {
			sub_b_r8h_r8l_partial();
			break;
		}
		case 0x19: {
			sub_w_r16h_r16l_partial();
			break;
		}
		case 0x1a: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: dec_b_one_r8l_partial(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: sub_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1b: {
			switch(inst_state & 0xf8) {
			case 0x00: subs_l_one_r32l_partial(); break;
			case 0x50: case 0x58: dec_w_one_r16l_partial(); break;
			case 0x70: dec_l_one_r32l_partial(); break;
			case 0x80: subs_l_two_r32l_partial(); break;
			case 0x90: subs_l_four_r32l_partial(); break;
			case 0xd0: case 0xd8: dec_w_two_r16l_partial(); break;
			case 0xf0: dec_l_two_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1c: {
			cmp_b_r8h_r8l_partial();
			break;
		}
		case 0x1d: {
			cmp_w_r16h_r16l_partial();
			break;
		}
		case 0x1e: {
			subx_b_r8h_r8l_partial();
			break;
		}
		case 0x1f: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: das_b_r8l_partial(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: cmp_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: {
			mov_b_abs8_r8u_partial();
			break;
		}
		case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: {
			mov_b_r8u_abs8_partial();
			break;
		}
		case 0x40: {
			bt_rel8_partial();
			break;
		}
		case 0x41: {
			bf_rel8_partial();
			break;
		}
		case 0x42: {
			bhi_rel8_partial();
			break;
		}
		case 0x43: {
			bls_rel8_partial();
			break;
		}
		case 0x44: {
			bcc_rel8_partial();
			break;
		}
		case 0x45: {
			bcs_rel8_partial();
			break;
		}
		case 0x46: {
			bne_rel8_partial();
			break;
		}
		case 0x47: {
			beq_rel8_partial();
			break;
		}
		case 0x48: {
			bvc_rel8_partial();
			break;
		}
		case 0x49: {
			bvs_rel8_partial();
			break;
		}
		case 0x4a: {
			bpl_rel8_partial();
			break;
		}
		case 0x4b: {
			bmi_rel8_partial();
			break;
		}
		case 0x4c: {
			bge_rel8_partial();
			break;
		}
		case 0x4d: {
			blt_rel8_partial();
			break;
		}
		case 0x4e: {
			bgt_rel8_partial();
			break;
		}
		case 0x4f: {
			ble_rel8_partial();
			break;
		}
		case 0x50: {
			mulxu_b_r8h_r16l_partial();
			break;
		}
		case 0x51: {
			divxu_b_r8h_r16l_partial();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x08) {
			case 0x00: mulxu_w_r16h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x53: {
			switch(inst_state & 0x08) {
			case 0x00: divxu_w_r16h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x54: {
			switch(inst_state & 0xff) {
			case 0x70: rts_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x55: {
			bsr_rel8_partial();
			break;
		}
		case 0x56: {
			switch(inst_state & 0xff) {
			case 0x70: rte_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x57: {
			switch(inst_state & 0xcf) {
			case 0x00: trapa_imm2_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x58: {
			switch(inst_state & 0xff) {
			case 0x00: bt_rel16_partial(); break;
			case 0x10: bf_rel16_partial(); break;
			case 0x20: bhi_rel16_partial(); break;
			case 0x30: bls_rel16_partial(); break;
			case 0x40: bcc_rel16_partial(); break;
			case 0x50: bcs_rel16_partial(); break;
			case 0x60: bne_rel16_partial(); break;
			case 0x70: beq_rel16_partial(); break;
			case 0x80: bvc_rel16_partial(); break;
			case 0x90: bvs_rel16_partial(); break;
			case 0xa0: bpl_rel16_partial(); break;
			case 0xb0: bmi_rel16_partial(); break;
			case 0xc0: bge_rel16_partial(); break;
			case 0xd0: blt_rel16_partial(); break;
			case 0xe0: bgt_rel16_partial(); break;
			case 0xf0: ble_rel16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x59: {
			switch(inst_state & 0x8f) {
			case 0x00: jmp_r32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5a: {
			jmp_abs24e_partial();
			break;
		}
		case 0x5b: {
			jmp_abs8i_partial();
			break;
		}
		case 0x5c: {
			switch(inst_state & 0xff) {
			case 0x00: bsr_rel16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5d: {
			switch(inst_state & 0x8f) {
			case 0x00: jsr_r32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5e: {
			jsr_abs24e_partial();
			break;
		}
		case 0x5f: {
			jsr_abs8i_partial();
			break;
		}
		case 0x60: {
			bset_r8h_r8l_partial();
			break;
		}
		case 0x61: {
			bnot_r8h_r8l_partial();
			break;
		}
		case 0x62: {
			bclr_r8h_r8l_partial();
			break;
		}
		case 0x63: {
			btst_r8h_r8l_partial();
			break;
		}
		case 0x64: {
			or_w_r16h_r16l_partial();
			break;
		}
		case 0x65: {
			xor_w_r16h_r16l_partial();
			break;
		}
		case 0x66: {
			and_w_r16h_r16l_partial();
			break;
		}
		case 0x67: {
			switch(inst_state & 0x80) {
			case 0x00: bst_imm3_r8l_partial(); break;
			case 0x80: bist_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x68: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32ih_r8l_partial(); break;
			case 0x80: mov_b_r8l_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x69: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32ih_r16l_partial(); break;
			case 0x80: mov_w_r16l_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6a: {
			switch(inst_state & 0xff) {
			case 0x00: case 0x01: case 0x02: case 0x03: case 0x04: case 0x05: case 0x06: case 0x07: case 0x08: case 0x09: case 0x0a: case 0x0b: case 0x0c: case 0x0d: case 0x0e: case 0x0f: mov_b_abs16_r8l_partial(); break;
			case 0x10: dispatch_6a10_partial(); break;
			case 0x18: dispatch_6a18_partial(); break;
			case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: mov_b_abs32_r8l_partial(); break;
			case 0x30: dispatch_6a30_partial(); break;
			case 0x38: dispatch_6a38_partial(); break;
			case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f: movfpe_abs16_r8l_partial(); break;
			case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: mov_b_r8l_abs16_partial(); break;
			case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: mov_b_r8l_abs32_partial(); break;
			case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: movtpe_r8l_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_abs16_r16l_partial(); break;
			case 0x20: mov_w_abs32_r16l_partial(); break;
			case 0x80: mov_w_r16l_abs16_partial(); break;
			case 0xa0: mov_w_r16l_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6c: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32ph_r8l_partial(); break;
			case 0x80: mov_b_r8l_pr32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32ph_r16l_partial(); break;
			case 0x80: mov_w_r16l_pr32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6e: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32d16h_r8l_partial(); break;
			case 0x80: mov_b_r8l_r32d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32d16h_r16l_partial(); break;
			case 0x80: mov_w_r16l_r32d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x80) {
			case 0x00: bset_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x80) {
			case 0x00: bnot_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x80) {
			case 0x00: bclr_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x80) {
			case 0x00: btst_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x80) {
			case 0x00: bor_imm3_r8l_partial(); break;
			case 0x80: bior_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x80) {
			case 0x00: bxor_imm3_r8l_partial(); break;
			case 0x80: bixor_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x80) {
			case 0x00: band_imm3_r8l_partial(); break;
			case 0x80: biand_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x80) {
			case 0x00: bld_imm3_r8l_partial(); break;
			case 0x80: bild_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7800_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x79: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_imm16_r16l_partial(); break;
			case 0x10: add_w_imm16_r16l_partial(); break;
			case 0x20: cmp_w_imm16_r16l_partial(); break;
			case 0x30: sub_w_imm16_r16l_partial(); break;
			case 0x40: or_w_imm16_r16l_partial(); break;
			case 0x50: xor_w_imm16_r16l_partial(); break;
			case 0x60: and_w_imm16_r16l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7a: {
			switch(inst_state & 0xf8) {
			case 0x00: mov_l_imm32_r32l_partial(); break;
			case 0x10: add_l_imm32_r32l_partial(); break;
			case 0x20: cmp_l_imm32_r32l_partial(); break;
			case 0x30: sub_l_imm32_r32l_partial(); break;
			case 0x40: or_l_imm32_r32l_partial(); break;
			case 0x50: xor_l_imm32_r32l_partial(); break;
			case 0x60: and_l_imm32_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7b: {
			switch(inst_state & 0xff) {
			case 0x5c: dispatch_7b5c_partial(); break;
			case 0xd4: dispatch_7bd4_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7c: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7c00_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7d: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7d00_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7e: {
			dispatch_7e00_partial();
			break;
		}
		case 0x7f: {
			dispatch_7f00_partial();
			break;
		}
		case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: {
			add_b_imm8_r8u_partial();
			break;
		}
		case 0x90: case 0x91: case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: case 0x97: case 0x98: case 0x99: case 0x9a: case 0x9b: case 0x9c: case 0x9d: case 0x9e: case 0x9f: {
			addx_b_imm8_r8u_partial();
			break;
		}
		case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: {
			cmp_b_imm8_r8u_partial();
			break;
		}
		case 0xb0: case 0xb1: case 0xb2: case 0xb3: case 0xb4: case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xba: case 0xbb: case 0xbc: case 0xbd: case 0xbe: case 0xbf: {
			subx_b_imm8_r8u_partial();
			break;
		}
		case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: {
			or_b_imm8_r8u_partial();
			break;
		}
		case 0xd0: case 0xd1: case 0xd2: case 0xd3: case 0xd4: case 0xd5: case 0xd6: case 0xd7: case 0xd8: case 0xd9: case 0xda: case 0xdb: case 0xdc: case 0xdd: case 0xde: case 0xdf: {
			xor_b_imm8_r8u_partial();
			break;
		}
		case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe4: case 0xe5: case 0xe6: case 0xe7: case 0xe8: case 0xe9: case 0xea: case 0xeb: case 0xec: case 0xed: case 0xee: case 0xef: {
			and_b_imm8_r8u_partial();
			break;
		}
		case 0xf0: case 0xf1: case 0xf2: case 0xf3: case 0xf4: case 0xf5: case 0xf6: case 0xf7: case 0xf8: case 0xf9: case 0xfa: case 0xfb: case 0xfc: case 0xfd: case 0xfe: case 0xff: {
			mov_b_imm8_r8u_partial();
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x01: {
		switch(inst_state & 0xffff) {
		case 0x00: state_reset_partial(); break;
		case 0x01: state_irq_partial(); break;
		case 0x02: state_trace_partial(); break;
		case 0x03: state_dma_partial(); break;
		case 0x04: state_dtc_partial(); break;
		case 0x05: state_dtc_vector_partial(); break;
		case 0x06: state_dtc_writeback_partial(); break;
		}
		break;
	}
	case 0x02: {
		switch((inst_state >> 8) & 0xff) {
		case 0x69: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32ih_r32l_partial(); break;
			case 0x80: mov_l_r32l_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf8) {
			case 0x00: mov_l_abs16_r32l_partial(); break;
			case 0x20: mov_l_abs32_r32l_partial(); break;
			case 0x80: mov_l_r32l_abs16_partial(); break;
			case 0xa0: mov_l_r32l_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32ph_r32l_partial(); break;
			case 0x80: mov_l_r32l_pr32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32d16h_r32l_partial(); break;
			case 0x80: mov_l_r32l_r32d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x0f) {
			case 0x00: dispatch_01007800_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x03: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xf8) {
			case 0x20: mov_l_r32d32hh_r32l_partial(); break;
			case 0xa0: mov_l_r32l_r32d32hh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x04: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6d: {
			switch(inst_state & 0xf9) {
			case 0x71: ldm_l_spp_r32n2l_partial(); break;
			case 0xf0: stm_l_r32n2l_psp_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x05: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6d: {
			switch(inst_state & 0xfb) {
			case 0x72: ldm_l_spp_r32n3l_partial(); break;
			case 0xf0: stm_l_r32n3l_psp_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x06: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6d: {
			switch(inst_state & 0xfb) {
			case 0x73: ldm_l_spp_r32n4l_partial(); break;
			case 0xf0: stm_l_r32n4l_psp_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x07: {
		switch((inst_state >> 8) & 0xff) {
		case 0x69: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ih_ccr_partial(); break;
			case 0x80: stc_w_ccr_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x00: ldc_w_abs16_ccr_partial(); break;
			case 0x20: ldc_w_abs32_ccr_partial(); break;
			case 0x80: stc_w_ccr_abs16_partial(); break;
			case 0xa0: stc_w_ccr_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ph_ccr_partial(); break;
			case 0x80: stc_w_ccr_pr32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32d16h_ccr_partial(); break;
			case 0x80: stc_w_ccr_r32d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_01407800_partial(); break;
			case 0x80: dispatch_01407880_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x08: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x20: ldc_w_r32d32hh_ccr_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x09: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0xa0: stc_w_ccr_r32d32hh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0a: {
		switch((inst_state >> 8) & 0xff) {
		case 0x04: {
			orc_imm8_exr_partial();
			break;
		}
		case 0x05: {
			xorc_imm8_exr_partial();
			break;
		}
		case 0x06: {
			andc_imm8_exr_partial();
			break;
		}
		case 0x07: {
			ldc_imm8_exr_partial();
			break;
		}
		case 0x69: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ih_exr_partial(); break;
			case 0x80: stc_w_exr_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x00: ldc_w_abs16_exr_partial(); break;
			case 0x20: ldc_w_abs32_exr_partial(); break;
			case 0x80: stc_w_exr_abs16_partial(); break;
			case 0xa0: stc_w_exr_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ph_exr_partial(); break;
			case 0x80: stc_w_exr_pr32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32d16h_exr_partial(); break;
			case 0x80: stc_w_exr_r32d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_01417800_partial(); break;
			case 0x80: dispatch_01417880_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0b: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x20: ldc_w_r32d32hh_exr_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0c: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0xa0: stc_w_exr_r32d32hh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0d: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6d: {
			switch(inst_state & 0x88) {
			case 0x00: mac_r32ph_r32pl_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0e: {
		switch((inst_state >> 8) & 0xff) {
		case 0x50: {
			mulxs_b_r8h_r16l_partial();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x08) {
			case 0x00: mulxs_w_r16h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0f: {
		switch((inst_state >> 8) & 0xff) {
		case 0x51: {
			divxs_b_r8h_r16l_partial();
			break;
		}
		case 0x53: {
			switch(inst_state & 0x08) {
			case 0x00: divxs_w_r16h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x10: {
		switch((inst_state >> 8) & 0xff) {
		case 0x7b: {
			switch(inst_state & 0xaf) {
			case 0x0c: tas_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x11: {
		switch((inst_state >> 8) & 0xff) {
		case 0x64: {
			switch(inst_state & 0x88) {
			case 0x00: or_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x65: {
			switch(inst_state & 0x88) {
			case 0x00: xor_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x66: {
			switch(inst_state & 0x88) {
			case 0x00: and_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x12: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs16_partial(); break;
			case 0x80: bior_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs16_partial(); break;
			case 0x80: bixor_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs16_partial(); break;
			case 0x80: biand_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs16_partial(); break;
			case 0x80: bild_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x13: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs16_partial(); break;
			case 0x80: bist_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x14: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs32_partial(); break;
			case 0x80: bior_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs32_partial(); break;
			case 0x80: bixor_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs32_partial(); break;
			case 0x80: biand_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs32_partial(); break;
			case 0x80: bild_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x15: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs32_partial(); break;
			case 0x80: bist_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x16: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6a: {
			switch(inst_state & 0xf0) {
			case 0x20: mov_b_r32d32hh_r8l_partial(); break;
			case 0xa0: mov_b_r8l_r32d32hh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf0) {
			case 0x20: mov_w_r32d32hh_r16l_partial(); break;
			case 0xa0: mov_w_r16l_r32d32hh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x17: {
		switch((inst_state >> 8) & 0xff) {
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x8f: eepmov_b_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x18: {
		switch((inst_state >> 8) & 0xff) {
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x8f: eepmov_w_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x19: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_r32ihh_partial(); break;
			case 0x80: bior_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_r32ihh_partial(); break;
			case 0x80: bixor_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_r32ihh_partial(); break;
			case 0x80: biand_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_r32ihh_partial(); break;
			case 0x80: bild_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1a: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_r32ihh_partial(); break;
			case 0x80: bist_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1b: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs8_partial(); break;
			case 0x80: bior_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs8_partial(); break;
			case 0x80: bixor_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs8_partial(); break;
			case 0x80: biand_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs8_partial(); break;
			case 0x80: bild_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1c: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs8_partial(); break;
			case 0x80: bist_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	}
}
