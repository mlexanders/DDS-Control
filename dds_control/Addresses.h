#pragma once

// Адресное пространство регистров управления DDS для 1-го канала
class Addresses
{
public:
	static const unsigned short SWRST = 0x0000;
	static const unsigned short DEVID = 0x0001;
	static const unsigned short SEL_REG = 0x0002;			//Выбор активного профиля синтеза
	static const unsigned short CTR = 0x0003;
	static const unsigned short SYNC = 0x0004;
	static const unsigned short CLR = 0x0005;
	static const unsigned short LINK = 0x0006;
	static const unsigned short ROUTE = 0x0007;
	static const unsigned short TC_L = 0x0008;
	static const unsigned short TC_H = 0x0009;
	static const unsigned short T_CAPTURE = 0x00E0;
	static const unsigned short T_SEL_STATE = 0x00E1;
	static const unsigned short T_E_SEL = 0x00E2;

	static const unsigned short CH1_LS_CTR = 0x1000;
	static const unsigned short CH1_LS_CRFMIN = 0x1001;
	static const unsigned short CH1_TSW = 0x1002;

	static const unsigned short CH1_LS_TPH1_L = 0x1010;
	static const unsigned short CH1_LS_TPH1_M = 0x1011;
	static const unsigned short CH1_LS_TPH1_H = 0x1012;

	static const unsigned short CH1_LS_TPH2_L = 0x1014;
	static const unsigned short CH1_LS_TPH2_M = 0x1015;
	static const unsigned short CH1_LS_TPH2_H = 0x1016;

	static const unsigned short CH1_LS_TPH3_L = 0x1018;
	static const unsigned short CH1_LS_TPH3_M = 0x1019;
	static const unsigned short CH1_LS_TPH3_H = 0x101A;

	static const unsigned short CH1_LS_TPH4_L = 0x101C;
	static const unsigned short CH1_LS_TPH4_M = 0x101D;
	static const unsigned short CH1_LS_TPH4_H = 0x101E;

	static const unsigned short CH1_LS_F1_L = 0x1020;
	static const unsigned short CH1_LS_F1_M = 0x1021;
	static const unsigned short CH1_LS_F1_H = 0x1022;

	static const unsigned short CH1_LS_F2_L = 0x1024;
	static const unsigned short CH1_LS_F2_M = 0x1025;
	static const unsigned short CH1_LS_F2_H = 0x1026;

	static const unsigned short CH1_LS_Ph1 = 0x1030;
	static const unsigned short CH1_LS_Ph2 = 0x1031;

	static const unsigned short CH1_LS_dF1_L = 0x1040;
	static const unsigned short CH1_LS_dF1_M = 0x1041;
	static const unsigned short CH1_LS_dF1_H = 0x1042;

	static const unsigned short CH1_LS_dF2_L = 0x1044;
	static const unsigned short CH1_LS_dF2_M = 0x1045;
	static const unsigned short CH1_LS_dF2_H = 0x1046;

	static const unsigned short CH1_dPh_all_L = 0x1300;
	static const unsigned short CH1_dPh_all_M = 0x1301;
	static const unsigned short CH1_dPh_all_H = 0x1302;

	static const unsigned short CH1_P_all = 0x1304;
	static const unsigned short CH1_Mul_all = 0x1305;
	static const unsigned short CH1_Offset_all = 0x1306;

	static const unsigned short CH1_dPh0_L = 0x1400;	//0x1400 Приращение фазы, канал 1, профиль 0, младшие 16 разрядов - [15:0]
	static const unsigned short CH1_dPh0_M = 0x1401;	//0x1401 Приращение фазы, канал 1, профиль 0, разряды [31:16]
	static const unsigned short CH1_dPh0_H = 0x1402;	//0x1402 Приращение фазы, канал 1, профиль 0, старшие 16 разрядов - [47:32]

	static const unsigned short CH1_P0 = 0x1404;		//Смещение фазы синтезируемого сигнала (Φ). value – двоично-дополнительное целое
	static const unsigned short CH1_Mul0 = 0x1405;		//Амплитуда синтезируемого сигнала (A). A=(mul/2)^12, mul – двоично дополнительное целое -[15:3] 
	static const unsigned short CH1_Offset0 = 0x1406;	//Постоянное смещение. Двоично-дополнительное целое [15:4]

	static const unsigned short CH1_dPy_L = 0x1410;
	static const unsigned short CH1_dPy_M = 0x1411;
	static const unsigned short CH1_dPy_H = 0x1412;

	//static const unsigned short CH1_Py = 0x1413;
	//static const unsigned short CH1_Muly = 0x1414;
	//static const unsigned short CH1_Offsety = 0x1414; // 17F6 ???

	static const unsigned short CH1_T_dPh_L = 0x1800;
	static const unsigned short CH1_T_dPh_M = 0x1801;
	static const unsigned short CH1_T_dPh_H = 0x1802;

	//static const unsigned short CH1_T_P = 0x1804;
	//static const unsigned short CH1_T_Mul = 0x1805;
	//static const unsigned short CH1_T_Offset = 0x1806;
	//static const unsigned short CH1_T_SEL = 0x1808;
	//static const unsigned short CH1_T_out1 = 0x1810;
	//static const unsigned short CH1_T_out2 = 0x18111;
	//static const unsigned short CH1_T_out3 = 0x1812;
	//static const unsigned short CH1_T_out4 = 0x1813;
};

