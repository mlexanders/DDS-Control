#pragma once

namespace DdsControl {
	// Адресное пространство регистров управления DDS для 1-го канала
	class Addresses
	{
	public:
		const unsigned short SWRST = 0x0000;
		const unsigned short DEVID = 0x0001;
		const unsigned short SEL_REG = 0x0002;
		const unsigned short CTR = 0x0003;
		const unsigned short SYNC = 0x0004;
		const unsigned short CLR = 0x0005;
		const unsigned short LINK = 0x0006;
		const unsigned short ROUTE = 0x0007;
		const unsigned short TC_L = 0x0008;
		const unsigned short TC_H = 0x0009;
		const unsigned short T_CAPTURE = 0x00E0;
		const unsigned short T_SEL_STATE = 0x00E1;
		const unsigned short T_E_SEL = 0x00E2;

		const unsigned short CH1_LS_CTR = 0x1000;
		const unsigned short CH1_LS_CRFMIN = 0x1001;
		const unsigned short CH1_TSW = 0x1002;

		const unsigned short CH1_LS_TPH1_L = 0x1010;
		const unsigned short CH1_LS_TPH1_M = 0x1011;
		const unsigned short CH1_LS_TPH1_H = 0x1012;

		const unsigned short CH1_LS_TPH2_L = 0x1014;
		const unsigned short CH1_LS_TPH2_M = 0x1015;
		const unsigned short CH1_LS_TPH2_H = 0x1016;

		const unsigned short CH1_LS_TPH3_L = 0x1018;
		const unsigned short CH1_LS_TPH3_M = 0x1019;
		const unsigned short CH1_LS_TPH3_H = 0x101A;

		const unsigned short CH1_LS_TPH4_L = 0x101C;
		const unsigned short CH1_LS_TPH4_M = 0x101D;
		const unsigned short CH1_LS_TPH4_H = 0x101E;

		const unsigned short CH1_LS_F1_L = 0x1020;
		const unsigned short CH1_LS_F1_M = 0x1021;
		const unsigned short CH1_LS_F1_H = 0x1022;

		const unsigned short CH1_LS_F2_L = 0x1024;
		const unsigned short CH1_LS_F2_M = 0x1025;
		const unsigned short CH1_LS_F2_H = 0x1026;

		const unsigned short CH1_LS_Ph1 = 0x1030;
		const unsigned short CH1_LS_Ph2 = 0x1031;

		const unsigned short CH1_LS_dF1_L = 0x1040;
		const unsigned short CH1_LS_dF1_M = 0x1041;
		const unsigned short CH1_LS_dF1_H = 0x1042;

		const unsigned short CH1_LS_dF2_L = 0x1044;
		const unsigned short CH1_LS_dF2_M = 0x1045;
		const unsigned short CH1_LS_dF2_H = 0x1046;

		const unsigned short CH1_dPh_all_L = 0x1300;
		const unsigned short CH1_dPh_all_M = 0x1301;
		const unsigned short CH1_dPh_all_H = 0x1302;

		const unsigned short CH1_P_all = 0x1304;
		const unsigned short CH1_Mul_all = 0x1305;
		const unsigned short CH1_Offset_all = 0x1306;

		const unsigned short CH1_dPh0_L = 0x1400;
		const unsigned short CH1_dPh0_M = 0x1401;
		const unsigned short CH1_dPh0_H = 0x1402;

		const unsigned short CH1_P0 = 0x1404;
		const unsigned short CH1_Mul0 = 0x1405;
		const unsigned short CH1_Offset0 = 0x1406;

		const unsigned short CH1_dPy_L = 0x1410;
		const unsigned short CH1_dPy_M = 0x1411;
		const unsigned short CH1_dPy_H = 0x1412;

		//const unsigned short CH1_Py = 0x1413;
		//const unsigned short CH1_Muly = 0x1414;
		//const unsigned short CH1_Offsety = 0x1414; // 17F6 ???

		const unsigned short CH1_T_dPh_L = 0x1800;
		const unsigned short CH1_T_dPh_M = 0x1801;
		const unsigned short CH1_T_dPh_H = 0x1802;

		const unsigned short CH1_T_P = 0x1804;
		const unsigned short CH1_T_Mul = 0x1805;
		const unsigned short CH1_T_Offset = 0x1806;
		const unsigned short CH1_T_SEL = 0x1808;
		const unsigned short CH1_T_out1 = 0x1810;
		const unsigned short CH1_T_out2 = 0x18111;
		const unsigned short CH1_T_out3 = 0x1812;
		const unsigned short CH1_T_out4 = 0x1813;
	};

}

