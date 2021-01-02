void m65ce02_device::adc_ce_aba_full()
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

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::adc_ce_aba_partial()
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

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::adc_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP);
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::adc_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP);
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::adc_ce_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP);
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::adc_ce_aby_partial()
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

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP);
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::adc_ce_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	do_adc(read(TMP));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::adc_ce_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	do_adc(read(TMP));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::adc_ce_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	do_adc(read(TMP+Y));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::adc_ce_idy_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	do_adc(read(TMP+Y));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::adc_idz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	do_adc(read(TMP+Z));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::adc_idz_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	do_adc(read(TMP+Z));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::adc_ce_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::adc_ce_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::adc_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP);
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::adc_ce_zpg_partial()
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
	TMP = read(B|TMP);
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::adc_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|uint8_t(TMP+X));
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::adc_ce_zpx_partial()
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
	TMP = read(B|uint8_t(TMP+X));
	icount--;

	do_adc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::and_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	A &= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::and_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A &= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::and_ce_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	A &= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::and_ce_aby_partial()
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

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A &= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::and_ce_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A &= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::and_ce_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A &= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::and_ce_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A &= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::and_ce_idy_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A &= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::and_idz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A &= read(TMP+Z);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::and_idz_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A &= read(TMP+Z);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::and_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A &= read(B|TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::and_ce_zpg_partial()
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
	A &= read(B|TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::and_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A &= read(B|uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::and_ce_zpx_partial()
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
	A &= read(B|uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::asl_ce_aba_full()
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

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::asl_ce_aba_partial()
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

	TMP2 = do_asl(TMP2);

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


void m65ce02_device::asl_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::asl_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asl(TMP2);

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


void m65ce02_device::asl_ce_acc_full()
{

	A = do_asl(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::asl_ce_acc_partial()
{
switch(inst_substate) {
case 0:

	A = do_asl(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::asl_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::asl_ce_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::asl_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::asl_ce_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asl(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::asr_acc_full()
{

	A = do_asr(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::asr_acc_partial()
{
switch(inst_substate) {
case 0:

	A = do_asr(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::asr_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::asr_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::asr_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::asr_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_asr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::asw_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP3 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP3 = set_h(TMP3, read(TMP+1));
	icount--;

	P &= ~(F_C|F_N|F_Z);

	if(TMP3 & 0x8000)

		P |= F_C;

	TMP3 <<= 1;

	if(!TMP3)

		P |= F_Z;

	else if(TMP3 & 0x8000)

		P |= F_N;

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP, TMP3);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP3 >> 8);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m65ce02_device::asw_aba_partial()
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
	TMP3 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP3 = set_h(TMP3, read(TMP+1));
	icount--;

	P &= ~(F_C|F_N|F_Z);

	if(TMP3 & 0x8000)

		P |= F_C;

	TMP3 <<= 1;

	if(!TMP3)

		P |= F_Z;

	else if(TMP3 & 0x8000)

		P |= F_N;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(TMP, TMP3);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP3 >> 8);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::aug_iw3_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::aug_iw3_partial()
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
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bbr_ce_zpb_full()
{

	// Access pattern uncertain

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_pc();
	icount--;

	if(!(TMP2 & (1 << ((inst_state >> 4) & 7))))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bbr_ce_zpb_partial()
{
switch(inst_substate) {
case 0:

	// Access pattern uncertain

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
	TMP = read_pc();
	icount--;

	if(!(TMP2 & (1 << ((inst_state >> 4) & 7))))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bbs_ce_zpb_full()
{

	// Access pattern uncertain

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read_pc();
	icount--;

	if(TMP2 & (1 << ((inst_state >> 4) & 7)))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bbs_ce_zpb_partial()
{
switch(inst_substate) {
case 0:

	// Access pattern uncertain

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
	TMP = read_pc();
	icount--;

	if(TMP2 & (1 << ((inst_state >> 4) & 7)))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bcc_ce_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(!(P & F_C))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bcc_ce_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(!(P & F_C))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bcc_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(!(P & F_C))

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bcc_rw2_partial()
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

	if(!(P & F_C))

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bcs_ce_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(P & F_C)

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bcs_ce_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(P & F_C)

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bcs_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(P & F_C)

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bcs_rw2_partial()
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

	if(P & F_C)

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::beq_ce_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(P & F_Z)

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::beq_ce_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(P & F_Z)

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::beq_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(P & F_Z)

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::beq_rw2_partial()
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

	if(P & F_Z)

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bit_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	do_bit(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bit_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	do_bit(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bit_ce_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	do_bit(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bit_ce_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	do_bit(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bit_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	do_bit(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bit_ce_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	do_bit(read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bit_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|uint8_t(TMP+X));
	icount--;

	do_bit(TMP);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bit_ce_zpx_partial()
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
	TMP = read(B|uint8_t(TMP+X));
	icount--;

	do_bit(TMP);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bmi_ce_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(P & F_N)

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bmi_ce_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(P & F_N)

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bmi_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(P & F_N)

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bmi_rw2_partial()
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

	if(P & F_N)

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bne_ce_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(!(P & F_Z))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bne_ce_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(!(P & F_Z))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bne_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(!(P & F_Z))

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bne_rw2_partial()
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

	if(!(P & F_Z))

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bpl_ce_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(!(P & F_N))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bpl_ce_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(!(P & F_N))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bpl_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(!(P & F_N))

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bpl_rw2_partial()
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

	if(!(P & F_N))

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bra_ce_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bra_ce_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bra_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	PC += TMP - 1;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bra_rw2_partial()
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

	PC += TMP - 1;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::brk_ce_imp_full()
{

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

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 5; return; }
	write(SP, irq_taken || nmi_pending ? P & ~F_B : P);
	icount--;

	dec_SP_ce();

	if(nmi_pending) {

	if(icount == 0) { inst_substate = 6; return; }
		PC = read_arg(0xfffa);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
		PC = set_h(PC, read_arg(0xfffb));
	icount--;

		nmi_pending = false;

	} else {

	if(icount == 0) { inst_substate = 8; return; }
		PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 9; return; }
		PC = set_h(PC, read_arg(0xffff));
	icount--;

	}

	irq_taken = false;

	P = (P | F_I) & ~F_D; // Do *not* move after the prefetch

	if(icount == 0) { inst_substate = 10; return; }
	prefetch();
	icount--;

	inst_state = -1;

}

void m65ce02_device::brk_ce_imp_partial()
{
switch(inst_substate) {
case 0:

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

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(SP, irq_taken || nmi_pending ? P & ~F_B : P);
	icount--;

	dec_SP_ce();

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

	} else {

	if(icount == 0) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:
		PC = read_arg(0xfffe);
	icount--;

	if(icount == 0) { inst_substate = 9; return; }
	[[fallthrough]];
case 9:
		PC = set_h(PC, read_arg(0xffff));
	icount--;

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


void m65ce02_device::bsr_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, PC>>8);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	PC += TMP-1;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bsr_rw2_partial()
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
	write(SP, PC>>8);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_pc());
	icount--;

	PC += TMP-1;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bvc_ce_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(!(P & F_V))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bvc_ce_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(!(P & F_V))

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bvc_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(!(P & F_V))

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bvc_rw2_partial()
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

	if(!(P & F_V))

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bvs_ce_rel_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(P & F_V)

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bvs_ce_rel_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(P & F_V)

		PC += int8_t(TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::bvs_rw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(P & F_V)

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::bvs_rw2_partial()
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

	if(P & F_V)

		PC += TMP-1;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::clc_ce_imp_full()
{

	P &= ~F_C;

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::clc_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	P &= ~F_C;

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cld_ce_imp_full()
{

	P &= ~F_D;

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cld_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	P &= ~F_D;

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cle_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	P &= ~F_E;

	logerror("CLE\n");

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cle_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	P &= ~F_E;

	logerror("CLE\n");

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cli_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

	P &= ~F_I; // Do *not* move it before the prefetch

}

void m65ce02_device::cli_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

	P &= ~F_I; // Do *not* move it before the prefetch

}
	inst_substate = 0;
}


void m65ce02_device::clv_ce_imp_full()
{

	P &= ~F_V;

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::clv_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	P &= ~F_V;

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cmp_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP);
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cmp_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP);
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cmp_ce_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP);
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cmp_ce_aby_partial()
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

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP);
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cmp_ce_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	do_cmp(A, read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cmp_ce_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	do_cmp(A, read(TMP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cmp_ce_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	do_cmp(A, read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cmp_ce_idy_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	do_cmp(A, read(TMP+Y));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cmp_idz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	do_cmp(A, read(TMP+Z));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cmp_idz_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	do_cmp(A, read(TMP+Z));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cmp_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP);
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cmp_ce_zpg_partial()
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
	TMP = read(B|TMP);
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cmp_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(B|uint8_t(TMP+X));
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cmp_ce_zpx_partial()
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
	TMP = read(B|uint8_t(TMP+X));
	icount--;

	do_cmp(A, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cpx_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP);
	icount--;

	do_cmp(X, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cpx_ce_zpg_partial()
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
	TMP = read(B|TMP);
	icount--;

	do_cmp(X, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cpy_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP);
	icount--;

	do_cmp(Y, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cpy_ce_zpg_partial()
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
	TMP = read(B|TMP);
	icount--;

	do_cmp(Y, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cpz_aba_full()
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

	do_cmp(Z, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cpz_aba_partial()
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

	do_cmp(Z, TMP);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cpz_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	do_cmp(Z, TMP);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cpz_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	do_cmp(Z, TMP);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::cpz_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP);
	icount--;

	do_cmp(Z, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::cpz_zpg_partial()
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
	TMP = read(B|TMP);
	icount--;

	do_cmp(Z, TMP);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::dec_ce_aba_full()
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

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::dec_ce_aba_partial()
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

	TMP2--;

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


void m65ce02_device::dec_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::dec_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	TMP2--;

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


void m65ce02_device::dec_ce_acc_full()
{

	A--;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::dec_ce_acc_partial()
{
switch(inst_substate) {
case 0:

	A--;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::dec_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::dec_ce_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::dec_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::dec_ce_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2--;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::dew_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	P &= ~(F_N|F_Z);

	TMP++;

	if(!TMP)

		P |= F_Z;

	else if(TMP & 0x8000)

		P |= F_N;

	TMP2++;

	if(icount == 0) { inst_substate = 4; return; }
	write(B|TMP2, TMP);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 5; return; }
	write(B|TMP2, TMP >> 8);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m65ce02_device::dew_zpg_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	P &= ~(F_N|F_Z);

	TMP++;

	if(!TMP)

		P |= F_Z;

	else if(TMP & 0x8000)

		P |= F_N;

	TMP2++;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(B|TMP2, TMP);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(B|TMP2, TMP >> 8);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::dex_ce_imp_full()
{

	X--;

	set_nz(X);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::dex_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	X--;

	set_nz(X);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::dey_ce_imp_full()
{

	Y--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::dey_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	Y--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::dez_imp_full()
{

	Z--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::dez_imp_partial()
{
switch(inst_substate) {
case 0:

	Z--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::eor_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	A ^= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::eor_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A ^= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::eor_ce_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	A ^= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::eor_ce_aby_partial()
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

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A ^= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::eor_ce_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A ^= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::eor_ce_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A ^= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::eor_ce_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A ^= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::eor_ce_idy_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A ^= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::eor_idz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A ^= read(TMP+Z);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::eor_idz_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A ^= read(TMP+Z);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::eor_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A ^= read(B|TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::eor_ce_zpg_partial()
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
	A ^= read(B|TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::eor_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A ^= read(B|uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::eor_ce_zpx_partial()
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
	A ^= read(B|uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::inc_ce_aba_full()
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

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::inc_ce_aba_partial()
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

	TMP2++;

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


void m65ce02_device::inc_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::inc_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	TMP2++;

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


void m65ce02_device::inc_ce_acc_full()
{

	A++;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::inc_ce_acc_partial()
{
switch(inst_substate) {
case 0:

	A++;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::inc_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::inc_ce_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::inc_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::inc_ce_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2++;

	set_nz(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::inw_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	P &= ~(F_N|F_Z);

	TMP++;

	if(!TMP)

		P |= F_Z;

	else if(TMP & 0x8000)

		P |= F_N;

	TMP2--;

	if(icount == 0) { inst_substate = 4; return; }
	write(B|TMP2, TMP);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 5; return; }
	write(B|TMP2, TMP >> 8);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m65ce02_device::inw_zpg_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	P &= ~(F_N|F_Z);

	TMP++;

	if(!TMP)

		P |= F_Z;

	else if(TMP & 0x8000)

		P |= F_N;

	TMP2--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(B|TMP2, TMP);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(B|TMP2, TMP >> 8);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::inx_ce_imp_full()
{

	X++;

	set_nz(X);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::inx_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	X++;

	set_nz(X);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::iny_ce_imp_full()
{

	Y++;

	set_nz(Y);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::iny_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	Y++;

	set_nz(Y);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::inz_imp_full()
{

	Z++;

	set_nz(Z);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::inz_imp_partial()
{
switch(inst_substate) {
case 0:

	Z++;

	set_nz(Z);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::jmp_ce_iax_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

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

void m65ce02_device::jmp_ce_iax_partial()
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

	TMP += X;

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


void m65ce02_device::jmp_ce_ind_full()
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

void m65ce02_device::jmp_ce_ind_partial()
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


void m65ce02_device::jsr_ce_adr_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, PC>>8);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	PC = TMP;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::jsr_ce_adr_partial()
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
	write(SP, PC>>8);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_pc());
	icount--;

	PC = TMP;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::jsr_iax_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, PC>>8);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	PC = set_h(PC, read(TMP+1));
	icount--;

	PC += X;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m65ce02_device::jsr_iax_partial()
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
	write(SP, PC>>8);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	PC = set_h(PC, read(TMP+1));
	icount--;

	PC += X;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::jsr_ind_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, PC>>8);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	PC = set_h(PC, read(TMP+1));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m65ce02_device::jsr_ind_partial()
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
	write(SP, PC>>8);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, PC);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	PC = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	PC = set_h(PC, read(TMP+1));
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lda_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	A = read(TMP + X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lda_ce_abx_partial()
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
	A = read(TMP + X);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lda_ce_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	A = read(TMP + Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lda_ce_aby_partial()
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
	A = read(TMP + Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lda_ce_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A = read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lda_ce_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A = read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lda_ce_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A = read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lda_ce_idy_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A = read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lda_idz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A = read(TMP+Z);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lda_idz_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A = read(TMP+Z);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lda_isy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_pc();
	icount--;

	if(P & F_E)

		TMP = set_l(SP, SP+TMP);

	else

		TMP = SP + TMP;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	TMP++;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = TMP2 | (read(TMP) << 8);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	A = read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lda_isy_partial()
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
	TMP = read_pc();
	icount--;

	if(P & F_E)

		TMP = set_l(SP, SP+TMP);

	else

		TMP = SP + TMP;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	TMP++;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = TMP2 | (read(TMP) << 8);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	A = read(TMP+Y);
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


void m65ce02_device::lda_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A = read(B|TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lda_ce_zpg_partial()
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
	A = read(B|TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lda_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A = read(B|uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lda_ce_zpx_partial()
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
	A = read(B|uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ldx_ce_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	X = read(TMP + Y);
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ldx_ce_aby_partial()
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
	X = read(TMP + Y);
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ldx_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	X = read(B|TMP);
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ldx_ce_zpg_partial()
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
	X = read(B|TMP);
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ldx_ce_zpy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	X = read(B|uint8_t(TMP+Y));
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ldx_ce_zpy_partial()
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
	X = read(B|uint8_t(TMP+Y));
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ldy_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	Y = read(TMP);
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ldy_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	Y = read(TMP);
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ldy_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	Y = read(B|TMP);
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ldy_ce_zpg_partial()
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
	Y = read(B|TMP);
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ldy_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	Y = read(B|uint8_t(TMP+X));
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ldy_ce_zpx_partial()
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
	Y = read(B|uint8_t(TMP+X));
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ldz_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	Z = read(TMP);
	icount--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ldz_aba_partial()
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
	Z = read(TMP);
	icount--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ldz_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	Z = read(TMP + X);
	icount--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ldz_abx_partial()
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
	Z = read(TMP + X);
	icount--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ldz_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	Z = read_pc();
	icount--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ldz_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	Z = read_pc();
	icount--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lsr_ce_aba_full()
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

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lsr_ce_aba_partial()
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

	TMP2 = do_lsr(TMP2);

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


void m65ce02_device::lsr_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read(set_l(TMP, TMP+X));
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lsr_ce_abx_partial()
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
	read(set_l(TMP, TMP+X));
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lsr_ce_acc_full()
{

	A = do_lsr(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lsr_ce_acc_partial()
{
switch(inst_substate) {
case 0:

	A = do_lsr(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lsr_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lsr_ce_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::lsr_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::lsr_ce_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_lsr(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::neg_acc_full()
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

void m65ce02_device::neg_acc_partial()
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


void m65ce02_device::ora_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	A |= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ora_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A |= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ora_ce_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	A |= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ora_ce_aby_partial()
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

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	A |= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ora_ce_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A |= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ora_ce_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A |= read(TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ora_ce_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A |= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ora_ce_idy_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A |= read(TMP+Y);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ora_idz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	A |= read(TMP+Z);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ora_idz_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	A |= read(TMP+Z);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ora_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A |= read(B|TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ora_ce_zpg_partial()
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
	A |= read(B|TMP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ora_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	A |= read(B|uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ora_ce_zpx_partial()
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
	A |= read(B|uint8_t(TMP+X));
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::pha_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, A);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::pha_ce_imp_partial()
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

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::php_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, P);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::php_ce_imp_partial()
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
	write(SP, P);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::phw_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP3 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP3 = set_h(TMP3, read(TMP+1));
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 5; return; }
	write(SP, TMP3);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 6; return; }
	write(SP, TMP3 >> 8);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m65ce02_device::phw_aba_partial()
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
	TMP3 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP3 = set_h(TMP3, read(TMP+1));
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(SP, TMP3);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(SP, TMP3 >> 8);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::phw_iw2_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	write(SP, TMP);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	write(SP, TMP >> 8);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::phw_iw2_partial()
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

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(SP, TMP);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(SP, TMP >> 8);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::phx_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, X);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::phx_ce_imp_partial()
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
	write(SP, X);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::phy_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, Y);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::phy_ce_imp_partial()
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
	write(SP, Y);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::phz_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(SP, Z);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::phz_imp_partial()
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
	write(SP, Z);
	icount--;

	dec_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::pla_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	A = read(SP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::pla_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	A = read(SP);
	icount--;

	set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::plp_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(SP) | F_B;
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

	P = TMP; // Do *not* move it before the prefetch

}

void m65ce02_device::plp_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(SP) | F_B;
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

	P = TMP; // Do *not* move it before the prefetch

}
	inst_substate = 0;
}


void m65ce02_device::plx_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	X = read(SP);
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::plx_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	X = read(SP);
	icount--;

	set_nz(X);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ply_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	Y = read(SP);
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ply_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	Y = read(SP);
	icount--;

	set_nz(Y);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::plz_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	Z = read(SP);
	icount--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::plz_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	Z = read(SP);
	icount--;

	set_nz(Z);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::rmb_ce_bzp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 &= ~(1 << ((inst_state >> 4) & 7));

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::rmb_ce_bzp_partial()
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

	TMP2 &= ~(1 << ((inst_state >> 4) & 7));

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::rol_ce_aba_full()
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

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::rol_ce_aba_partial()
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

	TMP2 = do_rol(TMP2);

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


void m65ce02_device::rol_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::rol_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_rol(TMP2);

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


void m65ce02_device::rol_ce_acc_full()
{

	A = do_rol(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::rol_ce_acc_partial()
{
switch(inst_substate) {
case 0:

	A = do_rol(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::rol_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::rol_ce_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::rol_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::rol_ce_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_rol(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ror_ce_aba_full()
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

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ror_ce_aba_partial()
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

	TMP2 = do_ror(TMP2);

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


void m65ce02_device::ror_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ror_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_ror(TMP2);

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


void m65ce02_device::ror_ce_acc_full()
{

	A = do_ror(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ror_ce_acc_partial()
{
switch(inst_substate) {
case 0:

	A = do_ror(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ror_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ror_ce_zpg_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = B|read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::ror_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::ror_ce_zpx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	TMP = B|uint8_t(TMP+X);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP2 = read(TMP);
	icount--;

	TMP2 = do_ror(TMP2);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::row_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP3 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	TMP3 = set_h(TMP3, read(TMP+1));
	icount--;

	TMP2 = P;

	P &= ~(F_C|F_N|F_Z);

	if(TMP3 & 0x8000)

		P |= F_C;

	TMP3 <<= 1;

	if(TMP2 & F_C)

		TMP3 |= 0x0001;

	if(!TMP3)

		P |= F_Z;

	else if(TMP3 & 0x8000)

		P |= F_N;

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP, TMP3);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	write(TMP, TMP3 >> 8);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m65ce02_device::row_aba_partial()
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
	TMP3 = read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP3 = set_h(TMP3, read(TMP+1));
	icount--;

	TMP2 = P;

	P &= ~(F_C|F_N|F_Z);

	if(TMP3 & 0x8000)

		P |= F_C;

	TMP3 <<= 1;

	if(TMP2 & F_C)

		TMP3 |= 0x0001;

	if(!TMP3)

		P |= F_Z;

	else if(TMP3 & 0x8000)

		P |= F_N;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(TMP, TMP3);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	write(TMP, TMP3 >> 8);
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::rti_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	P = read(SP) | F_B;
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	PC = read(SP);
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 4; return; }
	PC = set_h(PC, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::rti_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	P = read(SP) | F_B;
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	PC = read(SP);
	icount--;

	inc_SP_ce();

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


void m65ce02_device::rtn_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(P & F_E)

		SP = set_l(SP, SP+TMP);

	else

		SP += TMP;

	if(icount == 0) { inst_substate = 2; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	PC = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 5; return; }
	PC = set_h(PC, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	prefetch();
	icount--;

}

void m65ce02_device::rtn_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	if(P & F_E)

		SP = set_l(SP, SP+TMP);

	else

		SP += TMP;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	PC = read(SP);
	icount--;

	inc_SP();

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	PC = set_h(PC, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::rts_ce_imp_full()
{

	inc_SP_ce();

	if(icount == 0) { inst_substate = 1; return; }
	PC = read(SP);
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	PC = set_h(PC, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::rts_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	inc_SP_ce();

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	PC = read(SP);
	icount--;

	inc_SP_ce();

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	PC = set_h(PC, read(SP));
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	read_pc();
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sbc_ce_aba_full()
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

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sbc_ce_aba_partial()
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

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sbc_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP);
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sbc_ce_abx_partial()
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

	TMP += X;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP);
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sbc_ce_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(TMP);
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sbc_ce_aby_partial()
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

	TMP += Y;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = read(TMP);
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sbc_ce_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	do_sbc(read(TMP));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sbc_ce_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	do_sbc(read(TMP));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sbc_ce_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	do_sbc(read(TMP+Y));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sbc_ce_idy_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	do_sbc(read(TMP+Y));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sbc_idz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	do_sbc(read(TMP+Z));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sbc_idz_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	do_sbc(read(TMP+Z));
	icount--;

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sbc_ce_imm_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sbc_ce_imm_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP = read_pc();
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sbc_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP);
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sbc_ce_zpg_partial()
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
	TMP = read(B|TMP);
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sbc_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	read(TMP);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = read(B|uint8_t(TMP+X));
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sbc_ce_zpx_partial()
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
	TMP = read(B|uint8_t(TMP+X));
	icount--;

	do_sbc(TMP);

	if(P & F_D)

		set_nz(A);

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sec_ce_imp_full()
{

	P |= F_C;

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sec_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	P |= F_C;

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sed_ce_imp_full()
{

	P |= F_D;

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sed_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	P |= F_D;

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::see_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	P |= F_E;

	if(icount == 0) { inst_substate = 2; return; }
	prefetch();
	icount--;

}

void m65ce02_device::see_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	read_pc_noinc();
	icount--;

	P |= F_E;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sei_ce_imp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

	P |= F_I; // Do *not* move it before the prefetch

}

void m65ce02_device::sei_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

	P |= F_I; // Do *not* move it before the prefetch

}
	inst_substate = 0;
}


void m65ce02_device::smb_ce_bzp_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	TMP2 |= 1 << ((inst_state >> 4) & 7);

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::smb_ce_bzp_partial()
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

	TMP2 |= 1 << ((inst_state >> 4) & 7);

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sta_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP+X, A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sta_ce_abx_partial()
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
	write(TMP+X, A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sta_ce_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP+Y, A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sta_ce_aby_partial()
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
	write(TMP+Y, A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sta_ce_idx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, A);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sta_ce_idx_partial()
{
switch(inst_substate) {
case 0:

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	TMP2 = read_pc();
	icount--;

	TMP2 += X;

	if(icount == 0) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(TMP, A);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sta_ce_idy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP+Y, A);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sta_ce_idy_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(TMP+Y, A);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sta_idz_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP2 = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP+Z, A);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sta_idz_partial()
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
	TMP = read(B|TMP2);
	icount--;

	TMP2++;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP = set_h(TMP, read(B|TMP2));
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	write(TMP+Z, A);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sta_isy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	read_pc_noinc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = read_pc();
	icount--;

	if(P & F_E)

		TMP = set_l(SP, SP+TMP);

	else

		TMP = SP + TMP;

	if(icount == 0) { inst_substate = 3; return; }
	TMP2 = read(TMP);
	icount--;

	TMP++;

	if(icount == 0) { inst_substate = 4; return; }
	TMP = TMP2 | (read(TMP) << 8);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	write(TMP+Y, A);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sta_isy_partial()
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
	TMP = read_pc();
	icount--;

	if(P & F_E)

		TMP = set_l(SP, SP+TMP);

	else

		TMP = SP + TMP;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	TMP2 = read(TMP);
	icount--;

	TMP++;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	TMP = TMP2 | (read(TMP) << 8);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:
	write(TMP+Y, A);
	icount--;

	if(icount == 0) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sta_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(B|TMP, A);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sta_ce_zpg_partial()
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
	write(B|TMP, A);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sta_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(B|uint8_t(TMP+X), A);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sta_ce_zpx_partial()
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
	write(B|uint8_t(TMP+X), A);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::stx_aby_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP+Y, X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::stx_aby_partial()
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
	write(TMP+Y, X);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::stx_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(B|TMP, X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::stx_ce_zpg_partial()
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
	write(B|TMP, X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::stx_ce_zpy_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(B|uint8_t(TMP+Y), X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::stx_ce_zpy_partial()
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
	write(B|uint8_t(TMP+Y), X);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sty_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP+X, Y);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sty_abx_partial()
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
	write(TMP+X, Y);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sty_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(B|TMP, Y);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sty_ce_zpg_partial()
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
	write(B|TMP, Y);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::sty_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(B|uint8_t(TMP+X), Y);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::sty_ce_zpx_partial()
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
	write(B|uint8_t(TMP+X), Y);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::stz_ce_aba_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::stz_ce_aba_partial()
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
	write(TMP, A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::stz_ce_abx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP = set_h(TMP, read_pc());
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP+X, A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::stz_ce_abx_partial()
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
	write(TMP+X, A);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::stz_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(B|TMP, Z);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::stz_ce_zpg_partial()
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
	write(B|TMP, Z);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::stz_ce_zpx_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	write(B|uint8_t(TMP+X), Z);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	prefetch();
	icount--;

}

void m65ce02_device::stz_ce_zpx_partial()
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
	write(B|uint8_t(TMP+X), Z);
	icount--;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tab_imp_full()
{

	B = A << 8;

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tab_imp_partial()
{
switch(inst_substate) {
case 0:

	B = A << 8;

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tax_ce_imp_full()
{

	X = A;

	set_nz(X);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tax_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	X = A;

	set_nz(X);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tay_ce_imp_full()
{

	Y = A;

	set_nz(Y);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tay_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	Y = A;

	set_nz(Y);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::taz_imp_full()
{

	Z = A;

	set_nz(Z);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::taz_imp_partial()
{
switch(inst_substate) {
case 0:

	Z = A;

	set_nz(Z);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tba_imp_full()
{

	A = B >> 8;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tba_imp_partial()
{
switch(inst_substate) {
case 0:

	A = B >> 8;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::trb_ce_aba_full()
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

	if(A & TMP2)

		P &= ~F_Z;

	else

		P |= F_Z;

	TMP2 &= ~A;

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::trb_ce_aba_partial()
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

	if(A & TMP2)

		P &= ~F_Z;

	else

		P |= F_Z;

	TMP2 &= ~A;

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


void m65ce02_device::trb_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(A & TMP2)

		P &= ~F_Z;

	else

		P |= F_Z;

	TMP2 &= ~A;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::trb_ce_zpg_partial()
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

	if(A & TMP2)

		P &= ~F_Z;

	else

		P |= F_Z;

	TMP2 &= ~A;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tsb_ce_aba_full()
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

	if(A & TMP2)

		P &= ~F_Z;

	else

		P |= F_Z;

	TMP2 |= A;

	if(icount == 0) { inst_substate = 4; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 5; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tsb_ce_aba_partial()
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

	if(A & TMP2)

		P &= ~F_Z;

	else

		P |= F_Z;

	TMP2 |= A;

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


void m65ce02_device::tsb_ce_zpg_full()
{

	if(icount == 0) { inst_substate = 1; return; }
	TMP = read_pc();
	icount--;

	if(icount == 0) { inst_substate = 2; return; }
	TMP2 = read(TMP);
	icount--;

	if(A & TMP2)

		P &= ~F_Z;

	else

		P |= F_Z;

	TMP2 |= A;

	if(icount == 0) { inst_substate = 3; return; }
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tsb_ce_zpg_partial()
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

	if(A & TMP2)

		P &= ~F_Z;

	else

		P |= F_Z;

	TMP2 |= A;

	if(icount == 0) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:
	write(TMP, TMP2);
	icount--;

	if(icount == 0) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tsx_ce_imp_full()
{

	X = SP;

	set_nz(X);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tsx_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	X = SP;

	set_nz(X);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tsy_imp_full()
{

	Y = SP >> 8;

	set_nz(Y);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tsy_imp_partial()
{
switch(inst_substate) {
case 0:

	Y = SP >> 8;

	set_nz(Y);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::txa_ce_imp_full()
{

	A = X;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::txa_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	A = X;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::txs_ce_imp_full()
{

	SP = set_l(SP, X);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch_noirq();
	icount--;

}

void m65ce02_device::txs_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	SP = set_l(SP, X);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch_noirq();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tys_imp_full()
{

	SP = set_h(SP, Y);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tys_imp_partial()
{
switch(inst_substate) {
case 0:

	SP = set_h(SP, Y);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tya_ce_imp_full()
{

	A = Y;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tya_ce_imp_partial()
{
switch(inst_substate) {
case 0:

	A = Y;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}


void m65ce02_device::tza_imp_full()
{

	A = Z;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	prefetch();
	icount--;

}

void m65ce02_device::tza_imp_partial()
{
switch(inst_substate) {
case 0:

	A = Z;

	set_nz(A);

	if(icount == 0) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:
	prefetch();
	icount--;

}
	inst_substate = 0;
}




void m65ce02_device::do_exec_full()
{
	switch(inst_state) {

	case 0x00: brk_ce_imp_full(); break;
	case 0x01: ora_ce_idx_full(); break;
	case 0x02: cle_imp_full(); break;
	case 0x03: see_imp_full(); break;
	case 0x04: tsb_ce_zpg_full(); break;
	case 0x05: ora_ce_zpg_full(); break;
	case 0x06: asl_ce_zpg_full(); break;
	case 0x07: rmb_ce_bzp_full(); break;
	case 0x08: php_ce_imp_full(); break;
	case 0x09: ora_imm_full(); break;
	case 0x0a: asl_ce_acc_full(); break;
	case 0x0b: tsy_imp_full(); break;
	case 0x0c: tsb_ce_aba_full(); break;
	case 0x0d: ora_aba_full(); break;
	case 0x0e: asl_ce_aba_full(); break;
	case 0x0f: bbr_ce_zpb_full(); break;
	case 0x10: bpl_ce_rel_full(); break;
	case 0x11: ora_ce_idy_full(); break;
	case 0x12: ora_idz_full(); break;
	case 0x13: bpl_rw2_full(); break;
	case 0x14: trb_ce_zpg_full(); break;
	case 0x15: ora_ce_zpx_full(); break;
	case 0x16: asl_ce_zpx_full(); break;
	case 0x17: rmb_ce_bzp_full(); break;
	case 0x18: clc_ce_imp_full(); break;
	case 0x19: ora_ce_aby_full(); break;
	case 0x1a: inc_ce_acc_full(); break;
	case 0x1b: inz_imp_full(); break;
	case 0x1c: trb_ce_aba_full(); break;
	case 0x1d: ora_ce_abx_full(); break;
	case 0x1e: asl_ce_abx_full(); break;
	case 0x1f: bbr_ce_zpb_full(); break;
	case 0x20: jsr_ce_adr_full(); break;
	case 0x21: and_ce_idx_full(); break;
	case 0x22: jsr_ind_full(); break;
	case 0x23: jsr_iax_full(); break;
	case 0x24: bit_ce_zpg_full(); break;
	case 0x25: and_ce_zpg_full(); break;
	case 0x26: rol_ce_zpg_full(); break;
	case 0x27: rmb_ce_bzp_full(); break;
	case 0x28: plp_ce_imp_full(); break;
	case 0x29: and_imm_full(); break;
	case 0x2a: rol_ce_acc_full(); break;
	case 0x2b: tys_imp_full(); break;
	case 0x2c: bit_aba_full(); break;
	case 0x2d: and_aba_full(); break;
	case 0x2e: rol_ce_aba_full(); break;
	case 0x2f: bbr_ce_zpb_full(); break;
	case 0x30: bmi_ce_rel_full(); break;
	case 0x31: and_ce_idy_full(); break;
	case 0x32: and_idz_full(); break;
	case 0x33: bmi_rw2_full(); break;
	case 0x34: bit_ce_zpx_full(); break;
	case 0x35: and_ce_zpx_full(); break;
	case 0x36: rol_ce_zpx_full(); break;
	case 0x37: rmb_ce_bzp_full(); break;
	case 0x38: sec_ce_imp_full(); break;
	case 0x39: and_ce_aby_full(); break;
	case 0x3a: dec_ce_acc_full(); break;
	case 0x3b: dez_imp_full(); break;
	case 0x3c: bit_ce_abx_full(); break;
	case 0x3d: and_ce_abx_full(); break;
	case 0x3e: rol_ce_abx_full(); break;
	case 0x3f: bbr_ce_zpb_full(); break;
	case 0x40: rti_ce_imp_full(); break;
	case 0x41: eor_ce_idx_full(); break;
	case 0x42: neg_acc_full(); break;
	case 0x43: asr_acc_full(); break;
	case 0x44: asr_zpg_full(); break;
	case 0x45: eor_ce_zpg_full(); break;
	case 0x46: lsr_ce_zpg_full(); break;
	case 0x47: rmb_ce_bzp_full(); break;
	case 0x48: pha_ce_imp_full(); break;
	case 0x49: eor_imm_full(); break;
	case 0x4a: lsr_ce_acc_full(); break;
	case 0x4b: taz_imp_full(); break;
	case 0x4c: jmp_adr_full(); break;
	case 0x4d: eor_aba_full(); break;
	case 0x4e: lsr_ce_aba_full(); break;
	case 0x4f: bbr_ce_zpb_full(); break;
	case 0x50: bvc_ce_rel_full(); break;
	case 0x51: eor_ce_idy_full(); break;
	case 0x52: eor_idz_full(); break;
	case 0x53: bvc_rw2_full(); break;
	case 0x54: asr_zpx_full(); break;
	case 0x55: eor_ce_zpx_full(); break;
	case 0x56: lsr_ce_zpx_full(); break;
	case 0x57: rmb_ce_bzp_full(); break;
	case 0x58: cli_ce_imp_full(); break;
	case 0x59: eor_ce_aby_full(); break;
	case 0x5a: phy_ce_imp_full(); break;
	case 0x5b: tab_imp_full(); break;
	case 0x5c: aug_iw3_full(); break;
	case 0x5d: eor_ce_abx_full(); break;
	case 0x5e: lsr_ce_abx_full(); break;
	case 0x5f: bbr_ce_zpb_full(); break;
	case 0x60: rts_ce_imp_full(); break;
	case 0x61: adc_ce_idx_full(); break;
	case 0x62: rtn_imm_full(); break;
	case 0x63: bsr_rw2_full(); break;
	case 0x64: stz_ce_zpg_full(); break;
	case 0x65: adc_ce_zpg_full(); break;
	case 0x66: ror_ce_zpg_full(); break;
	case 0x67: rmb_ce_bzp_full(); break;
	case 0x68: pla_ce_imp_full(); break;
	case 0x69: adc_ce_imm_full(); break;
	case 0x6a: ror_ce_acc_full(); break;
	case 0x6b: tza_imp_full(); break;
	case 0x6c: jmp_ce_ind_full(); break;
	case 0x6d: adc_ce_aba_full(); break;
	case 0x6e: ror_ce_aba_full(); break;
	case 0x6f: bbr_ce_zpb_full(); break;
	case 0x70: bvs_ce_rel_full(); break;
	case 0x71: adc_ce_idy_full(); break;
	case 0x72: adc_idz_full(); break;
	case 0x73: bvs_rw2_full(); break;
	case 0x74: stz_ce_zpx_full(); break;
	case 0x75: adc_ce_zpx_full(); break;
	case 0x76: ror_ce_zpx_full(); break;
	case 0x77: rmb_ce_bzp_full(); break;
	case 0x78: sei_ce_imp_full(); break;
	case 0x79: adc_ce_aby_full(); break;
	case 0x7a: ply_ce_imp_full(); break;
	case 0x7b: tba_imp_full(); break;
	case 0x7c: jmp_ce_iax_full(); break;
	case 0x7d: adc_ce_abx_full(); break;
	case 0x7e: ror_ce_abx_full(); break;
	case 0x7f: bbr_ce_zpb_full(); break;
	case 0x80: bra_ce_rel_full(); break;
	case 0x81: sta_ce_idx_full(); break;
	case 0x82: sta_isy_full(); break;
	case 0x83: bra_rw2_full(); break;
	case 0x84: sty_ce_zpg_full(); break;
	case 0x85: sta_ce_zpg_full(); break;
	case 0x86: stx_ce_zpg_full(); break;
	case 0x87: smb_ce_bzp_full(); break;
	case 0x88: dey_ce_imp_full(); break;
	case 0x89: bit_ce_imm_full(); break;
	case 0x8a: txa_ce_imp_full(); break;
	case 0x8b: sty_abx_full(); break;
	case 0x8c: sty_aba_full(); break;
	case 0x8d: sta_aba_full(); break;
	case 0x8e: stx_aba_full(); break;
	case 0x8f: bbs_ce_zpb_full(); break;
	case 0x90: bcc_ce_rel_full(); break;
	case 0x91: sta_ce_idy_full(); break;
	case 0x92: sta_idz_full(); break;
	case 0x93: bcc_rw2_full(); break;
	case 0x94: sty_ce_zpx_full(); break;
	case 0x95: sta_ce_zpx_full(); break;
	case 0x96: stx_ce_zpy_full(); break;
	case 0x97: smb_ce_bzp_full(); break;
	case 0x98: tya_ce_imp_full(); break;
	case 0x99: sta_ce_aby_full(); break;
	case 0x9a: txs_ce_imp_full(); break;
	case 0x9b: stx_aby_full(); break;
	case 0x9c: stz_ce_aba_full(); break;
	case 0x9d: sta_ce_abx_full(); break;
	case 0x9e: stz_ce_abx_full(); break;
	case 0x9f: bbs_ce_zpb_full(); break;
	case 0xa0: ldy_imm_full(); break;
	case 0xa1: lda_ce_idx_full(); break;
	case 0xa2: ldx_imm_full(); break;
	case 0xa3: ldz_imm_full(); break;
	case 0xa4: ldy_ce_zpg_full(); break;
	case 0xa5: lda_ce_zpg_full(); break;
	case 0xa6: ldx_ce_zpg_full(); break;
	case 0xa7: smb_ce_bzp_full(); break;
	case 0xa8: tay_ce_imp_full(); break;
	case 0xa9: lda_imm_full(); break;
	case 0xaa: tax_ce_imp_full(); break;
	case 0xab: ldz_aba_full(); break;
	case 0xac: ldy_aba_full(); break;
	case 0xad: lda_aba_full(); break;
	case 0xae: ldx_aba_full(); break;
	case 0xaf: bbs_ce_zpb_full(); break;
	case 0xb0: bcs_ce_rel_full(); break;
	case 0xb1: lda_ce_idy_full(); break;
	case 0xb2: lda_idz_full(); break;
	case 0xb3: bcs_rw2_full(); break;
	case 0xb4: ldy_ce_zpx_full(); break;
	case 0xb5: lda_ce_zpx_full(); break;
	case 0xb6: ldx_ce_zpy_full(); break;
	case 0xb7: smb_ce_bzp_full(); break;
	case 0xb8: clv_ce_imp_full(); break;
	case 0xb9: lda_ce_aby_full(); break;
	case 0xba: tsx_ce_imp_full(); break;
	case 0xbb: ldz_abx_full(); break;
	case 0xbc: ldy_ce_abx_full(); break;
	case 0xbd: lda_ce_abx_full(); break;
	case 0xbe: ldx_ce_aby_full(); break;
	case 0xbf: bbs_ce_zpb_full(); break;
	case 0xc0: cpy_imm_full(); break;
	case 0xc1: cmp_ce_idx_full(); break;
	case 0xc2: cpz_imm_full(); break;
	case 0xc3: dew_zpg_full(); break;
	case 0xc4: cpy_ce_zpg_full(); break;
	case 0xc5: cmp_ce_zpg_full(); break;
	case 0xc6: dec_ce_zpg_full(); break;
	case 0xc7: smb_ce_bzp_full(); break;
	case 0xc8: iny_ce_imp_full(); break;
	case 0xc9: cmp_imm_full(); break;
	case 0xca: dex_ce_imp_full(); break;
	case 0xcb: asw_aba_full(); break;
	case 0xcc: cpy_aba_full(); break;
	case 0xcd: cmp_aba_full(); break;
	case 0xce: dec_ce_aba_full(); break;
	case 0xcf: bbs_ce_zpb_full(); break;
	case 0xd0: bne_ce_rel_full(); break;
	case 0xd1: cmp_ce_idy_full(); break;
	case 0xd2: cmp_idz_full(); break;
	case 0xd3: bne_rw2_full(); break;
	case 0xd4: cpz_zpg_full(); break;
	case 0xd5: cmp_ce_zpx_full(); break;
	case 0xd6: dec_ce_zpx_full(); break;
	case 0xd7: smb_ce_bzp_full(); break;
	case 0xd8: cld_ce_imp_full(); break;
	case 0xd9: cmp_ce_aby_full(); break;
	case 0xda: phx_ce_imp_full(); break;
	case 0xdb: phz_imp_full(); break;
	case 0xdc: cpz_aba_full(); break;
	case 0xdd: cmp_ce_abx_full(); break;
	case 0xde: dec_ce_abx_full(); break;
	case 0xdf: bbs_ce_zpb_full(); break;
	case 0xe0: cpx_imm_full(); break;
	case 0xe1: sbc_ce_idx_full(); break;
	case 0xe2: lda_isy_full(); break;
	case 0xe3: inw_zpg_full(); break;
	case 0xe4: cpx_ce_zpg_full(); break;
	case 0xe5: sbc_ce_zpg_full(); break;
	case 0xe6: inc_ce_zpg_full(); break;
	case 0xe7: smb_ce_bzp_full(); break;
	case 0xe8: inx_ce_imp_full(); break;
	case 0xe9: sbc_ce_imm_full(); break;
	case 0xea: nop_c_imp_full(); break;
	case 0xeb: row_aba_full(); break;
	case 0xec: cpx_aba_full(); break;
	case 0xed: sbc_ce_aba_full(); break;
	case 0xee: inc_ce_aba_full(); break;
	case 0xef: bbs_ce_zpb_full(); break;
	case 0xf0: beq_ce_rel_full(); break;
	case 0xf1: sbc_ce_idy_full(); break;
	case 0xf2: sbc_idz_full(); break;
	case 0xf3: beq_rw2_full(); break;
	case 0xf4: phw_iw2_full(); break;
	case 0xf5: sbc_ce_zpx_full(); break;
	case 0xf6: inc_ce_zpx_full(); break;
	case 0xf7: smb_ce_bzp_full(); break;
	case 0xf8: sed_ce_imp_full(); break;
	case 0xf9: sbc_ce_aby_full(); break;
	case 0xfa: plx_ce_imp_full(); break;
	case 0xfb: plz_imp_full(); break;
	case 0xfc: phw_aba_full(); break;
	case 0xfd: sbc_ce_abx_full(); break;
	case 0xfe: inc_ce_abx_full(); break;
	case 0xff: bbs_ce_zpb_full(); break;
	case STATE_RESET: reset_c_full(); break;
	}
}

void m65ce02_device::do_exec_partial()
{
	switch(inst_state) {

	case 0x00: brk_ce_imp_partial(); break;
	case 0x01: ora_ce_idx_partial(); break;
	case 0x02: cle_imp_partial(); break;
	case 0x03: see_imp_partial(); break;
	case 0x04: tsb_ce_zpg_partial(); break;
	case 0x05: ora_ce_zpg_partial(); break;
	case 0x06: asl_ce_zpg_partial(); break;
	case 0x07: rmb_ce_bzp_partial(); break;
	case 0x08: php_ce_imp_partial(); break;
	case 0x09: ora_imm_partial(); break;
	case 0x0a: asl_ce_acc_partial(); break;
	case 0x0b: tsy_imp_partial(); break;
	case 0x0c: tsb_ce_aba_partial(); break;
	case 0x0d: ora_aba_partial(); break;
	case 0x0e: asl_ce_aba_partial(); break;
	case 0x0f: bbr_ce_zpb_partial(); break;
	case 0x10: bpl_ce_rel_partial(); break;
	case 0x11: ora_ce_idy_partial(); break;
	case 0x12: ora_idz_partial(); break;
	case 0x13: bpl_rw2_partial(); break;
	case 0x14: trb_ce_zpg_partial(); break;
	case 0x15: ora_ce_zpx_partial(); break;
	case 0x16: asl_ce_zpx_partial(); break;
	case 0x17: rmb_ce_bzp_partial(); break;
	case 0x18: clc_ce_imp_partial(); break;
	case 0x19: ora_ce_aby_partial(); break;
	case 0x1a: inc_ce_acc_partial(); break;
	case 0x1b: inz_imp_partial(); break;
	case 0x1c: trb_ce_aba_partial(); break;
	case 0x1d: ora_ce_abx_partial(); break;
	case 0x1e: asl_ce_abx_partial(); break;
	case 0x1f: bbr_ce_zpb_partial(); break;
	case 0x20: jsr_ce_adr_partial(); break;
	case 0x21: and_ce_idx_partial(); break;
	case 0x22: jsr_ind_partial(); break;
	case 0x23: jsr_iax_partial(); break;
	case 0x24: bit_ce_zpg_partial(); break;
	case 0x25: and_ce_zpg_partial(); break;
	case 0x26: rol_ce_zpg_partial(); break;
	case 0x27: rmb_ce_bzp_partial(); break;
	case 0x28: plp_ce_imp_partial(); break;
	case 0x29: and_imm_partial(); break;
	case 0x2a: rol_ce_acc_partial(); break;
	case 0x2b: tys_imp_partial(); break;
	case 0x2c: bit_aba_partial(); break;
	case 0x2d: and_aba_partial(); break;
	case 0x2e: rol_ce_aba_partial(); break;
	case 0x2f: bbr_ce_zpb_partial(); break;
	case 0x30: bmi_ce_rel_partial(); break;
	case 0x31: and_ce_idy_partial(); break;
	case 0x32: and_idz_partial(); break;
	case 0x33: bmi_rw2_partial(); break;
	case 0x34: bit_ce_zpx_partial(); break;
	case 0x35: and_ce_zpx_partial(); break;
	case 0x36: rol_ce_zpx_partial(); break;
	case 0x37: rmb_ce_bzp_partial(); break;
	case 0x38: sec_ce_imp_partial(); break;
	case 0x39: and_ce_aby_partial(); break;
	case 0x3a: dec_ce_acc_partial(); break;
	case 0x3b: dez_imp_partial(); break;
	case 0x3c: bit_ce_abx_partial(); break;
	case 0x3d: and_ce_abx_partial(); break;
	case 0x3e: rol_ce_abx_partial(); break;
	case 0x3f: bbr_ce_zpb_partial(); break;
	case 0x40: rti_ce_imp_partial(); break;
	case 0x41: eor_ce_idx_partial(); break;
	case 0x42: neg_acc_partial(); break;
	case 0x43: asr_acc_partial(); break;
	case 0x44: asr_zpg_partial(); break;
	case 0x45: eor_ce_zpg_partial(); break;
	case 0x46: lsr_ce_zpg_partial(); break;
	case 0x47: rmb_ce_bzp_partial(); break;
	case 0x48: pha_ce_imp_partial(); break;
	case 0x49: eor_imm_partial(); break;
	case 0x4a: lsr_ce_acc_partial(); break;
	case 0x4b: taz_imp_partial(); break;
	case 0x4c: jmp_adr_partial(); break;
	case 0x4d: eor_aba_partial(); break;
	case 0x4e: lsr_ce_aba_partial(); break;
	case 0x4f: bbr_ce_zpb_partial(); break;
	case 0x50: bvc_ce_rel_partial(); break;
	case 0x51: eor_ce_idy_partial(); break;
	case 0x52: eor_idz_partial(); break;
	case 0x53: bvc_rw2_partial(); break;
	case 0x54: asr_zpx_partial(); break;
	case 0x55: eor_ce_zpx_partial(); break;
	case 0x56: lsr_ce_zpx_partial(); break;
	case 0x57: rmb_ce_bzp_partial(); break;
	case 0x58: cli_ce_imp_partial(); break;
	case 0x59: eor_ce_aby_partial(); break;
	case 0x5a: phy_ce_imp_partial(); break;
	case 0x5b: tab_imp_partial(); break;
	case 0x5c: aug_iw3_partial(); break;
	case 0x5d: eor_ce_abx_partial(); break;
	case 0x5e: lsr_ce_abx_partial(); break;
	case 0x5f: bbr_ce_zpb_partial(); break;
	case 0x60: rts_ce_imp_partial(); break;
	case 0x61: adc_ce_idx_partial(); break;
	case 0x62: rtn_imm_partial(); break;
	case 0x63: bsr_rw2_partial(); break;
	case 0x64: stz_ce_zpg_partial(); break;
	case 0x65: adc_ce_zpg_partial(); break;
	case 0x66: ror_ce_zpg_partial(); break;
	case 0x67: rmb_ce_bzp_partial(); break;
	case 0x68: pla_ce_imp_partial(); break;
	case 0x69: adc_ce_imm_partial(); break;
	case 0x6a: ror_ce_acc_partial(); break;
	case 0x6b: tza_imp_partial(); break;
	case 0x6c: jmp_ce_ind_partial(); break;
	case 0x6d: adc_ce_aba_partial(); break;
	case 0x6e: ror_ce_aba_partial(); break;
	case 0x6f: bbr_ce_zpb_partial(); break;
	case 0x70: bvs_ce_rel_partial(); break;
	case 0x71: adc_ce_idy_partial(); break;
	case 0x72: adc_idz_partial(); break;
	case 0x73: bvs_rw2_partial(); break;
	case 0x74: stz_ce_zpx_partial(); break;
	case 0x75: adc_ce_zpx_partial(); break;
	case 0x76: ror_ce_zpx_partial(); break;
	case 0x77: rmb_ce_bzp_partial(); break;
	case 0x78: sei_ce_imp_partial(); break;
	case 0x79: adc_ce_aby_partial(); break;
	case 0x7a: ply_ce_imp_partial(); break;
	case 0x7b: tba_imp_partial(); break;
	case 0x7c: jmp_ce_iax_partial(); break;
	case 0x7d: adc_ce_abx_partial(); break;
	case 0x7e: ror_ce_abx_partial(); break;
	case 0x7f: bbr_ce_zpb_partial(); break;
	case 0x80: bra_ce_rel_partial(); break;
	case 0x81: sta_ce_idx_partial(); break;
	case 0x82: sta_isy_partial(); break;
	case 0x83: bra_rw2_partial(); break;
	case 0x84: sty_ce_zpg_partial(); break;
	case 0x85: sta_ce_zpg_partial(); break;
	case 0x86: stx_ce_zpg_partial(); break;
	case 0x87: smb_ce_bzp_partial(); break;
	case 0x88: dey_ce_imp_partial(); break;
	case 0x89: bit_ce_imm_partial(); break;
	case 0x8a: txa_ce_imp_partial(); break;
	case 0x8b: sty_abx_partial(); break;
	case 0x8c: sty_aba_partial(); break;
	case 0x8d: sta_aba_partial(); break;
	case 0x8e: stx_aba_partial(); break;
	case 0x8f: bbs_ce_zpb_partial(); break;
	case 0x90: bcc_ce_rel_partial(); break;
	case 0x91: sta_ce_idy_partial(); break;
	case 0x92: sta_idz_partial(); break;
	case 0x93: bcc_rw2_partial(); break;
	case 0x94: sty_ce_zpx_partial(); break;
	case 0x95: sta_ce_zpx_partial(); break;
	case 0x96: stx_ce_zpy_partial(); break;
	case 0x97: smb_ce_bzp_partial(); break;
	case 0x98: tya_ce_imp_partial(); break;
	case 0x99: sta_ce_aby_partial(); break;
	case 0x9a: txs_ce_imp_partial(); break;
	case 0x9b: stx_aby_partial(); break;
	case 0x9c: stz_ce_aba_partial(); break;
	case 0x9d: sta_ce_abx_partial(); break;
	case 0x9e: stz_ce_abx_partial(); break;
	case 0x9f: bbs_ce_zpb_partial(); break;
	case 0xa0: ldy_imm_partial(); break;
	case 0xa1: lda_ce_idx_partial(); break;
	case 0xa2: ldx_imm_partial(); break;
	case 0xa3: ldz_imm_partial(); break;
	case 0xa4: ldy_ce_zpg_partial(); break;
	case 0xa5: lda_ce_zpg_partial(); break;
	case 0xa6: ldx_ce_zpg_partial(); break;
	case 0xa7: smb_ce_bzp_partial(); break;
	case 0xa8: tay_ce_imp_partial(); break;
	case 0xa9: lda_imm_partial(); break;
	case 0xaa: tax_ce_imp_partial(); break;
	case 0xab: ldz_aba_partial(); break;
	case 0xac: ldy_aba_partial(); break;
	case 0xad: lda_aba_partial(); break;
	case 0xae: ldx_aba_partial(); break;
	case 0xaf: bbs_ce_zpb_partial(); break;
	case 0xb0: bcs_ce_rel_partial(); break;
	case 0xb1: lda_ce_idy_partial(); break;
	case 0xb2: lda_idz_partial(); break;
	case 0xb3: bcs_rw2_partial(); break;
	case 0xb4: ldy_ce_zpx_partial(); break;
	case 0xb5: lda_ce_zpx_partial(); break;
	case 0xb6: ldx_ce_zpy_partial(); break;
	case 0xb7: smb_ce_bzp_partial(); break;
	case 0xb8: clv_ce_imp_partial(); break;
	case 0xb9: lda_ce_aby_partial(); break;
	case 0xba: tsx_ce_imp_partial(); break;
	case 0xbb: ldz_abx_partial(); break;
	case 0xbc: ldy_ce_abx_partial(); break;
	case 0xbd: lda_ce_abx_partial(); break;
	case 0xbe: ldx_ce_aby_partial(); break;
	case 0xbf: bbs_ce_zpb_partial(); break;
	case 0xc0: cpy_imm_partial(); break;
	case 0xc1: cmp_ce_idx_partial(); break;
	case 0xc2: cpz_imm_partial(); break;
	case 0xc3: dew_zpg_partial(); break;
	case 0xc4: cpy_ce_zpg_partial(); break;
	case 0xc5: cmp_ce_zpg_partial(); break;
	case 0xc6: dec_ce_zpg_partial(); break;
	case 0xc7: smb_ce_bzp_partial(); break;
	case 0xc8: iny_ce_imp_partial(); break;
	case 0xc9: cmp_imm_partial(); break;
	case 0xca: dex_ce_imp_partial(); break;
	case 0xcb: asw_aba_partial(); break;
	case 0xcc: cpy_aba_partial(); break;
	case 0xcd: cmp_aba_partial(); break;
	case 0xce: dec_ce_aba_partial(); break;
	case 0xcf: bbs_ce_zpb_partial(); break;
	case 0xd0: bne_ce_rel_partial(); break;
	case 0xd1: cmp_ce_idy_partial(); break;
	case 0xd2: cmp_idz_partial(); break;
	case 0xd3: bne_rw2_partial(); break;
	case 0xd4: cpz_zpg_partial(); break;
	case 0xd5: cmp_ce_zpx_partial(); break;
	case 0xd6: dec_ce_zpx_partial(); break;
	case 0xd7: smb_ce_bzp_partial(); break;
	case 0xd8: cld_ce_imp_partial(); break;
	case 0xd9: cmp_ce_aby_partial(); break;
	case 0xda: phx_ce_imp_partial(); break;
	case 0xdb: phz_imp_partial(); break;
	case 0xdc: cpz_aba_partial(); break;
	case 0xdd: cmp_ce_abx_partial(); break;
	case 0xde: dec_ce_abx_partial(); break;
	case 0xdf: bbs_ce_zpb_partial(); break;
	case 0xe0: cpx_imm_partial(); break;
	case 0xe1: sbc_ce_idx_partial(); break;
	case 0xe2: lda_isy_partial(); break;
	case 0xe3: inw_zpg_partial(); break;
	case 0xe4: cpx_ce_zpg_partial(); break;
	case 0xe5: sbc_ce_zpg_partial(); break;
	case 0xe6: inc_ce_zpg_partial(); break;
	case 0xe7: smb_ce_bzp_partial(); break;
	case 0xe8: inx_ce_imp_partial(); break;
	case 0xe9: sbc_ce_imm_partial(); break;
	case 0xea: nop_c_imp_partial(); break;
	case 0xeb: row_aba_partial(); break;
	case 0xec: cpx_aba_partial(); break;
	case 0xed: sbc_ce_aba_partial(); break;
	case 0xee: inc_ce_aba_partial(); break;
	case 0xef: bbs_ce_zpb_partial(); break;
	case 0xf0: beq_ce_rel_partial(); break;
	case 0xf1: sbc_ce_idy_partial(); break;
	case 0xf2: sbc_idz_partial(); break;
	case 0xf3: beq_rw2_partial(); break;
	case 0xf4: phw_iw2_partial(); break;
	case 0xf5: sbc_ce_zpx_partial(); break;
	case 0xf6: inc_ce_zpx_partial(); break;
	case 0xf7: smb_ce_bzp_partial(); break;
	case 0xf8: sed_ce_imp_partial(); break;
	case 0xf9: sbc_ce_aby_partial(); break;
	case 0xfa: plx_ce_imp_partial(); break;
	case 0xfb: plz_imp_partial(); break;
	case 0xfc: phw_aba_partial(); break;
	case 0xfd: sbc_ce_abx_partial(); break;
	case 0xfe: inc_ce_abx_partial(); break;
	case 0xff: bbs_ce_zpb_partial(); break;
	case STATE_RESET: reset_c_partial(); break;
	}
}

