/* Data for log.
   Copyright (c) 2018 Arm Ltd.  All rights reserved.

   SPDX-License-Identifier: BSD-3-Clause

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
   1. Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
   3. The name of the company may not be used to endorse or promote
      products derived from this software without specific prior written
      permission.

   THIS SOFTWARE IS PROVIDED BY Arm LTD ``AS IS AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
   IN NO EVENT SHALL Arm LTD BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include "fdlibm.h"
#if !__OBSOLETE_MATH

#include "math_config.h"

#define N (1 << LOG_TABLE_BITS)

const struct log_data __log_data = {
.ln2hi = 0x1.62e42fefa3800p-1,
.ln2lo = 0x1.ef35793c76730p-45,
.poly1 = {
#if LOG_POLY1_ORDER == 10
// relative error: 0x1.32eccc6p-62
// in -0x1p-5 0x1.1p-5 (|log(1+x)| > 0x1p-5 outside this interval)
-0x1p-1,
0x1.55555555554e5p-2,
-0x1.0000000000af2p-2,
0x1.9999999bbe436p-3,
-0x1.55555537f9cdep-3,
0x1.24922fc8127cfp-3,
-0x1.0000b7d6bb612p-3,
0x1.c806ee1ddbcafp-4,
-0x1.972335a9c2d6ep-4,
#elif LOG_POLY1_ORDER == 11
// relative error: 0x1.52c8b708p-68
// in -0x1p-5 0x1.1p-5 (|log(1+x)| > 0x1p-5 outside this interval)
-0x1p-1,
0x1.5555555555555p-2,
-0x1.ffffffffffea9p-3,
0x1.999999999c4d4p-3,
-0x1.55555557f5541p-3,
0x1.249248fbe33e4p-3,
-0x1.ffffc9a3c825bp-4,
0x1.c71e1f204435dp-4,
-0x1.9a7f26377d06ep-4,
0x1.71c30cf8f7364p-4,
#elif LOG_POLY1_ORDER == 12
// relative error: 0x1.c04d76cp-63
// in -0x1p-4 0x1.09p-4 (|log(1+x)| > 0x1p-4 outside the interval)
-0x1p-1,
0x1.5555555555577p-2,
-0x1.ffffffffffdcbp-3,
0x1.999999995dd0cp-3,
-0x1.55555556745a7p-3,
0x1.24924a344de3p-3,
-0x1.fffffa4423d65p-4,
0x1.c7184282ad6cap-4,
-0x1.999eb43b068ffp-4,
0x1.78182f7afd085p-4,
-0x1.5521375d145cdp-4,
#endif
},
.poly = {
#if N == 64 && LOG_POLY_ORDER == 7
// relative error: 0x1.906eb8ap-58
// abs error: 0x1.d2cad5a8p-67
// in -0x1.fp-8 0x1.fp-8
-0x1.0000000000027p-1,
0x1.555555555556ap-2,
-0x1.fffffff0440bap-3,
0x1.99999991906c3p-3,
-0x1.555c8d7e8201ep-3,
0x1.24978c59151fap-3,
#elif N == 128 && LOG_POLY_ORDER == 6
// relative error: 0x1.926199e8p-56
// abs error: 0x1.882ff33p-65
// in -0x1.fp-9 0x1.fp-9
-0x1.0000000000001p-1,
0x1.555555551305bp-2,
-0x1.fffffffeb459p-3,
0x1.999b324f10111p-3,
-0x1.55575e506c89fp-3,
#elif N == 128 && LOG_POLY_ORDER == 7
// relative error: 0x1.649fc4bp-64
// abs error: 0x1.c3b5769p-74
// in -0x1.fp-9 0x1.fp-9
-0x1.0000000000001p-1,
0x1.5555555555556p-2,
-0x1.fffffffea1a8p-3,
0x1.99999998e9139p-3,
-0x1.555776801b968p-3,
0x1.2493c29331a5cp-3,
#endif
},
.tab = {
#if N == 64
{0x1.7242886495cd8p+0, -0x1.79e267bdfe000p-2},
{0x1.6e1f769340dc9p+0, -0x1.6e60ee0ecb000p-2},
{0x1.6a13ccc8f195cp+0, -0x1.63002fdbf6000p-2},
{0x1.661ec72e86f3ap+0, -0x1.57bf76c597000p-2},
{0x1.623fa6c447b16p+0, -0x1.4c9e07f0d2000p-2},
{0x1.5e75bbca31702p+0, -0x1.419b42f027000p-2},
{0x1.5ac05655adb10p+0, -0x1.36b67660e6000p-2},
{0x1.571ed3e940191p+0, -0x1.2bef0839e4800p-2},
{0x1.539094ac0fbbfp+0, -0x1.21445727cb000p-2},
{0x1.5015007e7fc42p+0, -0x1.16b5ca3c3d000p-2},
{0x1.4cab877c31cf9p+0, -0x1.0c42d3805f800p-2},
{0x1.49539e76a88d3p+0, -0x1.01eae61b60800p-2},
{0x1.460cbc12211dap+0, -0x1.ef5adb9fb0000p-3},
{0x1.42d6624debe3ap+0, -0x1.db13daab99000p-3},
{0x1.3fb0144f0d462p+0, -0x1.c6ffbe896e000p-3},
{0x1.3c995a1f9a9b4p+0, -0x1.b31d84722d000p-3},
{0x1.3991c23952500p+0, -0x1.9f6c3cf6eb000p-3},
{0x1.3698df35eaa14p+0, -0x1.8beafe7f13000p-3},
{0x1.33ae463091760p+0, -0x1.7898db878d000p-3},
{0x1.30d190aae3d72p+0, -0x1.6574efe4ec000p-3},
{0x1.2e025c9203c89p+0, -0x1.527e620845000p-3},
{0x1.2b404a7244988p+0, -0x1.3fb457d798000p-3},
{0x1.288b01dc19544p+0, -0x1.2d1615a077000p-3},
{0x1.25e2268085f69p+0, -0x1.1aa2b431e5000p-3},
{0x1.23456812abb74p+0, -0x1.08598f1d2b000p-3},
{0x1.20b4703174157p+0, -0x1.ec738fee40000p-4},
{0x1.1e2ef308b4e9bp+0, -0x1.c885768862000p-4},
{0x1.1bb4a36b70a3fp+0, -0x1.a4e75b6a46000p-4},
{0x1.194538e960658p+0, -0x1.8197efba9a000p-4},
{0x1.16e0692a10ac8p+0, -0x1.5e95ad734e000p-4},
{0x1.1485f1ba1568bp+0, -0x1.3bdf67117c000p-4},
{0x1.12358e123ed6fp+0, -0x1.1973b744f0000p-4},
{0x1.0fef01de37c8dp+0, -0x1.eea33446bc000p-5},
{0x1.0db20b82be414p+0, -0x1.aaef4ab304000p-5},
{0x1.0b7e6f67f69b3p+0, -0x1.67c962fd2c000p-5},
{0x1.0953f342fc108p+0, -0x1.252f29acf8000p-5},
{0x1.0732604ec956bp+0, -0x1.c63d19e9c0000p-6},
{0x1.051980117f9b0p+0, -0x1.432ab6a388000p-6},
{0x1.03091aa6810f1p+0, -0x1.8244357f50000p-7},
{0x1.01010152cf066p+0, -0x1.0080a711c0000p-8},
{0x1.fc07ef6b6e30bp-1, 0x1.fe03018e80000p-8},
{0x1.f4465aa1024afp-1, 0x1.7b91986450000p-6},
{0x1.ecc07a8fd3f5ep-1, 0x1.39e88608c8000p-5},
{0x1.e573ad856b537p-1, 0x1.b42dc6e624000p-5},
{0x1.de5d6dc7b8057p-1, 0x1.165372ec20000p-4},
{0x1.d77b6498bddf7p-1, 0x1.51b07a0170000p-4},
{0x1.d0cb580315c0fp-1, 0x1.8c3465c7ea000p-4},
{0x1.ca4b30d1cf449p-1, 0x1.c5e544a290000p-4},
{0x1.c3f8ef4810d8ep-1, 0x1.fec91aa0a6000p-4},
{0x1.bdd2b8b311f44p-1, 0x1.1b72acdc5c000p-3},
{0x1.b7d6c2eeac054p-1, 0x1.371fc65a98000p-3},
{0x1.b20363474c8f5p-1, 0x1.526e61c1aa000p-3},
{0x1.ac570165eeab1p-1, 0x1.6d60ffc240000p-3},
{0x1.a6d019f331df4p-1, 0x1.87fa08a013000p-3},
{0x1.a16d3ebc9e3c3p-1, 0x1.a23bc630c3000p-3},
{0x1.9c2d14567ef45p-1, 0x1.bc286a3512000p-3},
{0x1.970e4efae9169p-1, 0x1.d5c2195697000p-3},
{0x1.920fb3bd0b802p-1, 0x1.ef0ae132d3000p-3},
{0x1.8d3018b58699ap-1, 0x1.040259974e000p-2},
{0x1.886e5ff170ee6p-1, 0x1.1058bd40e2000p-2},
{0x1.83c977ad35d27p-1, 0x1.1c898c1137800p-2},
{0x1.7f405ed16c520p-1, 0x1.2895a3e65b000p-2},
{0x1.7ad220d0335c4p-1, 0x1.347dd8f6bd000p-2},
{0x1.767dce53474fdp-1, 0x1.4043083cb3800p-2},
#elif N == 128
{0x1.734f0c3e0de9fp+0, -0x1.7cc7f79e69000p-2},
{0x1.713786a2ce91fp+0, -0x1.76feec20d0000p-2},
{0x1.6f26008fab5a0p+0, -0x1.713e31351e000p-2},
{0x1.6d1a61f138c7dp+0, -0x1.6b85b38287800p-2},
{0x1.6b1490bc5b4d1p+0, -0x1.65d5590807800p-2},
{0x1.69147332f0cbap+0, -0x1.602d076180000p-2},
{0x1.6719f18224223p+0, -0x1.5a8ca86909000p-2},
{0x1.6524f99a51ed9p+0, -0x1.54f4356035000p-2},
{0x1.63356aa8f24c4p+0, -0x1.4f637c36b4000p-2},
{0x1.614b36b9ddc14p+0, -0x1.49da7fda85000p-2},
{0x1.5f66452c65c4cp+0, -0x1.445923989a800p-2},
{0x1.5d867b5912c4fp+0, -0x1.3edf439b0b800p-2},
{0x1.5babccb5b90dep+0, -0x1.396ce448f7000p-2},
{0x1.59d61f2d91a78p+0, -0x1.3401e17bda000p-2},
{0x1.5805612465687p+0, -0x1.2e9e2ef468000p-2},
{0x1.56397cee76bd3p+0, -0x1.2941b3830e000p-2},
{0x1.54725e2a77f93p+0, -0x1.23ec58cda8800p-2},
{0x1.52aff42064583p+0, -0x1.1e9e129279000p-2},
{0x1.50f22dbb2bddfp+0, -0x1.1956d2b48f800p-2},
{0x1.4f38f4734ded7p+0, -0x1.141679ab9f800p-2},
{0x1.4d843cfde2840p+0, -0x1.0edd094ef9800p-2},
{0x1.4bd3ec078a3c8p+0, -0x1.09aa518db1000p-2},
{0x1.4a27fc3e0258ap+0, -0x1.047e65263b800p-2},
{0x1.4880524d48434p+0, -0x1.feb224586f000p-3},
{0x1.46dce1b192d0bp+0, -0x1.f474a7517b000p-3},
{0x1.453d9d3391854p+0, -0x1.ea4443d103000p-3},
{0x1.43a2744b4845ap+0, -0x1.e020d44e9b000p-3},
{0x1.420b54115f8fbp+0, -0x1.d60a22977f000p-3},
{0x1.40782da3ef4b1p+0, -0x1.cc00104959000p-3},
{0x1.3ee8f5d57fe8fp+0, -0x1.c202956891000p-3},
{0x1.3d5d9a00b4ce9p+0, -0x1.b81178d811000p-3},
{0x1.3bd60c010c12bp+0, -0x1.ae2c9ccd3d000p-3},
{0x1.3a5242b75dab8p+0, -0x1.a45402e129000p-3},
{0x1.38d22cd9fd002p+0, -0x1.9a877681df000p-3},
{0x1.3755bc5847a1cp+0, -0x1.90c6d69483000p-3},
{0x1.35dce49ad36e2p+0, -0x1.87120a645c000p-3},
{0x1.34679984dd440p+0, -0x1.7d68fb4143000p-3},
{0x1.32f5cceffcb24p+0, -0x1.73cb83c627000p-3},
{0x1.3187775a10d49p+0, -0x1.6a39a9b376000p-3},
{0x1.301c8373e3990p+0, -0x1.60b3154b7a000p-3},
{0x1.2eb4ebb95f841p+0, -0x1.5737d76243000p-3},
{0x1.2d50a0219a9d1p+0, -0x1.4dc7b8fc23000p-3},
{0x1.2bef9a8b7fd2ap+0, -0x1.4462c51d20000p-3},
{0x1.2a91c7a0c1babp+0, -0x1.3b08abc830000p-3},
{0x1.293726014b530p+0, -0x1.31b996b490000p-3},
{0x1.27dfa5757a1f5p+0, -0x1.2875490a44000p-3},
{0x1.268b39b1d3bbfp+0, -0x1.1f3b9f879a000p-3},
{0x1.2539d838ff5bdp+0, -0x1.160c8252ca000p-3},
{0x1.23eb7aac9083bp+0, -0x1.0ce7f57f72000p-3},
{0x1.22a012ba940b6p+0, -0x1.03cdc49fea000p-3},
{0x1.2157996cc4132p+0, -0x1.f57bdbc4b8000p-4},
{0x1.201201dd2fc9bp+0, -0x1.e370896404000p-4},
{0x1.1ecf4494d480bp+0, -0x1.d17983ef94000p-4},
{0x1.1d8f5528f6569p+0, -0x1.bf9674ed8a000p-4},
{0x1.1c52311577e7cp+0, -0x1.adc79202f6000p-4},
{0x1.1b17c74cb26e9p+0, -0x1.9c0c3e7288000p-4},
{0x1.19e010c2c1ab6p+0, -0x1.8a646b372c000p-4},
{0x1.18ab07bb670bdp+0, -0x1.78d01b3ac0000p-4},
{0x1.1778a25efbcb6p+0, -0x1.674f145380000p-4},
{0x1.1648d354c31dap+0, -0x1.55e0e6d878000p-4},
{0x1.151b990275fddp+0, -0x1.4485cdea1e000p-4},
{0x1.13f0ea432d24cp+0, -0x1.333d94d6aa000p-4},
{0x1.12c8b7210f9dap+0, -0x1.22079f8c56000p-4},
{0x1.11a3028ecb531p+0, -0x1.10e4698622000p-4},
{0x1.107fbda8434afp+0, -0x1.ffa6c6ad20000p-5},
{0x1.0f5ee0f4e6bb3p+0, -0x1.dda8d4a774000p-5},
{0x1.0e4065d2a9fcep+0, -0x1.bbcece4850000p-5},
{0x1.0d244632ca521p+0, -0x1.9a1894012c000p-5},
{0x1.0c0a77ce2981ap+0, -0x1.788583302c000p-5},
{0x1.0af2f83c636d1p+0, -0x1.5715e67d68000p-5},
{0x1.09ddb98a01339p+0, -0x1.35c8a49658000p-5},
{0x1.08cabaf52e7dfp+0, -0x1.149e364154000p-5},
{0x1.07b9f2f4e28fbp+0, -0x1.e72c082eb8000p-6},
{0x1.06ab58c358f19p+0, -0x1.a55f152528000p-6},
{0x1.059eea5ecf92cp+0, -0x1.63d62cf818000p-6},
{0x1.04949cdd12c90p+0, -0x1.228fb8caa0000p-6},
{0x1.038c6c6f0ada9p+0, -0x1.c317b20f90000p-7},
{0x1.02865137932a9p+0, -0x1.419355daa0000p-7},
{0x1.0182427ea7348p+0, -0x1.81203c2ec0000p-8},
{0x1.008040614b195p+0, -0x1.0040979240000p-9},
{0x1.fe01ff726fa1ap-1, 0x1.feff384900000p-9},
{0x1.fa11cc261ea74p-1, 0x1.7dc41353d0000p-7},
{0x1.f6310b081992ep-1, 0x1.3cea3c4c28000p-6},
{0x1.f25f63ceeadcdp-1, 0x1.b9fc114890000p-6},
{0x1.ee9c8039113e7p-1, 0x1.1b0d8ce110000p-5},
{0x1.eae8078cbb1abp-1, 0x1.58a5bd001c000p-5},
{0x1.e741aa29d0c9bp-1, 0x1.95c8340d88000p-5},
{0x1.e3a91830a99b5p-1, 0x1.d276aef578000p-5},
{0x1.e01e009609a56p-1, 0x1.07598e598c000p-4},
{0x1.dca01e577bb98p-1, 0x1.253f5e30d2000p-4},
{0x1.d92f20b7c9103p-1, 0x1.42edd8b380000p-4},
{0x1.d5cac66fb5ccep-1, 0x1.606598757c000p-4},
{0x1.d272caa5ede9dp-1, 0x1.7da76356a0000p-4},
{0x1.cf26e3e6b2ccdp-1, 0x1.9ab434e1c6000p-4},
{0x1.cbe6da2a77902p-1, 0x1.b78c7bb0d6000p-4},
{0x1.c8b266d37086dp-1, 0x1.d431332e72000p-4},
{0x1.c5894bd5d5804p-1, 0x1.f0a3171de6000p-4},
{0x1.c26b533bb9f8cp-1, 0x1.067152b914000p-3},
{0x1.bf583eeece73fp-1, 0x1.147858292b000p-3},
{0x1.bc4fd75db96c1p-1, 0x1.2266ecdca3000p-3},
{0x1.b951e0c864a28p-1, 0x1.303d7a6c55000p-3},
{0x1.b65e2c5ef3e2cp-1, 0x1.3dfc33c331000p-3},
{0x1.b374867c9888bp-1, 0x1.4ba366b7a8000p-3},
{0x1.b094b211d304ap-1, 0x1.5933928d1f000p-3},
{0x1.adbe885f2ef7ep-1, 0x1.66acd2418f000p-3},
{0x1.aaf1d31603da2p-1, 0x1.740f8ec669000p-3},
{0x1.a82e63fd358a7p-1, 0x1.815c0f51af000p-3},
{0x1.a5740ef09738bp-1, 0x1.8e92954f68000p-3},
{0x1.a2c2a90ab4b27p-1, 0x1.9bb3602f84000p-3},
{0x1.a01a01393f2d1p-1, 0x1.a8bed1c2c0000p-3},
{0x1.9d79f24db3c1bp-1, 0x1.b5b515c01d000p-3},
{0x1.9ae2505c7b190p-1, 0x1.c2967ccbcc000p-3},
{0x1.9852ef297ce2fp-1, 0x1.cf635d5486000p-3},
{0x1.95cbaeea44b75p-1, 0x1.dc1bd3446c000p-3},
{0x1.934c69de74838p-1, 0x1.e8c01b8cfe000p-3},
{0x1.90d4f2f6752e6p-1, 0x1.f5509c0179000p-3},
{0x1.8e6528effd79dp-1, 0x1.00e6c121fb800p-2},
{0x1.8bfce9fcc007cp-1, 0x1.071b80e93d000p-2},
{0x1.899c0dabec30ep-1, 0x1.0d46b9e867000p-2},
{0x1.87427aa2317fbp-1, 0x1.13687334bd000p-2},
{0x1.84f00acb39a08p-1, 0x1.1980d67234800p-2},
{0x1.82a49e8653e55p-1, 0x1.1f8ffe0cc8000p-2},
{0x1.8060195f40260p-1, 0x1.2595fd7636800p-2},
{0x1.7e22563e0a329p-1, 0x1.2b9300914a800p-2},
{0x1.7beb377dcb5adp-1, 0x1.3187210436000p-2},
{0x1.79baa679725c2p-1, 0x1.377266dec1800p-2},
{0x1.77907f2170657p-1, 0x1.3d54ffbaf3000p-2},
{0x1.756cadbd6130cp-1, 0x1.432eee32fe000p-2},
#endif
},
#if !__HAVE_FAST_FMA
.tab2 = {
# if N == 64
{0x1.61ffff94c4fecp-1, -0x1.9fe4fc998f325p-56},
{0x1.66000020377ddp-1, 0x1.e804c7a9519f2p-55},
{0x1.6a00004c41678p-1, 0x1.902c675d9ecfep-55},
{0x1.6dffff7384f87p-1, -0x1.2fd6b95e55043p-56},
{0x1.720000b37216ep-1, 0x1.802bc8d437043p-55},
{0x1.75ffffbeb3c9dp-1, 0x1.6047ad0a0d4e4p-57},
{0x1.7a0000628daep-1, -0x1.e00434b49313dp-56},
{0x1.7dffffd7abd1ap-1, -0x1.6015f8a083576p-56},
{0x1.81ffffdf40c54p-1, 0x1.7f54bf76a42c9p-57},
{0x1.860000f334e11p-1, 0x1.60054cb5344d7p-56},
{0x1.8a0001238aca7p-1, 0x1.c03c9bd132f55p-57},
{0x1.8dffffb81d212p-1, -0x1.001e519f2764fp-55},
{0x1.92000086adc7cp-1, 0x1.1fe40f88f49c6p-55},
{0x1.960000135d8eap-1, -0x1.f832268dc3095p-55},
{0x1.99ffff9435acp-1, 0x1.7031d8b835edcp-56},
{0x1.9e00003478565p-1, -0x1.0030b221ce3eep-58},
{0x1.a20000b592948p-1, 0x1.8fd2f1dbd4639p-55},
{0x1.a600000ad0bcfp-1, 0x1.901d6a974e6bep-55},
{0x1.a9ffff55953a5p-1, 0x1.a07556192db98p-57},
{0x1.adffff29ce03dp-1, -0x1.fff0717ec71c2p-56},
{0x1.b1ffff34f3ac8p-1, 0x1.8005573de89d1p-57},
{0x1.b60000894c55bp-1, -0x1.ff2fb51b044c7p-57},
{0x1.b9fffef45ec7dp-1, -0x1.9ff7c4e8730fp-56},
{0x1.be0000cda7b2ap-1, 0x1.57d058dbf3c1dp-55},
{0x1.c1ffff2c57917p-1, 0x1.7e66d7e48dbc9p-58},
{0x1.c60000ea5b82ap-1, -0x1.47f5e132ed4bep-55},
{0x1.ca0001121ae98p-1, -0x1.40958c8d5e00ap-58},
{0x1.ce0000f9241cbp-1, -0x1.7da063caa81c8p-59},
{0x1.d1fffe8be95a4p-1, -0x1.82e3a411afcd9p-59},
{0x1.d5ffff035932bp-1, -0x1.00f901b3fe87dp-58},
{0x1.d9fffe8b54ba7p-1, 0x1.ffef55d6e3a4p-55},
{0x1.de0000ad95d19p-1, 0x1.5feb2efd4c7c7p-55},
{0x1.e1fffe925ce47p-1, 0x1.c8085484eaf08p-55},
{0x1.e5fffe3ddf853p-1, -0x1.fd5ed02c5cadp-60},
{0x1.e9fffed0a0e5fp-1, -0x1.a80aaef411586p-55},
{0x1.ee00008f82eep-1, -0x1.b000aeaf97276p-55},
{0x1.f20000a22d2f4p-1, -0x1.8f8906e13eba3p-56},
{0x1.f5fffee35b57dp-1, 0x1.1fdd33b2d3714p-57},
{0x1.fa00014eec3a6p-1, -0x1.3ee0b7a18c1a5p-58},
{0x1.fdffff5daa89fp-1, -0x1.c1e24c8e3b503p-58},
{0x1.0200005b93349p+0, -0x1.50197fe6bedcap-54},
{0x1.05ffff9d597acp+0, 0x1.20160d062d0dcp-55},
{0x1.0a00005687a63p+0, -0x1.27f3f9307696ep-54},
{0x1.0dffff779164ep+0, 0x1.b7eb40bb9c4f4p-54},
{0x1.12000044a0aa8p+0, 0x1.efbc914d512c4p-55},
{0x1.16000069685bcp+0, -0x1.c0bea3eb2d82cp-57},
{0x1.1a000093f0d78p+0, 0x1.1fecbf1e8c52p-54},
{0x1.1dffffb2b1457p+0, -0x1.3fc91365637d6p-55},
{0x1.2200008824a1p+0, -0x1.dff7e9feb578ap-54},
{0x1.25ffffeef953p+0, -0x1.b00a61ec912f7p-55},
{0x1.2a0000a1e7783p+0, 0x1.60048318b0483p-56},
{0x1.2e0000853d4c7p+0, -0x1.77fbedf2c8cf3p-54},
{0x1.320000324c55bp+0, 0x1.f81983997354fp-54},
{0x1.360000594f796p+0, -0x1.cfe4beff900a9p-54},
{0x1.3a0000a4c1c0fp+0, 0x1.07dbb2e268d0ep-54},
{0x1.3e0000751c61bp+0, 0x1.80583ed1c566ep-56},
{0x1.42000069e8a9fp+0, 0x1.f01f1edf82045p-54},
{0x1.460000b5a1e34p+0, -0x1.dfdf0cf45c14ap-55},
{0x1.4a0000187e513p+0, 0x1.401306b83a98dp-55},
{0x1.4dffff3ba420bp+0, 0x1.9fc6539a6454ep-56},
{0x1.51fffffe391c9p+0, -0x1.601ef3353ac83p-54},
{0x1.560000e342455p+0, 0x1.3fb7fac8ac151p-55},
{0x1.59ffffc39676fp+0, 0x1.4fe7dd6659cc2p-55},
{0x1.5dfffff10ef42p+0, -0x1.48154cb592bcbp-54},
# elif N == 128
{0x1.61000014fb66bp-1, 0x1.e026c91425b3cp-56},
{0x1.63000034db495p-1, 0x1.dbfea48005d41p-55},
{0x1.650000d94d478p-1, 0x1.e7fa786d6a5b7p-55},
{0x1.67000074e6fadp-1, 0x1.1fcea6b54254cp-57},
{0x1.68ffffedf0faep-1, -0x1.c7e274c590efdp-56},
{0x1.6b0000763c5bcp-1, -0x1.ac16848dcda01p-55},
{0x1.6d0001e5cc1f6p-1, 0x1.33f1c9d499311p-55},
{0x1.6efffeb05f63ep-1, -0x1.e80041ae22d53p-56},
{0x1.710000e86978p-1, 0x1.bff6671097952p-56},
{0x1.72ffffc67e912p-1, 0x1.c00e226bd8724p-55},
{0x1.74fffdf81116ap-1, -0x1.e02916ef101d2p-57},
{0x1.770000f679c9p-1, -0x1.7fc71cd549c74p-57},
{0x1.78ffffa7ec835p-1, 0x1.1bec19ef50483p-55},
{0x1.7affffe20c2e6p-1, -0x1.07e1729cc6465p-56},
{0x1.7cfffed3fc9p-1, -0x1.08072087b8b1cp-55},
{0x1.7efffe9261a76p-1, 0x1.dc0286d9df9aep-55},
{0x1.81000049ca3e8p-1, 0x1.97fd251e54c33p-55},
{0x1.8300017932c8fp-1, -0x1.afee9b630f381p-55},
{0x1.850000633739cp-1, 0x1.9bfbf6b6535bcp-55},
{0x1.87000204289c6p-1, -0x1.bbf65f3117b75p-55},
{0x1.88fffebf57904p-1, -0x1.9006ea23dcb57p-55},
{0x1.8b00022bc04dfp-1, -0x1.d00df38e04b0ap-56},
{0x1.8cfffe50c1b8ap-1, -0x1.8007146ff9f05p-55},
{0x1.8effffc918e43p-1, 0x1.3817bd07a7038p-55},
{0x1.910001efa5fc7p-1, 0x1.93e9176dfb403p-55},
{0x1.9300013467bb9p-1, 0x1.f804e4b980276p-56},
{0x1.94fffe6ee076fp-1, -0x1.f7ef0d9ff622ep-55},
{0x1.96fffde3c12d1p-1, -0x1.082aa962638bap-56},
{0x1.98ffff4458a0dp-1, -0x1.7801b9164a8efp-55},
{0x1.9afffdd982e3ep-1, -0x1.740e08a5a9337p-55},
{0x1.9cfffed49fb66p-1, 0x1.fce08c19bep-60},
{0x1.9f00020f19c51p-1, -0x1.a3faa27885b0ap-55},
{0x1.a10001145b006p-1, 0x1.4ff489958da56p-56},
{0x1.a300007bbf6fap-1, 0x1.cbeab8a2b6d18p-55},
{0x1.a500010971d79p-1, 0x1.8fecadd78793p-55},
{0x1.a70001df52e48p-1, -0x1.f41763dd8abdbp-55},
{0x1.a90001c593352p-1, -0x1.ebf0284c27612p-55},
{0x1.ab0002a4f3e4bp-1, -0x1.9fd043cff3f5fp-57},
{0x1.acfffd7ae1ed1p-1, -0x1.23ee7129070b4p-55},
{0x1.aefffee510478p-1, 0x1.a063ee00edea3p-57},
{0x1.b0fffdb650d5bp-1, 0x1.a06c8381f0ab9p-58},
{0x1.b2ffffeaaca57p-1, -0x1.9011e74233c1dp-56},
{0x1.b4fffd995badcp-1, -0x1.9ff1068862a9fp-56},
{0x1.b7000249e659cp-1, 0x1.aff45d0864f3ep-55},
{0x1.b8ffff987164p-1, 0x1.cfe7796c2c3f9p-56},
{0x1.bafffd204cb4fp-1, -0x1.3ff27eef22bc4p-57},
{0x1.bcfffd2415c45p-1, -0x1.cffb7ee3bea21p-57},
{0x1.beffff86309dfp-1, -0x1.14103972e0b5cp-55},
{0x1.c0fffe1b57653p-1, 0x1.bc16494b76a19p-55},
{0x1.c2ffff1fa57e3p-1, -0x1.4feef8d30c6edp-57},
{0x1.c4fffdcbfe424p-1, -0x1.43f68bcec4775p-55},
{0x1.c6fffed54b9f7p-1, 0x1.47ea3f053e0ecp-55},
{0x1.c8fffeb998fd5p-1, 0x1.383068df992f1p-56},
{0x1.cb0002125219ap-1, -0x1.8fd8e64180e04p-57},
{0x1.ccfffdd94469cp-1, 0x1.e7ebe1cc7ea72p-55},
{0x1.cefffeafdc476p-1, 0x1.ebe39ad9f88fep-55},
{0x1.d1000169af82bp-1, 0x1.57d91a8b95a71p-56},
{0x1.d30000d0ff71dp-1, 0x1.9c1906970c7dap-55},
{0x1.d4fffea790fc4p-1, -0x1.80e37c558fe0cp-58},
{0x1.d70002edc87e5p-1, -0x1.f80d64dc10f44p-56},
{0x1.d900021dc82aap-1, -0x1.47c8f94fd5c5cp-56},
{0x1.dafffd86b0283p-1, 0x1.c7f1dc521617ep-55},
{0x1.dd000296c4739p-1, 0x1.8019eb2ffb153p-55},
{0x1.defffe54490f5p-1, 0x1.e00d2c652cc89p-57},
{0x1.e0fffcdabf694p-1, -0x1.f8340202d69d2p-56},
{0x1.e2fffdb52c8ddp-1, 0x1.b00c1ca1b0864p-56},
{0x1.e4ffff24216efp-1, 0x1.2ffa8b094ab51p-56},
{0x1.e6fffe88a5e11p-1, -0x1.7f673b1efbe59p-58},
{0x1.e9000119eff0dp-1, -0x1.4808d5e0bc801p-55},
{0x1.eafffdfa51744p-1, 0x1.80006d54320b5p-56},
{0x1.ed0001a127fa1p-1, -0x1.002f860565c92p-58},
{0x1.ef00007babcc4p-1, -0x1.540445d35e611p-55},
{0x1.f0ffff57a8d02p-1, -0x1.ffb3139ef9105p-59},
{0x1.f30001ee58ac7p-1, 0x1.a81acf2731155p-55},
{0x1.f4ffff5823494p-1, 0x1.a3f41d4d7c743p-55},
{0x1.f6ffffca94c6bp-1, -0x1.202f41c987875p-57},
{0x1.f8fffe1f9c441p-1, 0x1.77dd1f477e74bp-56},
{0x1.fafffd2e0e37ep-1, -0x1.f01199a7ca331p-57},
{0x1.fd0001c77e49ep-1, 0x1.181ee4bceacb1p-56},
{0x1.feffff7e0c331p-1, -0x1.e05370170875ap-57},
{0x1.00ffff465606ep+0, -0x1.a7ead491c0adap-55},
{0x1.02ffff3867a58p+0, -0x1.77f69c3fcb2ep-54},
{0x1.04ffffdfc0d17p+0, 0x1.7bffe34cb945bp-54},
{0x1.0700003cd4d82p+0, 0x1.20083c0e456cbp-55},
{0x1.08ffff9f2cbe8p+0, -0x1.dffdfbe37751ap-57},
{0x1.0b000010cda65p+0, -0x1.13f7faee626ebp-54},
{0x1.0d00001a4d338p+0, 0x1.07dfa79489ff7p-55},
{0x1.0effffadafdfdp+0, -0x1.7040570d66bcp-56},
{0x1.110000bbafd96p+0, 0x1.e80d4846d0b62p-55},
{0x1.12ffffae5f45dp+0, 0x1.dbffa64fd36efp-54},
{0x1.150000dd59ad9p+0, 0x1.a0077701250aep-54},
{0x1.170000f21559ap+0, 0x1.dfdf9e2e3deeep-55},
{0x1.18ffffc275426p+0, 0x1.10030dc3b7273p-54},
{0x1.1b000123d3c59p+0, 0x1.97f7980030188p-54},
{0x1.1cffff8299eb7p+0, -0x1.5f932ab9f8c67p-57},
{0x1.1effff48ad4p+0, 0x1.37fbf9da75bebp-54},
{0x1.210000c8b86a4p+0, 0x1.f806b91fd5b22p-54},
{0x1.2300003854303p+0, 0x1.3ffc2eb9fbf33p-54},
{0x1.24fffffbcf684p+0, 0x1.601e77e2e2e72p-56},
{0x1.26ffff52921d9p+0, 0x1.ffcbb767f0c61p-56},
{0x1.2900014933a3cp+0, -0x1.202ca3c02412bp-56},
{0x1.2b00014556313p+0, -0x1.2808233f21f02p-54},
{0x1.2cfffebfe523bp+0, -0x1.8ff7e384fdcf2p-55},
{0x1.2f0000bb8ad96p+0, -0x1.5ff51503041c5p-55},
{0x1.30ffffb7ae2afp+0, -0x1.10071885e289dp-55},
{0x1.32ffffeac5f7fp+0, -0x1.1ff5d3fb7b715p-54},
{0x1.350000ca66756p+0, 0x1.57f82228b82bdp-54},
{0x1.3700011fbf721p+0, 0x1.000bac40dd5ccp-55},
{0x1.38ffff9592fb9p+0, -0x1.43f9d2db2a751p-54},
{0x1.3b00004ddd242p+0, 0x1.57f6b707638e1p-55},
{0x1.3cffff5b2c957p+0, 0x1.a023a10bf1231p-56},
{0x1.3efffeab0b418p+0, 0x1.87f6d66b152bp-54},
{0x1.410001532aff4p+0, 0x1.7f8375f198524p-57},
{0x1.4300017478b29p+0, 0x1.301e672dc5143p-55},
{0x1.44fffe795b463p+0, 0x1.9ff69b8b2895ap-55},
{0x1.46fffe80475ep+0, -0x1.5c0b19bc2f254p-54},
{0x1.48fffef6fc1e7p+0, 0x1.b4009f23a2a72p-54},
{0x1.4afffe5bea704p+0, -0x1.4ffb7bf0d7d45p-54},
{0x1.4d000171027dep+0, -0x1.9c06471dc6a3dp-54},
{0x1.4f0000ff03ee2p+0, 0x1.77f890b85531cp-54},
{0x1.5100012dc4bd1p+0, 0x1.004657166a436p-57},
{0x1.530001605277ap+0, -0x1.6bfcece233209p-54},
{0x1.54fffecdb704cp+0, -0x1.902720505a1d7p-55},
{0x1.56fffef5f54a9p+0, 0x1.bbfe60ec96412p-54},
{0x1.5900017e61012p+0, 0x1.87ec581afef9p-55},
{0x1.5b00003c93e92p+0, -0x1.f41080abf0ccp-54},
{0x1.5d0001d4919bcp+0, -0x1.8812afb254729p-54},
{0x1.5efffe7b87a89p+0, -0x1.47eb780ed6904p-54},
#endif
},
#endif /* !__HAVE_FAST_FMA */
};
#endif /* __OBSOLETE_MATH */
