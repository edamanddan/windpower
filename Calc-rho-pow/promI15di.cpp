//Programa lee datos de un archivo .txt y almacena en matriz
//Almacena cada columna en un vector
//De acuerdo a índices podrá generar promedios móviles
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
using namespace std;

int main()
{
float data [14][28624], rhoI[28624], rhoH[28624], Idi[28624], Idh[28624], I15di[28624], I15dh[28624];
float I20di[28624], I20dh[28624], I25di[28624], I25dh[28624];

float s,c,pr=0,p1,	p2,	p3,	p4,	p5,	p6,	p7,	p8,	p9,	p10,	p11,	p12,	p13,	p14,	p15,	p16,	p17,	p18,	p19,	p20,	p21,	p22,	p23,	p24,	p25,	p26,	p27,	p28,	p29,	p30,	p31,	p32,	p33,	p34,	p35,	p36,	p37,	p38,	p39,	p40,	p41,	p42,	p43,	p44,	p45,	p46,	p47,	p48,	p49,	p50,	p51,	p52,	p53,	p54,	p55,	p56,	p57,	p58,	p59,	p60,	p61,	p62,	p63,	p64,	p65,	p66,	p67,	p68,	p69,	p70,	p71,	p72,	p73,	p74,	p75,	p76,	p77,	p78,	p79,	p80,	p81,	p82,	p83,	p84,	p85,	p86,	p87,	p88,	p89,	p90,	p91,	p92,	p93,	p94,	p95,	p96,	p97,	p98,	p99,	p100,	p101,	p102,	p103,	p104,	p105,	p106,	p107,	p108,	p109,	p110,	p111,	p112,	p113,	p114,	p115,	p116,	p117,	p118,	p119,	p120,	p121,	p122,	p123,	p124,	p125,	p126,	p127,	p128,	p129,	p130,	p131,	p132,	p133,	p134,	p135,	p136,	p137,	p138,	p139,	p140,	p141,	p142,	p143,	p144,	p145,	p146,	p147,	p148,	p149,	p150,	p151,	p152,	p153,	p154,	p155,	p156,	p157,	p158,	p159,	p160,	p161,	p162,	p163,	p164,	p165,	p166,	p167,	p168,	p169,	p170,	p171,	p172,	p173,	p174,	p175,	p176,	p177,	p178,	p179,	p180,	p181,	p182,	p183,	p184,	p185,	p186,	p187,	p188,	p189,	p190,	p191,	p192,	p193,	p194,	p195,	p196,	p197,	p198,	p199,	p200,	p201,	p202,	p203,	p204,	p205,	p206,	p207,	p208,	p209,	p210,	p211,	p212,	p213,	p214,	p215,	p216,	p217,	p218,	p219,	p220,	p221,	p222,	p223,	p224,	p225,	p226,	p227,	p228,	p229,	p230,	p231,	p232,	p233,	p234,	p235,	p236,	p237,	p238,	p239,	p240,	p241,	p242,	p243,	p244,	p245,	p246,	p247,	p248,	p249,	p250,	p251,	p252,	p253,	p254,	p255,	p256,	p257,	p258,	p259,	p260,	p261,	p262,	p263,	p264,	p265,	p266,	p267,	p268,	p269,	p270,	p271,	p272,	p273,	p274,	p275,	p276,	p277,	p278,	p279,	p280,	p281,	p282,	p283,	p284,	p285,	p286,	p287,	p288,	p289,	p290,	p291,	p292,	p293,	p294,	p295,	p296,	p297,	p298,	p299,	p300,	p301,	p302,	p303,	p304,	p305,	p306,	p307,	p308,	p309,	p310,	p311,	p312,	p313,	p314,	p315,	p316,	p317,	p318,	p319,	p320,	p321,	p322,	p323,	p324,	p325,	p326,	p327,	p328,	p329,	p330,	p331,	p332,	p333,	p334,	p335,	p336,	p337,	p338,	p339,	p340,	p341,	p342,	p343,	p344,	p345,	p346,	p347,	p348,	p349,	p350,	p351,	p352,	p353,	p354,	p355,	p356,	p357,	p358,	p359,	p360,	p361,	p362,	p363,	p364,	p365;

int x,y;

ifstream in ("resss.txt");

if (!in){
    cout<<"Not open file. \n";
    return 0;
    }

    for (y=0; y<28624;y++)
    {
        for (x=0;x<14;x++)
        {
            in>>data[x][y];
        }
    }
    
 in.close();
 
    for(x=0;x<28624;x++)
    {
        rhoI[x] = data[4][x];       //densidad ideal
        rhoH[x] = data[5][x];       //densidad humedo
        Idi[x] = data[6][x];        //Intesidad gas ideal
        Idh[x] = data[7][x];        //intensidad gas humedo
        I15di[x] = data[8][x];      //Intesidad gas ideal 15m
        I15dh[x] = data[9][x];     //Intesidad gas humedo 15m
        I20di[x] = data[10][x];      //Intesidad gas ideal 20m
        I20dh[x] = data[11][x];     //Intesidad gas humedo 20m   
        I25di[x] = data[12][x];      //Intesidad gas ideal 25m
        I25dh[x] = data[13][x];     //Intesidad gas humedo 25m
             
    }

    
for(y=0;y<80;y++){pr=pr+I15di[y];}  p1=pr/80; cout<<fixed<<setprecision(3)<<1<<"\t"<<p1<<endl;pr=0;
for(y=80;y<160;y++){pr=pr+I15di[y];}  p2=pr/80; cout<<2<<"\t"<<p2<<endl;pr=0;
for(y=160;y<240;y++){pr=pr+I15di[y];}  p3=pr/80; cout<<3<<"\t"<<p3<<endl;pr=0;
for(y=240;y<320;y++){pr=pr+I15di[y];}  p4=pr/80; cout<<4<<"\t"<<p4<<endl;pr=0;
for(y=320;y<400;y++){pr=pr+I15di[y];}  p5=pr/80; cout<<5<<"\t"<<p5<<endl;pr=0;
for(y=400;y<480;y++){pr=pr+I15di[y];}  p6=pr/80; cout<<6<<"\t"<<p6<<endl;pr=0;
for(y=480;y<560;y++){pr=pr+I15di[y];}  p7=pr/80; cout<<7<<"\t"<<p7<<endl;pr=0;
for(y=560;y<640;y++){pr=pr+I15di[y];}  p8=pr/80; cout<<8<<"\t"<<p8<<endl;pr=0;
for(y=640;y<720;y++){pr=pr+I15di[y];}  p9=pr/80; cout<<9<<"\t"<<p9<<endl;pr=0;
for(y=720;y<800;y++){pr=pr+I15di[y];}  p10=pr/80; cout<<10<<"\t"<<p10<<endl;pr=0;
for(y=800;y<880;y++){pr=pr+I15di[y];}  p11=pr/80; cout<<11<<"\t"<<p11<<endl;pr=0;
for(y=880;y<960;y++){pr=pr+I15di[y];}  p12=pr/80; cout<<12<<"\t"<<p12<<endl;pr=0;
for(y=960;y<1040;y++){pr=pr+I15di[y];}  p13=pr/80; cout<<13<<"\t"<<p13<<endl;pr=0;
for(y=1040;y<1120;y++){pr=pr+I15di[y];}  p14=pr/80; cout<<14<<"\t"<<p14<<endl;pr=0;
for(y=1120;y<1200;y++){pr=pr+I15di[y];}  p15=pr/80; cout<<15<<"\t"<<p15<<endl;pr=0;
for(y=1200;y<1280;y++){pr=pr+I15di[y];}  p16=pr/80; cout<<16<<"\t"<<p16<<endl;pr=0;
for(y=1280;y<1360;y++){pr=pr+I15di[y];}  p17=pr/80; cout<<17<<"\t"<<p17<<endl;pr=0;
for(y=1360;y<1440;y++){pr=pr+I15di[y];}  p18=pr/80; cout<<18<<"\t"<<p18<<endl;pr=0;
for(y=1440;y<1520;y++){pr=pr+I15di[y];}  p19=pr/80; cout<<19<<"\t"<<p19<<endl;pr=0;
for(y=1520;y<1600;y++){pr=pr+I15di[y];}  p20=pr/80; cout<<20<<"\t"<<p20<<endl;pr=0;
for(y=1600;y<1680;y++){pr=pr+I15di[y];}  p21=pr/80; cout<<21<<"\t"<<p21<<endl;pr=0;
for(y=1680;y<1760;y++){pr=pr+I15di[y];}  p22=pr/80; cout<<22<<"\t"<<p22<<endl;pr=0;
for(y=1760;y<1840;y++){pr=pr+I15di[y];}  p23=pr/80; cout<<23<<"\t"<<p23<<endl;pr=0;
for(y=1840;y<1920;y++){pr=pr+I15di[y];}  p24=pr/80; cout<<24<<"\t"<<p24<<endl;pr=0;
for(y=1920;y<2000;y++){pr=pr+I15di[y];}  p25=pr/80; cout<<25<<"\t"<<p25<<endl;pr=0;
for(y=2000;y<2080;y++){pr=pr+I15di[y];}  p26=pr/80; cout<<26<<"\t"<<p26<<endl;pr=0;
for(y=2080;y<2160;y++){pr=pr+I15di[y];}  p27=pr/80; cout<<27<<"\t"<<p27<<endl;pr=0;
for(y=2160;y<2240;y++){pr=pr+I15di[y];}  p28=pr/80; cout<<28<<"\t"<<p28<<endl;pr=0;
for(y=2240;y<2320;y++){pr=pr+I15di[y];}  p29=pr/80; cout<<29<<"\t"<<p29<<endl;pr=0;
for(y=2320;y<2400;y++){pr=pr+I15di[y];}  p30=pr/80; cout<<30<<"\t"<<p30<<endl;pr=0;
for(y=2400;y<2480;y++){pr=pr+I15di[y];}  p31=pr/80; cout<<31<<"\t"<<p31<<endl;pr=0;
for(y=2480;y<2560;y++){pr=pr+I15di[y];}  p32=pr/80; cout<<32<<"\t"<<p32<<endl;pr=0;
for(y=2560;y<2640;y++){pr=pr+I15di[y];}  p33=pr/80; cout<<33<<"\t"<<p33<<endl;pr=0;
for(y=2640;y<2720;y++){pr=pr+I15di[y];}  p34=pr/80; cout<<34<<"\t"<<p34<<endl;pr=0;
for(y=2720;y<2800;y++){pr=pr+I15di[y];}  p35=pr/80; cout<<35<<"\t"<<p35<<endl;pr=0;
for(y=2800;y<2880;y++){pr=pr+I15di[y];}  p36=pr/80; cout<<36<<"\t"<<p36<<endl;pr=0;
for(y=2880;y<2960;y++){pr=pr+I15di[y];}  p37=pr/80; cout<<37<<"\t"<<p37<<endl;pr=0;
for(y=2960;y<3040;y++){pr=pr+I15di[y];}  p38=pr/80; cout<<38<<"\t"<<p38<<endl;pr=0;
for(y=3040;y<3120;y++){pr=pr+I15di[y];}  p39=pr/80; cout<<39<<"\t"<<p39<<endl;pr=0;
for(y=3120;y<3200;y++){pr=pr+I15di[y];}  p40=pr/80; cout<<40<<"\t"<<p40<<endl;pr=0;
for(y=3200;y<3280;y++){pr=pr+I15di[y];}  p41=pr/80; cout<<41<<"\t"<<p41<<endl;pr=0;
for(y=3280;y<3360;y++){pr=pr+I15di[y];}  p42=pr/80; cout<<42<<"\t"<<p42<<endl;pr=0;
for(y=3360;y<3440;y++){pr=pr+I15di[y];}  p43=pr/80; cout<<43<<"\t"<<p43<<endl;pr=0;
for(y=3440;y<3520;y++){pr=pr+I15di[y];}  p44=pr/80; cout<<44<<"\t"<<p44<<endl;pr=0;
for(y=3520;y<3600;y++){pr=pr+I15di[y];}  p45=pr/80; cout<<45<<"\t"<<p45<<endl;pr=0;
for(y=3600;y<3680;y++){pr=pr+I15di[y];}  p46=pr/80; cout<<46<<"\t"<<p46<<endl;pr=0;
for(y=3680;y<3760;y++){pr=pr+I15di[y];}  p47=pr/80; cout<<47<<"\t"<<p47<<endl;pr=0;
for(y=3760;y<3840;y++){pr=pr+I15di[y];}  p48=pr/80; cout<<48<<"\t"<<p48<<endl;pr=0;
for(y=3840;y<3920;y++){pr=pr+I15di[y];}  p49=pr/80; cout<<49<<"\t"<<p49<<endl;pr=0;
for(y=3920;y<4000;y++){pr=pr+I15di[y];}  p50=pr/80; cout<<50<<"\t"<<p50<<endl;pr=0;
for(y=4000;y<4080;y++){pr=pr+I15di[y];}  p51=pr/80; cout<<51<<"\t"<<p51<<endl;pr=0;
for(y=4080;y<4160;y++){pr=pr+I15di[y];}  p52=pr/80; cout<<52<<"\t"<<p52<<endl;pr=0;
for(y=4160;y<4240;y++){pr=pr+I15di[y];}  p53=pr/80; cout<<53<<"\t"<<p53<<endl;pr=0;
for(y=4240;y<4320;y++){pr=pr+I15di[y];}  p54=pr/80; cout<<54<<"\t"<<p54<<endl;pr=0;
for(y=4320;y<4400;y++){pr=pr+I15di[y];}  p55=pr/80; cout<<55<<"\t"<<p55<<endl;pr=0;
for(y=4400;y<4480;y++){pr=pr+I15di[y];}  p56=pr/80; cout<<56<<"\t"<<p56<<endl;pr=0;
for(y=4480;y<4560;y++){pr=pr+I15di[y];}  p57=pr/80; cout<<57<<"\t"<<p57<<endl;pr=0;
for(y=4560;y<4640;y++){pr=pr+I15di[y];}  p58=pr/80; cout<<58<<"\t"<<p58<<endl;pr=0;
for(y=4640;y<4720;y++){pr=pr+I15di[y];}  p59=pr/80; cout<<59<<"\t"<<p59<<endl;pr=0;
for(y=4720;y<4800;y++){pr=pr+I15di[y];}  p60=pr/80; cout<<60<<"\t"<<p60<<endl;pr=0;
for(y=4800;y<4880;y++){pr=pr+I15di[y];}  p61=pr/80; cout<<61<<"\t"<<p61<<endl;pr=0;
for(y=4880;y<4960;y++){pr=pr+I15di[y];}  p62=pr/80; cout<<62<<"\t"<<p62<<endl;pr=0;
for(y=4960;y<5040;y++){pr=pr+I15di[y];}  p63=pr/80; cout<<63<<"\t"<<p63<<endl;pr=0;
for(y=5040;y<5120;y++){pr=pr+I15di[y];}  p64=pr/80; cout<<64<<"\t"<<p64<<endl;pr=0;
for(y=5120;y<5200;y++){pr=pr+I15di[y];}  p65=pr/80; cout<<65<<"\t"<<p65<<endl;pr=0;
for(y=5200;y<5280;y++){pr=pr+I15di[y];}  p66=pr/80; cout<<66<<"\t"<<p66<<endl;pr=0;
for(y=5280;y<5360;y++){pr=pr+I15di[y];}  p67=pr/80; cout<<67<<"\t"<<p67<<endl;pr=0;
for(y=5360;y<5440;y++){pr=pr+I15di[y];}  p68=pr/80; cout<<68<<"\t"<<p68<<endl;pr=0;
for(y=5440;y<5520;y++){pr=pr+I15di[y];}  p69=pr/80; cout<<69<<"\t"<<p69<<endl;pr=0;
for(y=5520;y<5600;y++){pr=pr+I15di[y];}  p70=pr/80; cout<<70<<"\t"<<p70<<endl;pr=0;
for(y=5600;y<5680;y++){pr=pr+I15di[y];}  p71=pr/80; cout<<71<<"\t"<<p71<<endl;pr=0;
for(y=5680;y<5760;y++){pr=pr+I15di[y];}  p72=pr/80; cout<<72<<"\t"<<p72<<endl;pr=0;
for(y=5760;y<5840;y++){pr=pr+I15di[y];}  p73=pr/80; cout<<73<<"\t"<<p73<<endl;pr=0;
for(y=5840;y<5920;y++){pr=pr+I15di[y];}  p74=pr/80; cout<<74<<"\t"<<p74<<endl;pr=0;
for(y=5920;y<6000;y++){pr=pr+I15di[y];}  p75=pr/80; cout<<75<<"\t"<<p75<<endl;pr=0;
for(y=6000;y<6080;y++){pr=pr+I15di[y];}  p76=pr/80; cout<<76<<"\t"<<p76<<endl;pr=0;
for(y=6080;y<6160;y++){pr=pr+I15di[y];}  p77=pr/80; cout<<77<<"\t"<<p77<<endl;pr=0;
for(y=6160;y<6240;y++){pr=pr+I15di[y];}  p78=pr/80; cout<<78<<"\t"<<p78<<endl;pr=0;
for(y=6240;y<6320;y++){pr=pr+I15di[y];}  p79=pr/80; cout<<79<<"\t"<<p79<<endl;pr=0;
for(y=6320;y<6400;y++){pr=pr+I15di[y];}  p80=pr/80; cout<<80<<"\t"<<p80<<endl;pr=0;
for(y=6400;y<6480;y++){pr=pr+I15di[y];}  p81=pr/80; cout<<81<<"\t"<<p81<<endl;pr=0;
for(y=6480;y<6560;y++){pr=pr+I15di[y];}  p82=pr/80; cout<<82<<"\t"<<p82<<endl;pr=0;
for(y=6560;y<6640;y++){pr=pr+I15di[y];}  p83=pr/80; cout<<83<<"\t"<<p83<<endl;pr=0;
for(y=6640;y<6720;y++){pr=pr+I15di[y];}  p84=pr/80; cout<<84<<"\t"<<p84<<endl;pr=0;
for(y=6720;y<6800;y++){pr=pr+I15di[y];}  p85=pr/80; cout<<85<<"\t"<<p85<<endl;pr=0;
for(y=6800;y<6880;y++){pr=pr+I15di[y];}  p86=pr/80; cout<<86<<"\t"<<p86<<endl;pr=0;
for(y=6880;y<6960;y++){pr=pr+I15di[y];}  p87=pr/80; cout<<87<<"\t"<<p87<<endl;pr=0;
for(y=6960;y<7040;y++){pr=pr+I15di[y];}  p88=pr/80; cout<<88<<"\t"<<p88<<endl;pr=0;
for(y=7040;y<7120;y++){pr=pr+I15di[y];}  p89=pr/80; cout<<89<<"\t"<<p89<<endl;pr=0;
for(y=7120;y<7200;y++){pr=pr+I15di[y];}  p90=pr/80; cout<<90<<"\t"<<p90<<endl;pr=0;
for(y=7200;y<7280;y++){pr=pr+I15di[y];}  p91=pr/80; cout<<91<<"\t"<<p91<<endl;pr=0;
for(y=7280;y<7360;y++){pr=pr+I15di[y];}  p92=pr/80; cout<<92<<"\t"<<p92<<endl;pr=0;
for(y=7360;y<7440;y++){pr=pr+I15di[y];}  p93=pr/80; cout<<93<<"\t"<<p93<<endl;pr=0;
for(y=7440;y<7520;y++){pr=pr+I15di[y];}  p94=pr/80; cout<<94<<"\t"<<p94<<endl;pr=0;
for(y=7520;y<7600;y++){pr=pr+I15di[y];}  p95=pr/80; cout<<95<<"\t"<<p95<<endl;pr=0;
for(y=7600;y<7680;y++){pr=pr+I15di[y];}  p96=pr/80; cout<<96<<"\t"<<p96<<endl;pr=0;
for(y=7680;y<7760;y++){pr=pr+I15di[y];}  p97=pr/80; cout<<97<<"\t"<<p97<<endl;pr=0;
for(y=7760;y<7840;y++){pr=pr+I15di[y];}  p98=pr/80; cout<<98<<"\t"<<p98<<endl;pr=0;
for(y=7840;y<7920;y++){pr=pr+I15di[y];}  p99=pr/80; cout<<99<<"\t"<<p99<<endl;pr=0;
for(y=7920;y<8000;y++){pr=pr+I15di[y];}  p100=pr/80; cout<<100<<"\t"<<p100<<endl;pr=0;
for(y=8000;y<8080;y++){pr=pr+I15di[y];}  p101=pr/80; cout<<101<<"\t"<<p101<<endl;pr=0;
for(y=8080;y<8160;y++){pr=pr+I15di[y];}  p102=pr/80; cout<<102<<"\t"<<p102<<endl;pr=0;
for(y=8160;y<8240;y++){pr=pr+I15di[y];}  p103=pr/80; cout<<103<<"\t"<<p103<<endl;pr=0;
for(y=8240;y<8320;y++){pr=pr+I15di[y];}  p104=pr/80; cout<<104<<"\t"<<p104<<endl;pr=0;
for(y=8320;y<8400;y++){pr=pr+I15di[y];}  p105=pr/80; cout<<105<<"\t"<<p105<<endl;pr=0;
for(y=8400;y<8480;y++){pr=pr+I15di[y];}  p106=pr/80; cout<<106<<"\t"<<p106<<endl;pr=0;
for(y=8480;y<8560;y++){pr=pr+I15di[y];}  p107=pr/80; cout<<107<<"\t"<<p107<<endl;pr=0;
for(y=8560;y<8640;y++){pr=pr+I15di[y];}  p108=pr/80; cout<<108<<"\t"<<p108<<endl;pr=0;
for(y=8640;y<8720;y++){pr=pr+I15di[y];}  p109=pr/80; cout<<109<<"\t"<<p109<<endl;pr=0;
for(y=8720;y<8800;y++){pr=pr+I15di[y];}  p110=pr/80; cout<<110<<"\t"<<p110<<endl;pr=0;
for(y=8800;y<8880;y++){pr=pr+I15di[y];}  p111=pr/80; cout<<111<<"\t"<<p111<<endl;pr=0;
for(y=8880;y<8960;y++){pr=pr+I15di[y];}  p112=pr/80; cout<<112<<"\t"<<p112<<endl;pr=0;
for(y=8960;y<9040;y++){pr=pr+I15di[y];}  p113=pr/80; cout<<113<<"\t"<<p113<<endl;pr=0;
for(y=9040;y<9120;y++){pr=pr+I15di[y];}  p114=pr/80; cout<<114<<"\t"<<p114<<endl;pr=0;
for(y=9120;y<9200;y++){pr=pr+I15di[y];}  p115=pr/80; cout<<115<<"\t"<<p115<<endl;pr=0;
for(y=9200;y<9280;y++){pr=pr+I15di[y];}  p116=pr/80; cout<<116<<"\t"<<p116<<endl;pr=0;
for(y=9280;y<9360;y++){pr=pr+I15di[y];}  p117=pr/80; cout<<117<<"\t"<<p117<<endl;pr=0;
for(y=9360;y<9440;y++){pr=pr+I15di[y];}  p118=pr/80; cout<<118<<"\t"<<p118<<endl;pr=0;
for(y=9440;y<9520;y++){pr=pr+I15di[y];}  p119=pr/80; cout<<119<<"\t"<<p119<<endl;pr=0;
for(y=9520;y<9600;y++){pr=pr+I15di[y];}  p120=pr/80; cout<<120<<"\t"<<p120<<endl;pr=0;
for(y=9600;y<9680;y++){pr=pr+I15di[y];}  p121=pr/80; cout<<121<<"\t"<<p121<<endl;pr=0;
for(y=9680;y<9760;y++){pr=pr+I15di[y];}  p122=pr/80; cout<<122<<"\t"<<p122<<endl;pr=0;
for(y=9760;y<9840;y++){pr=pr+I15di[y];}  p123=pr/80; cout<<123<<"\t"<<p123<<endl;pr=0;
for(y=9840;y<9920;y++){pr=pr+I15di[y];}  p124=pr/80; cout<<124<<"\t"<<p124<<endl;pr=0;
for(y=9920;y<10000;y++){pr=pr+I15di[y];}  p125=pr/80; cout<<125<<"\t"<<p125<<endl;pr=0;
for(y=10000;y<10080;y++){pr=pr+I15di[y];}  p126=pr/80; cout<<126<<"\t"<<p126<<endl;pr=0;
for(y=10080;y<10160;y++){pr=pr+I15di[y];}  p127=pr/80; cout<<127<<"\t"<<p127<<endl;pr=0;
for(y=10160;y<10240;y++){pr=pr+I15di[y];}  p128=pr/80; cout<<128<<"\t"<<p128<<endl;pr=0;
for(y=10240;y<10320;y++){pr=pr+I15di[y];}  p129=pr/80; cout<<129<<"\t"<<p129<<endl;pr=0;
for(y=10320;y<10400;y++){pr=pr+I15di[y];}  p130=pr/80; cout<<130<<"\t"<<p130<<endl;pr=0;
for(y=10400;y<10480;y++){pr=pr+I15di[y];}  p131=pr/80; cout<<131<<"\t"<<p131<<endl;pr=0;
for(y=10480;y<10560;y++){pr=pr+I15di[y];}  p132=pr/80; cout<<132<<"\t"<<p132<<endl;pr=0;
for(y=10560;y<10640;y++){pr=pr+I15di[y];}  p133=pr/80; cout<<133<<"\t"<<p133<<endl;pr=0;
for(y=10640;y<10720;y++){pr=pr+I15di[y];}  p134=pr/80; cout<<134<<"\t"<<p134<<endl;pr=0;
for(y=10720;y<10800;y++){pr=pr+I15di[y];}  p135=pr/80; cout<<135<<"\t"<<p135<<endl;pr=0;
for(y=10800;y<10880;y++){pr=pr+I15di[y];}  p136=pr/80; cout<<136<<"\t"<<p136<<endl;pr=0;
for(y=10880;y<10960;y++){pr=pr+I15di[y];}  p137=pr/80; cout<<137<<"\t"<<p137<<endl;pr=0;
for(y=10960;y<11040;y++){pr=pr+I15di[y];}  p138=pr/80; cout<<138<<"\t"<<p138<<endl;pr=0;
for(y=11040;y<11120;y++){pr=pr+I15di[y];}  p139=pr/80; cout<<139<<"\t"<<p139<<endl;pr=0;
for(y=11120;y<11200;y++){pr=pr+I15di[y];}  p140=pr/80; cout<<140<<"\t"<<p140<<endl;pr=0;
for(y=11200;y<11280;y++){pr=pr+I15di[y];}  p141=pr/80; cout<<141<<"\t"<<p141<<endl;pr=0;
for(y=11280;y<11360;y++){pr=pr+I15di[y];}  p142=pr/80; cout<<142<<"\t"<<p142<<endl;pr=0;
for(y=11360;y<11440;y++){pr=pr+I15di[y];}  p143=pr/80; cout<<143<<"\t"<<p143<<endl;pr=0;
for(y=11440;y<11520;y++){pr=pr+I15di[y];}  p144=pr/80; cout<<144<<"\t"<<p144<<endl;pr=0;
for(y=11520;y<11600;y++){pr=pr+I15di[y];}  p145=pr/80; cout<<145<<"\t"<<p145<<endl;pr=0;
for(y=11600;y<11680;y++){pr=pr+I15di[y];}  p146=pr/80; cout<<146<<"\t"<<p146<<endl;pr=0;
for(y=11680;y<11760;y++){pr=pr+I15di[y];}  p147=pr/80; cout<<147<<"\t"<<p147<<endl;pr=0;
for(y=11760;y<11840;y++){pr=pr+I15di[y];}  p148=pr/80; cout<<148<<"\t"<<p148<<endl;pr=0;
for(y=11840;y<11920;y++){pr=pr+I15di[y];}  p149=pr/80; cout<<149<<"\t"<<p149<<endl;pr=0;
for(y=11920;y<12000;y++){pr=pr+I15di[y];}  p150=pr/80; cout<<150<<"\t"<<p150<<endl;pr=0;
for(y=12000;y<12080;y++){pr=pr+I15di[y];}  p151=pr/80; cout<<151<<"\t"<<p151<<endl;pr=0;
for(y=12080;y<12160;y++){pr=pr+I15di[y];}  p152=pr/80; cout<<152<<"\t"<<p152<<endl;pr=0;
for(y=12160;y<12240;y++){pr=pr+I15di[y];}  p153=pr/80; cout<<153<<"\t"<<p153<<endl;pr=0;
for(y=12240;y<12320;y++){pr=pr+I15di[y];}  p154=pr/80; cout<<154<<"\t"<<p154<<endl;pr=0;
for(y=12320;y<12400;y++){pr=pr+I15di[y];}  p155=pr/80; cout<<155<<"\t"<<p155<<endl;pr=0;
for(y=12400;y<12480;y++){pr=pr+I15di[y];}  p156=pr/80; cout<<156<<"\t"<<p156<<endl;pr=0;
for(y=12480;y<12560;y++){pr=pr+I15di[y];}  p157=pr/80; cout<<157<<"\t"<<p157<<endl;pr=0;
for(y=12560;y<12640;y++){pr=pr+I15di[y];}  p158=pr/80; cout<<158<<"\t"<<p158<<endl;pr=0;
for(y=12640;y<12720;y++){pr=pr+I15di[y];}  p159=pr/80; cout<<159<<"\t"<<p159<<endl;pr=0;
for(y=12720;y<12800;y++){pr=pr+I15di[y];}  p160=pr/80; cout<<160<<"\t"<<p160<<endl;pr=0;
for(y=12800;y<12880;y++){pr=pr+I15di[y];}  p161=pr/80; cout<<161<<"\t"<<p161<<endl;pr=0;
for(y=12880;y<12960;y++){pr=pr+I15di[y];}  p162=pr/80; cout<<162<<"\t"<<p162<<endl;pr=0;
for(y=12960;y<13040;y++){pr=pr+I15di[y];}  p163=pr/80; cout<<163<<"\t"<<p163<<endl;pr=0;
for(y=13040;y<13120;y++){pr=pr+I15di[y];}  p164=pr/80; cout<<164<<"\t"<<p164<<endl;pr=0;
for(y=13120;y<13200;y++){pr=pr+I15di[y];}  p165=pr/80; cout<<165<<"\t"<<p165<<endl;pr=0;
for(y=13200;y<13280;y++){pr=pr+I15di[y];}  p166=pr/80; cout<<166<<"\t"<<p166<<endl;pr=0;
for(y=13280;y<13360;y++){pr=pr+I15di[y];}  p167=pr/80; cout<<167<<"\t"<<p167<<endl;pr=0;
for(y=13360;y<13440;y++){pr=pr+I15di[y];}  p168=pr/80; cout<<168<<"\t"<<p168<<endl;pr=0;
for(y=13440;y<13520;y++){pr=pr+I15di[y];}  p169=pr/80; cout<<169<<"\t"<<p169<<endl;pr=0;
for(y=13520;y<13600;y++){pr=pr+I15di[y];}  p170=pr/80; cout<<170<<"\t"<<p170<<endl;pr=0;
for(y=13600;y<13680;y++){pr=pr+I15di[y];}  p171=pr/80; cout<<171<<"\t"<<p171<<endl;pr=0;
for(y=13680;y<13760;y++){pr=pr+I15di[y];}  p172=pr/80; cout<<172<<"\t"<<p172<<endl;pr=0;
for(y=13760;y<13840;y++){pr=pr+I15di[y];}  p173=pr/80; cout<<173<<"\t"<<p173<<endl;pr=0;
for(y=13840;y<13920;y++){pr=pr+I15di[y];}  p174=pr/80; cout<<174<<"\t"<<p174<<endl;pr=0;
for(y=13920;y<14000;y++){pr=pr+I15di[y];}  p175=pr/80; cout<<175<<"\t"<<p175<<endl;pr=0;
for(y=14000;y<14080;y++){pr=pr+I15di[y];}  p176=pr/80; cout<<176<<"\t"<<p176<<endl;pr=0;
for(y=14080;y<14160;y++){pr=pr+I15di[y];}  p177=pr/80; cout<<177<<"\t"<<p177<<endl;pr=0;
for(y=14160;y<14240;y++){pr=pr+I15di[y];}  p178=pr/80; cout<<178<<"\t"<<p178<<endl;pr=0;
for(y=14240;y<14320;y++){pr=pr+I15di[y];}  p179=pr/80; cout<<179<<"\t"<<p179<<endl;pr=0;
for(y=14320;y<14400;y++){pr=pr+I15di[y];}  p180=pr/80; cout<<180<<"\t"<<p180<<endl;pr=0;
for(y=14400;y<14480;y++){pr=pr+I15di[y];}  p181=pr/80; cout<<181<<"\t"<<p181<<endl;pr=0;
for(y=14480;y<14560;y++){pr=pr+I15di[y];}  p182=pr/80; cout<<182<<"\t"<<p182<<endl;pr=0;
for(y=14560;y<14640;y++){pr=pr+I15di[y];}  p183=pr/80; cout<<183<<"\t"<<p183<<endl;pr=0;
for(y=14640;y<14720;y++){pr=pr+I15di[y];}  p184=pr/80; cout<<184<<"\t"<<p184<<endl;pr=0;
for(y=14720;y<14800;y++){pr=pr+I15di[y];}  p185=pr/80; cout<<185<<"\t"<<p185<<endl;pr=0;
for(y=14800;y<14880;y++){pr=pr+I15di[y];}  p186=pr/80; cout<<186<<"\t"<<p186<<endl;pr=0;
for(y=14880;y<14960;y++){pr=pr+I15di[y];}  p187=pr/80; cout<<187<<"\t"<<p187<<endl;pr=0;
for(y=14960;y<15040;y++){pr=pr+I15di[y];}  p188=pr/80; cout<<188<<"\t"<<p188<<endl;pr=0;
for(y=15040;y<15120;y++){pr=pr+I15di[y];}  p189=pr/80; cout<<189<<"\t"<<p189<<endl;pr=0;
for(y=15120;y<15200;y++){pr=pr+I15di[y];}  p190=pr/80; cout<<190<<"\t"<<p190<<endl;pr=0;
for(y=15200;y<15280;y++){pr=pr+I15di[y];}  p191=pr/80; cout<<191<<"\t"<<p191<<endl;pr=0;
for(y=15280;y<15360;y++){pr=pr+I15di[y];}  p192=pr/80; cout<<192<<"\t"<<p192<<endl;pr=0;
for(y=15360;y<15440;y++){pr=pr+I15di[y];}  p193=pr/80; cout<<193<<"\t"<<p193<<endl;pr=0;
for(y=15440;y<15520;y++){pr=pr+I15di[y];}  p194=pr/80; cout<<194<<"\t"<<p194<<endl;pr=0;
for(y=15520;y<15600;y++){pr=pr+I15di[y];}  p195=pr/80; cout<<195<<"\t"<<p195<<endl;pr=0;
for(y=15600;y<15680;y++){pr=pr+I15di[y];}  p196=pr/80; cout<<196<<"\t"<<p196<<endl;pr=0;
for(y=15680;y<15760;y++){pr=pr+I15di[y];}  p197=pr/80; cout<<197<<"\t"<<p197<<endl;pr=0;
for(y=15760;y<15840;y++){pr=pr+I15di[y];}  p198=pr/80; cout<<198<<"\t"<<p198<<endl;pr=0;
for(y=15840;y<15920;y++){pr=pr+I15di[y];}  p199=pr/80; cout<<199<<"\t"<<p199<<endl;pr=0;
for(y=15920;y<16000;y++){pr=pr+I15di[y];}  p200=pr/80; cout<<200<<"\t"<<p200<<endl;pr=0;
for(y=16000;y<16080;y++){pr=pr+I15di[y];}  p201=pr/80; cout<<201<<"\t"<<p201<<endl;pr=0;
for(y=16080;y<16160;y++){pr=pr+I15di[y];}  p202=pr/80; cout<<202<<"\t"<<p202<<endl;pr=0;
for(y=16160;y<16240;y++){pr=pr+I15di[y];}  p203=pr/80; cout<<203<<"\t"<<p203<<endl;pr=0;
for(y=16240;y<16320;y++){pr=pr+I15di[y];}  p204=pr/80; cout<<204<<"\t"<<p204<<endl;pr=0;
for(y=16320;y<16400;y++){pr=pr+I15di[y];}  p205=pr/80; cout<<205<<"\t"<<p205<<endl;pr=0;
for(y=16400;y<16480;y++){pr=pr+I15di[y];}  p206=pr/80; cout<<206<<"\t"<<p206<<endl;pr=0;
for(y=16480;y<16560;y++){pr=pr+I15di[y];}  p207=pr/80; cout<<207<<"\t"<<p207<<endl;pr=0;
for(y=16560;y<16640;y++){pr=pr+I15di[y];}  p208=pr/80; cout<<208<<"\t"<<p208<<endl;pr=0;
for(y=16640;y<16720;y++){pr=pr+I15di[y];}  p209=pr/80; cout<<209<<"\t"<<p209<<endl;pr=0;
for(y=16720;y<16800;y++){pr=pr+I15di[y];}  p210=pr/80; cout<<210<<"\t"<<p210<<endl;pr=0;
for(y=16800;y<16880;y++){pr=pr+I15di[y];}  p211=pr/80; cout<<211<<"\t"<<p211<<endl;pr=0;
for(y=16880;y<16960;y++){pr=pr+I15di[y];}  p212=pr/80; cout<<212<<"\t"<<p212<<endl;pr=0;
for(y=16960;y<17040;y++){pr=pr+I15di[y];}  p213=pr/80; cout<<213<<"\t"<<p213<<endl;pr=0;
for(y=17040;y<17120;y++){pr=pr+I15di[y];}  p214=pr/80; cout<<214<<"\t"<<p214<<endl;pr=0;
for(y=17120;y<17200;y++){pr=pr+I15di[y];}  p215=pr/80; cout<<215<<"\t"<<p215<<endl;pr=0;
for(y=17200;y<17280;y++){pr=pr+I15di[y];}  p216=pr/80; cout<<216<<"\t"<<p216<<endl;pr=0;
for(y=17280;y<17360;y++){pr=pr+I15di[y];}  p217=pr/80; cout<<217<<"\t"<<p217<<endl;pr=0;
for(y=17360;y<17440;y++){pr=pr+I15di[y];}  p218=pr/80; cout<<218<<"\t"<<p218<<endl;pr=0;
for(y=17440;y<17520;y++){pr=pr+I15di[y];}  p219=pr/80; cout<<219<<"\t"<<p219<<endl;pr=0;
for(y=17520;y<17600;y++){pr=pr+I15di[y];}  p220=pr/80; cout<<220<<"\t"<<p220<<endl;pr=0;
for(y=17600;y<17680;y++){pr=pr+I15di[y];}  p221=pr/80; cout<<221<<"\t"<<p221<<endl;pr=0;
for(y=17680;y<17760;y++){pr=pr+I15di[y];}  p222=pr/80; cout<<222<<"\t"<<p222<<endl;pr=0;
for(y=17760;y<17840;y++){pr=pr+I15di[y];}  p223=pr/80; cout<<223<<"\t"<<p223<<endl;pr=0;
for(y=17840;y<17920;y++){pr=pr+I15di[y];}  p224=pr/80; cout<<224<<"\t"<<p224<<endl;pr=0;
for(y=17920;y<18000;y++){pr=pr+I15di[y];}  p225=pr/80; cout<<225<<"\t"<<p225<<endl;pr=0;
for(y=18000;y<18080;y++){pr=pr+I15di[y];}  p226=pr/80; cout<<226<<"\t"<<p226<<endl;pr=0;
for(y=18080;y<18160;y++){pr=pr+I15di[y];}  p227=pr/80; cout<<227<<"\t"<<p227<<endl;pr=0;
for(y=18160;y<18240;y++){pr=pr+I15di[y];}  p228=pr/80; cout<<228<<"\t"<<p228<<endl;pr=0;
for(y=18240;y<18320;y++){pr=pr+I15di[y];}  p229=pr/80; cout<<229<<"\t"<<p229<<endl;pr=0;
for(y=18320;y<18400;y++){pr=pr+I15di[y];}  p230=pr/80; cout<<230<<"\t"<<p230<<endl;pr=0;
for(y=18400;y<18480;y++){pr=pr+I15di[y];}  p231=pr/80; cout<<231<<"\t"<<p231<<endl;pr=0;
for(y=18480;y<18560;y++){pr=pr+I15di[y];}  p232=pr/80; cout<<232<<"\t"<<p232<<endl;pr=0;
for(y=18560;y<18640;y++){pr=pr+I15di[y];}  p233=pr/80; cout<<233<<"\t"<<p233<<endl;pr=0;
for(y=18640;y<18720;y++){pr=pr+I15di[y];}  p234=pr/80; cout<<234<<"\t"<<p234<<endl;pr=0;
for(y=18720;y<18800;y++){pr=pr+I15di[y];}  p235=pr/80; cout<<235<<"\t"<<p235<<endl;pr=0;
for(y=18800;y<18880;y++){pr=pr+I15di[y];}  p236=pr/80; cout<<236<<"\t"<<p236<<endl;pr=0;
for(y=18880;y<18960;y++){pr=pr+I15di[y];}  p237=pr/80; cout<<237<<"\t"<<p237<<endl;pr=0;
for(y=18960;y<19040;y++){pr=pr+I15di[y];}  p238=pr/80; cout<<238<<"\t"<<p238<<endl;pr=0;
for(y=19040;y<19120;y++){pr=pr+I15di[y];}  p239=pr/80; cout<<239<<"\t"<<p239<<endl;pr=0;
for(y=19120;y<19200;y++){pr=pr+I15di[y];}  p240=pr/80; cout<<240<<"\t"<<p240<<endl;pr=0;
for(y=19200;y<19280;y++){pr=pr+I15di[y];}  p241=pr/80; cout<<241<<"\t"<<p241<<endl;pr=0;
for(y=19280;y<19360;y++){pr=pr+I15di[y];}  p242=pr/80; cout<<242<<"\t"<<p242<<endl;pr=0;
for(y=19360;y<19440;y++){pr=pr+I15di[y];}  p243=pr/80; cout<<243<<"\t"<<p243<<endl;pr=0;
for(y=19440;y<19520;y++){pr=pr+I15di[y];}  p244=pr/80; cout<<244<<"\t"<<p244<<endl;pr=0;
for(y=19520;y<19600;y++){pr=pr+I15di[y];}  p245=pr/80; cout<<245<<"\t"<<p245<<endl;pr=0;
for(y=19600;y<19680;y++){pr=pr+I15di[y];}  p246=pr/80; cout<<246<<"\t"<<p246<<endl;pr=0;
for(y=19680;y<19760;y++){pr=pr+I15di[y];}  p247=pr/80; cout<<247<<"\t"<<p247<<endl;pr=0;
for(y=19760;y<19840;y++){pr=pr+I15di[y];}  p248=pr/80; cout<<248<<"\t"<<p248<<endl;pr=0;
for(y=19840;y<19920;y++){pr=pr+I15di[y];}  p249=pr/80; cout<<249<<"\t"<<p249<<endl;pr=0;
for(y=19920;y<20000;y++){pr=pr+I15di[y];}  p250=pr/80; cout<<250<<"\t"<<p250<<endl;pr=0;
for(y=20000;y<20080;y++){pr=pr+I15di[y];}  p251=pr/80; cout<<251<<"\t"<<p251<<endl;pr=0;
for(y=20080;y<20160;y++){pr=pr+I15di[y];}  p252=pr/80; cout<<252<<"\t"<<p252<<endl;pr=0;
for(y=20160;y<20240;y++){pr=pr+I15di[y];}  p253=pr/80; cout<<253<<"\t"<<p253<<endl;pr=0;
for(y=20240;y<20320;y++){pr=pr+I15di[y];}  p254=pr/80; cout<<254<<"\t"<<p254<<endl;pr=0;
for(y=20320;y<20400;y++){pr=pr+I15di[y];}  p255=pr/80; cout<<255<<"\t"<<p255<<endl;pr=0;
for(y=20400;y<20480;y++){pr=pr+I15di[y];}  p256=pr/80; cout<<256<<"\t"<<p256<<endl;pr=0;
for(y=20480;y<20560;y++){pr=pr+I15di[y];}  p257=pr/80; cout<<257<<"\t"<<p257<<endl;pr=0;
for(y=20560;y<20640;y++){pr=pr+I15di[y];}  p258=pr/80; cout<<258<<"\t"<<p258<<endl;pr=0;
for(y=20640;y<20720;y++){pr=pr+I15di[y];}  p259=pr/80; cout<<259<<"\t"<<p259<<endl;pr=0;
for(y=20720;y<20800;y++){pr=pr+I15di[y];}  p260=pr/80; cout<<260<<"\t"<<p260<<endl;pr=0;
for(y=20800;y<20880;y++){pr=pr+I15di[y];}  p261=pr/80; cout<<261<<"\t"<<p261<<endl;pr=0;
for(y=20880;y<20960;y++){pr=pr+I15di[y];}  p262=pr/80; cout<<262<<"\t"<<p262<<endl;pr=0;
for(y=20960;y<21040;y++){pr=pr+I15di[y];}  p263=pr/80; cout<<263<<"\t"<<p263<<endl;pr=0;
for(y=21040;y<21120;y++){pr=pr+I15di[y];}  p264=pr/80; cout<<264<<"\t"<<p264<<endl;pr=0;
for(y=21120;y<21200;y++){pr=pr+I15di[y];}  p265=pr/80; cout<<265<<"\t"<<p265<<endl;pr=0;
for(y=21200;y<21280;y++){pr=pr+I15di[y];}  p266=pr/80; cout<<266<<"\t"<<p266<<endl;pr=0;
for(y=21280;y<21360;y++){pr=pr+I15di[y];}  p267=pr/80; cout<<267<<"\t"<<p267<<endl;pr=0;
for(y=21360;y<21440;y++){pr=pr+I15di[y];}  p268=pr/80; cout<<268<<"\t"<<p268<<endl;pr=0;
for(y=21440;y<21520;y++){pr=pr+I15di[y];}  p269=pr/80; cout<<269<<"\t"<<p269<<endl;pr=0;
for(y=21520;y<21600;y++){pr=pr+I15di[y];}  p270=pr/80; cout<<270<<"\t"<<p270<<endl;pr=0;
for(y=21600;y<21680;y++){pr=pr+I15di[y];}  p271=pr/80; cout<<271<<"\t"<<p271<<endl;pr=0;
for(y=21680;y<21760;y++){pr=pr+I15di[y];}  p272=pr/80; cout<<272<<"\t"<<p272<<endl;pr=0;
for(y=21760;y<21840;y++){pr=pr+I15di[y];}  p273=pr/80; cout<<273<<"\t"<<p273<<endl;pr=0;
for(y=21840;y<21920;y++){pr=pr+I15di[y];}  p274=pr/80; cout<<274<<"\t"<<p274<<endl;pr=0;
for(y=21920;y<22000;y++){pr=pr+I15di[y];}  p275=pr/80; cout<<275<<"\t"<<p275<<endl;pr=0;
for(y=22000;y<22080;y++){pr=pr+I15di[y];}  p276=pr/80; cout<<276<<"\t"<<p276<<endl;pr=0;
for(y=22080;y<22160;y++){pr=pr+I15di[y];}  p277=pr/80; cout<<277<<"\t"<<p277<<endl;pr=0;
for(y=22160;y<22240;y++){pr=pr+I15di[y];}  p278=pr/80; cout<<278<<"\t"<<p278<<endl;pr=0;
for(y=22240;y<22320;y++){pr=pr+I15di[y];}  p279=pr/80; cout<<279<<"\t"<<p279<<endl;pr=0;
for(y=22320;y<22400;y++){pr=pr+I15di[y];}  p280=pr/80; cout<<280<<"\t"<<p280<<endl;pr=0;
for(y=22400;y<22480;y++){pr=pr+I15di[y];}  p281=pr/80; cout<<281<<"\t"<<p281<<endl;pr=0;
for(y=22480;y<22560;y++){pr=pr+I15di[y];}  p282=pr/80; cout<<282<<"\t"<<p282<<endl;pr=0;
for(y=22560;y<22640;y++){pr=pr+I15di[y];}  p283=pr/80; cout<<283<<"\t"<<p283<<endl;pr=0;
for(y=22640;y<22720;y++){pr=pr+I15di[y];}  p284=pr/80; cout<<284<<"\t"<<p284<<endl;pr=0;
for(y=22720;y<22800;y++){pr=pr+I15di[y];}  p285=pr/80; cout<<285<<"\t"<<p285<<endl;pr=0;
for(y=22800;y<22880;y++){pr=pr+I15di[y];}  p286=pr/80; cout<<286<<"\t"<<p286<<endl;pr=0;
for(y=22880;y<22960;y++){pr=pr+I15di[y];}  p287=pr/80; cout<<287<<"\t"<<p287<<endl;pr=0;
for(y=22960;y<23040;y++){pr=pr+I15di[y];}  p288=pr/80; cout<<288<<"\t"<<p288<<endl;pr=0;
for(y=23040;y<23120;y++){pr=pr+I15di[y];}  p289=pr/80; cout<<289<<"\t"<<p289<<endl;pr=0;
for(y=23120;y<23200;y++){pr=pr+I15di[y];}  p290=pr/80; cout<<290<<"\t"<<p290<<endl;pr=0;
for(y=23200;y<23280;y++){pr=pr+I15di[y];}  p291=pr/80; cout<<291<<"\t"<<p291<<endl;pr=0;
for(y=23280;y<23360;y++){pr=pr+I15di[y];}  p292=pr/80; cout<<292<<"\t"<<p292<<endl;pr=0;
for(y=23360;y<23440;y++){pr=pr+I15di[y];}  p293=pr/80; cout<<293<<"\t"<<p293<<endl;pr=0;
for(y=23440;y<23520;y++){pr=pr+I15di[y];}  p294=pr/80; cout<<294<<"\t"<<p294<<endl;pr=0;
for(y=23520;y<23600;y++){pr=pr+I15di[y];}  p295=pr/80; cout<<295<<"\t"<<p295<<endl;pr=0;
for(y=23600;y<23680;y++){pr=pr+I15di[y];}  p296=pr/80; cout<<296<<"\t"<<p296<<endl;pr=0;
for(y=23680;y<23760;y++){pr=pr+I15di[y];}  p297=pr/80; cout<<297<<"\t"<<p297<<endl;pr=0;
for(y=23760;y<23840;y++){pr=pr+I15di[y];}  p298=pr/80; cout<<298<<"\t"<<p298<<endl;pr=0;
for(y=23840;y<23920;y++){pr=pr+I15di[y];}  p299=pr/80; cout<<299<<"\t"<<p299<<endl;pr=0;
for(y=23920;y<24000;y++){pr=pr+I15di[y];}  p300=pr/80; cout<<300<<"\t"<<p300<<endl;pr=0;
for(y=24000;y<24080;y++){pr=pr+I15di[y];}  p301=pr/80; cout<<301<<"\t"<<p301<<endl;pr=0;
for(y=24080;y<24160;y++){pr=pr+I15di[y];}  p302=pr/80; cout<<302<<"\t"<<p302<<endl;pr=0;
for(y=24160;y<24240;y++){pr=pr+I15di[y];}  p303=pr/80; cout<<303<<"\t"<<p303<<endl;pr=0;
for(y=24240;y<24320;y++){pr=pr+I15di[y];}  p304=pr/80; cout<<304<<"\t"<<p304<<endl;pr=0;
for(y=24320;y<24400;y++){pr=pr+I15di[y];}  p305=pr/80; cout<<305<<"\t"<<p305<<endl;pr=0;
for(y=24400;y<24480;y++){pr=pr+I15di[y];}  p306=pr/80; cout<<306<<"\t"<<p306<<endl;pr=0;
for(y=24480;y<24560;y++){pr=pr+I15di[y];}  p307=pr/80; cout<<307<<"\t"<<p307<<endl;pr=0;
for(y=24560;y<24640;y++){pr=pr+I15di[y];}  p308=pr/80; cout<<308<<"\t"<<p308<<endl;pr=0;
for(y=24640;y<24720;y++){pr=pr+I15di[y];}  p309=pr/80; cout<<309<<"\t"<<p309<<endl;pr=0;
for(y=24720;y<24800;y++){pr=pr+I15di[y];}  p310=pr/80; cout<<310<<"\t"<<p310<<endl;pr=0;
for(y=24800;y<24880;y++){pr=pr+I15di[y];}  p311=pr/80; cout<<311<<"\t"<<p311<<endl;pr=0;
for(y=24880;y<24960;y++){pr=pr+I15di[y];}  p312=pr/80; cout<<312<<"\t"<<p312<<endl;pr=0;
for(y=24960;y<25040;y++){pr=pr+I15di[y];}  p313=pr/80; cout<<313<<"\t"<<p313<<endl;pr=0;
for(y=25040;y<25120;y++){pr=pr+I15di[y];}  p314=pr/80; cout<<314<<"\t"<<p314<<endl;pr=0;
for(y=25120;y<25200;y++){pr=pr+I15di[y];}  p315=pr/80; cout<<315<<"\t"<<p315<<endl;pr=0;
for(y=25200;y<25280;y++){pr=pr+I15di[y];}  p316=pr/80; cout<<316<<"\t"<<p316<<endl;pr=0;
for(y=25280;y<25360;y++){pr=pr+I15di[y];}  p317=pr/80; cout<<317<<"\t"<<p317<<endl;pr=0;
for(y=25360;y<25440;y++){pr=pr+I15di[y];}  p318=pr/80; cout<<318<<"\t"<<p318<<endl;pr=0;
for(y=25440;y<25520;y++){pr=pr+I15di[y];}  p319=pr/80; cout<<319<<"\t"<<p319<<endl;pr=0;
for(y=25520;y<25600;y++){pr=pr+I15di[y];}  p320=pr/80; cout<<320<<"\t"<<p320<<endl;pr=0;
for(y=25600;y<25680;y++){pr=pr+I15di[y];}  p321=pr/80; cout<<321<<"\t"<<p321<<endl;pr=0;
for(y=25680;y<25760;y++){pr=pr+I15di[y];}  p322=pr/80; cout<<322<<"\t"<<p322<<endl;pr=0;
for(y=25760;y<25840;y++){pr=pr+I15di[y];}  p323=pr/80; cout<<323<<"\t"<<p323<<endl;pr=0;
for(y=25840;y<25920;y++){pr=pr+I15di[y];}  p324=pr/80; cout<<324<<"\t"<<p324<<endl;pr=0;
for(y=25920;y<26000;y++){pr=pr+I15di[y];}  p325=pr/80; cout<<325<<"\t"<<p325<<endl;pr=0;
for(y=26000;y<26080;y++){pr=pr+I15di[y];}  p326=pr/80; cout<<326<<"\t"<<p326<<endl;pr=0;
for(y=26080;y<26160;y++){pr=pr+I15di[y];}  p327=pr/80; cout<<327<<"\t"<<p327<<endl;pr=0;
for(y=26160;y<26240;y++){pr=pr+I15di[y];}  p328=pr/80; cout<<328<<"\t"<<p328<<endl;pr=0;
for(y=26240;y<26320;y++){pr=pr+I15di[y];}  p329=pr/80; cout<<329<<"\t"<<p329<<endl;pr=0;
for(y=26320;y<26400;y++){pr=pr+I15di[y];}  p330=pr/80; cout<<330<<"\t"<<p330<<endl;pr=0;
for(y=26400;y<26480;y++){pr=pr+I15di[y];}  p331=pr/80; cout<<331<<"\t"<<p331<<endl;pr=0;
for(y=26480;y<26560;y++){pr=pr+I15di[y];}  p332=pr/80; cout<<332<<"\t"<<p332<<endl;pr=0;
for(y=26560;y<26640;y++){pr=pr+I15di[y];}  p333=pr/80; cout<<333<<"\t"<<p333<<endl;pr=0;
for(y=26640;y<26720;y++){pr=pr+I15di[y];}  p334=pr/80; cout<<334<<"\t"<<p334<<endl;pr=0;
for(y=26720;y<26800;y++){pr=pr+I15di[y];}  p335=pr/80; cout<<335<<"\t"<<p335<<endl;pr=0;
for(y=26800;y<26880;y++){pr=pr+I15di[y];}  p336=pr/80; cout<<336<<"\t"<<p336<<endl;pr=0;
for(y=26880;y<26960;y++){pr=pr+I15di[y];}  p337=pr/80; cout<<337<<"\t"<<p337<<endl;pr=0;
for(y=26960;y<27040;y++){pr=pr+I15di[y];}  p338=pr/80; cout<<338<<"\t"<<p338<<endl;pr=0;
for(y=27040;y<27120;y++){pr=pr+I15di[y];}  p339=pr/80; cout<<339<<"\t"<<p339<<endl;pr=0;
for(y=27120;y<27200;y++){pr=pr+I15di[y];}  p340=pr/80; cout<<340<<"\t"<<p340<<endl;pr=0;
for(y=27200;y<27280;y++){pr=pr+I15di[y];}  p341=pr/80; cout<<341<<"\t"<<p341<<endl;pr=0;
for(y=27280;y<27360;y++){pr=pr+I15di[y];}  p342=pr/80; cout<<342<<"\t"<<p342<<endl;pr=0;
for(y=27360;y<27440;y++){pr=pr+I15di[y];}  p343=pr/80; cout<<343<<"\t"<<p343<<endl;pr=0;
for(y=27440;y<27520;y++){pr=pr+I15di[y];}  p344=pr/80; cout<<344<<"\t"<<p344<<endl;pr=0;
for(y=27520;y<27600;y++){pr=pr+I15di[y];}  p345=pr/80; cout<<345<<"\t"<<p345<<endl;pr=0;
for(y=27600;y<27680;y++){pr=pr+I15di[y];}  p346=pr/80; cout<<346<<"\t"<<p346<<endl;pr=0;
for(y=27680;y<27760;y++){pr=pr+I15di[y];}  p347=pr/80; cout<<347<<"\t"<<p347<<endl;pr=0;
for(y=27760;y<27840;y++){pr=pr+I15di[y];}  p348=pr/80; cout<<348<<"\t"<<p348<<endl;pr=0;
for(y=27840;y<27920;y++){pr=pr+I15di[y];}  p349=pr/80; cout<<349<<"\t"<<p349<<endl;pr=0;
for(y=27920;y<28000;y++){pr=pr+I15di[y];}  p350=pr/80; cout<<350<<"\t"<<p350<<endl;pr=0;
for(y=28000;y<28080;y++){pr=pr+I15di[y];}  p351=pr/80; cout<<351<<"\t"<<p351<<endl;pr=0;
for(y=28080;y<28160;y++){pr=pr+I15di[y];}  p352=pr/80; cout<<352<<"\t"<<p352<<endl;pr=0;
for(y=28160;y<28240;y++){pr=pr+I15di[y];}  p353=pr/80; cout<<353<<"\t"<<p353<<endl;pr=0;
for(y=28240;y<28320;y++){pr=pr+I15di[y];}  p354=pr/80; cout<<354<<"\t"<<p354<<endl;pr=0;
for(y=28320;y<28400;y++){pr=pr+I15di[y];}  p355=pr/80; cout<<355<<"\t"<<p355<<endl;pr=0;
for(y=28400;y<28480;y++){pr=pr+I15di[y];}  p356=pr/80; cout<<356<<"\t"<<p356<<endl;pr=0;
for(y=28480;y<28560;y++){pr=pr+I15di[y];}  p357=pr/80; cout<<357<<"\t"<<p357<<endl;pr=0;
for(y=28560;y<28640;y++){pr=pr+I15di[y];}  p358=pr/64; cout<<358<<"\t"<<p358<<endl;pr=0;



}
