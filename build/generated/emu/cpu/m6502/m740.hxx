void m740_device::set_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	P |= F_T;

	inst_state_base = 0x100;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m740_device::set_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	P |= F_T;

	inst_state_base = 0x100;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::clt_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	P &= ~F_T;

	inst_state_base = 0;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m740_device::clt_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	P &= ~F_T;

	inst_state_base = 0;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ldm_imz_full()
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

void m740_device::ldm_imz_partial()
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


void m740_device::jsr_spg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(SP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	write(SP, PC);
	icount--;

	dec_SP();

	TMP = set_h(TMP, 0xff);

	PC = TMP;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::jsr_spg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read(SP);
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

	TMP = set_h(TMP, 0xff);

	PC = TMP;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::clb_bac_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = do_clb(A, (IR>>5) & 7);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m740_device::clb_bac_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = do_clb(A, (IR>>5) & 7);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::seb_bac_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A = do_seb(A, (IR>>5) & 7);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m740_device::seb_bac_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A = do_seb(A, (IR>>5) & 7);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::clb_biz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read(TMP);
	icount--;

	TMP2 = do_clb(TMP2, (IR>>5) & 7);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::clb_biz_partial()
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
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read(TMP);
	icount--;

	TMP2 = do_clb(TMP2, (IR>>5) & 7);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::seb_biz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read(TMP);
	icount--;

	TMP2 = do_seb(TMP2, (IR>>5) & 7);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::seb_biz_partial()
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
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read(TMP);
	icount--;

	TMP2 = do_seb(TMP2, (IR>>5) & 7);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::bbc_bzr_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read_pc_noinc();
	icount--;

	if(!(TMP2 & (1 << ((IR>>5) & 7)))) {

	if(icount == 0) { inst_substate = 4; return; }
		TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
		read_arg(set_l(PC, PC+1));
	icount--;

		PC++;

	if(icount == 0) { inst_substate = 6; return; }
		read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		PC += int8_t(TMP);

	} else {

	if(icount == 0) { inst_substate = 7; return; }
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::bbc_bzr_partial()
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
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read_pc_noinc();
	icount--;

	if(!(TMP2 & (1 << ((IR>>5) & 7)))) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
		read_arg(set_l(PC, PC+1));
	icount--;

		PC++;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
		read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		PC += int8_t(TMP);

	} else {

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::bbs_bzr_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read_pc_noinc();
	icount--;

	if(TMP2 & (1 << ((IR>>5) & 7))) {

	if(icount == 0) { inst_substate = 4; return; }
		TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
		read_arg(set_l(PC, PC+1));
	icount--;

		PC++;

	if(icount == 0) { inst_substate = 6; return; }
		read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		PC += int8_t(TMP);

	} else {

	if(icount == 0) { inst_substate = 7; return; }
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::bbs_bzr_partial()
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
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read_pc_noinc();
	icount--;

	if(TMP2 & (1 << ((IR>>5) & 7))) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
		read_arg(set_l(PC, PC+1));
	icount--;

		PC++;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
		read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		PC += int8_t(TMP);

	} else {

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::bbc_bar_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_pc_noinc();
	icount--;

	if(!(A & (1 << ((IR>>5) & 7)))) {

	if(icount == 0) { inst_substate = 3; return; }
		TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
		read_arg(set_l(PC, PC+1));
	icount--;

		PC++;

	if(icount == 0) { inst_substate = 5; return; }
		read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		PC += int8_t(TMP);

	} else {

	if(icount == 0) { inst_substate = 6; return; }
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::bbc_bar_partial()
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

	if(!(A & (1 << ((IR>>5) & 7)))) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read_arg(set_l(PC, PC+1));
	icount--;

		PC++;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
		read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		PC += int8_t(TMP);

	} else {

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::bbs_bar_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_pc_noinc();
	icount--;

	if(A & (1 << ((IR>>5) & 7))) {

	if(icount == 0) { inst_substate = 3; return; }
		TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
		read_arg(set_l(PC, PC+1));
	icount--;

		PC++;

	if(icount == 0) { inst_substate = 5; return; }
		read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		PC += int8_t(TMP);

	} else {

	if(icount == 0) { inst_substate = 6; return; }
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::bbs_bar_partial()
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

	if(A & (1 << ((IR>>5) & 7))) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read_arg(set_l(PC, PC+1));
	icount--;

		PC++;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
		read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

		PC += int8_t(TMP);

	} else {

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
		read_pc();
	icount--;

	}

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::rrf_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	read(TMP);
	icount--;

	TMP2 = do_rrf(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::rrf_zpg_partial()
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
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	read(TMP);
	icount--;

	TMP2 = do_rrf(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::bra_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_arg(set_l(PC, PC+1));
	icount--;

	PC++;

	if(icount == 0) { inst_substate = 3; return; }
	read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

	PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::bra_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_arg(set_l(PC, PC+1));
	icount--;

	PC++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read_arg(set_l(PC, PC+int8_t(TMP)));
	icount--;

	PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::jmp_zpi_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	PC = TMP;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::jmp_zpi_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	PC = TMP;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::jsr_zpi_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(SP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, PC>>8);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 4; return; }
	write(SP, PC);
	icount--;

	dec_SP();

	if(icount == 0) { inst_substate = 5; return; }
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	PC = TMP;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::jsr_zpi_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read(SP);
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

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	PC = TMP;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::reset740_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	P |= F_I; PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	PC = set_h(PC, read_arg(0xffff));
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

	inst_state = -1;

}

void m740_device::reset740_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	P |= F_I; PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	PC = set_h(PC, read_arg(0xffff));
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

	inst_state = -1;

}
	inst_substate = 0;
}


void m740_device::brk740_imp_full()
{

	// The 6502 bug when a nmi occurs in a brk is reproduced (case !irq_taken && nmi_pending)

	if(irq_taken) {

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
	write(SP, irq_taken ? P & ~F_B : P);
	icount--;

	dec_SP();

	if(nmi_pending) {

	if(icount == 0) { inst_substate = 6; return; }
		PC = read_arg(0xfffa);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
		PC = set_h(PC, read_arg(0xfffb));
	icount--;

		nmi_pending = false;

		standard_irq_callback(NMI_LINE);

	} else {

	if(icount == 0) { inst_substate = 8; return; }
		PC = read_arg(m_irq_vector);
	icount--;

	if(icount == 0) { inst_substate = 9; return; }
		PC = set_h(PC, read_arg(m_irq_vector+1));
	icount--;

		if(irq_taken)

			standard_irq_callback(IRQ_LINE);

	}

	irq_taken = false;

	P |= F_I; // Do *not* move after the prefetch

	if(icount == 0) { inst_substate = 10; return; }
	prefetch();
	icount--;

	inst_state = -1;

}

void m740_device::brk740_imp_partial()
{
switch(inst_substate) {
case 0:

	// The 6502 bug when a nmi occurs in a brk is reproduced (case !irq_taken && nmi_pending)

	if(irq_taken) {

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
	write(SP, irq_taken ? P & ~F_B : P);
	icount--;

	dec_SP();

	if(nmi_pending) {

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
		PC = read_arg(0xfffa);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
		PC = set_h(PC, read_arg(0xfffb));
	icount--;

		nmi_pending = false;

		standard_irq_callback(NMI_LINE);

	} else {

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
		PC = read_arg(m_irq_vector);
	icount--;

	if(icount == 0) { inst_substate = 9; return; }
	[[fallthrough]];
case 9:
		PC = set_h(PC, read_arg(m_irq_vector+1));
	icount--;

		if(irq_taken)

			standard_irq_callback(IRQ_LINE);

	}

	irq_taken = false;

	P |= F_I; // Do *not* move after the prefetch

	if(icount == 0) { inst_substate = 10; return; }
	[[fallthrough]];
case 10:
	prefetch();
	icount--;

	inst_state = -1;

}
	inst_substate = 0;
}


void m740_device::adct_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::adct_aba_partial()
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
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::adct_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::adct_abx_partial()
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

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::adct_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::adct_aby_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::adct_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	do_adct(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::adct_idx_partial()
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
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	do_adct(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::adct_idy_full()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	do_adct(read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::adct_idy_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	do_adct(read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::adct_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 3; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::adct_imm_partial()
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
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::adct_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::adct_zpg_partial()
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

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::adct_zpx_full()
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

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::adct_zpx_partial()
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

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	do_adct(TMP);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::andt_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::andt_aba_partial()
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
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::andt_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::andt_abx_partial()
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

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::andt_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::andt_aby_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::andt_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 &= read_pc();
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::andt_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 &= read_pc();
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::andt_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::andt_idx_partial()
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
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::andt_idy_full()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	TMP2 &= read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::andt_idy_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP2 &= read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::andt_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::andt_zpg_partial()
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
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 &= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::andt_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 &= read(uint8_t(TMP+X));
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::andt_zpx_partial()
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
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 &= read(uint8_t(TMP+X));
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::com_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read(TMP);
	icount--;

	TMP2 ^= 0xff;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::com_zpg_partial()
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
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read(TMP);
	icount--;

	TMP2 ^= 0xff;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::cmpt_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::cmpt_aba_partial()
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
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::cmpt_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::cmpt_abx_partial()
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

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::cmpt_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::cmpt_aby_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::cmpt_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	do_cmp(TMP2, read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::cmpt_idx_partial()
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
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	do_cmp(TMP2, read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::cmpt_idy_full()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	do_cmp(TMP2, read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::cmpt_idy_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	do_cmp(TMP2, read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::cmpt_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m740_device::cmpt_imm_partial()
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
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::cmpt_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::cmpt_zpg_partial()
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

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::cmpt_zpx_full()
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

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::cmpt_zpx_partial()
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

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	do_cmp(TMP2, TMP);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::dec_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A--;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m740_device::dec_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A--;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::dect_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(X);
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::dect_acc_partial()
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
	TMP2 = read(X);
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::eort_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 ^= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::eort_aba_partial()
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
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 ^= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::eort_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 ^= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::eort_abx_partial()
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

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 ^= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::eort_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 ^= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::eort_aby_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 ^= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::eort_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	TMP2 ^= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::eort_idx_partial()
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
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP2 ^= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::eort_idy_full()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	TMP2 ^= read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::eort_idy_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP2 ^= read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::eort_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 ^= read_pc();
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::eort_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 ^= read_pc();
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::eort_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 ^= read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::eort_zpg_partial()
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
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 ^= read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::eort_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 ^= read(uint8_t(TMP+X));
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::eort_zpx_partial()
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
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 ^= read(uint8_t(TMP+X));
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::inc_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	A++;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m740_device::inc_acc_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	A++;

	set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::inct_acc_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(X);
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::inct_acc_partial()
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
	TMP2 = read(X);
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ldt_aba_full()
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

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::ldt_aba_partial()
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

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ldt_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(TMP + X);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::ldt_abx_partial()
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

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(TMP + X);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ldt_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(TMP + Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::ldt_aby_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(TMP + Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ldt_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::ldt_idx_partial()
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
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ldt_idy_full()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::ldt_idy_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ldt_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 2; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m740_device::ldt_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ldt_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::ldt_zpg_partial()
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
	TMP2 = read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ldt_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(uint8_t(TMP+X));
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::ldt_zpx_partial()
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
	TMP2 = read(uint8_t(TMP+X));
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ort_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::ort_aba_partial()
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
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ort_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::ort_abx_partial()
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

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ort_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::ort_aby_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ort_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 |= read_pc();
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::ort_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 |= read_pc();
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ort_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::ort_idx_partial()
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
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ort_idy_full()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	TMP2 |= read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::ort_idy_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	TMP2 |= read(TMP+Y);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ort_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::ort_zpg_partial()
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
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 |= read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::ort_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 |= read(uint8_t(TMP+X));
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::ort_zpx_partial()
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
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 |= read(uint8_t(TMP+X));
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::sbct_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::sbct_aba_partial()
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
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::sbct_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::sbct_abx_partial()
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

	if(page_changing(TMP, X)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+X));
	icount--;

	}

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::sbct_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 6; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m740_device::sbct_aby_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	TMP += Y;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::sbct_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	do_sbct(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::sbct_idx_partial()
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
	read(TMP2);
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP2 & 0xff);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read((TMP2+1) & 0xff));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	do_sbct(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::sbct_idy_full()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	do_sbct(read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	prefetch();
	icount--;

}

void m740_device::sbct_idy_partial()
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

	if(page_changing(TMP, Y)) {

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
		read(set_l(TMP, TMP+Y));
	icount--;

	}

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	TMP2 = read(X);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	do_sbct(read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::sbct_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 3; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m740_device::sbct_imm_partial()
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
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::sbct_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m740_device::sbct_zpg_partial()
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

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::sbct_zpx_full()
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

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 5; return; }
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m740_device::sbct_zpx_partial()
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

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(X);
	icount--;

	do_sbct(TMP);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(X, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m740_device::tst_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m740_device::tst_zpg_partial()
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
	TMP2 = read(TMP);
	icount--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}




void m740_device::do_exec_full()
{
	switch(inst_state) {

	case 0x00: brk740_imp_full(); break;
	case 0x01: ora_idx_full(); break;
	case 0x02: jsr_zpi_full(); break;
	case 0x03: bbs_bar_full(); break;
	case 0x04: nop_zpg_full(); break;
	case 0x05: ora_zpg_full(); break;
	case 0x06: asl_zpg_full(); break;
	case 0x07: bbs_bzr_full(); break;
	case 0x08: php_imp_full(); break;
	case 0x09: ora_imm_full(); break;
	case 0x0a: asl_acc_full(); break;
	case 0x0b: seb_bac_full(); break;
	case 0x0c: nop_aba_full(); break;
	case 0x0d: ora_aba_full(); break;
	case 0x0e: asl_aba_full(); break;
	case 0x0f: seb_biz_full(); break;
	case 0x10: bpl_rel_full(); break;
	case 0x11: ora_idy_full(); break;
	case 0x12: clt_imp_full(); break;
	case 0x13: bbc_bar_full(); break;
	case 0x14: nop_zpx_full(); break;
	case 0x15: ora_zpx_full(); break;
	case 0x16: asl_zpx_full(); break;
	case 0x17: bbc_bzr_full(); break;
	case 0x18: clc_imp_full(); break;
	case 0x19: ora_aby_full(); break;
	case 0x1a: dec_acc_full(); break;
	case 0x1b: clb_bac_full(); break;
	case 0x1c: nop_abx_full(); break;
	case 0x1d: ora_abx_full(); break;
	case 0x1e: asl_abx_full(); break;
	case 0x1f: clb_biz_full(); break;
	case 0x20: jsr_adr_full(); break;
	case 0x21: and_idx_full(); break;
	case 0x22: jsr_spg_full(); break;
	case 0x23: bbs_bar_full(); break;
	case 0x24: bit_zpg_full(); break;
	case 0x25: and_zpg_full(); break;
	case 0x26: rol_zpg_full(); break;
	case 0x27: bbs_bzr_full(); break;
	case 0x28: plp_imp_full(); break;
	case 0x29: and_imm_full(); break;
	case 0x2a: rol_acc_full(); break;
	case 0x2b: seb_bac_full(); break;
	case 0x2c: bit_aba_full(); break;
	case 0x2d: and_aba_full(); break;
	case 0x2e: rol_aba_full(); break;
	case 0x2f: seb_biz_full(); break;
	case 0x30: bmi_rel_full(); break;
	case 0x31: and_idy_full(); break;
	case 0x32: set_imp_full(); break;
	case 0x33: bbc_bar_full(); break;
	case 0x34: nop_zpx_full(); break;
	case 0x35: and_zpx_full(); break;
	case 0x36: rol_zpx_full(); break;
	case 0x37: bbc_bzr_full(); break;
	case 0x38: sec_imp_full(); break;
	case 0x39: and_aby_full(); break;
	case 0x3a: inc_acc_full(); break;
	case 0x3b: clb_bac_full(); break;
	case 0x3c: ldm_imz_full(); break;
	case 0x3d: and_abx_full(); break;
	case 0x3e: rol_abx_full(); break;
	case 0x3f: clb_biz_full(); break;
	case 0x40: rti_imp_full(); break;
	case 0x41: eor_idx_full(); break;
	case 0x42: kil_non_full(); break;
	case 0x43: bbs_bar_full(); break;
	case 0x44: com_zpg_full(); break;
	case 0x45: eor_zpg_full(); break;
	case 0x46: lsr_zpg_full(); break;
	case 0x47: bbs_bzr_full(); break;
	case 0x48: pha_imp_full(); break;
	case 0x49: eor_imm_full(); break;
	case 0x4a: lsr_acc_full(); break;
	case 0x4b: seb_bac_full(); break;
	case 0x4c: jmp_adr_full(); break;
	case 0x4d: eor_aba_full(); break;
	case 0x4e: lsr_aba_full(); break;
	case 0x4f: seb_biz_full(); break;
	case 0x50: bvc_rel_full(); break;
	case 0x51: eor_idy_full(); break;
	case 0x52: kil_non_full(); break;
	case 0x53: bbc_bar_full(); break;
	case 0x54: nop_zpx_full(); break;
	case 0x55: eor_zpx_full(); break;
	case 0x56: lsr_zpx_full(); break;
	case 0x57: bbc_bzr_full(); break;
	case 0x58: cli_imp_full(); break;
	case 0x59: eor_aby_full(); break;
	case 0x5a: nop_imp_full(); break;
	case 0x5b: clb_bac_full(); break;
	case 0x5c: nop_abx_full(); break;
	case 0x5d: eor_abx_full(); break;
	case 0x5e: lsr_abx_full(); break;
	case 0x5f: clb_biz_full(); break;
	case 0x60: rts_imp_full(); break;
	case 0x61: adc_idx_full(); break;
	case 0x62: kil_non_full(); break;
	case 0x63: bbs_bar_full(); break;
	case 0x64: tst_zpg_full(); break;
	case 0x65: adc_zpg_full(); break;
	case 0x66: ror_zpg_full(); break;
	case 0x67: bbs_bzr_full(); break;
	case 0x68: pla_imp_full(); break;
	case 0x69: adc_imm_full(); break;
	case 0x6a: ror_acc_full(); break;
	case 0x6b: seb_bac_full(); break;
	case 0x6c: jmp_ind_full(); break;
	case 0x6d: adc_aba_full(); break;
	case 0x6e: ror_aba_full(); break;
	case 0x6f: seb_biz_full(); break;
	case 0x70: bvs_rel_full(); break;
	case 0x71: adc_idy_full(); break;
	case 0x72: kil_non_full(); break;
	case 0x73: bbc_bar_full(); break;
	case 0x74: nop_zpx_full(); break;
	case 0x75: adc_zpx_full(); break;
	case 0x76: ror_zpx_full(); break;
	case 0x77: bbc_bzr_full(); break;
	case 0x78: sei_imp_full(); break;
	case 0x79: adc_aby_full(); break;
	case 0x7a: nop_imp_full(); break;
	case 0x7b: clb_bac_full(); break;
	case 0x7c: nop_abx_full(); break;
	case 0x7d: adc_abx_full(); break;
	case 0x7e: ror_abx_full(); break;
	case 0x7f: clb_biz_full(); break;
	case 0x80: bra_rel_full(); break;
	case 0x81: sta_idx_full(); break;
	case 0x82: rrf_zpg_full(); break;
	case 0x83: bbs_bar_full(); break;
	case 0x84: sty_zpg_full(); break;
	case 0x85: sta_zpg_full(); break;
	case 0x86: stx_zpg_full(); break;
	case 0x87: bbs_bzr_full(); break;
	case 0x88: dey_imp_full(); break;
	case 0x89: nop_imm_full(); break;
	case 0x8a: txa_imp_full(); break;
	case 0x8b: seb_bac_full(); break;
	case 0x8c: sty_aba_full(); break;
	case 0x8d: sta_aba_full(); break;
	case 0x8e: stx_aba_full(); break;
	case 0x8f: seb_biz_full(); break;
	case 0x90: bcc_rel_full(); break;
	case 0x91: sta_idy_full(); break;
	case 0x92: kil_non_full(); break;
	case 0x93: bbc_bar_full(); break;
	case 0x94: sty_zpx_full(); break;
	case 0x95: sta_zpx_full(); break;
	case 0x96: stx_zpy_full(); break;
	case 0x97: bbc_bzr_full(); break;
	case 0x98: tya_imp_full(); break;
	case 0x99: sta_aby_full(); break;
	case 0x9a: txs_imp_full(); break;
	case 0x9b: clb_bac_full(); break;
	case 0x9c: shy_abx_full(); break;
	case 0x9d: sta_abx_full(); break;
	case 0x9e: shx_aby_full(); break;
	case 0x9f: clb_biz_full(); break;
	case 0xa0: ldy_imm_full(); break;
	case 0xa1: lda_idx_full(); break;
	case 0xa2: ldx_imm_full(); break;
	case 0xa3: bbs_bar_full(); break;
	case 0xa4: ldy_zpg_full(); break;
	case 0xa5: lda_zpg_full(); break;
	case 0xa6: ldx_zpg_full(); break;
	case 0xa7: bbs_bzr_full(); break;
	case 0xa8: tay_imp_full(); break;
	case 0xa9: lda_imm_full(); break;
	case 0xaa: tax_imp_full(); break;
	case 0xab: seb_bac_full(); break;
	case 0xac: ldy_aba_full(); break;
	case 0xad: lda_aba_full(); break;
	case 0xae: ldx_aba_full(); break;
	case 0xaf: seb_biz_full(); break;
	case 0xb0: bcs_rel_full(); break;
	case 0xb1: lda_idy_full(); break;
	case 0xb2: jmp_zpi_full(); break;
	case 0xb3: bbc_bar_full(); break;
	case 0xb4: ldy_zpx_full(); break;
	case 0xb5: lda_zpx_full(); break;
	case 0xb6: ldx_zpy_full(); break;
	case 0xb7: bbc_bzr_full(); break;
	case 0xb8: clv_imp_full(); break;
	case 0xb9: lda_aby_full(); break;
	case 0xba: tsx_imp_full(); break;
	case 0xbb: clb_bac_full(); break;
	case 0xbc: ldy_abx_full(); break;
	case 0xbd: lda_abx_full(); break;
	case 0xbe: ldx_aby_full(); break;
	case 0xbf: clb_biz_full(); break;
	case 0xc0: cpy_imm_full(); break;
	case 0xc1: cmp_idx_full(); break;
	case 0xc2: nop_imm_full(); break;
	case 0xc3: bbs_bar_full(); break;
	case 0xc4: cpy_zpg_full(); break;
	case 0xc5: cmp_zpg_full(); break;
	case 0xc6: dec_zpg_full(); break;
	case 0xc7: bbs_bzr_full(); break;
	case 0xc8: iny_imp_full(); break;
	case 0xc9: cmp_imm_full(); break;
	case 0xca: dex_imp_full(); break;
	case 0xcb: seb_bac_full(); break;
	case 0xcc: cpy_aba_full(); break;
	case 0xcd: cmp_aba_full(); break;
	case 0xce: dec_aba_full(); break;
	case 0xcf: seb_biz_full(); break;
	case 0xd0: bne_rel_full(); break;
	case 0xd1: cmp_idy_full(); break;
	case 0xd2: kil_non_full(); break;
	case 0xd3: bbc_bar_full(); break;
	case 0xd4: nop_zpx_full(); break;
	case 0xd5: cmp_zpx_full(); break;
	case 0xd6: dec_zpx_full(); break;
	case 0xd7: bbc_bzr_full(); break;
	case 0xd8: cld_imp_full(); break;
	case 0xd9: cmp_aby_full(); break;
	case 0xda: nop_imp_full(); break;
	case 0xdb: clb_bac_full(); break;
	case 0xdc: nop_abx_full(); break;
	case 0xdd: cmp_abx_full(); break;
	case 0xde: dec_abx_full(); break;
	case 0xdf: clb_biz_full(); break;
	case 0xe0: cpx_imm_full(); break;
	case 0xe1: sbc_idx_full(); break;
	case 0xe2: nop_imm_full(); break;
	case 0xe3: bbs_bar_full(); break;
	case 0xe4: cpx_zpg_full(); break;
	case 0xe5: sbc_zpg_full(); break;
	case 0xe6: inc_zpg_full(); break;
	case 0xe7: bbs_bzr_full(); break;
	case 0xe8: inx_imp_full(); break;
	case 0xe9: sbc_imm_full(); break;
	case 0xea: nop_imp_full(); break;
	case 0xeb: seb_bac_full(); break;
	case 0xec: cpx_aba_full(); break;
	case 0xed: sbc_aba_full(); break;
	case 0xee: inc_aba_full(); break;
	case 0xef: seb_biz_full(); break;
	case 0xf0: beq_rel_full(); break;
	case 0xf1: sbc_idy_full(); break;
	case 0xf2: kil_non_full(); break;
	case 0xf3: bbc_bar_full(); break;
	case 0xf4: nop_zpx_full(); break;
	case 0xf5: sbc_zpx_full(); break;
	case 0xf6: inc_zpx_full(); break;
	case 0xf7: bbc_bzr_full(); break;
	case 0xf8: sed_imp_full(); break;
	case 0xf9: sbc_aby_full(); break;
	case 0xfa: nop_imp_full(); break;
	case 0xfb: clb_bac_full(); break;
	case 0xfc: nop_abx_full(); break;
	case 0xfd: sbc_abx_full(); break;
	case 0xfe: inc_abx_full(); break;
	case 0xff: clb_biz_full(); break;
	case 0x100: brk740_imp_full(); break;
	case 0x101: ort_idx_full(); break;
	case 0x102: jsr_zpi_full(); break;
	case 0x103: bbs_bar_full(); break;
	case 0x104: nop_zpg_full(); break;
	case 0x105: ort_zpg_full(); break;
	case 0x106: asl_zpg_full(); break;
	case 0x107: bbs_bzr_full(); break;
	case 0x108: php_imp_full(); break;
	case 0x109: ort_imm_full(); break;
	case 0x10a: asl_acc_full(); break;
	case 0x10b: seb_bac_full(); break;
	case 0x10c: nop_aba_full(); break;
	case 0x10d: ort_aba_full(); break;
	case 0x10e: asl_aba_full(); break;
	case 0x10f: seb_biz_full(); break;
	case 0x110: bpl_rel_full(); break;
	case 0x111: ort_idy_full(); break;
	case 0x112: clt_imp_full(); break;
	case 0x113: bbc_bar_full(); break;
	case 0x114: nop_zpx_full(); break;
	case 0x115: ort_zpx_full(); break;
	case 0x116: asl_zpx_full(); break;
	case 0x117: bbc_bzr_full(); break;
	case 0x118: clc_imp_full(); break;
	case 0x119: ort_aby_full(); break;
	case 0x11a: dect_acc_full(); break;
	case 0x11b: clb_bac_full(); break;
	case 0x11c: nop_abx_full(); break;
	case 0x11d: ort_abx_full(); break;
	case 0x11e: asl_abx_full(); break;
	case 0x11f: clb_biz_full(); break;
	case 0x120: jsr_adr_full(); break;
	case 0x121: andt_idx_full(); break;
	case 0x122: jsr_spg_full(); break;
	case 0x123: bbs_bar_full(); break;
	case 0x124: bit_zpg_full(); break;
	case 0x125: andt_zpg_full(); break;
	case 0x126: rol_zpg_full(); break;
	case 0x127: bbs_bzr_full(); break;
	case 0x128: plp_imp_full(); break;
	case 0x129: andt_imm_full(); break;
	case 0x12a: rol_acc_full(); break;
	case 0x12b: seb_bac_full(); break;
	case 0x12c: bit_aba_full(); break;
	case 0x12d: andt_aba_full(); break;
	case 0x12e: rol_aba_full(); break;
	case 0x12f: seb_biz_full(); break;
	case 0x130: bmi_rel_full(); break;
	case 0x131: andt_idy_full(); break;
	case 0x132: set_imp_full(); break;
	case 0x133: bbc_bar_full(); break;
	case 0x134: nop_zpx_full(); break;
	case 0x135: andt_zpx_full(); break;
	case 0x136: rol_zpx_full(); break;
	case 0x137: bbc_bzr_full(); break;
	case 0x138: sec_imp_full(); break;
	case 0x139: andt_aby_full(); break;
	case 0x13a: inct_acc_full(); break;
	case 0x13b: clb_bac_full(); break;
	case 0x13c: ldm_imz_full(); break;
	case 0x13d: andt_abx_full(); break;
	case 0x13e: rol_abx_full(); break;
	case 0x13f: clb_biz_full(); break;
	case 0x140: rti_imp_full(); break;
	case 0x141: eort_idx_full(); break;
	case 0x142: kil_non_full(); break;
	case 0x143: bbs_bar_full(); break;
	case 0x144: com_zpg_full(); break;
	case 0x145: eort_zpg_full(); break;
	case 0x146: lsr_zpg_full(); break;
	case 0x147: bbs_bzr_full(); break;
	case 0x148: pha_imp_full(); break;
	case 0x149: eort_imm_full(); break;
	case 0x14a: lsr_acc_full(); break;
	case 0x14b: seb_bac_full(); break;
	case 0x14c: jmp_adr_full(); break;
	case 0x14d: eort_aba_full(); break;
	case 0x14e: lsr_aba_full(); break;
	case 0x14f: seb_biz_full(); break;
	case 0x150: bvc_rel_full(); break;
	case 0x151: eort_idy_full(); break;
	case 0x152: kil_non_full(); break;
	case 0x153: bbc_bar_full(); break;
	case 0x154: nop_zpx_full(); break;
	case 0x155: eort_zpx_full(); break;
	case 0x156: lsr_zpx_full(); break;
	case 0x157: bbc_bzr_full(); break;
	case 0x158: cli_imp_full(); break;
	case 0x159: eort_aby_full(); break;
	case 0x15a: nop_imp_full(); break;
	case 0x15b: clb_bac_full(); break;
	case 0x15c: nop_abx_full(); break;
	case 0x15d: eort_abx_full(); break;
	case 0x15e: lsr_abx_full(); break;
	case 0x15f: clb_biz_full(); break;
	case 0x160: rts_imp_full(); break;
	case 0x161: adct_idx_full(); break;
	case 0x162: kil_non_full(); break;
	case 0x163: bbs_bar_full(); break;
	case 0x164: tst_zpg_full(); break;
	case 0x165: adct_zpg_full(); break;
	case 0x166: ror_zpg_full(); break;
	case 0x167: bbs_bzr_full(); break;
	case 0x168: pla_imp_full(); break;
	case 0x169: adct_imm_full(); break;
	case 0x16a: ror_acc_full(); break;
	case 0x16b: seb_bac_full(); break;
	case 0x16c: jmp_ind_full(); break;
	case 0x16d: adct_aba_full(); break;
	case 0x16e: ror_aba_full(); break;
	case 0x16f: seb_biz_full(); break;
	case 0x170: bvs_rel_full(); break;
	case 0x171: adct_idy_full(); break;
	case 0x172: kil_non_full(); break;
	case 0x173: bbc_bar_full(); break;
	case 0x174: nop_zpx_full(); break;
	case 0x175: adct_zpx_full(); break;
	case 0x176: ror_zpx_full(); break;
	case 0x177: bbc_bzr_full(); break;
	case 0x178: sei_imp_full(); break;
	case 0x179: adct_aby_full(); break;
	case 0x17a: nop_imp_full(); break;
	case 0x17b: clb_bac_full(); break;
	case 0x17c: nop_abx_full(); break;
	case 0x17d: adct_abx_full(); break;
	case 0x17e: ror_abx_full(); break;
	case 0x17f: clb_biz_full(); break;
	case 0x180: bra_rel_full(); break;
	case 0x181: sta_idx_full(); break;
	case 0x182: rrf_zpg_full(); break;
	case 0x183: bbs_bar_full(); break;
	case 0x184: sty_zpg_full(); break;
	case 0x185: sta_zpg_full(); break;
	case 0x186: stx_zpg_full(); break;
	case 0x187: bbs_bzr_full(); break;
	case 0x188: dey_imp_full(); break;
	case 0x189: nop_imm_full(); break;
	case 0x18a: txa_imp_full(); break;
	case 0x18b: seb_bac_full(); break;
	case 0x18c: sty_aba_full(); break;
	case 0x18d: sta_aba_full(); break;
	case 0x18e: stx_aba_full(); break;
	case 0x18f: seb_biz_full(); break;
	case 0x190: bcc_rel_full(); break;
	case 0x191: sta_idy_full(); break;
	case 0x192: kil_non_full(); break;
	case 0x193: bbc_bar_full(); break;
	case 0x194: sty_zpx_full(); break;
	case 0x195: sta_zpx_full(); break;
	case 0x196: stx_zpy_full(); break;
	case 0x197: bbc_bzr_full(); break;
	case 0x198: tya_imp_full(); break;
	case 0x199: sta_aby_full(); break;
	case 0x19a: txs_imp_full(); break;
	case 0x19b: clb_bac_full(); break;
	case 0x19c: shy_abx_full(); break;
	case 0x19d: sta_abx_full(); break;
	case 0x19e: shx_aby_full(); break;
	case 0x19f: clb_biz_full(); break;
	case 0x1a0: ldy_imm_full(); break;
	case 0x1a1: ldt_idx_full(); break;
	case 0x1a2: ldx_imm_full(); break;
	case 0x1a3: bbs_bar_full(); break;
	case 0x1a4: ldy_zpg_full(); break;
	case 0x1a5: ldt_zpg_full(); break;
	case 0x1a6: ldx_zpg_full(); break;
	case 0x1a7: bbs_bzr_full(); break;
	case 0x1a8: tay_imp_full(); break;
	case 0x1a9: ldt_imm_full(); break;
	case 0x1aa: tax_imp_full(); break;
	case 0x1ab: seb_bac_full(); break;
	case 0x1ac: ldy_aba_full(); break;
	case 0x1ad: ldt_aba_full(); break;
	case 0x1ae: ldx_aba_full(); break;
	case 0x1af: seb_biz_full(); break;
	case 0x1b0: bcs_rel_full(); break;
	case 0x1b1: ldt_idy_full(); break;
	case 0x1b2: jmp_zpi_full(); break;
	case 0x1b3: bbc_bar_full(); break;
	case 0x1b4: ldy_zpx_full(); break;
	case 0x1b5: ldt_zpx_full(); break;
	case 0x1b6: ldx_zpy_full(); break;
	case 0x1b7: bbc_bzr_full(); break;
	case 0x1b8: clv_imp_full(); break;
	case 0x1b9: ldt_aby_full(); break;
	case 0x1ba: tsx_imp_full(); break;
	case 0x1bb: clb_bac_full(); break;
	case 0x1bc: ldy_abx_full(); break;
	case 0x1bd: ldt_abx_full(); break;
	case 0x1be: ldx_aby_full(); break;
	case 0x1bf: clb_biz_full(); break;
	case 0x1c0: cpy_imm_full(); break;
	case 0x1c1: cmp_idx_full(); break;
	case 0x1c2: nop_imm_full(); break;
	case 0x1c3: bbs_bar_full(); break;
	case 0x1c4: cpy_zpg_full(); break;
	case 0x1c5: cmpt_zpg_full(); break;
	case 0x1c6: dec_zpg_full(); break;
	case 0x1c7: bbs_bzr_full(); break;
	case 0x1c8: iny_imp_full(); break;
	case 0x1c9: cmpt_imm_full(); break;
	case 0x1ca: dex_imp_full(); break;
	case 0x1cb: seb_bac_full(); break;
	case 0x1cc: cpy_aba_full(); break;
	case 0x1cd: cmpt_aba_full(); break;
	case 0x1ce: dec_aba_full(); break;
	case 0x1cf: seb_biz_full(); break;
	case 0x1d0: bne_rel_full(); break;
	case 0x1d1: cmp_idy_full(); break;
	case 0x1d2: kil_non_full(); break;
	case 0x1d3: bbc_bar_full(); break;
	case 0x1d4: nop_zpx_full(); break;
	case 0x1d5: cmpt_zpx_full(); break;
	case 0x1d6: dec_zpx_full(); break;
	case 0x1d7: bbc_bzr_full(); break;
	case 0x1d8: cld_imp_full(); break;
	case 0x1d9: cmpt_aby_full(); break;
	case 0x1da: nop_imp_full(); break;
	case 0x1db: clb_bac_full(); break;
	case 0x1dc: nop_abx_full(); break;
	case 0x1dd: cmpt_abx_full(); break;
	case 0x1de: dec_abx_full(); break;
	case 0x1df: clb_biz_full(); break;
	case 0x1e0: cpx_imm_full(); break;
	case 0x1e1: sbct_idx_full(); break;
	case 0x1e2: nop_imm_full(); break;
	case 0x1e3: bbs_bar_full(); break;
	case 0x1e4: cpx_zpg_full(); break;
	case 0x1e5: sbct_zpg_full(); break;
	case 0x1e6: inc_zpg_full(); break;
	case 0x1e7: bbs_bzr_full(); break;
	case 0x1e8: inx_imp_full(); break;
	case 0x1e9: sbc_imm_full(); break;
	case 0x1ea: nop_imp_full(); break;
	case 0x1eb: seb_bac_full(); break;
	case 0x1ec: cpx_aba_full(); break;
	case 0x1ed: sbct_aba_full(); break;
	case 0x1ee: inc_aba_full(); break;
	case 0x1ef: seb_biz_full(); break;
	case 0x1f0: beq_rel_full(); break;
	case 0x1f1: sbct_idy_full(); break;
	case 0x1f2: kil_non_full(); break;
	case 0x1f3: bbc_bar_full(); break;
	case 0x1f4: nop_zpx_full(); break;
	case 0x1f5: sbct_zpx_full(); break;
	case 0x1f6: inc_zpx_full(); break;
	case 0x1f7: bbc_bzr_full(); break;
	case 0x1f8: sed_imp_full(); break;
	case 0x1f9: sbc_aby_full(); break;
	case 0x1fa: nop_imp_full(); break;
	case 0x1fb: clb_bac_full(); break;
	case 0x1fc: nop_abx_full(); break;
	case 0x1fd: sbct_abx_full(); break;
	case 0x1fe: inc_abx_full(); break;
	case 0x1ff: clb_biz_full(); break;
	case STATE_RESET: reset740_full(); break;
	}
}

void m740_device::do_exec_partial()
{
	switch(inst_state) {

	case 0x00: brk740_imp_partial(); break;
	case 0x01: ora_idx_partial(); break;
	case 0x02: jsr_zpi_partial(); break;
	case 0x03: bbs_bar_partial(); break;
	case 0x04: nop_zpg_partial(); break;
	case 0x05: ora_zpg_partial(); break;
	case 0x06: asl_zpg_partial(); break;
	case 0x07: bbs_bzr_partial(); break;
	case 0x08: php_imp_partial(); break;
	case 0x09: ora_imm_partial(); break;
	case 0x0a: asl_acc_partial(); break;
	case 0x0b: seb_bac_partial(); break;
	case 0x0c: nop_aba_partial(); break;
	case 0x0d: ora_aba_partial(); break;
	case 0x0e: asl_aba_partial(); break;
	case 0x0f: seb_biz_partial(); break;
	case 0x10: bpl_rel_partial(); break;
	case 0x11: ora_idy_partial(); break;
	case 0x12: clt_imp_partial(); break;
	case 0x13: bbc_bar_partial(); break;
	case 0x14: nop_zpx_partial(); break;
	case 0x15: ora_zpx_partial(); break;
	case 0x16: asl_zpx_partial(); break;
	case 0x17: bbc_bzr_partial(); break;
	case 0x18: clc_imp_partial(); break;
	case 0x19: ora_aby_partial(); break;
	case 0x1a: dec_acc_partial(); break;
	case 0x1b: clb_bac_partial(); break;
	case 0x1c: nop_abx_partial(); break;
	case 0x1d: ora_abx_partial(); break;
	case 0x1e: asl_abx_partial(); break;
	case 0x1f: clb_biz_partial(); break;
	case 0x20: jsr_adr_partial(); break;
	case 0x21: and_idx_partial(); break;
	case 0x22: jsr_spg_partial(); break;
	case 0x23: bbs_bar_partial(); break;
	case 0x24: bit_zpg_partial(); break;
	case 0x25: and_zpg_partial(); break;
	case 0x26: rol_zpg_partial(); break;
	case 0x27: bbs_bzr_partial(); break;
	case 0x28: plp_imp_partial(); break;
	case 0x29: and_imm_partial(); break;
	case 0x2a: rol_acc_partial(); break;
	case 0x2b: seb_bac_partial(); break;
	case 0x2c: bit_aba_partial(); break;
	case 0x2d: and_aba_partial(); break;
	case 0x2e: rol_aba_partial(); break;
	case 0x2f: seb_biz_partial(); break;
	case 0x30: bmi_rel_partial(); break;
	case 0x31: and_idy_partial(); break;
	case 0x32: set_imp_partial(); break;
	case 0x33: bbc_bar_partial(); break;
	case 0x34: nop_zpx_partial(); break;
	case 0x35: and_zpx_partial(); break;
	case 0x36: rol_zpx_partial(); break;
	case 0x37: bbc_bzr_partial(); break;
	case 0x38: sec_imp_partial(); break;
	case 0x39: and_aby_partial(); break;
	case 0x3a: inc_acc_partial(); break;
	case 0x3b: clb_bac_partial(); break;
	case 0x3c: ldm_imz_partial(); break;
	case 0x3d: and_abx_partial(); break;
	case 0x3e: rol_abx_partial(); break;
	case 0x3f: clb_biz_partial(); break;
	case 0x40: rti_imp_partial(); break;
	case 0x41: eor_idx_partial(); break;
	case 0x42: kil_non_partial(); break;
	case 0x43: bbs_bar_partial(); break;
	case 0x44: com_zpg_partial(); break;
	case 0x45: eor_zpg_partial(); break;
	case 0x46: lsr_zpg_partial(); break;
	case 0x47: bbs_bzr_partial(); break;
	case 0x48: pha_imp_partial(); break;
	case 0x49: eor_imm_partial(); break;
	case 0x4a: lsr_acc_partial(); break;
	case 0x4b: seb_bac_partial(); break;
	case 0x4c: jmp_adr_partial(); break;
	case 0x4d: eor_aba_partial(); break;
	case 0x4e: lsr_aba_partial(); break;
	case 0x4f: seb_biz_partial(); break;
	case 0x50: bvc_rel_partial(); break;
	case 0x51: eor_idy_partial(); break;
	case 0x52: kil_non_partial(); break;
	case 0x53: bbc_bar_partial(); break;
	case 0x54: nop_zpx_partial(); break;
	case 0x55: eor_zpx_partial(); break;
	case 0x56: lsr_zpx_partial(); break;
	case 0x57: bbc_bzr_partial(); break;
	case 0x58: cli_imp_partial(); break;
	case 0x59: eor_aby_partial(); break;
	case 0x5a: nop_imp_partial(); break;
	case 0x5b: clb_bac_partial(); break;
	case 0x5c: nop_abx_partial(); break;
	case 0x5d: eor_abx_partial(); break;
	case 0x5e: lsr_abx_partial(); break;
	case 0x5f: clb_biz_partial(); break;
	case 0x60: rts_imp_partial(); break;
	case 0x61: adc_idx_partial(); break;
	case 0x62: kil_non_partial(); break;
	case 0x63: bbs_bar_partial(); break;
	case 0x64: tst_zpg_partial(); break;
	case 0x65: adc_zpg_partial(); break;
	case 0x66: ror_zpg_partial(); break;
	case 0x67: bbs_bzr_partial(); break;
	case 0x68: pla_imp_partial(); break;
	case 0x69: adc_imm_partial(); break;
	case 0x6a: ror_acc_partial(); break;
	case 0x6b: seb_bac_partial(); break;
	case 0x6c: jmp_ind_partial(); break;
	case 0x6d: adc_aba_partial(); break;
	case 0x6e: ror_aba_partial(); break;
	case 0x6f: seb_biz_partial(); break;
	case 0x70: bvs_rel_partial(); break;
	case 0x71: adc_idy_partial(); break;
	case 0x72: kil_non_partial(); break;
	case 0x73: bbc_bar_partial(); break;
	case 0x74: nop_zpx_partial(); break;
	case 0x75: adc_zpx_partial(); break;
	case 0x76: ror_zpx_partial(); break;
	case 0x77: bbc_bzr_partial(); break;
	case 0x78: sei_imp_partial(); break;
	case 0x79: adc_aby_partial(); break;
	case 0x7a: nop_imp_partial(); break;
	case 0x7b: clb_bac_partial(); break;
	case 0x7c: nop_abx_partial(); break;
	case 0x7d: adc_abx_partial(); break;
	case 0x7e: ror_abx_partial(); break;
	case 0x7f: clb_biz_partial(); break;
	case 0x80: bra_rel_partial(); break;
	case 0x81: sta_idx_partial(); break;
	case 0x82: rrf_zpg_partial(); break;
	case 0x83: bbs_bar_partial(); break;
	case 0x84: sty_zpg_partial(); break;
	case 0x85: sta_zpg_partial(); break;
	case 0x86: stx_zpg_partial(); break;
	case 0x87: bbs_bzr_partial(); break;
	case 0x88: dey_imp_partial(); break;
	case 0x89: nop_imm_partial(); break;
	case 0x8a: txa_imp_partial(); break;
	case 0x8b: seb_bac_partial(); break;
	case 0x8c: sty_aba_partial(); break;
	case 0x8d: sta_aba_partial(); break;
	case 0x8e: stx_aba_partial(); break;
	case 0x8f: seb_biz_partial(); break;
	case 0x90: bcc_rel_partial(); break;
	case 0x91: sta_idy_partial(); break;
	case 0x92: kil_non_partial(); break;
	case 0x93: bbc_bar_partial(); break;
	case 0x94: sty_zpx_partial(); break;
	case 0x95: sta_zpx_partial(); break;
	case 0x96: stx_zpy_partial(); break;
	case 0x97: bbc_bzr_partial(); break;
	case 0x98: tya_imp_partial(); break;
	case 0x99: sta_aby_partial(); break;
	case 0x9a: txs_imp_partial(); break;
	case 0x9b: clb_bac_partial(); break;
	case 0x9c: shy_abx_partial(); break;
	case 0x9d: sta_abx_partial(); break;
	case 0x9e: shx_aby_partial(); break;
	case 0x9f: clb_biz_partial(); break;
	case 0xa0: ldy_imm_partial(); break;
	case 0xa1: lda_idx_partial(); break;
	case 0xa2: ldx_imm_partial(); break;
	case 0xa3: bbs_bar_partial(); break;
	case 0xa4: ldy_zpg_partial(); break;
	case 0xa5: lda_zpg_partial(); break;
	case 0xa6: ldx_zpg_partial(); break;
	case 0xa7: bbs_bzr_partial(); break;
	case 0xa8: tay_imp_partial(); break;
	case 0xa9: lda_imm_partial(); break;
	case 0xaa: tax_imp_partial(); break;
	case 0xab: seb_bac_partial(); break;
	case 0xac: ldy_aba_partial(); break;
	case 0xad: lda_aba_partial(); break;
	case 0xae: ldx_aba_partial(); break;
	case 0xaf: seb_biz_partial(); break;
	case 0xb0: bcs_rel_partial(); break;
	case 0xb1: lda_idy_partial(); break;
	case 0xb2: jmp_zpi_partial(); break;
	case 0xb3: bbc_bar_partial(); break;
	case 0xb4: ldy_zpx_partial(); break;
	case 0xb5: lda_zpx_partial(); break;
	case 0xb6: ldx_zpy_partial(); break;
	case 0xb7: bbc_bzr_partial(); break;
	case 0xb8: clv_imp_partial(); break;
	case 0xb9: lda_aby_partial(); break;
	case 0xba: tsx_imp_partial(); break;
	case 0xbb: clb_bac_partial(); break;
	case 0xbc: ldy_abx_partial(); break;
	case 0xbd: lda_abx_partial(); break;
	case 0xbe: ldx_aby_partial(); break;
	case 0xbf: clb_biz_partial(); break;
	case 0xc0: cpy_imm_partial(); break;
	case 0xc1: cmp_idx_partial(); break;
	case 0xc2: nop_imm_partial(); break;
	case 0xc3: bbs_bar_partial(); break;
	case 0xc4: cpy_zpg_partial(); break;
	case 0xc5: cmp_zpg_partial(); break;
	case 0xc6: dec_zpg_partial(); break;
	case 0xc7: bbs_bzr_partial(); break;
	case 0xc8: iny_imp_partial(); break;
	case 0xc9: cmp_imm_partial(); break;
	case 0xca: dex_imp_partial(); break;
	case 0xcb: seb_bac_partial(); break;
	case 0xcc: cpy_aba_partial(); break;
	case 0xcd: cmp_aba_partial(); break;
	case 0xce: dec_aba_partial(); break;
	case 0xcf: seb_biz_partial(); break;
	case 0xd0: bne_rel_partial(); break;
	case 0xd1: cmp_idy_partial(); break;
	case 0xd2: kil_non_partial(); break;
	case 0xd3: bbc_bar_partial(); break;
	case 0xd4: nop_zpx_partial(); break;
	case 0xd5: cmp_zpx_partial(); break;
	case 0xd6: dec_zpx_partial(); break;
	case 0xd7: bbc_bzr_partial(); break;
	case 0xd8: cld_imp_partial(); break;
	case 0xd9: cmp_aby_partial(); break;
	case 0xda: nop_imp_partial(); break;
	case 0xdb: clb_bac_partial(); break;
	case 0xdc: nop_abx_partial(); break;
	case 0xdd: cmp_abx_partial(); break;
	case 0xde: dec_abx_partial(); break;
	case 0xdf: clb_biz_partial(); break;
	case 0xe0: cpx_imm_partial(); break;
	case 0xe1: sbc_idx_partial(); break;
	case 0xe2: nop_imm_partial(); break;
	case 0xe3: bbs_bar_partial(); break;
	case 0xe4: cpx_zpg_partial(); break;
	case 0xe5: sbc_zpg_partial(); break;
	case 0xe6: inc_zpg_partial(); break;
	case 0xe7: bbs_bzr_partial(); break;
	case 0xe8: inx_imp_partial(); break;
	case 0xe9: sbc_imm_partial(); break;
	case 0xea: nop_imp_partial(); break;
	case 0xeb: seb_bac_partial(); break;
	case 0xec: cpx_aba_partial(); break;
	case 0xed: sbc_aba_partial(); break;
	case 0xee: inc_aba_partial(); break;
	case 0xef: seb_biz_partial(); break;
	case 0xf0: beq_rel_partial(); break;
	case 0xf1: sbc_idy_partial(); break;
	case 0xf2: kil_non_partial(); break;
	case 0xf3: bbc_bar_partial(); break;
	case 0xf4: nop_zpx_partial(); break;
	case 0xf5: sbc_zpx_partial(); break;
	case 0xf6: inc_zpx_partial(); break;
	case 0xf7: bbc_bzr_partial(); break;
	case 0xf8: sed_imp_partial(); break;
	case 0xf9: sbc_aby_partial(); break;
	case 0xfa: nop_imp_partial(); break;
	case 0xfb: clb_bac_partial(); break;
	case 0xfc: nop_abx_partial(); break;
	case 0xfd: sbc_abx_partial(); break;
	case 0xfe: inc_abx_partial(); break;
	case 0xff: clb_biz_partial(); break;
	case 0x100: brk740_imp_partial(); break;
	case 0x101: ort_idx_partial(); break;
	case 0x102: jsr_zpi_partial(); break;
	case 0x103: bbs_bar_partial(); break;
	case 0x104: nop_zpg_partial(); break;
	case 0x105: ort_zpg_partial(); break;
	case 0x106: asl_zpg_partial(); break;
	case 0x107: bbs_bzr_partial(); break;
	case 0x108: php_imp_partial(); break;
	case 0x109: ort_imm_partial(); break;
	case 0x10a: asl_acc_partial(); break;
	case 0x10b: seb_bac_partial(); break;
	case 0x10c: nop_aba_partial(); break;
	case 0x10d: ort_aba_partial(); break;
	case 0x10e: asl_aba_partial(); break;
	case 0x10f: seb_biz_partial(); break;
	case 0x110: bpl_rel_partial(); break;
	case 0x111: ort_idy_partial(); break;
	case 0x112: clt_imp_partial(); break;
	case 0x113: bbc_bar_partial(); break;
	case 0x114: nop_zpx_partial(); break;
	case 0x115: ort_zpx_partial(); break;
	case 0x116: asl_zpx_partial(); break;
	case 0x117: bbc_bzr_partial(); break;
	case 0x118: clc_imp_partial(); break;
	case 0x119: ort_aby_partial(); break;
	case 0x11a: dect_acc_partial(); break;
	case 0x11b: clb_bac_partial(); break;
	case 0x11c: nop_abx_partial(); break;
	case 0x11d: ort_abx_partial(); break;
	case 0x11e: asl_abx_partial(); break;
	case 0x11f: clb_biz_partial(); break;
	case 0x120: jsr_adr_partial(); break;
	case 0x121: andt_idx_partial(); break;
	case 0x122: jsr_spg_partial(); break;
	case 0x123: bbs_bar_partial(); break;
	case 0x124: bit_zpg_partial(); break;
	case 0x125: andt_zpg_partial(); break;
	case 0x126: rol_zpg_partial(); break;
	case 0x127: bbs_bzr_partial(); break;
	case 0x128: plp_imp_partial(); break;
	case 0x129: andt_imm_partial(); break;
	case 0x12a: rol_acc_partial(); break;
	case 0x12b: seb_bac_partial(); break;
	case 0x12c: bit_aba_partial(); break;
	case 0x12d: andt_aba_partial(); break;
	case 0x12e: rol_aba_partial(); break;
	case 0x12f: seb_biz_partial(); break;
	case 0x130: bmi_rel_partial(); break;
	case 0x131: andt_idy_partial(); break;
	case 0x132: set_imp_partial(); break;
	case 0x133: bbc_bar_partial(); break;
	case 0x134: nop_zpx_partial(); break;
	case 0x135: andt_zpx_partial(); break;
	case 0x136: rol_zpx_partial(); break;
	case 0x137: bbc_bzr_partial(); break;
	case 0x138: sec_imp_partial(); break;
	case 0x139: andt_aby_partial(); break;
	case 0x13a: inct_acc_partial(); break;
	case 0x13b: clb_bac_partial(); break;
	case 0x13c: ldm_imz_partial(); break;
	case 0x13d: andt_abx_partial(); break;
	case 0x13e: rol_abx_partial(); break;
	case 0x13f: clb_biz_partial(); break;
	case 0x140: rti_imp_partial(); break;
	case 0x141: eort_idx_partial(); break;
	case 0x142: kil_non_partial(); break;
	case 0x143: bbs_bar_partial(); break;
	case 0x144: com_zpg_partial(); break;
	case 0x145: eort_zpg_partial(); break;
	case 0x146: lsr_zpg_partial(); break;
	case 0x147: bbs_bzr_partial(); break;
	case 0x148: pha_imp_partial(); break;
	case 0x149: eort_imm_partial(); break;
	case 0x14a: lsr_acc_partial(); break;
	case 0x14b: seb_bac_partial(); break;
	case 0x14c: jmp_adr_partial(); break;
	case 0x14d: eort_aba_partial(); break;
	case 0x14e: lsr_aba_partial(); break;
	case 0x14f: seb_biz_partial(); break;
	case 0x150: bvc_rel_partial(); break;
	case 0x151: eort_idy_partial(); break;
	case 0x152: kil_non_partial(); break;
	case 0x153: bbc_bar_partial(); break;
	case 0x154: nop_zpx_partial(); break;
	case 0x155: eort_zpx_partial(); break;
	case 0x156: lsr_zpx_partial(); break;
	case 0x157: bbc_bzr_partial(); break;
	case 0x158: cli_imp_partial(); break;
	case 0x159: eort_aby_partial(); break;
	case 0x15a: nop_imp_partial(); break;
	case 0x15b: clb_bac_partial(); break;
	case 0x15c: nop_abx_partial(); break;
	case 0x15d: eort_abx_partial(); break;
	case 0x15e: lsr_abx_partial(); break;
	case 0x15f: clb_biz_partial(); break;
	case 0x160: rts_imp_partial(); break;
	case 0x161: adct_idx_partial(); break;
	case 0x162: kil_non_partial(); break;
	case 0x163: bbs_bar_partial(); break;
	case 0x164: tst_zpg_partial(); break;
	case 0x165: adct_zpg_partial(); break;
	case 0x166: ror_zpg_partial(); break;
	case 0x167: bbs_bzr_partial(); break;
	case 0x168: pla_imp_partial(); break;
	case 0x169: adct_imm_partial(); break;
	case 0x16a: ror_acc_partial(); break;
	case 0x16b: seb_bac_partial(); break;
	case 0x16c: jmp_ind_partial(); break;
	case 0x16d: adct_aba_partial(); break;
	case 0x16e: ror_aba_partial(); break;
	case 0x16f: seb_biz_partial(); break;
	case 0x170: bvs_rel_partial(); break;
	case 0x171: adct_idy_partial(); break;
	case 0x172: kil_non_partial(); break;
	case 0x173: bbc_bar_partial(); break;
	case 0x174: nop_zpx_partial(); break;
	case 0x175: adct_zpx_partial(); break;
	case 0x176: ror_zpx_partial(); break;
	case 0x177: bbc_bzr_partial(); break;
	case 0x178: sei_imp_partial(); break;
	case 0x179: adct_aby_partial(); break;
	case 0x17a: nop_imp_partial(); break;
	case 0x17b: clb_bac_partial(); break;
	case 0x17c: nop_abx_partial(); break;
	case 0x17d: adct_abx_partial(); break;
	case 0x17e: ror_abx_partial(); break;
	case 0x17f: clb_biz_partial(); break;
	case 0x180: bra_rel_partial(); break;
	case 0x181: sta_idx_partial(); break;
	case 0x182: rrf_zpg_partial(); break;
	case 0x183: bbs_bar_partial(); break;
	case 0x184: sty_zpg_partial(); break;
	case 0x185: sta_zpg_partial(); break;
	case 0x186: stx_zpg_partial(); break;
	case 0x187: bbs_bzr_partial(); break;
	case 0x188: dey_imp_partial(); break;
	case 0x189: nop_imm_partial(); break;
	case 0x18a: txa_imp_partial(); break;
	case 0x18b: seb_bac_partial(); break;
	case 0x18c: sty_aba_partial(); break;
	case 0x18d: sta_aba_partial(); break;
	case 0x18e: stx_aba_partial(); break;
	case 0x18f: seb_biz_partial(); break;
	case 0x190: bcc_rel_partial(); break;
	case 0x191: sta_idy_partial(); break;
	case 0x192: kil_non_partial(); break;
	case 0x193: bbc_bar_partial(); break;
	case 0x194: sty_zpx_partial(); break;
	case 0x195: sta_zpx_partial(); break;
	case 0x196: stx_zpy_partial(); break;
	case 0x197: bbc_bzr_partial(); break;
	case 0x198: tya_imp_partial(); break;
	case 0x199: sta_aby_partial(); break;
	case 0x19a: txs_imp_partial(); break;
	case 0x19b: clb_bac_partial(); break;
	case 0x19c: shy_abx_partial(); break;
	case 0x19d: sta_abx_partial(); break;
	case 0x19e: shx_aby_partial(); break;
	case 0x19f: clb_biz_partial(); break;
	case 0x1a0: ldy_imm_partial(); break;
	case 0x1a1: ldt_idx_partial(); break;
	case 0x1a2: ldx_imm_partial(); break;
	case 0x1a3: bbs_bar_partial(); break;
	case 0x1a4: ldy_zpg_partial(); break;
	case 0x1a5: ldt_zpg_partial(); break;
	case 0x1a6: ldx_zpg_partial(); break;
	case 0x1a7: bbs_bzr_partial(); break;
	case 0x1a8: tay_imp_partial(); break;
	case 0x1a9: ldt_imm_partial(); break;
	case 0x1aa: tax_imp_partial(); break;
	case 0x1ab: seb_bac_partial(); break;
	case 0x1ac: ldy_aba_partial(); break;
	case 0x1ad: ldt_aba_partial(); break;
	case 0x1ae: ldx_aba_partial(); break;
	case 0x1af: seb_biz_partial(); break;
	case 0x1b0: bcs_rel_partial(); break;
	case 0x1b1: ldt_idy_partial(); break;
	case 0x1b2: jmp_zpi_partial(); break;
	case 0x1b3: bbc_bar_partial(); break;
	case 0x1b4: ldy_zpx_partial(); break;
	case 0x1b5: ldt_zpx_partial(); break;
	case 0x1b6: ldx_zpy_partial(); break;
	case 0x1b7: bbc_bzr_partial(); break;
	case 0x1b8: clv_imp_partial(); break;
	case 0x1b9: ldt_aby_partial(); break;
	case 0x1ba: tsx_imp_partial(); break;
	case 0x1bb: clb_bac_partial(); break;
	case 0x1bc: ldy_abx_partial(); break;
	case 0x1bd: ldt_abx_partial(); break;
	case 0x1be: ldx_aby_partial(); break;
	case 0x1bf: clb_biz_partial(); break;
	case 0x1c0: cpy_imm_partial(); break;
	case 0x1c1: cmp_idx_partial(); break;
	case 0x1c2: nop_imm_partial(); break;
	case 0x1c3: bbs_bar_partial(); break;
	case 0x1c4: cpy_zpg_partial(); break;
	case 0x1c5: cmpt_zpg_partial(); break;
	case 0x1c6: dec_zpg_partial(); break;
	case 0x1c7: bbs_bzr_partial(); break;
	case 0x1c8: iny_imp_partial(); break;
	case 0x1c9: cmpt_imm_partial(); break;
	case 0x1ca: dex_imp_partial(); break;
	case 0x1cb: seb_bac_partial(); break;
	case 0x1cc: cpy_aba_partial(); break;
	case 0x1cd: cmpt_aba_partial(); break;
	case 0x1ce: dec_aba_partial(); break;
	case 0x1cf: seb_biz_partial(); break;
	case 0x1d0: bne_rel_partial(); break;
	case 0x1d1: cmp_idy_partial(); break;
	case 0x1d2: kil_non_partial(); break;
	case 0x1d3: bbc_bar_partial(); break;
	case 0x1d4: nop_zpx_partial(); break;
	case 0x1d5: cmpt_zpx_partial(); break;
	case 0x1d6: dec_zpx_partial(); break;
	case 0x1d7: bbc_bzr_partial(); break;
	case 0x1d8: cld_imp_partial(); break;
	case 0x1d9: cmpt_aby_partial(); break;
	case 0x1da: nop_imp_partial(); break;
	case 0x1db: clb_bac_partial(); break;
	case 0x1dc: nop_abx_partial(); break;
	case 0x1dd: cmpt_abx_partial(); break;
	case 0x1de: dec_abx_partial(); break;
	case 0x1df: clb_biz_partial(); break;
	case 0x1e0: cpx_imm_partial(); break;
	case 0x1e1: sbct_idx_partial(); break;
	case 0x1e2: nop_imm_partial(); break;
	case 0x1e3: bbs_bar_partial(); break;
	case 0x1e4: cpx_zpg_partial(); break;
	case 0x1e5: sbct_zpg_partial(); break;
	case 0x1e6: inc_zpg_partial(); break;
	case 0x1e7: bbs_bzr_partial(); break;
	case 0x1e8: inx_imp_partial(); break;
	case 0x1e9: sbc_imm_partial(); break;
	case 0x1ea: nop_imp_partial(); break;
	case 0x1eb: seb_bac_partial(); break;
	case 0x1ec: cpx_aba_partial(); break;
	case 0x1ed: sbct_aba_partial(); break;
	case 0x1ee: inc_aba_partial(); break;
	case 0x1ef: seb_biz_partial(); break;
	case 0x1f0: beq_rel_partial(); break;
	case 0x1f1: sbct_idy_partial(); break;
	case 0x1f2: kil_non_partial(); break;
	case 0x1f3: bbc_bar_partial(); break;
	case 0x1f4: nop_zpx_partial(); break;
	case 0x1f5: sbct_zpx_partial(); break;
	case 0x1f6: inc_zpx_partial(); break;
	case 0x1f7: bbc_bzr_partial(); break;
	case 0x1f8: sed_imp_partial(); break;
	case 0x1f9: sbc_aby_partial(); break;
	case 0x1fa: nop_imp_partial(); break;
	case 0x1fb: clb_bac_partial(); break;
	case 0x1fc: nop_abx_partial(); break;
	case 0x1fd: sbct_abx_partial(); break;
	case 0x1fe: inc_abx_partial(); break;
	case 0x1ff: clb_biz_partial(); break;
	case STATE_RESET: reset740_partial(); break;
	}
}

