const float ADC_mV = 1.955;      // convesion multiplier from Arduino ADC value to voltage in mV
const float sensitivity = 0.2;     // in mV/mmH2O taken from datasheet
const float mmh2O_cmH2O = 100;        // divide by this figure to convert mmH2O to cmH2O
const float mmh2O_kpa = 0.00981;     // convesion multiplier from mmH2O to kPa
const float mmh2O_pa = 9.80665;      // convesion multiplier from mmH2O to Pa
int flowRate;
int flowArray[644] = {
  0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 0
  , 3
  , 9
  , 17
  , 24
  , 35
  , 42
  , 56
  , 65
  , 73
  , 86
  , 99
  , 104
  , 115
  , 126
  , 139
  , 146
  , 159
  , 166
  , 177
  , 189
  , 200
  , 211
  , 220
  , 230
  , 240
  , 249
  , 257
  , 266
  , 274
  , 281
  , 289
  , 296
  , 304
  , 311
  , 317
  , 324
  , 330
  , 337
  , 343
  , 349
  , 355
  , 361
  , 367
  , 372
  , 378
  , 384
  , 389
  , 395
  , 400
  , 405
  , 410
  , 415
  , 420
  , 425
  , 430
  , 435
  , 439
  , 444
  , 449
  , 453
  , 458
  , 463
  , 467
  , 471
  , 476
  , 480
  , 484
  , 489
  , 493
  , 497
  , 501
  , 505
  , 509
  , 513
  , 517
  , 521
  , 525
  , 529
  , 533
  , 536
  , 540
  , 544
  , 548
  , 551
  , 555
  , 559
  , 562
  , 566
  , 570
  , 573
  , 577
  , 580
  , 584
  , 587
  , 591
  , 594
  , 597
  , 601
  , 604
  , 607
  , 611
  , 614
  , 617
  , 620
  , 624
  , 627
  , 630
  , 633
  , 637
  , 640
  , 643
  , 646
  , 649
  , 652
  , 655
  , 658
  , 661
  , 664
  , 667
  , 670
  , 673
  , 676
  , 679
  , 682
  , 685
  , 688
  , 691
  , 694
  , 697
  , 699
  , 702
  , 705
  , 708
  , 711
  , 713
  , 716
  , 719
  , 722
  , 724
  , 727
  , 730
  , 733
  , 735
  , 738
  , 741
  , 743
  , 746
  , 749
  , 751
  , 754
  , 756
  , 759
  , 762
  , 764
  , 767
  , 769
  , 772
  , 774
  , 777
  , 780
  , 782
  , 785
  , 787
  , 789
  , 792
  , 794
  , 797
  , 799
  , 802
  , 804
  , 807
  , 809
  , 812
  , 814
  , 816
  , 819
  , 821
  , 823
  , 826
  , 828
  , 831
  , 833
  , 835
  , 838
  , 840
  , 842
  , 845
  , 847
  , 849
  , 852
  , 854
  , 856
  , 858
  , 861
  , 863
  , 865
  , 867
  , 869
  , 872
  , 874
  , 876
  , 878
  , 881
  , 883
  , 885
  , 887
  , 889
  , 891
  , 894
  , 896
  , 898
  , 900
  , 902
  , 904
  , 906
  , 909
  , 911
  , 913
  , 915
  , 917
  , 919
  , 921
  , 923
  , 925
  , 927
  , 929
  , 931
  , 934
  , 936
  , 938
  , 940
  , 942
  , 944
  , 946
  , 948
  , 950
  , 952
  , 954
  , 956
  , 958
  , 960
  , 962
  , 964
  , 966
  , 968
  , 970
  , 972
  , 974
  , 976
  , 978
  , 979
  , 981
  , 983
  , 985
  , 987
  , 989
  , 991
  , 993
  , 995
  , 997
  , 999
  , 1001
  , 1002
  , 1004
  , 1006
  , 1008
  , 1010
  , 1012
  , 1014
  , 1016
  , 1017
  , 1019
  , 1021
  , 1023
  , 1025
  , 1027
  , 1028
  , 1030
  , 1032
  , 1034
  , 1036
  , 1038
  , 1039
  , 1041
  , 1043
  , 1045
  , 1046
  , 1048
  , 1050
  , 1052
  , 1054
  , 1055
  , 1057
  , 1059
  , 1061
  , 1063
  , 1064
  , 1066
  , 1068
  , 1069
  , 1071
  , 1073
  , 1075
  , 1076
  , 1078
  , 1080
  , 1082
  , 1083
  , 1085
  , 1087
  , 1088
  , 1090
  , 1092
  , 1094
  , 1095
  , 1097
  , 1099
  , 1100
  , 1102
  , 1104
  , 1105
  , 1107
  , 1109
  , 1111
  , 1112
  , 1114
  , 1115
  , 1117
  , 1119
  , 1120
  , 1122
  , 1124
  , 1125
  , 1127
  , 1129
  , 1130
  , 1132
  , 1133
  , 1135
  , 1137
  , 1138
  , 1140
  , 1142
  , 1143
  , 1145
  , 1146
  , 1148
  , 1150
  , 1151
  , 1153
  , 1154
  , 1156
  , 1158
  , 1159
  , 1161
  , 1162
  , 1164
  , 1165
  , 1167
  , 1169
  , 1170
  , 1172
  , 1173
  , 1175
  , 1176
  , 1178
  , 1180
  , 1181
  , 1183
  , 1184
  , 1186
  , 1187
  , 1189
  , 1190
  , 1192
  , 1193
  , 1195
  , 1196
  , 1198
  , 1199
  , 1201
  , 1203
  , 1204
  , 1206
  , 1207
  , 1208
  , 1210
  , 1212
  , 1213
  , 1215
  , 1216
  , 1217
  , 1219
  , 1220
  , 1222
  , 1223
  , 1225
  , 1226
  , 1228
  , 1229
  , 1231
  , 1232
  , 1234
  , 1235
  , 1237
  , 1238
  , 1240
  , 1241
  , 1242
  , 1244
  , 1245
  , 1247
  , 1248
  , 1250
  , 1251
  , 1253
  , 1254
  , 1255
  , 1257
  , 1258
  , 1260
  , 1261
  , 1263
  , 1264
  , 1265
  , 1267
  , 1268
  , 1270
  , 1271
  , 1272
  , 1274
  , 1275
  , 1277
  , 1278
  , 1279
  , 1281
  , 1282
  , 1284
  , 1285
  , 1286
  , 1288
  , 1289
  , 1291
  , 1292
  , 1293
  , 1295
  , 1296
  , 1297
  , 1299
  , 1300
  , 1302
  , 1303
  , 1304
  , 1306
  , 1307
  , 1308
  , 1310
  , 1311
  , 1312
  , 1314
  , 1315
  , 1316
  , 1318
  , 1319
  , 1320
  , 1322
  , 1323
  , 1325
  , 1326
  , 1327
  , 1329
  , 1330
  , 1331
  , 1332
  , 1334
  , 1335
  , 1336
  , 1338
  , 1339
  , 1340
  , 1342
  , 1343
  , 1344
  , 1346
  , 1347
  , 1348
  , 1350
  , 1351
  , 1352
  , 1353
  , 1355
  , 1356
  , 1357
  , 1359
  , 1360
  , 1361
  , 1363
  , 1364
  , 1365
  , 1366
  , 1368
  , 1369
  , 1370
  , 1371
  , 1373
  , 1374
  , 1375
  , 1377
  , 1378
  , 1379
  , 1380
  , 1382
  , 1383
  , 1384
  , 1385
  , 1387
  , 1388
  , 1389
  , 1390
  , 1392
  , 1393
  , 1394
  , 1395
  , 1397
  , 1398
  , 1399
  , 1400
  , 1402
  , 1403
  , 1404
  , 1405
  , 1406
  , 1408
  , 1409
  , 1410
  , 1411
  , 1413
  , 1414
  , 1415
  , 1416
  , 1418
  , 1419
  , 1420
  , 1421
  , 1422
  , 1424
  , 1425
  , 1426
  , 1427
  , 1428
  , 1430
  , 1431
  , 1432
  , 1433
  , 1434
  , 1436
  , 1437
  , 1438
  , 1439
  , 1440
  , 1442
  , 1443
  , 1444
  , 1445
  , 1446
  , 1448
  , 1449
  , 1450
  , 1451
  , 1452
  , 1454
  , 1455
  , 1456
  , 1457
  , 1458
  , 1459
  , 1461
  , 1462
  , 1463
  , 1464
  , 1465
  , 1466
  , 1468
  , 1469
  , 1470
  , 1471
  , 1472
  , 1473
  , 1474
  , 1476
  , 1477
  , 1478
  , 1479
  , 1480
  , 1481
  , 1483
  , 1484
  , 1485
  , 1486
  , 1487
  , 1488
  , 1489
  , 1491
  , 1492
  , 1493
  , 1494
  , 1495
  , 1496
  , 1497
  , 1498
  , 1500
  , 1501
  , 1502
  , 1503
  , 1504
  , 1505
  , 1506
  , 1507
  , 1508
  , 1510
  , 1511
  , 1512
  , 1513
};

#include <SimpleKalmanFilter.h>
SimpleKalmanFilter simpleKalmanFilter(1, 2, 0.02);
const long SERIAL_REFRESH_TIME = 10;
long refresh_time;
float pressurePa_filter;

//stepper
#include "BasicStepperDriver.h"
#define MOTOR_STEPS 200
#define RPM 100
#define MICROSTEPS 2
#define DIR 32
#define STEP 33
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);
int refreshRR, refreshSTEP, r_down, r_up, r_loop, ra_loop;
int direct = 2; // STEPS
int delay_step = 500;

int RR = 16; //RESPIRATORY RATE
float time_RR = 60.00 / RR * 1000;

float IE_ratio[] = {1, 2}; // I=1 E=2
float conv_IE = IE_ratio[0] / (IE_ratio[0] + IE_ratio[1]);
float set_Ti = time_RR * conv_IE;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  stepper.begin(RPM, MICROSTEPS);
  r_loop = 1;
}

// the loop routine runs over and over again forever:
void loop() {

  /////////////////////////////SENSOR////////////////////////////////
  
  // read the input on analog pin 0:
  int sensorValue = analogRead(25);
  // print out the value you read:
  int rangeSen = constrain(sensorValue, 0, 2560);
  int mapSen = map(rangeSen, 0, 2560, 0, 1023);
  float pressurePa = mapSen * ADC_mV / sensitivity;  // result in Pa use this line when using ADCoffset
  flowRate = flowArray[mapSen];
  // kalman
  float measured_value = pressurePa + random(-1023, 1023) / 1023.0;

  pressurePa_filter = simpleKalmanFilter.updateEstimate(measured_value);
  if (millis() > refresh_time) {
    Serial.print(pressurePa_filter);           // raw ADC value
    Serial.print(",");
    Serial.println(flowRate);        // reading of differential pressure over the orifice
    refresh_time = millis() + SERIAL_REFRESH_TIME;
  }

  /////////////////////////////STEPPER////////////////////////////////
  if (millis() > refreshRR) {
    if (ra_loop > 0) {
      direct = -2;
      r_loop = 0;
    }

    refreshRR = millis() + time_RR;
  }
  if (millis() - r_down >= set_Ti && r_loop < 2) {
    direct = direct * (-1);
    r_down = millis();
    r_loop++;

  }
  if (millis() - r_down >= set_Ti && r_loop == 2) {
    direct = 0;
  }
  if (micros() > refreshSTEP) {
    refreshSTEP = micros() + delay_step;
    stepper.move(direct);
  }
  ra_loop = 1;
}
