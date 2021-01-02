void h8s2000_device::ldm_l_spp_r32n2l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1], TMP2);
	if((IR[1] & 7) == 7)
		TMP1 = TMP2;
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-1, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	prefetch_done();
}

void h8s2000_device::ldm_l_spp_r32n2l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1], TMP2);
	if((IR[1] & 7) == 7)
		TMP1 = TMP2;
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-1, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stm_l_r32n2l_psp_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+1);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	write16(TMP1+2, TMP2);
	prefetch_done();
}

void h8s2000_device::stm_l_r32n2l_psp_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	write16(TMP1+2, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldm_l_spp_r32n3l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1], TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-1, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 6; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 7; return; }
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-2, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	prefetch_done();
}

void h8s2000_device::ldm_l_spp_r32n3l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1], TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-1, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-2, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stm_l_r32n3l_psp_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+1);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+2);
	if(icount <= bcount) { inst_substate = 6; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 7; return; }
	write16(TMP1+2, TMP2);
	prefetch_done();
}

void h8s2000_device::stm_l_r32n3l_psp_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+2);
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
	write16(TMP1+2, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldm_l_spp_r32n4l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1], TMP2);
	if((IR[1] & 7) == 7)
		TMP1 = TMP2;
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-1, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 6; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 7; return; }
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-2, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 8; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 9; return; }
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-3, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	prefetch_done();
}

void h8s2000_device::ldm_l_spp_r32n4l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1], TMP2);
	if((IR[1] & 7) == 7)
		TMP1 = TMP2;
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-1, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-2, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 9; return; }
	[[fallthrough]];
case 9:;
	TMP2 |= read16(TMP1+2);
	r32_w(IR[1]-3, TMP2);
	TMP1 += 4;
	r32_w(7, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stm_l_r32n4l_psp_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+1);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+2);
	if(icount <= bcount) { inst_substate = 6; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 7; return; }
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+3);
	if(icount <= bcount) { inst_substate = 8; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 9; return; }
	write16(TMP1+2, TMP2);
	prefetch_done();
}

void h8s2000_device::stm_l_r32n4l_psp_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(7);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+2);
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
	write16(TMP1+2, TMP2);
	TMP1 -= 4;
	r32_w(7, TMP1);
	TMP2 = r32_r(IR[1]+3);
	if(icount <= bcount) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 9; return; }
	[[fallthrough]];
case 9:;
	write16(TMP1+2, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::orc_imm8_exr_full()
{
	EXR |= IR[1];
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_noirq();
}

void h8s2000_device::orc_imm8_exr_partial()
{
switch(inst_substate) {
case 0:
	EXR |= IR[1];
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::xorc_imm8_exr_full()
{
	EXR ^= IR[1] & ~EXR_NC;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_noirq();
}

void h8s2000_device::xorc_imm8_exr_partial()
{
switch(inst_substate) {
case 0:
	EXR ^= IR[1] & ~EXR_NC;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::andc_imm8_exr_full()
{
	EXR &= IR[1] | EXR_NC;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_noirq();
}

void h8s2000_device::andc_imm8_exr_partial()
{
switch(inst_substate) {
case 0:
	EXR &= IR[1] | EXR_NC;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldc_imm8_exr_full()
{
	EXR = IR[1] | EXR_NC;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_noirq();
}

void h8s2000_device::ldc_imm8_exr_partial()
{
switch(inst_substate) {
case 0:
	EXR = IR[1] | EXR_NC;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldc_w_r32ih_exr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8s2000_device::ldc_w_r32ih_exr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stc_w_exr_r32ih_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
}

void h8s2000_device::stc_w_exr_r32ih_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldc_w_abs16_exr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8s2000_device::ldc_w_abs16_exr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldc_w_abs32_exr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8s2000_device::ldc_w_abs32_exr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stc_w_exr_abs16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
}

void h8s2000_device::stc_w_exr_abs16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stc_w_exr_abs32_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
}

void h8s2000_device::stc_w_exr_abs32_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldc_w_r32ph_exr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1] >> 4);
	r32_w(IR[1] >> 4, TMP1+2);
	if(icount <= bcount) { inst_substate = 2; return; }
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8s2000_device::ldc_w_r32ph_exr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1] >> 4);
	r32_w(IR[1] >> 4, TMP1+2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stc_w_exr_pr32h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1] >> 4) - 2;
	r32_w(IR[1] >> 4, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
}

void h8s2000_device::stc_w_exr_pr32h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1] >> 4) - 2;
	r32_w(IR[1] >> 4, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldc_w_r32d16h_exr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8s2000_device::ldc_w_r32d16h_exr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stc_w_exr_r32d16h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
}

void h8s2000_device::stc_w_exr_r32d16h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldc_w_r32d32hh_exr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8s2000_device::ldc_w_r32d32hh_exr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	EXR = (read16(TMP1) >> 8) | EXR_NC;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stc_w_exr_r32d32hh_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
}

void h8s2000_device::stc_w_exr_r32d32hh_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1, (EXR << 8) | EXR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::tas_r32ih_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP2 = read8(TMP1);
	set_nzv8(TMP2);
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP1, TMP2 | 0x80);
	prefetch_done();
}

void h8s2000_device::tas_r32ih_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP2 = read8(TMP1);
	set_nzv8(TMP2);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP1, TMP2 | 0x80);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::stc_exr_r8l_full()
{
	r8_w(IR[0], EXR);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::stc_exr_r8l_partial()
{
switch(inst_substate) {
case 0:
	r8_w(IR[0], EXR);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::ldc_r8l_exr_full()
{
	EXR = r8_r(IR[0]) | EXR_NC;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_noirq();
}

void h8s2000_device::ldc_r8l_exr_partial()
{
switch(inst_substate) {
case 0:
	EXR = r8_r(IR[0]) | EXR_NC;
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shll_b_two_r8l_full()
{
	r8_w(IR[0], do_shll2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shll_b_two_r8l_partial()
{
switch(inst_substate) {
case 0:
	r8_w(IR[0], do_shll2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shll_w_two_r16l_full()
{
	r16_w(IR[0], do_shll2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shll_w_two_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_shll2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shll_l_two_r32l_full()
{
	r32_w(IR[0], do_shll2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shll_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_shll2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shal_b_two_r8l_full()
{
	r8_w(IR[0], do_shal2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shal_b_two_r8l_partial()
{
switch(inst_substate) {
case 0:
	r8_w(IR[0], do_shal2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shal_w_two_r16l_full()
{
	r16_w(IR[0], do_shal2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shal_w_two_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_shal2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shal_l_two_r32l_full()
{
	r32_w(IR[0], do_shal2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shal_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_shal2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shlr_b_two_r8l_full()
{
	r8_w(IR[0], do_shlr2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shlr_b_two_r8l_partial()
{
switch(inst_substate) {
case 0:
	r8_w(IR[0], do_shlr2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shlr_w_two_r16l_full()
{
	r16_w(IR[0], do_shlr2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shlr_w_two_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_shlr2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shlr_l_two_r32l_full()
{
	r32_w(IR[0], do_shlr2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shlr_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_shlr2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shar_b_two_r8l_full()
{
	r8_w(IR[0], do_shar2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shar_b_two_r8l_partial()
{
switch(inst_substate) {
case 0:
	r8_w(IR[0], do_shar2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shar_w_two_r16l_full()
{
	r16_w(IR[0], do_shar2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shar_w_two_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_shar2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::shar_l_two_r32l_full()
{
	r32_w(IR[0], do_shar2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::shar_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_shar2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotxl_b_two_r8l_full()
{
	r8_w(IR[0], do_rotxl2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotxl_b_two_r8l_partial()
{
switch(inst_substate) {
case 0:
	r8_w(IR[0], do_rotxl2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotxl_w_two_r16l_full()
{
	r16_w(IR[0], do_rotxl2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotxl_w_two_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_rotxl2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotxl_l_two_r32l_full()
{
	r32_w(IR[0], do_rotxl2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotxl_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_rotxl2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotl_b_two_r8l_full()
{
	r8_w(IR[0], do_rotl2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotl_b_two_r8l_partial()
{
switch(inst_substate) {
case 0:
	r8_w(IR[0], do_rotl2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotl_w_two_r16l_full()
{
	r16_w(IR[0], do_rotl2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotl_w_two_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_rotl2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotl_l_two_r32l_full()
{
	r32_w(IR[0], do_rotl2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotl_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_rotl2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotxr_b_two_r8l_full()
{
	r8_w(IR[0], do_rotxr2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotxr_b_two_r8l_partial()
{
switch(inst_substate) {
case 0:
	r8_w(IR[0], do_rotxr2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotxr_w_two_r16l_full()
{
	r16_w(IR[0], do_rotxr2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotxr_w_two_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_rotxr2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotxr_l_two_r32l_full()
{
	r32_w(IR[0], do_rotxr2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotxr_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_rotxr2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotr_b_two_r8l_full()
{
	r8_w(IR[0], do_rotr2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotr_b_two_r8l_partial()
{
switch(inst_substate) {
case 0:
	r8_w(IR[0], do_rotr2_8(r8_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotr_w_two_r16l_full()
{
	r16_w(IR[0], do_rotr2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotr_w_two_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_rotr2_16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::rotr_l_two_r32l_full()
{
	r32_w(IR[0], do_rotr2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8s2000_device::rotr_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_rotr2_32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::state_trace_full()
{
	internal(1);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	write16(TMP1, NPC);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, (CCR << 8) | ((NPC >> 16) & 0xff));
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1, EXR << 8);
	taken_irq_vector = trace_setup();
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 4; return; }
		IR[0] = read16i(4*taken_irq_vector);
	if(icount <= bcount) { inst_substate = 5; return; }
		IR[1] = read16i(4*taken_irq_vector+2);
		PC = (IR[0] << 16) | IR[1];
	} else {
	if(icount <= bcount) { inst_substate = 6; return; }
		PC = read16i(2*taken_irq_vector);
	}
	internal(1);
	if(icount <= bcount) { inst_substate = 7; return; }
	prefetch_noirq();
}

void h8s2000_device::state_trace_partial()
{
switch(inst_substate) {
case 0:
	internal(1);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	write16(TMP1, NPC);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, (CCR << 8) | ((NPC >> 16) & 0xff));
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1, EXR << 8);
	taken_irq_vector = trace_setup();
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		IR[0] = read16i(4*taken_irq_vector);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
		IR[1] = read16i(4*taken_irq_vector+2);
		PC = (IR[0] << 16) | IR[1];
	} else {
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
		PC = read16i(2*taken_irq_vector);
	}
	internal(1);
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
	prefetch_noirq();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::state_dtc_full()
{
	if(current_dtc->sra & 0x01000000) {
	if(icount <= bcount) { inst_substate = 1; return; }
		TMP1 = read16(current_dtc->sra & 0xffffff);
	if(icount <= bcount) { inst_substate = 2; return; }
		write16(current_dtc->dar & 0xffffff, TMP1);
	} else {
	if(icount <= bcount) { inst_substate = 3; return; }
		TMP1 = read8(current_dtc->sra & 0xffffff);
	if(icount <= bcount) { inst_substate = 4; return; }
		write8(current_dtc->dar & 0xffffff, TMP1);
	}
	current_dtc->sra = (current_dtc->sra & 0xff000000) | ((current_dtc->sra + current_dtc->incs) & 0x00ffffff);
	current_dtc->dar = (current_dtc->dar & 0xff000000) | ((current_dtc->dar + current_dtc->incd) & 0x00ffffff);
	current_dtc->count--;
	if(!current_dtc->count) {
		uint8_t id = current_dtc->id;
		current_dtc = nullptr;
		dtc_device->count_done(id);
	}
	prefetch_done();
}

void h8s2000_device::state_dtc_partial()
{
switch(inst_substate) {
case 0:
	if(current_dtc->sra & 0x01000000) {
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
		TMP1 = read16(current_dtc->sra & 0xffffff);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
		write16(current_dtc->dar & 0xffffff, TMP1);
	} else {
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		TMP1 = read8(current_dtc->sra & 0xffffff);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		write8(current_dtc->dar & 0xffffff, TMP1);
	}
	current_dtc->sra = (current_dtc->sra & 0xff000000) | ((current_dtc->sra + current_dtc->incs) & 0x00ffffff);
	current_dtc->dar = (current_dtc->dar & 0xff000000) | ((current_dtc->dar + current_dtc->incd) & 0x00ffffff);
	current_dtc->count--;
	if(!current_dtc->count) {
		uint8_t id = current_dtc->id;
		current_dtc = nullptr;
		dtc_device->count_done(id);
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::state_dtc_vector_full()
{
	TMP1 = dtc_device->get_waiting_vector();
	if(TMP1 < h8_dtc_device::DTC_CHAINED) {
		TMP2 = dtc_device->get_vector_address(TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
		TMP2 = read16(TMP2);
		TMP2 |= 0xff0000;
	} else {
		TMP1 -= h8_dtc_device::DTC_CHAINED;
		TMP2 = dtc_device->get_object(TMP1)->base + 12;
	}
	dtc_device->get_object(TMP1)->base = TMP2;
	if(icount <= bcount) { inst_substate = 2; return; }
	dtc_device->get_object(TMP1)->sra  = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	dtc_device->get_object(TMP1)->sra |= read16(TMP2+2);
	if(icount <= bcount) { inst_substate = 4; return; }
	dtc_device->get_object(TMP1)->dar  = read16(TMP2+4) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	dtc_device->get_object(TMP1)->dar |= read16(TMP2+6);
	if(icount <= bcount) { inst_substate = 6; return; }
	dtc_device->get_object(TMP1)->cr   = read16(TMP2+8) << 16;
	if(icount <= bcount) { inst_substate = 7; return; }
	dtc_device->get_object(TMP1)->cr  |= read16(TMP2+10);
	dtc_device->vector_done(TMP1);
	prefetch_done();
}

void h8s2000_device::state_dtc_vector_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = dtc_device->get_waiting_vector();
	if(TMP1 < h8_dtc_device::DTC_CHAINED) {
		TMP2 = dtc_device->get_vector_address(TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
		TMP2 = read16(TMP2);
		TMP2 |= 0xff0000;
	} else {
		TMP1 -= h8_dtc_device::DTC_CHAINED;
		TMP2 = dtc_device->get_object(TMP1)->base + 12;
	}
	dtc_device->get_object(TMP1)->base = TMP2;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	dtc_device->get_object(TMP1)->sra  = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	dtc_device->get_object(TMP1)->sra |= read16(TMP2+2);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	dtc_device->get_object(TMP1)->dar  = read16(TMP2+4) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	dtc_device->get_object(TMP1)->dar |= read16(TMP2+6);
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
	dtc_device->get_object(TMP1)->cr   = read16(TMP2+8) << 16;
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
	dtc_device->get_object(TMP1)->cr  |= read16(TMP2+10);
	dtc_device->vector_done(TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::state_dtc_writeback_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = dtc_device->get_waiting_writeback();
	TMP2 = dtc_device->get_object(TMP1)->base;
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP2, dtc_device->get_object(TMP1)->sra >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP2+2, dtc_device->get_object(TMP1)->sra);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP2+4, dtc_device->get_object(TMP1)->dar >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	write16(TMP2+6, dtc_device->get_object(TMP1)->dar);
	if(icount <= bcount) { inst_substate = 6; return; }
	write16(TMP2+8, dtc_device->get_object(TMP1)->cr >> 16);
	if(icount <= bcount) { inst_substate = 7; return; }
	write16(TMP2+10, dtc_device->get_object(TMP1)->cr);
	if(icount <= bcount) { inst_substate = 8; return; }
	dtc_device->writeback_done(TMP1);
	prefetch_done();
}

void h8s2000_device::state_dtc_writeback_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = dtc_device->get_waiting_writeback();
	TMP2 = dtc_device->get_object(TMP1)->base;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP2, dtc_device->get_object(TMP1)->sra >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP2+2, dtc_device->get_object(TMP1)->sra);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP2+4, dtc_device->get_object(TMP1)->dar >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	write16(TMP2+6, dtc_device->get_object(TMP1)->dar);
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
	write16(TMP2+8, dtc_device->get_object(TMP1)->cr >> 16);
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
	write16(TMP2+10, dtc_device->get_object(TMP1)->cr);
	if(icount <= bcount) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:;
	dtc_device->writeback_done(TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8s2000_device::do_exec_full()
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
			case 0x80: sleep_full(); break;
			case 0xc0: dispatch_01c0_full(); break;
			case 0xd0: dispatch_01d0_full(); break;
			case 0xe0: dispatch_01e0_full(); break;
			case 0xf0: dispatch_01f0_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x02: {
			switch(inst_state & 0xf0) {
			case 0x00: stc_ccr_r8l_full(); break;
			case 0x10: stc_exr_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x03: {
			switch(inst_state & 0xf0) {
			case 0x00: ldc_r8l_ccr_full(); break;
			case 0x10: ldc_r8l_exr_full(); break;
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
void h8s2000_device::do_exec_partial()
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
			case 0x80: sleep_partial(); break;
			case 0xc0: dispatch_01c0_partial(); break;
			case 0xd0: dispatch_01d0_partial(); break;
			case 0xe0: dispatch_01e0_partial(); break;
			case 0xf0: dispatch_01f0_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x02: {
			switch(inst_state & 0xf0) {
			case 0x00: stc_ccr_r8l_partial(); break;
			case 0x10: stc_exr_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x03: {
			switch(inst_state & 0xf0) {
			case 0x00: ldc_r8l_ccr_partial(); break;
			case 0x10: ldc_r8l_exr_partial(); break;
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
