/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sat Jul 30 16:51:09 EDT 2016 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cb.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 25 -name r2cbIII_25 -dft-III -include r2cbIII.h */

/*
 * This function contains 152 FP additions, 120 FP multiplications,
 * (or, 32 additions, 0 multiplications, 120 fused multiply/add),
 * 115 stack variables, 44 constants, and 50 memory accesses
 */
#include "r2cbIII.h"

static void r2cbIII_25(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP979740652, +0.979740652857618686258237536568998933733477632);
     DK(KP438153340, +0.438153340021931793654057951961031291699532119);
     DK(KP1_752613360, +1.752613360087727174616231807844125166798128477);
     DK(KP963507348, +0.963507348203430549974383005744259307057084020);
     DK(KP1_721083328, +1.721083328735889354196523361841037632825608373);
     DK(KP1_606007150, +1.606007150877320829666881187140752009270929701);
     DK(KP1_011627398, +1.011627398597394192215998921771049272931807941);
     DK(KP641441904, +0.641441904830606407298806329068862424939687989);
     DK(KP595480289, +0.595480289600000014706716770488118292997907308);
     DK(KP452413526, +0.452413526233009763856834323966348796985206956);
     DK(KP1_809654104, +1.809654104932039055427337295865395187940827822);
     DK(KP933137358, +0.933137358350283770603023973254446451924190884);
     DK(KP1_666834356, +1.666834356657377354817925100486477686277992119);
     DK(KP1_842354653, +1.842354653930286640500894870830132058718564461);
     DK(KP1_082908895, +1.082908895072625554092571180165639018104066379);
     DK(KP576710603, +0.576710603632765877371579268136471017090111488);
     DK(KP662318342, +0.662318342759882818626911127577439236802190210);
     DK(KP484291580, +0.484291580564315559745084187732367906918006201);
     DK(KP1_937166322, +1.937166322257262238980336750929471627672024806);
     DK(KP1_898359647, +1.898359647016882523151110931686726543423167685);
     DK(KP1_386580726, +1.386580726567734802700860150804827247498955921);
     DK(KP904730450, +0.904730450839922351881287709692877908104763647);
     DK(KP1_115827804, +1.115827804063668528375399296931134075984874304);
     DK(KP470564281, +0.470564281212251493087595091036643380879947982);
     DK(KP634619297, +0.634619297544148100711287640319130485732531031);
     DK(KP499013364, +0.499013364214135780976168403431725276668452610);
     DK(KP1_996053456, +1.996053456856543123904673613726901106673810439);
     DK(KP559154169, +0.559154169276087864842202529084232643714075927);
     DK(KP683113946, +0.683113946453479238701949862233725244439656928);
     DK(KP730409924, +0.730409924561256563751459444999838399157094302);
     DK(KP549754652, +0.549754652192770074288023275540779861653779767);
     DK(KP256756360, +0.256756360367726783319498520922669048172391148);
     DK(KP451418159, +0.451418159099103183892477933432151804893354132);
     DK(KP846146756, +0.846146756728608505452954290121135880883743802);
     DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
     DK(KP062914667, +0.062914667253649757225485955897349402364686947);
     DK(KP939062505, +0.939062505817492352556001843133229685779824606);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(100, rs), MAKE_VOLATILE_STRIDE(100, csr), MAKE_VOLATILE_STRIDE(100, csi)) {
	       E T1P, T2c, T2a, T24, T26, T25, T27, T2b;
	       {
		    E T1O, TS, T5, T1N, TP, Te, TA, T2i, T1V, T17, T1B, T2h, T1S, T10, T1C;
		    E T1a, T19, Tn, T1h, T1l, T1Y, T1e, T21, TJ, T1g;
		    {
			 E T1, T2, T3, TQ, TR;
			 TQ = Ci[WS(csi, 7)];
			 TR = Ci[WS(csi, 2)];
			 T1 = Cr[WS(csr, 12)];
			 T2 = Cr[WS(csr, 7)];
			 T3 = Cr[WS(csr, 2)];
			 T1O = FNMS(KP618033988, TQ, TR);
			 TS = FMA(KP618033988, TR, TQ);
			 {
			      E TV, TU, T1U, T16, T12, T1R, TZ, T11;
			      {
				   E T6, Tz, T14, T15, TX, Tu, Td, Tx, TY, T4, TO, Ty;
				   T6 = Cr[WS(csr, 11)];
				   T4 = T2 + T3;
				   TO = T3 - T2;
				   Tz = Ci[WS(csi, 11)];
				   {
					E Ta, T9, Tb, T7, T8, TN;
					T7 = Cr[WS(csr, 6)];
					T8 = Cr[WS(csr, 8)];
					TN = FNMS(KP500000000, T4, T1);
					T5 = FMA(KP2_000000000, T4, T1);
					Ta = Cr[WS(csr, 1)];
					T14 = T8 - T7;
					T9 = T7 + T8;
					T1N = FMA(KP1_118033988, TO, TN);
					TP = FNMS(KP1_118033988, TO, TN);
					Tb = Cr[WS(csr, 3)];
					{
					     E Tv, Tw, Ts, Tt, Tc;
					     Ts = Ci[WS(csi, 8)];
					     Tt = Ci[WS(csi, 6)];
					     T15 = Tb - Ta;
					     Tc = Ta + Tb;
					     Tv = Ci[WS(csi, 3)];
					     TX = Tt + Ts;
					     Tu = Ts - Tt;
					     Tw = Ci[WS(csi, 1)];
					     Td = T9 + Tc;
					     TV = Tc - T9;
					     Tx = Tv - Tw;
					     TY = Tw + Tv;
					}
				   }
				   Te = T6 + Td;
				   TU = FMS(KP250000000, Td, T6);
				   T1U = FNMS(KP618033988, T14, T15);
				   T16 = FMA(KP618033988, T15, T14);
				   T12 = Tx - Tu;
				   Ty = Tu + Tx;
				   T1R = FNMS(KP618033988, TX, TY);
				   TZ = FMA(KP618033988, TY, TX);
				   TA = Ty - Tz;
				   T11 = FMA(KP250000000, Ty, Tz);
			      }
			      {
				   E Tf, TI, T1j, T1k, Tm, T1c, TD, TG, T1d, TH;
				   Tf = Cr[WS(csr, 10)];
				   TI = Ci[WS(csi, 10)];
				   {
					E T13, T1T, TW, T1Q;
					T13 = FMA(KP559016994, T12, T11);
					T1T = FNMS(KP559016994, T12, T11);
					TW = FMA(KP559016994, TV, TU);
					T1Q = FNMS(KP559016994, TV, TU);
					T2i = FMA(KP951056516, T1U, T1T);
					T1V = FNMS(KP951056516, T1U, T1T);
					T17 = FMA(KP951056516, T16, T13);
					T1B = FNMS(KP951056516, T16, T13);
					T2h = FNMS(KP951056516, T1R, T1Q);
					T1S = FMA(KP951056516, T1R, T1Q);
					T10 = FNMS(KP951056516, TZ, TW);
					T1C = FMA(KP951056516, TZ, TW);
					{
					     E Tg, Th, Tj, Tk;
					     Tg = Cr[WS(csr, 5)];
					     Th = Cr[WS(csr, 9)];
					     Tj = Cr[0];
					     Tk = Cr[WS(csr, 4)];
					     {
						  E TB, Ti, Tl, TC, TE, TF;
						  TB = Ci[WS(csi, 9)];
						  T1j = Tg - Th;
						  Ti = Tg + Th;
						  T1k = Tk - Tj;
						  Tl = Tj + Tk;
						  TC = Ci[WS(csi, 5)];
						  TE = Ci[WS(csi, 4)];
						  TF = Ci[0];
						  Tm = Ti + Tl;
						  T1a = Ti - Tl;
						  T1c = TC + TB;
						  TD = TB - TC;
						  TG = TE - TF;
						  T1d = TF + TE;
					     }
					}
				   }
				   T19 = FMS(KP250000000, Tm, Tf);
				   Tn = Tf + Tm;
				   T1h = TD - TG;
				   TH = TD + TG;
				   T1l = FNMS(KP618033988, T1k, T1j);
				   T1Y = FMA(KP618033988, T1j, T1k);
				   T1e = FMA(KP618033988, T1d, T1c);
				   T21 = FNMS(KP618033988, T1c, T1d);
				   TJ = TH - TI;
				   T1g = FMA(KP250000000, TH, TI);
			      }
			 }
		    }
		    {
			 E T1Z, T1m, T1y, T22, T1f, T1z, T2j, T2g, T2d, T2q, T2s;
			 {
			      E Tq, To, T2e, T2f;
			      Tq = Tn - Te;
			      To = Te + Tn;
			      {
				   E T1i, T1X, T1b, T20;
				   T1i = FNMS(KP559016994, T1h, T1g);
				   T1X = FMA(KP559016994, T1h, T1g);
				   T1b = FNMS(KP559016994, T1a, T19);
				   T20 = FMA(KP559016994, T1a, T19);
				   T2e = FMA(KP951056516, T1Y, T1X);
				   T1Z = FNMS(KP951056516, T1Y, T1X);
				   T1m = FNMS(KP951056516, T1l, T1i);
				   T1y = FMA(KP951056516, T1l, T1i);
				   T2f = FNMS(KP951056516, T21, T20);
				   T22 = FMA(KP951056516, T21, T20);
				   T1f = FNMS(KP951056516, T1e, T1b);
				   T1z = FMA(KP951056516, T1e, T1b);
			      }
			      {
				   E T2o, TK, TM, T2p, Tr, TL, Tp;
				   T2o = FMA(KP939062505, T2h, T2i);
				   T2j = FNMS(KP939062505, T2i, T2h);
				   R0[0] = FMA(KP2_000000000, To, T5);
				   Tp = FNMS(KP500000000, To, T5);
				   TK = FMA(KP618033988, TJ, TA);
				   TM = FNMS(KP618033988, TA, TJ);
				   T2g = FNMS(KP062914667, T2f, T2e);
				   T2p = FMA(KP062914667, T2e, T2f);
				   Tr = FNMS(KP1_118033988, Tq, Tp);
				   TL = FMA(KP1_118033988, Tq, Tp);
				   T2d = FMA(KP1_902113032, T1O, T1N);
				   T1P = FNMS(KP1_902113032, T1O, T1N);
				   T2q = FMA(KP846146756, T2p, T2o);
				   T2s = FNMS(KP451418159, T2o, T2p);
				   R0[WS(rs, 10)] = FMA(KP1_902113032, TK, Tr);
				   R1[WS(rs, 2)] = FMS(KP1_902113032, TK, Tr);
				   R1[WS(rs, 7)] = FMS(KP1_902113032, TM, TL);
				   R0[WS(rs, 5)] = FMA(KP1_902113032, TM, TL);
			      }
			 }
			 {
			      E T18, T1n, T1x, TT, T2m, T1w, T1u, T2l, T1s, T1t, T2k;
			      T18 = FNMS(KP256756360, T17, T10);
			      T1s = FMA(KP256756360, T10, T17);
			      T1t = FMA(KP549754652, T1f, T1m);
			      T1n = FNMS(KP549754652, T1m, T1f);
			      T1x = FNMS(KP1_902113032, TS, TP);
			      TT = FMA(KP1_902113032, TS, TP);
			      T2m = FMA(KP730409924, T2j, T2g);
			      T2k = FNMS(KP730409924, T2j, T2g);
			      T1w = FNMS(KP683113946, T1s, T1t);
			      T1u = FMA(KP559154169, T1t, T1s);
			      R1[WS(rs, 1)] = -(FMA(KP1_996053456, T2k, T2d));
			      T2l = FNMS(KP499013364, T2k, T2d);
			      {
				   E T1K, T1M, T1G, T1E;
				   {
					E T1D, T1A, T1q, T1p, T1v, T1r;
					{
					     E T1I, T1J, T2n, T2r, T1o;
					     T1I = FMA(KP634619297, T1B, T1C);
					     T1D = FNMS(KP634619297, T1C, T1B);
					     T1A = FMA(KP470564281, T1z, T1y);
					     T1J = FNMS(KP470564281, T1y, T1z);
					     T2n = FNMS(KP1_115827804, T2m, T2l);
					     T2r = FMA(KP1_115827804, T2m, T2l);
					     T1q = FNMS(KP904730450, T1n, T18);
					     T1o = FMA(KP904730450, T1n, T18);
					     R1[WS(rs, 11)] = FMS(KP1_386580726, T2q, T2n);
					     R0[WS(rs, 4)] = FMA(KP1_386580726, T2q, T2n);
					     R0[WS(rs, 9)] = FMA(KP1_898359647, T2s, T2r);
					     R1[WS(rs, 6)] = FMS(KP1_898359647, T2s, T2r);
					     R1[0] = FMS(KP1_937166322, T1o, TT);
					     T1p = FMA(KP484291580, T1o, TT);
					     T1K = FMA(KP662318342, T1J, T1I);
					     T1M = FNMS(KP576710603, T1I, T1J);
					}
					T1v = FMA(KP1_082908895, T1q, T1p);
					T1r = FNMS(KP1_082908895, T1q, T1p);
					R1[WS(rs, 10)] = FMS(KP1_842354653, T1u, T1r);
					R0[WS(rs, 3)] = FMA(KP1_842354653, T1u, T1r);
					R0[WS(rs, 8)] = FMA(KP1_666834356, T1w, T1v);
					R1[WS(rs, 5)] = FMS(KP1_666834356, T1w, T1v);
					T1G = FNMS(KP933137358, T1D, T1A);
					T1E = FMA(KP933137358, T1D, T1A);
				   }
				   {
					E T23, T28, T29, T1W, T1F, T1H, T1L;
					T23 = FNMS(KP634619297, T22, T1Z);
					T28 = FMA(KP634619297, T1Z, T22);
					T29 = FMA(KP549754652, T1S, T1V);
					T1W = FNMS(KP549754652, T1V, T1S);
					R0[WS(rs, 2)] = FMA(KP1_809654104, T1E, T1x);
					T1F = FNMS(KP452413526, T1E, T1x);
					T2c = FMA(KP595480289, T28, T29);
					T2a = FNMS(KP641441904, T29, T28);
					T1H = FNMS(KP1_011627398, T1G, T1F);
					T1L = FMA(KP1_011627398, T1G, T1F);
					R0[WS(rs, 12)] = FNMS(KP1_606007150, T1K, T1H);
					R1[WS(rs, 4)] = -(FMA(KP1_606007150, T1K, T1H));
					R1[WS(rs, 9)] = -(FMA(KP1_721083328, T1M, T1L));
					R0[WS(rs, 7)] = FNMS(KP1_721083328, T1M, T1L);
					T24 = FNMS(KP963507348, T23, T1W);
					T26 = FMA(KP963507348, T23, T1W);
				   }
			      }
			 }
		    }
	       }
	       R0[WS(rs, 1)] = FNMS(KP1_752613360, T24, T1P);
	       T25 = FMA(KP438153340, T24, T1P);
	       T27 = FMA(KP979740652, T26, T25);
	       T2b = FNMS(KP979740652, T26, T25);
	       R1[WS(rs, 8)] = -(FMA(KP1_606007150, T2a, T27));
	       R0[WS(rs, 6)] = FNMS(KP1_606007150, T2a, T27);
	       R1[WS(rs, 3)] = -(FMA(KP1_666834356, T2c, T2b));
	       R0[WS(rs, 11)] = FNMS(KP1_666834356, T2c, T2b);
	  }
     }
}

static const kr2c_desc desc = { 25, "r2cbIII_25", {32, 0, 120, 0}, &GENUS };

void X(codelet_r2cbIII_25) (planner *p) {
     X(kr2c_register) (p, r2cbIII_25, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 25 -name r2cbIII_25 -dft-III -include r2cbIII.h */

/*
 * This function contains 152 FP additions, 98 FP multiplications,
 * (or, 100 additions, 46 multiplications, 52 fused multiply/add),
 * 65 stack variables, 21 constants, and 50 memory accesses
 */
#include "r2cbIII.h"

static void r2cbIII_25(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP968583161, +0.968583161128631119490168375464735813836012403);
     DK(KP248689887, +0.248689887164854788242283746006447968417567406);
     DK(KP684547105, +0.684547105928688673732283357621209269889519233);
     DK(KP728968627, +0.728968627421411523146730319055259111372571664);
     DK(KP062790519, +0.062790519529313376076178224565631133122484832);
     DK(KP998026728, +0.998026728428271561952336806863450553336905220);
     DK(KP876306680, +0.876306680043863587308115903922062583399064238);
     DK(KP481753674, +0.481753674101715274987191502872129653528542010);
     DK(KP535826794, +0.535826794978996618271308767867639978063575346);
     DK(KP844327925, +0.844327925502015078548558063966681505381659241);
     DK(KP904827052, +0.904827052466019527713668647932697593970413911);
     DK(KP425779291, +0.425779291565072648862502445744251703979973042);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
     DK(KP1_175570504, +1.175570504584946258337411909278145537195304875);
     DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(100, rs), MAKE_VOLATILE_STRIDE(100, csr), MAKE_VOLATILE_STRIDE(100, csi)) {
	       E TS, T1O, T5, TP, T1N, TI, TH, Te, T17, T2h, T1y, T1V, T10, T2g, T1x;
	       E T1S, Tz, Ty, Tn, T1m, T2e, T1B, T22, T1f, T2d, T1A, T1Z, TQ, TR;
	       TQ = Ci[WS(csi, 2)];
	       TR = Ci[WS(csi, 7)];
	       TS = FNMS(KP1_175570504, TR, KP1_902113032 * TQ);
	       T1O = FMA(KP1_902113032, TR, KP1_175570504 * TQ);
	       {
		    E T1, T4, TN, T2, T3, TO;
		    T1 = Cr[WS(csr, 12)];
		    T2 = Cr[WS(csr, 7)];
		    T3 = Cr[WS(csr, 2)];
		    T4 = T2 + T3;
		    TN = KP1_118033988 * (T3 - T2);
		    T5 = FMA(KP2_000000000, T4, T1);
		    TO = FMS(KP500000000, T4, T1);
		    TP = TN - TO;
		    T1N = TO + TN;
	       }
	       {
		    E T6, Td, T15, TU, T14, T11, TX, TY;
		    T6 = Cr[WS(csr, 11)];
		    TI = Ci[WS(csi, 11)];
		    {
			 E T7, T8, T9, Ta, Tb, Tc;
			 T7 = Cr[WS(csr, 6)];
			 T8 = Cr[WS(csr, 8)];
			 T9 = T7 + T8;
			 Ta = Cr[WS(csr, 1)];
			 Tb = Cr[WS(csr, 3)];
			 Tc = Ta + Tb;
			 Td = T9 + Tc;
			 T15 = Ta - Tb;
			 TU = KP559016994 * (Tc - T9);
			 T14 = T8 - T7;
		    }
		    {
			 E TB, TC, TD, TE, TF, TG;
			 TB = Ci[WS(csi, 6)];
			 TC = Ci[WS(csi, 8)];
			 TD = TB - TC;
			 TE = Ci[WS(csi, 1)];
			 TF = Ci[WS(csi, 3)];
			 TG = TE - TF;
			 TH = TD + TG;
			 T11 = KP559016994 * (TD - TG);
			 TX = TB + TC;
			 TY = TE + TF;
		    }
		    Te = T6 + Td;
		    {
			 E T16, T1T, T13, T1U, T12;
			 T16 = FMA(KP587785252, T14, KP951056516 * T15);
			 T1T = FNMS(KP587785252, T15, KP951056516 * T14);
			 T12 = FNMS(KP250000000, TH, TI);
			 T13 = T11 - T12;
			 T1U = T11 + T12;
			 T17 = T13 - T16;
			 T2h = T1T - T1U;
			 T1y = T16 + T13;
			 T1V = T1T + T1U;
		    }
		    {
			 E TZ, T1R, TW, T1Q, TV;
			 TZ = FNMS(KP951056516, TY, KP587785252 * TX);
			 T1R = FMA(KP951056516, TX, KP587785252 * TY);
			 TV = FMS(KP250000000, Td, T6);
			 TW = TU - TV;
			 T1Q = TV + TU;
			 T10 = TW + TZ;
			 T2g = T1Q + T1R;
			 T1x = TZ - TW;
			 T1S = T1Q - T1R;
		    }
	       }
	       {
		    E Tf, Tm, T1k, T19, T1j, T1g, T1c, T1d;
		    Tf = Cr[WS(csr, 10)];
		    Tz = Ci[WS(csi, 10)];
		    {
			 E Tg, Th, Ti, Tj, Tk, Tl;
			 Tg = Cr[WS(csr, 5)];
			 Th = Cr[WS(csr, 9)];
			 Ti = Tg + Th;
			 Tj = Cr[0];
			 Tk = Cr[WS(csr, 4)];
			 Tl = Tj + Tk;
			 Tm = Ti + Tl;
			 T1k = Tj - Tk;
			 T19 = KP559016994 * (Tl - Ti);
			 T1j = Th - Tg;
		    }
		    {
			 E Ts, Tt, Tu, Tv, Tw, Tx;
			 Ts = Ci[WS(csi, 4)];
			 Tt = Ci[0];
			 Tu = Ts - Tt;
			 Tv = Ci[WS(csi, 5)];
			 Tw = Ci[WS(csi, 9)];
			 Tx = Tv - Tw;
			 Ty = Tu - Tx;
			 T1g = KP559016994 * (Tx + Tu);
			 T1c = Tv + Tw;
			 T1d = Tt + Ts;
		    }
		    Tn = Tf + Tm;
		    {
			 E T1l, T20, T1i, T21, T1h;
			 T1l = FMA(KP587785252, T1j, KP951056516 * T1k);
			 T20 = FNMS(KP587785252, T1k, KP951056516 * T1j);
			 T1h = FMA(KP250000000, Ty, Tz);
			 T1i = T1g - T1h;
			 T21 = T1g + T1h;
			 T1m = T1i - T1l;
			 T2e = T21 - T20;
			 T1B = T1l + T1i;
			 T22 = T20 + T21;
		    }
		    {
			 E T1e, T1Y, T1b, T1X, T1a;
			 T1e = FNMS(KP951056516, T1d, KP587785252 * T1c);
			 T1Y = FMA(KP951056516, T1c, KP587785252 * T1d);
			 T1a = FMS(KP250000000, Tm, Tf);
			 T1b = T19 - T1a;
			 T1X = T1a + T19;
			 T1f = T1b + T1e;
			 T2d = T1X + T1Y;
			 T1A = T1e - T1b;
			 T1Z = T1X - T1Y;
		    }
	       }
	       {
		    E Tq, To, Tp, TK, TM, TA, TJ, TL, Tr;
		    Tq = KP1_118033988 * (Tn - Te);
		    To = Te + Tn;
		    Tp = FMS(KP500000000, To, T5);
		    TA = Ty - Tz;
		    TJ = TH + TI;
		    TK = FNMS(KP1_902113032, TJ, KP1_175570504 * TA);
		    TM = FMA(KP1_175570504, TJ, KP1_902113032 * TA);
		    R0[0] = FMA(KP2_000000000, To, T5);
		    TL = Tq - Tp;
		    R0[WS(rs, 5)] = TL + TM;
		    R1[WS(rs, 7)] = TM - TL;
		    Tr = Tp + Tq;
		    R1[WS(rs, 2)] = Tr + TK;
		    R0[WS(rs, 10)] = TK - Tr;
	       }
	       {
		    E T2q, T2s, T2k, T2j, T2l, T2m, T2r, T2n;
		    {
			 E T2o, T2p, T2f, T2i;
			 T2o = FNMS(KP904827052, T2d, KP425779291 * T2e);
			 T2p = FNMS(KP535826794, T2h, KP844327925 * T2g);
			 T2q = FNMS(KP1_902113032, T2p, KP1_175570504 * T2o);
			 T2s = FMA(KP1_175570504, T2p, KP1_902113032 * T2o);
			 T2k = T1N + T1O;
			 T2f = FMA(KP425779291, T2d, KP904827052 * T2e);
			 T2i = FMA(KP535826794, T2g, KP844327925 * T2h);
			 T2j = T2f - T2i;
			 T2l = FMA(KP500000000, T2j, T2k);
			 T2m = KP1_118033988 * (T2i + T2f);
		    }
		    R0[WS(rs, 2)] = FMS(KP2_000000000, T2j, T2k);
		    T2r = T2m - T2l;
		    R0[WS(rs, 7)] = T2r + T2s;
		    R1[WS(rs, 9)] = T2s - T2r;
		    T2n = T2l + T2m;
		    R1[WS(rs, 4)] = T2n + T2q;
		    R0[WS(rs, 12)] = T2q - T2n;
	       }
	       {
		    E T1u, T1w, TT, T1o, T1p, T1q, T1v, T1r;
		    {
			 E T1s, T1t, T18, T1n;
			 T1s = FMA(KP481753674, T10, KP876306680 * T17);
			 T1t = FMA(KP844327925, T1f, KP535826794 * T1m);
			 T1u = FMA(KP1_902113032, T1s, KP1_175570504 * T1t);
			 T1w = FNMS(KP1_175570504, T1s, KP1_902113032 * T1t);
			 TT = TP - TS;
			 T18 = FNMS(KP481753674, T17, KP876306680 * T10);
			 T1n = FNMS(KP844327925, T1m, KP535826794 * T1f);
			 T1o = T18 + T1n;
			 T1p = FMS(KP500000000, T1o, TT);
			 T1q = KP1_118033988 * (T1n - T18);
		    }
		    R0[WS(rs, 1)] = FMA(KP2_000000000, T1o, TT);
		    T1v = T1q - T1p;
		    R0[WS(rs, 6)] = T1v + T1w;
		    R1[WS(rs, 8)] = T1w - T1v;
		    T1r = T1p + T1q;
		    R1[WS(rs, 3)] = T1r + T1u;
		    R0[WS(rs, 11)] = T1u - T1r;
	       }
	       {
		    E T1H, T1L, T1E, T1D, T1I, T1J, T1M, T1K;
		    {
			 E T1F, T1G, T1z, T1C;
			 T1F = FNMS(KP062790519, T1B, KP998026728 * T1A);
			 T1G = FNMS(KP684547105, T1x, KP728968627 * T1y);
			 T1H = FNMS(KP1_902113032, T1G, KP1_175570504 * T1F);
			 T1L = FMA(KP1_175570504, T1G, KP1_902113032 * T1F);
			 T1E = TP + TS;
			 T1z = FMA(KP728968627, T1x, KP684547105 * T1y);
			 T1C = FMA(KP062790519, T1A, KP998026728 * T1B);
			 T1D = T1z + T1C;
			 T1I = FMA(KP500000000, T1D, T1E);
			 T1J = KP1_118033988 * (T1C - T1z);
		    }
		    R1[WS(rs, 1)] = FMS(KP2_000000000, T1D, T1E);
		    T1M = T1J - T1I;
		    R0[WS(rs, 9)] = T1L - T1M;
		    R1[WS(rs, 6)] = T1L + T1M;
		    T1K = T1I + T1J;
		    R1[WS(rs, 11)] = T1H - T1K;
		    R0[WS(rs, 4)] = T1H + T1K;
	       }
	       {
		    E T2a, T2c, T1P, T24, T25, T26, T2b, T27;
		    {
			 E T28, T29, T1W, T23;
			 T28 = FMA(KP248689887, T1S, KP968583161 * T1V);
			 T29 = FMA(KP481753674, T1Z, KP876306680 * T22);
			 T2a = FMA(KP1_902113032, T28, KP1_175570504 * T29);
			 T2c = FNMS(KP1_175570504, T28, KP1_902113032 * T29);
			 T1P = T1N - T1O;
			 T1W = FNMS(KP248689887, T1V, KP968583161 * T1S);
			 T23 = FNMS(KP481753674, T22, KP876306680 * T1Z);
			 T24 = T1W + T23;
			 T25 = FMS(KP500000000, T24, T1P);
			 T26 = KP1_118033988 * (T23 - T1W);
		    }
		    R1[0] = FMA(KP2_000000000, T24, T1P);
		    T2b = T26 - T25;
		    R1[WS(rs, 5)] = T2b + T2c;
		    R0[WS(rs, 8)] = T2c - T2b;
		    T27 = T25 + T26;
		    R0[WS(rs, 3)] = T27 + T2a;
		    R1[WS(rs, 10)] = T2a - T27;
	       }
	  }
     }
}

static const kr2c_desc desc = { 25, "r2cbIII_25", {100, 46, 52, 0}, &GENUS };

void X(codelet_r2cbIII_25) (planner *p) {
     X(kr2c_register) (p, r2cbIII_25, &desc);
}

#endif				/* HAVE_FMA */
