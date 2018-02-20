//-----------------------------------------------------------------------------
// Copyright 2015 Nehrutsa Ihor
//
// This file is part of LDmicro.
//
// LDmicro is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// LDmicro is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with LDmicro.  If not, see <http://www.gnu.org/licenses/>.
//------
//
// Constants, structures, declarations etc. for the PIC ladder logic compiler
//-----------------------------------------------------------------------------
#ifndef __ACCEL_H
#define __ACCEL_H

typedef signed short SWORD;
typedef signed long SDWORD;

#include "ldmicro.h"

#ifndef round
#define round(r)   ((r) < (LONG_MIN-0.5) || (r) > (LONG_MAX+0.5) ?\
    (r):\
    ((r) >= 0.0) ? ((r) + 0.5) : ((r) - 0.5))
#endif

typedef     double  fxFunc(double k, double x);
/*
    SDWORD  nSize,  // ࠧ��� ⠡���� �祪 ࠧ����/�ମ�����
    SDWORD  n,      // ������⢮ �祪 ࠧ����/�ମ����� ��� dt �⫨��� �� 1
    double  dtMax,  // ���ᨬ��쭮� ���祭�� ����� dt
    SDWORD  mult,   // �����⥫� dtMax �� 128
    SDWORD  shrt;   // mult = 2 ^ shrt
*/
typedef struct ElemAccelTag {
    //INPUT or OUTPUT DATAS
    //If s is input and ds=1 then t is output.
    //If t is input and dt=1 then s is output.
    double  s;      // �ன���� ���� �� 0 s(t)
    SDWORD  si;     // -/- 楫�� �� s
    double  ds;     // ���饭�� ��� �� �।��饩 �窨 ds=s[i]-s[i-1]
    SDWORD  dsi;    // -/- 楫�� �� ds �� int(s[i]-s[i-1])

    double  t;      // �६� ࠧ���� �� 0 �� v=1
    SDWORD  ti;     // -/- 楫�� �� t
    double  dt;     // ���饭�� �६��� �� �।��饩 �窨 dt=t[i]-t[i-1]
    SDWORD  dti;    // -/- 楫�� �� dt
    SDWORD  dtMul;  // dtMul = dt * mult;
    SDWORD  dtShr;  // dtShr = dtMul >> shrt;
    SDWORD  tdiscrete;//tdti;   // =summa(0..dti)
    //OUTPUT DATAS
    double  v,      // ᪮���� � ⥪�饩 �窥 ࠧ����
            dv,     // ���饭�� ᪮��� � ⥪�饩 �窥 ࠧ����
            vdiscrete, // dsi/dti
            a,      // �᪮७�� � ⥪�饩 �窥 ࠧ����
            da,     // ���饭�� �᪮७�� � ⥪�饩 �窥 ࠧ����
            e,      // �ࣨ� � ⥪�饩 �窥 ࠧ����
            de;     // ���饭�� �ࣨ� � ⥪�饩 �窥 ࠧ����

} ElemAccel;//, *ElemAccelPointer; //������� � 㪠��⥫쭠 ��������

//typedef  ElemAccel TableAccel[]; //���ᨢ �������

//typedef  ElemAccel (*TableAccelPointer)[]; //㪠��⥫� �� ���ᨢ �������
#endif
