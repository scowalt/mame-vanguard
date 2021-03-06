const n2a03_disassembler::disasm_entry n2a03_disassembler::disasm_entries[0x100] = {

	{ "brk", DASM_imp, 0 },
	{ "ora", DASM_idx, 0 },
	{ "kil", DASM_non, 0 },
	{ "slo", DASM_idx, 0 },
	{ "nop", DASM_zpg, 0 },
	{ "ora", DASM_zpg, 0 },
	{ "asl", DASM_zpg, 0 },
	{ "slo", DASM_zpg, 0 },
	{ "php", DASM_imp, 0 },
	{ "ora", DASM_imm, 0 },
	{ "asl", DASM_acc, 0 },
	{ "anc", DASM_imm, 0 },
	{ "nop", DASM_aba, 0 },
	{ "ora", DASM_aba, 0 },
	{ "asl", DASM_aba, 0 },
	{ "slo", DASM_aba, 0 },
	{ "bpl", DASM_rel, 0 },
	{ "ora", DASM_idy, 0 },
	{ "kil", DASM_non, 0 },
	{ "slo", DASM_idy, 0 },
	{ "nop", DASM_zpx, 0 },
	{ "ora", DASM_zpx, 0 },
	{ "asl", DASM_zpx, 0 },
	{ "slo", DASM_zpx, 0 },
	{ "clc", DASM_imp, 0 },
	{ "ora", DASM_aby, 0 },
	{ "nop", DASM_imp, 0 },
	{ "slo", DASM_aby, 0 },
	{ "nop", DASM_abx, 0 },
	{ "ora", DASM_abx, 0 },
	{ "asl", DASM_abx, 0 },
	{ "slo", DASM_abx, 0 },
	{ "jsr", DASM_adr, STEP_OVER },
	{ "and", DASM_idx, 0 },
	{ "kil", DASM_non, 0 },
	{ "rla", DASM_idx, 0 },
	{ "bit", DASM_zpg, 0 },
	{ "and", DASM_zpg, 0 },
	{ "rol", DASM_zpg, 0 },
	{ "rla", DASM_zpg, 0 },
	{ "plp", DASM_imp, 0 },
	{ "and", DASM_imm, 0 },
	{ "rol", DASM_acc, 0 },
	{ "anc", DASM_imm, 0 },
	{ "bit", DASM_aba, 0 },
	{ "and", DASM_aba, 0 },
	{ "rol", DASM_aba, 0 },
	{ "rla", DASM_aba, 0 },
	{ "bmi", DASM_rel, 0 },
	{ "and", DASM_idy, 0 },
	{ "kil", DASM_non, 0 },
	{ "rla", DASM_idy, 0 },
	{ "nop", DASM_zpx, 0 },
	{ "and", DASM_zpx, 0 },
	{ "rol", DASM_zpx, 0 },
	{ "rla", DASM_zpx, 0 },
	{ "sec", DASM_imp, 0 },
	{ "and", DASM_aby, 0 },
	{ "nop", DASM_imp, 0 },
	{ "rla", DASM_aby, 0 },
	{ "nop", DASM_abx, 0 },
	{ "and", DASM_abx, 0 },
	{ "rol", DASM_abx, 0 },
	{ "rla", DASM_abx, 0 },
	{ "rti", DASM_imp, STEP_OUT },
	{ "eor", DASM_idx, 0 },
	{ "kil", DASM_non, 0 },
	{ "sre", DASM_idx, 0 },
	{ "nop", DASM_zpg, 0 },
	{ "eor", DASM_zpg, 0 },
	{ "lsr", DASM_zpg, 0 },
	{ "sre", DASM_zpg, 0 },
	{ "pha", DASM_imp, 0 },
	{ "eor", DASM_imm, 0 },
	{ "lsr", DASM_acc, 0 },
	{ "asr", DASM_imm, 0 },
	{ "jmp", DASM_adr, 0 },
	{ "eor", DASM_aba, 0 },
	{ "lsr", DASM_aba, 0 },
	{ "sre", DASM_aba, 0 },
	{ "bvc", DASM_rel, 0 },
	{ "eor", DASM_idy, 0 },
	{ "kil", DASM_non, 0 },
	{ "sre", DASM_idy, 0 },
	{ "nop", DASM_zpx, 0 },
	{ "eor", DASM_zpx, 0 },
	{ "lsr", DASM_zpx, 0 },
	{ "sre", DASM_zpx, 0 },
	{ "cli", DASM_imp, 0 },
	{ "eor", DASM_aby, 0 },
	{ "nop", DASM_imp, 0 },
	{ "sre", DASM_aby, 0 },
	{ "nop", DASM_abx, 0 },
	{ "eor", DASM_abx, 0 },
	{ "lsr", DASM_abx, 0 },
	{ "sre", DASM_abx, 0 },
	{ "rts", DASM_imp, STEP_OUT },
	{ "adc", DASM_idx, 0 },
	{ "kil", DASM_non, 0 },
	{ "rra", DASM_idx, 0 },
	{ "nop", DASM_zpg, 0 },
	{ "adc", DASM_zpg, 0 },
	{ "ror", DASM_zpg, 0 },
	{ "rra", DASM_zpg, 0 },
	{ "pla", DASM_imp, 0 },
	{ "adc", DASM_imm, 0 },
	{ "ror", DASM_acc, 0 },
	{ "arr", DASM_imm, 0 },
	{ "jmp", DASM_ind, 0 },
	{ "adc", DASM_aba, 0 },
	{ "ror", DASM_aba, 0 },
	{ "rra", DASM_aba, 0 },
	{ "bvs", DASM_rel, 0 },
	{ "adc", DASM_idy, 0 },
	{ "kil", DASM_non, 0 },
	{ "rra", DASM_idy, 0 },
	{ "nop", DASM_zpx, 0 },
	{ "adc", DASM_zpx, 0 },
	{ "ror", DASM_zpx, 0 },
	{ "rra", DASM_zpx, 0 },
	{ "sei", DASM_imp, 0 },
	{ "adc", DASM_aby, 0 },
	{ "nop", DASM_imp, 0 },
	{ "rra", DASM_aby, 0 },
	{ "nop", DASM_abx, 0 },
	{ "adc", DASM_abx, 0 },
	{ "ror", DASM_abx, 0 },
	{ "rra", DASM_abx, 0 },
	{ "nop", DASM_imm, 0 },
	{ "sta", DASM_idx, 0 },
	{ "nop", DASM_imm, 0 },
	{ "sax", DASM_idx, 0 },
	{ "sty", DASM_zpg, 0 },
	{ "sta", DASM_zpg, 0 },
	{ "stx", DASM_zpg, 0 },
	{ "sax", DASM_zpg, 0 },
	{ "dey", DASM_imp, 0 },
	{ "nop", DASM_imm, 0 },
	{ "txa", DASM_imp, 0 },
	{ "ane", DASM_imm, 0 },
	{ "sty", DASM_aba, 0 },
	{ "sta", DASM_aba, 0 },
	{ "stx", DASM_aba, 0 },
	{ "sax", DASM_aba, 0 },
	{ "bcc", DASM_rel, 0 },
	{ "sta", DASM_idy, 0 },
	{ "kil", DASM_non, 0 },
	{ "sha", DASM_idy, 0 },
	{ "sty", DASM_zpx, 0 },
	{ "sta", DASM_zpx, 0 },
	{ "stx", DASM_zpy, 0 },
	{ "sax", DASM_zpy, 0 },
	{ "tya", DASM_imp, 0 },
	{ "sta", DASM_aby, 0 },
	{ "txs", DASM_imp, 0 },
	{ "shs", DASM_aby, 0 },
	{ "shy", DASM_abx, 0 },
	{ "sta", DASM_abx, 0 },
	{ "shx", DASM_aby, 0 },
	{ "sha", DASM_aby, 0 },
	{ "ldy", DASM_imm, 0 },
	{ "lda", DASM_idx, 0 },
	{ "ldx", DASM_imm, 0 },
	{ "lax", DASM_idx, 0 },
	{ "ldy", DASM_zpg, 0 },
	{ "lda", DASM_zpg, 0 },
	{ "ldx", DASM_zpg, 0 },
	{ "lax", DASM_zpg, 0 },
	{ "tay", DASM_imp, 0 },
	{ "lda", DASM_imm, 0 },
	{ "tax", DASM_imp, 0 },
	{ "lxa", DASM_imm, 0 },
	{ "ldy", DASM_aba, 0 },
	{ "lda", DASM_aba, 0 },
	{ "ldx", DASM_aba, 0 },
	{ "lax", DASM_aba, 0 },
	{ "bcs", DASM_rel, 0 },
	{ "lda", DASM_idy, 0 },
	{ "kil", DASM_non, 0 },
	{ "lax", DASM_idy, 0 },
	{ "ldy", DASM_zpx, 0 },
	{ "lda", DASM_zpx, 0 },
	{ "ldx", DASM_zpy, 0 },
	{ "lax", DASM_zpy, 0 },
	{ "clv", DASM_imp, 0 },
	{ "lda", DASM_aby, 0 },
	{ "tsx", DASM_imp, 0 },
	{ "las", DASM_aby, 0 },
	{ "ldy", DASM_abx, 0 },
	{ "lda", DASM_abx, 0 },
	{ "ldx", DASM_aby, 0 },
	{ "lax", DASM_aby, 0 },
	{ "cpy", DASM_imm, 0 },
	{ "cmp", DASM_idx, 0 },
	{ "nop", DASM_imm, 0 },
	{ "dcp", DASM_idx, 0 },
	{ "cpy", DASM_zpg, 0 },
	{ "cmp", DASM_zpg, 0 },
	{ "dec", DASM_zpg, 0 },
	{ "dcp", DASM_zpg, 0 },
	{ "iny", DASM_imp, 0 },
	{ "cmp", DASM_imm, 0 },
	{ "dex", DASM_imp, 0 },
	{ "sbx", DASM_imm, 0 },
	{ "cpy", DASM_aba, 0 },
	{ "cmp", DASM_aba, 0 },
	{ "dec", DASM_aba, 0 },
	{ "dcp", DASM_aba, 0 },
	{ "bne", DASM_rel, 0 },
	{ "cmp", DASM_idy, 0 },
	{ "kil", DASM_non, 0 },
	{ "dcp", DASM_idy, 0 },
	{ "nop", DASM_zpx, 0 },
	{ "cmp", DASM_zpx, 0 },
	{ "dec", DASM_zpx, 0 },
	{ "dcp", DASM_zpx, 0 },
	{ "cld", DASM_imp, 0 },
	{ "cmp", DASM_aby, 0 },
	{ "nop", DASM_imp, 0 },
	{ "dcp", DASM_aby, 0 },
	{ "nop", DASM_abx, 0 },
	{ "cmp", DASM_abx, 0 },
	{ "dec", DASM_abx, 0 },
	{ "dcp", DASM_abx, 0 },
	{ "cpx", DASM_imm, 0 },
	{ "sbc", DASM_idx, 0 },
	{ "nop", DASM_imm, 0 },
	{ "isb", DASM_idx, 0 },
	{ "cpx", DASM_zpg, 0 },
	{ "sbc", DASM_zpg, 0 },
	{ "inc", DASM_zpg, 0 },
	{ "isb", DASM_zpg, 0 },
	{ "inx", DASM_imp, 0 },
	{ "sbc", DASM_imm, 0 },
	{ "nop", DASM_imp, 0 },
	{ "sbc", DASM_imm, 0 },
	{ "cpx", DASM_aba, 0 },
	{ "sbc", DASM_aba, 0 },
	{ "inc", DASM_aba, 0 },
	{ "isb", DASM_aba, 0 },
	{ "beq", DASM_rel, 0 },
	{ "sbc", DASM_idy, 0 },
	{ "kil", DASM_non, 0 },
	{ "isb", DASM_idy, 0 },
	{ "nop", DASM_zpx, 0 },
	{ "sbc", DASM_zpx, 0 },
	{ "inc", DASM_zpx, 0 },
	{ "isb", DASM_zpx, 0 },
	{ "sed", DASM_imp, 0 },
	{ "sbc", DASM_aby, 0 },
	{ "nop", DASM_imp, 0 },
	{ "isb", DASM_aby, 0 },
	{ "nop", DASM_abx, 0 },
	{ "sbc", DASM_abx, 0 },
	{ "inc", DASM_abx, 0 },
	{ "isb", DASM_abx, 0 },
};

