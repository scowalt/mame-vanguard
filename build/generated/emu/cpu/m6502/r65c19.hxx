void r65c19_device::adc_ipx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	do_adc(read(TMP+X));
	icount--;

	if(P & F_D) {

	if(icount == 0) { inst_substate = 6; return; }
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void r65c19_device::adc_ipx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	do_adc(read(TMP+X));
	icount--;

	if(P & F_D) {

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::add_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	do_add(TMP);

	if(P & F_D) {

	if(icount == 0) { inst_substate = 2; return; }
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void r65c19_device::add_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	do_add(TMP);

	if(P & F_D) {

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::add_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP);
	icount--;

	do_add(TMP);

	if(P & F_D) {

	if(icount == 0) { inst_substate = 3; return; }
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void r65c19_device::add_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP);
	icount--;

	do_add(TMP);

	if(P & F_D) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::add_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(uint8_t(TMP+X));
	icount--;

	do_add(TMP);

	if(P & F_D) {

	if(icount == 0) { inst_substate = 4; return; }
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void r65c19_device::add_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(uint8_t(TMP+X));
	icount--;

	do_add(TMP);

	if(P & F_D) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::and_ipx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	A &= read(TMP+X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::and_ipx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A &= read(TMP+X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::asr_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = do_asr(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void r65c19_device::asr_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = do_asr(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::bar_amr_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read_pc();
	icount--;

	TMP2 = ~TMP2 & TMP;

	if(icount == 0) { inst_substate = 6; return; }
	TMP = read_pc();
	icount--;

	if(TMP2 != 0) {

	if(icount == 0) { inst_substate = 7; return; }
		read_pc_noinc();
	icount--;

		if(page_changing(PC, int8_t(TMP))) {

	if(icount == 0) { inst_substate = 8; return; }
			read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		}

		PC += int8_t(TMP);

	}

	if(icount == 0) { inst_substate = 9; return; }
	prefetch();
	icount--;

}

void r65c19_device::bar_amr_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read_pc();
	icount--;

	TMP2 = ~TMP2 & TMP;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP = read_pc();
	icount--;

	if(TMP2 != 0) {

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
		read_pc_noinc();
	icount--;

		if(page_changing(PC, int8_t(TMP))) {

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
			read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		}

		PC += int8_t(TMP);

	}

	if(icount == 0) { inst_substate = 9; return; }
	[[fallthrough]];
case 9:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::bas_amr_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read_pc();
	icount--;

	TMP2 &= TMP;

	if(icount == 0) { inst_substate = 6; return; }
	TMP = read_pc();
	icount--;

	if(TMP2 != 0) {

	if(icount == 0) { inst_substate = 7; return; }
		read_pc_noinc();
	icount--;

		if(page_changing(PC, int8_t(TMP))) {

	if(icount == 0) { inst_substate = 8; return; }
			read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		}

		PC += int8_t(TMP);

	}

	if(icount == 0) { inst_substate = 9; return; }
	prefetch();
	icount--;

}

void r65c19_device::bas_amr_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read_pc();
	icount--;

	TMP2 &= TMP;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP = read_pc();
	icount--;

	if(TMP2 != 0) {

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
		read_pc_noinc();
	icount--;

		if(page_changing(PC, int8_t(TMP))) {

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
			read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		}

		PC += int8_t(TMP);

	}

	if(icount == 0) { inst_substate = 9; return; }
	[[fallthrough]];
case 9:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::brk_r_imp_full()
{

	if(irq_taken || nmi_pending) {

	if(icount == 0) { inst_substate = 1; return; }
		read_pc_noinc();
	icount--;

	} else {

	if(icount == 0) { inst_substate = 2; return; }
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, PC >> 8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	write(SP, PC);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 5; return; }
	write(SP, irq_taken || nmi_pending ? P & ~F_B : P);
	icount--;

	dec_SP();

	if(irq_taken && nmi_pending) {

	if(icount == 0) { inst_substate = 6; return; }
		PC = read_arg(0xfffc);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
		PC = set_h(PC, read_arg(0xfffd));
	icount--;

		nmi_pending = false;

		standard_irq_callback(NMI_LINE);

	} else {

		TMP = get_irq_vector();

	if(icount == 0) { inst_substate = 8; return; }
		PC = read_arg(TMP);
	icount--;

	if(icount == 0) { inst_substate = 9; return; }
		PC = set_h(PC, read_arg(TMP+1));
	icount--;

		if(irq_taken)

			standard_irq_callback(((~TMP & 0x000e) >> 1) - 1);

	}

	irq_taken = false;

	P = (P | F_I) & ~F_D; // Do *not* move after the prefetch

	if(icount == 0) { inst_substate = 10; return; }
	prefetch();
	icount--;

	inst_state = -1;

}

void r65c19_device::brk_r_imp_partial()
{
switch(inst_substate) {
case 0:

	if(irq_taken || nmi_pending) {

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
		read_pc_noinc();
	icount--;

	} else {

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, PC >> 8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(SP, PC);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(SP, irq_taken || nmi_pending ? P & ~F_B : P);
	icount--;

	dec_SP();

	if(irq_taken && nmi_pending) {

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
		PC = read_arg(0xfffc);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
		PC = set_h(PC, read_arg(0xfffd));
	icount--;

		nmi_pending = false;

		standard_irq_callback(NMI_LINE);

	} else {

		TMP = get_irq_vector();

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
		PC = read_arg(TMP);
	icount--;

	if(icount == 0) { inst_substate = 9; return; }
	[[fallthrough]];
case 9:
		PC = set_h(PC, read_arg(TMP+1));
	icount--;

		if(irq_taken)

			standard_irq_callback(((~TMP & 0x000e) >> 1) - 1);

	}

	irq_taken = false;

	P = (P | F_I) & ~F_D; // Do *not* move after the prefetch

	if(icount == 0) { inst_substate = 10; return; }
	[[fallthrough]];
case 10:
	prefetch();
	icount--;

	inst_state = -1;

}
	inst_substate = 0;
}


void r65c19_device::clw_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	P &= ~F_V;

	m_w = 0;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void r65c19_device::clw_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	P &= ~F_V;

	m_w = 0;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::cmp_ipx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	do_cmp(A, read(TMP+X));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::cmp_ipx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	do_cmp(A, read(TMP+X));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::eor_ipx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	A ^= read(TMP+X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::eor_ipx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A ^= read(TMP+X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::exc_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP);
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, A);
	icount--;

	A = TMP2;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void r65c19_device::exc_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read(TMP);
	icount--;

	TMP = uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(TMP, A);
	icount--;

	A = TMP2;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::ini_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(m_i);
	icount--;

	m_i++;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void r65c19_device::ini_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read(m_i);
	icount--;

	m_i++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::jpi_ind_full()
{

	m_i = PC;

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_arg(m_i);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_arg(m_i+1));
	icount--;

	m_i += 2;

	if(icount == 0) { inst_substate = 3; return; }
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	PC = set_h(PC, read(TMP+1));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void r65c19_device::jpi_ind_partial()
{
switch(inst_substate) {
case 0:

	m_i = PC;

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_arg(m_i);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = set_h(TMP, read_arg(m_i+1));
	icount--;

	m_i += 2;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	PC = set_h(PC, read(TMP+1));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::jsb_vec_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, PC);
	icount--;

	dec_SP();

	TMP = 0xffe0 | ((inst_state >> 3) & 0x0e);

	if(icount == 0) { inst_substate = 4; return; }
	PC = read_arg(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	PC = set_h(PC, read_arg(TMP+1));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::jsb_vec_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, PC);
	icount--;

	dec_SP();

	TMP = 0xffe0 | ((inst_state >> 3) & 0x0e);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	PC = read_arg(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	PC = set_h(PC, read_arg(TMP+1));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::jmp_r_ind_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	PC = set_h(PC, read(TMP+1));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void r65c19_device::jmp_r_ind_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	PC = set_h(PC, read(TMP+1));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::jsr_r_adr_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	write(SP, PC);
	icount--;

	dec_SP();

	PC = TMP;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void r65c19_device::jsr_r_adr_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(SP, PC);
	icount--;

	dec_SP();

	PC = TMP;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::lab_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_pc_noinc();
	icount--;

	if(int8_t(A) < 0)

		A = -A;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void r65c19_device::lab_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_pc_noinc();
	icount--;

	if(int8_t(A) < 0)

		A = -A;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::lai_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A = read(m_i);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void r65c19_device::lai_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	A = read(m_i);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::lan_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A = read(m_i);
	icount--;

	m_i++;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void r65c19_device::lan_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	A = read(m_i);
	icount--;

	m_i++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::lda_ipx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	A = read(TMP+X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::lda_ipx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A = read(TMP+X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::lii_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(m_i);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(m_i+1));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(TMP);
	icount--;

	m_i = TMP;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void r65c19_device::lii_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(m_i);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(m_i+1));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(TMP);
	icount--;

	m_i = TMP;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::mpa_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read_pc_noinc();
	icount--;

	TMP = int8_t(A) * int8_t(Y);

	m_w = do_accumulate(TMP, m_w);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::mpa_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read_pc_noinc();
	icount--;

	TMP = int8_t(A) * int8_t(Y);

	m_w = do_accumulate(TMP, m_w);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::mpy_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read_pc_noinc();
	icount--;

	TMP = int8_t(A) * int8_t(Y);

	A = do_accumulate(TMP, 0)>>8;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::mpy_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read_pc_noinc();
	icount--;

	TMP = int8_t(A) * int8_t(Y);

	A = do_accumulate(TMP, 0)>>8;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::neg_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = -A;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void r65c19_device::neg_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = -A;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::nxt_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	PC = read(m_i);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	PC = set_h(PC, read(m_i+1));
	icount--;

	m_i += 2;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void r65c19_device::nxt_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	PC = read(m_i);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	PC = set_h(PC, read(m_i+1));
	icount--;

	m_i += 2;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::ora_ipx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	A |= read(TMP+X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::ora_ipx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A |= read(TMP+X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::phi_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, m_i>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, m_i);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void r65c19_device::phi_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write(SP, m_i>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, m_i);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::phw_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, m_w>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, m_w);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void r65c19_device::phw_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write(SP, m_w>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, m_w);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::pia_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	m_i = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	m_i = set_h(m_i, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	A = read(m_i);
	icount--;

	m_i++;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::pia_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	m_i = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	m_i = set_h(m_i, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A = read(m_i);
	icount--;

	m_i++;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::pli_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	m_i = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	m_i = set_h(m_i, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read(m_i);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::pli_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	m_i = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	m_i = set_h(m_i, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read(m_i);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::plw_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	m_w = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	m_w = set_h(m_w, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void r65c19_device::plw_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	m_w = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	m_w = set_h(m_w, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::psh_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, A);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, X);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	write(SP, Y);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void r65c19_device::psh_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write(SP, A);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, X);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(SP, Y);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::pul_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	Y = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	X = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 5; return; }
	A = read(SP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::pul_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	Y = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	X = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A = read(SP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::rba_ima_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	A = read_pc(); // "Note that Accumulator contents are altered by RBA and SBA" (C29/C39 Technical Reference Manual, p. C-29)
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read(TMP);
	icount--;

	TMP2 &= ~A;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void r65c19_device::rba_ima_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	A = read_pc(); // "Note that Accumulator contents are altered by RBA and SBA" (C29/C39 Technical Reference Manual, p. C-29)
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read(TMP);
	icount--;

	TMP2 &= ~A;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::rnd_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	TMP = set_l(m_w, Y);

	A = do_accumulate(TMP, (m_w<<1) & 0x100)>>8;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void r65c19_device::rnd_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	TMP = set_l(m_w, Y);

	A = do_accumulate(TMP, (m_w<<1) & 0x100)>>8;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::rts_r_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_pc_noinc();
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	PC = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	PC = set_h(PC, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void r65c19_device::rts_r_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_pc_noinc();
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	PC = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	PC = set_h(PC, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::sba_ima_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	A = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read(TMP);
	icount--;

	TMP2 |= A;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void r65c19_device::sba_ima_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	A = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read(TMP);
	icount--;

	TMP2 |= A;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::sbc_ipx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	do_sbc(read(TMP+X));
	icount--;

	if(P & F_D) {

	if(icount == 0) { inst_substate = 6; return; }
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void r65c19_device::sbc_ipx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	do_sbc(read(TMP+X));
	icount--;

	if(P & F_D) {

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
		read_pc_noinc();
	icount--;

		set_nz(A);

	}

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::sta_ipx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(set_l(TMP, TMP+X));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP+X, A);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void r65c19_device::sta_ipx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(set_l(TMP, TMP+X));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(TMP+X, A);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::sti_imz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP2, TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void r65c19_device::sti_imz_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP2, TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::taw_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	m_w = A<<8;

	set_nz(m_w>>8);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void r65c19_device::taw_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	m_w = A<<8;

	set_nz(m_w>>8);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::tip_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	PC = m_i;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void r65c19_device::tip_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	PC = m_i;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::twa_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = m_w>>8;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void r65c19_device::twa_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = m_w>>8;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void r65c19_device::reset_r_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read(SP); dec_SP();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(SP); dec_SP();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read(SP); dec_SP();
	icount--;

	P = (P | F_I) & ~F_D;

	if(icount == 0) { inst_substate = 6; return; }
	PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	PC = set_h(PC, read_arg(0xffff));
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

	inst_state = -1;

}

void r65c19_device::reset_r_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read(SP); dec_SP();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(SP); dec_SP();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read(SP); dec_SP();
	icount--;

	P = (P | F_I) & ~F_D;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	PC = set_h(PC, read_arg(0xffff));
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

	inst_state = -1;

}
	inst_substate = 0;
}




void r65c19_device::do_exec_full()
{
	switch(inst_state) {

	case 0x00: brk_r_imp_full(); break;
	case 0x01: ora_zpi_full(); break;
	case 0x02: mpy_imp_full(); break;
	case 0x03: tip_imp_full(); break;
	case 0x04: nop_zpg_full(); break;
	case 0x05: ora_zpg_full(); break;
	case 0x06: asl_c_zpg_full(); break;
	case 0x07: rmb_bzp_full(); break;
	case 0x08: php_imp_full(); break;
	case 0x09: ora_imm_full(); break;
	case 0x0a: asl_acc_full(); break;
	case 0x0b: jsb_vec_full(); break;
	case 0x0c: jpi_ind_full(); break;
	case 0x0d: ora_aba_full(); break;
	case 0x0e: asl_c_aba_full(); break;
	case 0x0f: bbr_zpb_full(); break;
	case 0x10: bpl_rel_full(); break;
	case 0x11: ora_ipx_full(); break;
	case 0x12: mpa_imp_full(); break;
	case 0x13: lab_acc_full(); break;
	case 0x14: nop_zpx_full(); break;
	case 0x15: ora_zpx_full(); break;
	case 0x16: asl_c_zpx_full(); break;
	case 0x17: rmb_bzp_full(); break;
	case 0x18: clc_imp_full(); break;
	case 0x19: ora_aby_full(); break;
	case 0x1a: neg_acc_full(); break;
	case 0x1b: jsb_vec_full(); break;
	case 0x1c: nop_c_abx_full(); break;
	case 0x1d: ora_abx_full(); break;
	case 0x1e: asl_c_abx_full(); break;
	case 0x1f: bbr_zpb_full(); break;
	case 0x20: jsr_r_adr_full(); break;
	case 0x21: and_zpi_full(); break;
	case 0x22: psh_imp_full(); break;
	case 0x23: phw_imp_full(); break;
	case 0x24: bit_zpg_full(); break;
	case 0x25: and_zpg_full(); break;
	case 0x26: rol_c_zpg_full(); break;
	case 0x27: rmb_bzp_full(); break;
	case 0x28: plp_imp_full(); break;
	case 0x29: and_imm_full(); break;
	case 0x2a: rol_acc_full(); break;
	case 0x2b: jsb_vec_full(); break;
	case 0x2c: bit_aba_full(); break;
	case 0x2d: and_aba_full(); break;
	case 0x2e: rol_c_aba_full(); break;
	case 0x2f: bbr_zpb_full(); break;
	case 0x30: bmi_rel_full(); break;
	case 0x31: and_ipx_full(); break;
	case 0x32: pul_imp_full(); break;
	case 0x33: plw_imp_full(); break;
	case 0x34: nop_zpx_full(); break;
	case 0x35: and_zpx_full(); break;
	case 0x36: rol_c_zpx_full(); break;
	case 0x37: rmb_bzp_full(); break;
	case 0x38: sec_imp_full(); break;
	case 0x39: and_aby_full(); break;
	case 0x3a: asr_acc_full(); break;
	case 0x3b: jsb_vec_full(); break;
	case 0x3c: nop_c_abx_full(); break;
	case 0x3d: and_abx_full(); break;
	case 0x3e: rol_c_abx_full(); break;
	case 0x3f: bbr_zpb_full(); break;
	case 0x40: rti_imp_full(); break;
	case 0x41: eor_zpi_full(); break;
	case 0x42: rnd_imp_full(); break;
	case 0x43: nop_c_imp_full(); break;
	case 0x44: nop_zpg_full(); break;
	case 0x45: eor_zpg_full(); break;
	case 0x46: lsr_c_zpg_full(); break;
	case 0x47: rmb_bzp_full(); break;
	case 0x48: pha_imp_full(); break;
	case 0x49: eor_imm_full(); break;
	case 0x4a: lsr_acc_full(); break;
	case 0x4b: jsb_vec_full(); break;
	case 0x4c: jmp_adr_full(); break;
	case 0x4d: eor_aba_full(); break;
	case 0x4e: lsr_c_aba_full(); break;
	case 0x4f: bbr_zpb_full(); break;
	case 0x50: bvc_rel_full(); break;
	case 0x51: eor_ipx_full(); break;
	case 0x52: clw_imp_full(); break;
	case 0x53: nop_c_imp_full(); break;
	case 0x54: nop_zpx_full(); break;
	case 0x55: eor_zpx_full(); break;
	case 0x56: lsr_c_zpx_full(); break;
	case 0x57: rmb_bzp_full(); break;
	case 0x58: cli_imp_full(); break;
	case 0x59: eor_aby_full(); break;
	case 0x5a: phy_imp_full(); break;
	case 0x5b: jsb_vec_full(); break;
	case 0x5c: nop_c_abx_full(); break;
	case 0x5d: eor_abx_full(); break;
	case 0x5e: lsr_c_abx_full(); break;
	case 0x5f: bbr_zpb_full(); break;
	case 0x60: rts_r_imp_full(); break;
	case 0x61: adc_c_zpi_full(); break;
	case 0x62: taw_imp_full(); break;
	case 0x63: nop_c_imp_full(); break;
	case 0x64: add_zpg_full(); break;
	case 0x65: adc_c_zpg_full(); break;
	case 0x66: ror_c_zpg_full(); break;
	case 0x67: rmb_bzp_full(); break;
	case 0x68: pla_imp_full(); break;
	case 0x69: adc_c_imm_full(); break;
	case 0x6a: ror_acc_full(); break;
	case 0x6b: jsb_vec_full(); break;
	case 0x6c: jmp_r_ind_full(); break;
	case 0x6d: adc_c_aba_full(); break;
	case 0x6e: ror_c_aba_full(); break;
	case 0x6f: bbr_zpb_full(); break;
	case 0x70: bvs_rel_full(); break;
	case 0x71: adc_ipx_full(); break;
	case 0x72: twa_imp_full(); break;
	case 0x73: nop_c_imp_full(); break;
	case 0x74: add_zpx_full(); break;
	case 0x75: adc_c_zpx_full(); break;
	case 0x76: ror_c_zpx_full(); break;
	case 0x77: rmb_bzp_full(); break;
	case 0x78: sei_imp_full(); break;
	case 0x79: adc_c_aby_full(); break;
	case 0x7a: ply_imp_full(); break;
	case 0x7b: jsb_vec_full(); break;
	case 0x7c: jmp_iax_full(); break;
	case 0x7d: adc_c_abx_full(); break;
	case 0x7e: ror_c_abx_full(); break;
	case 0x7f: bbr_zpb_full(); break;
	case 0x80: bra_rel_full(); break;
	case 0x81: sta_zpi_full(); break;
	case 0x82: nop_imm_full(); break;
	case 0x83: nop_c_imp_full(); break;
	case 0x84: sty_zpg_full(); break;
	case 0x85: sta_zpg_full(); break;
	case 0x86: stx_zpg_full(); break;
	case 0x87: smb_bzp_full(); break;
	case 0x88: dey_imp_full(); break;
	case 0x89: add_imm_full(); break;
	case 0x8a: txa_imp_full(); break;
	case 0x8b: nxt_imp_full(); break;
	case 0x8c: sty_aba_full(); break;
	case 0x8d: sta_aba_full(); break;
	case 0x8e: stx_aba_full(); break;
	case 0x8f: bbs_zpb_full(); break;
	case 0x90: bcc_rel_full(); break;
	case 0x91: sta_ipx_full(); break;
	case 0x92: nop_imm_full(); break;
	case 0x93: nop_c_imp_full(); break;
	case 0x94: sty_zpx_full(); break;
	case 0x95: sta_zpx_full(); break;
	case 0x96: stx_zpy_full(); break;
	case 0x97: smb_bzp_full(); break;
	case 0x98: tya_imp_full(); break;
	case 0x99: sta_aby_full(); break;
	case 0x9a: txs_imp_full(); break;
	case 0x9b: lii_imp_full(); break;
	case 0x9c: nop_c_abx_full(); break;
	case 0x9d: sta_abx_full(); break;
	case 0x9e: nop_c_abx_full(); break;
	case 0x9f: bbs_zpb_full(); break;
	case 0xa0: ldy_imm_full(); break;
	case 0xa1: lda_zpi_full(); break;
	case 0xa2: ldx_imm_full(); break;
	case 0xa3: nop_c_imp_full(); break;
	case 0xa4: ldy_zpg_full(); break;
	case 0xa5: lda_zpg_full(); break;
	case 0xa6: ldx_zpg_full(); break;
	case 0xa7: smb_bzp_full(); break;
	case 0xa8: tay_imp_full(); break;
	case 0xa9: lda_imm_full(); break;
	case 0xaa: tax_imp_full(); break;
	case 0xab: lan_imp_full(); break;
	case 0xac: ldy_aba_full(); break;
	case 0xad: lda_aba_full(); break;
	case 0xae: ldx_aba_full(); break;
	case 0xaf: bbs_zpb_full(); break;
	case 0xb0: bcs_rel_full(); break;
	case 0xb1: lda_ipx_full(); break;
	case 0xb2: sti_imz_full(); break;
	case 0xb3: nop_c_imp_full(); break;
	case 0xb4: ldy_zpx_full(); break;
	case 0xb5: lda_zpx_full(); break;
	case 0xb6: ldx_zpy_full(); break;
	case 0xb7: smb_bzp_full(); break;
	case 0xb8: clv_imp_full(); break;
	case 0xb9: lda_aby_full(); break;
	case 0xba: tsx_imp_full(); break;
	case 0xbb: ini_imp_full(); break;
	case 0xbc: ldy_abx_full(); break;
	case 0xbd: lda_abx_full(); break;
	case 0xbe: ldx_aby_full(); break;
	case 0xbf: bbs_zpb_full(); break;
	case 0xc0: cpy_imm_full(); break;
	case 0xc1: cmp_zpi_full(); break;
	case 0xc2: rba_ima_full(); break;
	case 0xc3: nop_c_imp_full(); break;
	case 0xc4: cpy_zpg_full(); break;
	case 0xc5: cmp_zpg_full(); break;
	case 0xc6: dec_c_zpg_full(); break;
	case 0xc7: smb_bzp_full(); break;
	case 0xc8: iny_imp_full(); break;
	case 0xc9: cmp_imm_full(); break;
	case 0xca: dex_imp_full(); break;
	case 0xcb: phi_imp_full(); break;
	case 0xcc: cpy_aba_full(); break;
	case 0xcd: cmp_aba_full(); break;
	case 0xce: dec_c_aba_full(); break;
	case 0xcf: bbs_zpb_full(); break;
	case 0xd0: bne_rel_full(); break;
	case 0xd1: cmp_ipx_full(); break;
	case 0xd2: sba_ima_full(); break;
	case 0xd3: nop_c_imp_full(); break;
	case 0xd4: exc_zpx_full(); break;
	case 0xd5: cmp_zpx_full(); break;
	case 0xd6: dec_c_zpx_full(); break;
	case 0xd7: smb_bzp_full(); break;
	case 0xd8: cld_imp_full(); break;
	case 0xd9: cmp_aby_full(); break;
	case 0xda: phx_imp_full(); break;
	case 0xdb: pli_imp_full(); break;
	case 0xdc: nop_c_abx_full(); break;
	case 0xdd: cmp_abx_full(); break;
	case 0xde: dec_c_abx_full(); break;
	case 0xdf: bbs_zpb_full(); break;
	case 0xe0: cpx_imm_full(); break;
	case 0xe1: sbc_c_zpi_full(); break;
	case 0xe2: bar_amr_full(); break;
	case 0xe3: nop_c_imp_full(); break;
	case 0xe4: cpx_zpg_full(); break;
	case 0xe5: sbc_c_zpg_full(); break;
	case 0xe6: inc_c_zpg_full(); break;
	case 0xe7: smb_bzp_full(); break;
	case 0xe8: inx_imp_full(); break;
	case 0xe9: sbc_c_imm_full(); break;
	case 0xea: nop_imp_full(); break;
	case 0xeb: lai_imp_full(); break;
	case 0xec: cpx_aba_full(); break;
	case 0xed: sbc_c_aba_full(); break;
	case 0xee: inc_c_aba_full(); break;
	case 0xef: bbs_zpb_full(); break;
	case 0xf0: beq_rel_full(); break;
	case 0xf1: sbc_ipx_full(); break;
	case 0xf2: bas_amr_full(); break;
	case 0xf3: nop_c_imp_full(); break;
	case 0xf4: nop_zpx_full(); break;
	case 0xf5: sbc_c_zpx_full(); break;
	case 0xf6: inc_c_zpx_full(); break;
	case 0xf7: smb_bzp_full(); break;
	case 0xf8: sed_imp_full(); break;
	case 0xf9: sbc_c_aby_full(); break;
	case 0xfa: plx_imp_full(); break;
	case 0xfb: pia_imp_full(); break;
	case 0xfc: nop_c_abx_full(); break;
	case 0xfd: sbc_c_abx_full(); break;
	case 0xfe: inc_c_abx_full(); break;
	case 0xff: bbs_zpb_full(); break;
	case STATE_RESET: reset_r_full(); break;
	}
}

void r65c19_device::do_exec_partial()
{
	switch(inst_state) {

	case 0x00: brk_r_imp_partial(); break;
	case 0x01: ora_zpi_partial(); break;
	case 0x02: mpy_imp_partial(); break;
	case 0x03: tip_imp_partial(); break;
	case 0x04: nop_zpg_partial(); break;
	case 0x05: ora_zpg_partial(); break;
	case 0x06: asl_c_zpg_partial(); break;
	case 0x07: rmb_bzp_partial(); break;
	case 0x08: php_imp_partial(); break;
	case 0x09: ora_imm_partial(); break;
	case 0x0a: asl_acc_partial(); break;
	case 0x0b: jsb_vec_partial(); break;
	case 0x0c: jpi_ind_partial(); break;
	case 0x0d: ora_aba_partial(); break;
	case 0x0e: asl_c_aba_partial(); break;
	case 0x0f: bbr_zpb_partial(); break;
	case 0x10: bpl_rel_partial(); break;
	case 0x11: ora_ipx_partial(); break;
	case 0x12: mpa_imp_partial(); break;
	case 0x13: lab_acc_partial(); break;
	case 0x14: nop_zpx_partial(); break;
	case 0x15: ora_zpx_partial(); break;
	case 0x16: asl_c_zpx_partial(); break;
	case 0x17: rmb_bzp_partial(); break;
	case 0x18: clc_imp_partial(); break;
	case 0x19: ora_aby_partial(); break;
	case 0x1a: neg_acc_partial(); break;
	case 0x1b: jsb_vec_partial(); break;
	case 0x1c: nop_c_abx_partial(); break;
	case 0x1d: ora_abx_partial(); break;
	case 0x1e: asl_c_abx_partial(); break;
	case 0x1f: bbr_zpb_partial(); break;
	case 0x20: jsr_r_adr_partial(); break;
	case 0x21: and_zpi_partial(); break;
	case 0x22: psh_imp_partial(); break;
	case 0x23: phw_imp_partial(); break;
	case 0x24: bit_zpg_partial(); break;
	case 0x25: and_zpg_partial(); break;
	case 0x26: rol_c_zpg_partial(); break;
	case 0x27: rmb_bzp_partial(); break;
	case 0x28: plp_imp_partial(); break;
	case 0x29: and_imm_partial(); break;
	case 0x2a: rol_acc_partial(); break;
	case 0x2b: jsb_vec_partial(); break;
	case 0x2c: bit_aba_partial(); break;
	case 0x2d: and_aba_partial(); break;
	case 0x2e: rol_c_aba_partial(); break;
	case 0x2f: bbr_zpb_partial(); break;
	case 0x30: bmi_rel_partial(); break;
	case 0x31: and_ipx_partial(); break;
	case 0x32: pul_imp_partial(); break;
	case 0x33: plw_imp_partial(); break;
	case 0x34: nop_zpx_partial(); break;
	case 0x35: and_zpx_partial(); break;
	case 0x36: rol_c_zpx_partial(); break;
	case 0x37: rmb_bzp_partial(); break;
	case 0x38: sec_imp_partial(); break;
	case 0x39: and_aby_partial(); break;
	case 0x3a: asr_acc_partial(); break;
	case 0x3b: jsb_vec_partial(); break;
	case 0x3c: nop_c_abx_partial(); break;
	case 0x3d: and_abx_partial(); break;
	case 0x3e: rol_c_abx_partial(); break;
	case 0x3f: bbr_zpb_partial(); break;
	case 0x40: rti_imp_partial(); break;
	case 0x41: eor_zpi_partial(); break;
	case 0x42: rnd_imp_partial(); break;
	case 0x43: nop_c_imp_partial(); break;
	case 0x44: nop_zpg_partial(); break;
	case 0x45: eor_zpg_partial(); break;
	case 0x46: lsr_c_zpg_partial(); break;
	case 0x47: rmb_bzp_partial(); break;
	case 0x48: pha_imp_partial(); break;
	case 0x49: eor_imm_partial(); break;
	case 0x4a: lsr_acc_partial(); break;
	case 0x4b: jsb_vec_partial(); break;
	case 0x4c: jmp_adr_partial(); break;
	case 0x4d: eor_aba_partial(); break;
	case 0x4e: lsr_c_aba_partial(); break;
	case 0x4f: bbr_zpb_partial(); break;
	case 0x50: bvc_rel_partial(); break;
	case 0x51: eor_ipx_partial(); break;
	case 0x52: clw_imp_partial(); break;
	case 0x53: nop_c_imp_partial(); break;
	case 0x54: nop_zpx_partial(); break;
	case 0x55: eor_zpx_partial(); break;
	case 0x56: lsr_c_zpx_partial(); break;
	case 0x57: rmb_bzp_partial(); break;
	case 0x58: cli_imp_partial(); break;
	case 0x59: eor_aby_partial(); break;
	case 0x5a: phy_imp_partial(); break;
	case 0x5b: jsb_vec_partial(); break;
	case 0x5c: nop_c_abx_partial(); break;
	case 0x5d: eor_abx_partial(); break;
	case 0x5e: lsr_c_abx_partial(); break;
	case 0x5f: bbr_zpb_partial(); break;
	case 0x60: rts_r_imp_partial(); break;
	case 0x61: adc_c_zpi_partial(); break;
	case 0x62: taw_imp_partial(); break;
	case 0x63: nop_c_imp_partial(); break;
	case 0x64: add_zpg_partial(); break;
	case 0x65: adc_c_zpg_partial(); break;
	case 0x66: ror_c_zpg_partial(); break;
	case 0x67: rmb_bzp_partial(); break;
	case 0x68: pla_imp_partial(); break;
	case 0x69: adc_c_imm_partial(); break;
	case 0x6a: ror_acc_partial(); break;
	case 0x6b: jsb_vec_partial(); break;
	case 0x6c: jmp_r_ind_partial(); break;
	case 0x6d: adc_c_aba_partial(); break;
	case 0x6e: ror_c_aba_partial(); break;
	case 0x6f: bbr_zpb_partial(); break;
	case 0x70: bvs_rel_partial(); break;
	case 0x71: adc_ipx_partial(); break;
	case 0x72: twa_imp_partial(); break;
	case 0x73: nop_c_imp_partial(); break;
	case 0x74: add_zpx_partial(); break;
	case 0x75: adc_c_zpx_partial(); break;
	case 0x76: ror_c_zpx_partial(); break;
	case 0x77: rmb_bzp_partial(); break;
	case 0x78: sei_imp_partial(); break;
	case 0x79: adc_c_aby_partial(); break;
	case 0x7a: ply_imp_partial(); break;
	case 0x7b: jsb_vec_partial(); break;
	case 0x7c: jmp_iax_partial(); break;
	case 0x7d: adc_c_abx_partial(); break;
	case 0x7e: ror_c_abx_partial(); break;
	case 0x7f: bbr_zpb_partial(); break;
	case 0x80: bra_rel_partial(); break;
	case 0x81: sta_zpi_partial(); break;
	case 0x82: nop_imm_partial(); break;
	case 0x83: nop_c_imp_partial(); break;
	case 0x84: sty_zpg_partial(); break;
	case 0x85: sta_zpg_partial(); break;
	case 0x86: stx_zpg_partial(); break;
	case 0x87: smb_bzp_partial(); break;
	case 0x88: dey_imp_partial(); break;
	case 0x89: add_imm_partial(); break;
	case 0x8a: txa_imp_partial(); break;
	case 0x8b: nxt_imp_partial(); break;
	case 0x8c: sty_aba_partial(); break;
	case 0x8d: sta_aba_partial(); break;
	case 0x8e: stx_aba_partial(); break;
	case 0x8f: bbs_zpb_partial(); break;
	case 0x90: bcc_rel_partial(); break;
	case 0x91: sta_ipx_partial(); break;
	case 0x92: nop_imm_partial(); break;
	case 0x93: nop_c_imp_partial(); break;
	case 0x94: sty_zpx_partial(); break;
	case 0x95: sta_zpx_partial(); break;
	case 0x96: stx_zpy_partial(); break;
	case 0x97: smb_bzp_partial(); break;
	case 0x98: tya_imp_partial(); break;
	case 0x99: sta_aby_partial(); break;
	case 0x9a: txs_imp_partial(); break;
	case 0x9b: lii_imp_partial(); break;
	case 0x9c: nop_c_abx_partial(); break;
	case 0x9d: sta_abx_partial(); break;
	case 0x9e: nop_c_abx_partial(); break;
	case 0x9f: bbs_zpb_partial(); break;
	case 0xa0: ldy_imm_partial(); break;
	case 0xa1: lda_zpi_partial(); break;
	case 0xa2: ldx_imm_partial(); break;
	case 0xa3: nop_c_imp_partial(); break;
	case 0xa4: ldy_zpg_partial(); break;
	case 0xa5: lda_zpg_partial(); break;
	case 0xa6: ldx_zpg_partial(); break;
	case 0xa7: smb_bzp_partial(); break;
	case 0xa8: tay_imp_partial(); break;
	case 0xa9: lda_imm_partial(); break;
	case 0xaa: tax_imp_partial(); break;
	case 0xab: lan_imp_partial(); break;
	case 0xac: ldy_aba_partial(); break;
	case 0xad: lda_aba_partial(); break;
	case 0xae: ldx_aba_partial(); break;
	case 0xaf: bbs_zpb_partial(); break;
	case 0xb0: bcs_rel_partial(); break;
	case 0xb1: lda_ipx_partial(); break;
	case 0xb2: sti_imz_partial(); break;
	case 0xb3: nop_c_imp_partial(); break;
	case 0xb4: ldy_zpx_partial(); break;
	case 0xb5: lda_zpx_partial(); break;
	case 0xb6: ldx_zpy_partial(); break;
	case 0xb7: smb_bzp_partial(); break;
	case 0xb8: clv_imp_partial(); break;
	case 0xb9: lda_aby_partial(); break;
	case 0xba: tsx_imp_partial(); break;
	case 0xbb: ini_imp_partial(); break;
	case 0xbc: ldy_abx_partial(); break;
	case 0xbd: lda_abx_partial(); break;
	case 0xbe: ldx_aby_partial(); break;
	case 0xbf: bbs_zpb_partial(); break;
	case 0xc0: cpy_imm_partial(); break;
	case 0xc1: cmp_zpi_partial(); break;
	case 0xc2: rba_ima_partial(); break;
	case 0xc3: nop_c_imp_partial(); break;
	case 0xc4: cpy_zpg_partial(); break;
	case 0xc5: cmp_zpg_partial(); break;
	case 0xc6: dec_c_zpg_partial(); break;
	case 0xc7: smb_bzp_partial(); break;
	case 0xc8: iny_imp_partial(); break;
	case 0xc9: cmp_imm_partial(); break;
	case 0xca: dex_imp_partial(); break;
	case 0xcb: phi_imp_partial(); break;
	case 0xcc: cpy_aba_partial(); break;
	case 0xcd: cmp_aba_partial(); break;
	case 0xce: dec_c_aba_partial(); break;
	case 0xcf: bbs_zpb_partial(); break;
	case 0xd0: bne_rel_partial(); break;
	case 0xd1: cmp_ipx_partial(); break;
	case 0xd2: sba_ima_partial(); break;
	case 0xd3: nop_c_imp_partial(); break;
	case 0xd4: exc_zpx_partial(); break;
	case 0xd5: cmp_zpx_partial(); break;
	case 0xd6: dec_c_zpx_partial(); break;
	case 0xd7: smb_bzp_partial(); break;
	case 0xd8: cld_imp_partial(); break;
	case 0xd9: cmp_aby_partial(); break;
	case 0xda: phx_imp_partial(); break;
	case 0xdb: pli_imp_partial(); break;
	case 0xdc: nop_c_abx_partial(); break;
	case 0xdd: cmp_abx_partial(); break;
	case 0xde: dec_c_abx_partial(); break;
	case 0xdf: bbs_zpb_partial(); break;
	case 0xe0: cpx_imm_partial(); break;
	case 0xe1: sbc_c_zpi_partial(); break;
	case 0xe2: bar_amr_partial(); break;
	case 0xe3: nop_c_imp_partial(); break;
	case 0xe4: cpx_zpg_partial(); break;
	case 0xe5: sbc_c_zpg_partial(); break;
	case 0xe6: inc_c_zpg_partial(); break;
	case 0xe7: smb_bzp_partial(); break;
	case 0xe8: inx_imp_partial(); break;
	case 0xe9: sbc_c_imm_partial(); break;
	case 0xea: nop_imp_partial(); break;
	case 0xeb: lai_imp_partial(); break;
	case 0xec: cpx_aba_partial(); break;
	case 0xed: sbc_c_aba_partial(); break;
	case 0xee: inc_c_aba_partial(); break;
	case 0xef: bbs_zpb_partial(); break;
	case 0xf0: beq_rel_partial(); break;
	case 0xf1: sbc_ipx_partial(); break;
	case 0xf2: bas_amr_partial(); break;
	case 0xf3: nop_c_imp_partial(); break;
	case 0xf4: nop_zpx_partial(); break;
	case 0xf5: sbc_c_zpx_partial(); break;
	case 0xf6: inc_c_zpx_partial(); break;
	case 0xf7: smb_bzp_partial(); break;
	case 0xf8: sed_imp_partial(); break;
	case 0xf9: sbc_c_aby_partial(); break;
	case 0xfa: plx_imp_partial(); break;
	case 0xfb: pia_imp_partial(); break;
	case 0xfc: nop_c_abx_partial(); break;
	case 0xfd: sbc_c_abx_partial(); break;
	case 0xfe: inc_c_abx_partial(); break;
	case 0xff: bbs_zpb_partial(); break;
	case STATE_RESET: reset_r_partial(); break;
	}
}

