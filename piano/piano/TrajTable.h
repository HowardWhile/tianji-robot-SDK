#ifndef TRAJTABLE_H
#define TRAJTABLE_H
#include "FXCommon.h"

typedef struct
{
    char name[128];
    int num;
} PianoTableItem;

//typedef struct {
//    double* points;   /* 指向轨迹点数组的指针 */
//    int*    length;   /* 轨迹点长度 */
//} TrackPoint;

typedef struct
{
    double*       points;   /* 指向轨迹点数组的指针 */
    int*          length;   /* 轨迹点长度 */
    int           distance; /* 两琴键距离 abs(key1-key2)，如 "2-3" → 1 */
} TrackPoint;

extern double left_set_halfbeat[150][2000];
extern int    left_set_half_num[150];
extern double left_set_onebeat[150][2000];
extern int    left_set_one_num[150];
extern double left_set_twobeat[150][2000];
extern int    left_set_two_num[150];
extern double left_set_oneandhalfbeat[150][2000];
extern int    left_set_oneandhalf_num[150];

extern double right_set_halfbeat[170][2000];
extern int    right_set_half_num[170];
extern double right_set_onebeat[170][2000];
extern int    right_set_one_num[170];
extern double right_set_twobeat[170][2000];
extern int    right_set_two_num[170];
extern double right_set_oneandhalfbeat[170][2000];
extern int    right_set_oneandhalf_num[170];


static const PianoTableItem Left_PianoTable[] =
{
    {"1-1", 0},
    {"1-2", 1},
    {"1-3", 2},
    {"1-4", 3},
    {"1-5", 4},
    {"1-6", 5},
    {"1-7", 6},
    {"1-8", 7},
    {"1-9", 8},
    {"1-10", 9},
    {"1-11", 10},
    {"1-12", 11},
    {"2-1", 12},
    {"2-2", 13},
    {"2-3", 14},
    {"2-4", 15},
    {"2-5", 16},
    {"2-6", 17},
    {"2-7", 18},
    {"2-8", 19},
    {"2-9", 20},
    {"2-10", 21},
    {"2-11", 22},
    {"2-12", 23},
    {"3-1", 24},
    {"3-2", 25},
    {"3-3", 26},
    {"3-4", 27},
    {"3-5", 28},
    {"3-6", 29},
    {"3-7", 30},
    {"3-8", 31},
    {"3-9", 32},
    {"3-10", 33},
    {"3-11", 34},
    {"3-12", 35},
    {"4-1", 36},
    {"4-2", 37},
    {"4-3", 38},
    {"4-4", 39},
    {"4-5", 40},
    {"4-6", 41},
    {"4-7", 42},
    {"4-8", 43},
    {"4-9", 44},
    {"4-10", 45},
    {"4-11", 46},
    {"4-12", 47},
    {"5-1", 48},
    {"5-2", 49},
    {"5-3", 50},
    {"5-4", 51},
    {"5-5", 52},
    {"5-6", 53},
    {"5-7", 54},
    {"5-8", 55},
    {"5-9", 56},
    {"5-10", 57},
    {"5-11", 58},
    {"5-12", 59},
    {"6-1", 60},
    {"6-2", 61},
    {"6-3", 62},
    {"6-4", 63},
    {"6-5", 64},
    {"6-6", 65},
    {"6-7", 66},
    {"6-8", 67},
    {"6-9", 68},
    {"6-10", 69},
    {"6-11", 70},
    {"6-12", 71},
    {"7-1", 72},
    {"7-2", 73},
    {"7-3", 74},
    {"7-4", 75},
    {"7-5", 76},
    {"7-6", 77},
    {"7-7", 78},
    {"7-8", 79},
    {"7-9", 80},
    {"7-10", 81},
    {"7-11", 82},
    {"7-12", 83},
    {"8-1", 84},
    {"8-2", 85},
    {"8-3", 86},
    {"8-4", 87},
    {"8-5", 88},
    {"8-6", 89},
    {"8-7", 90},
    {"8-8", 91},
    {"8-9", 92},
    {"8-10", 93},
    {"8-11", 94},
    {"8-12", 95},
    {"9-1", 96},
    {"9-2", 97},
    {"9-3", 98},
    {"9-4", 99},
    {"9-5", 100},
    {"9-6", 101},
    {"9-7", 102},
    {"9-8", 103},
    {"9-9", 104},
    {"9-10", 105},
    {"9-11", 106},
    {"9-12", 107},
    {"10-1", 108},
    {"10-2", 109},
    {"10-3", 110},
    {"10-4", 111},
    {"10-5", 112},
    {"10-6", 113},
    {"10-7", 114},
    {"10-8", 115},
    {"10-9", 116},
    {"10-10", 117},
    {"10-11", 118},
    {"10-12", 119},
    {"11-1", 120},
    {"11-2", 121},
    {"11-3", 122},
    {"11-4", 123},
    {"11-5", 124},
    {"11-6", 125},
    {"11-7", 126},
    {"11-8", 127},
    {"11-9", 128},
    {"11-10", 129},
    {"11-11", 130},
    {"11-12", 131},
    {"12-1", 132},
    {"12-2", 133},
    {"12-3", 134},
    {"12-4", 135},
    {"12-5", 136},
    {"12-6", 137},
    {"12-7", 138},
    {"12-8", 139},
    {"12-9", 140},
    {"12-10", 141},
    {"12-11", 142},
    {"12-12", 143},
 };

static const PianoTableItem Right_PianoTable[] =
{
    {"1-1", 0},
    {"1-2", 1},
    {"1-3", 2},
    {"1-4", 3},
    {"1-5", 4},
    {"1-6", 5},
    {"1-7", 6},
    {"1-8", 7},
    {"1-9", 8},
    {"1-10", 9},
    {"1-11", 10},
    {"1-12", 11},
    {"1-13", 12},
    {"2-1", 13},
    {"2-2", 14},
    {"2-3", 15},
    {"2-4", 16},
    {"2-5", 17},
    {"2-6", 18},
    {"2-7", 19},
    {"2-8", 20},
    {"2-9", 21},
    {"2-10", 22},
    {"2-11", 23},
    {"2-12", 24},
    {"2-13", 25},
    {"3-1", 26},
    {"3-2", 27},
    {"3-3", 28},
    {"3-4", 29},
    {"3-5", 30},
    {"3-6", 31},
    {"3-7", 32},
    {"3-8", 33},
    {"3-9", 34},
    {"3-10", 35},
    {"3-11", 36},
    {"3-12", 37},
    {"3-13", 38},
    {"4-1", 39},
    {"4-2", 40},
    {"4-3", 41},
    {"4-4", 42},
    {"4-5", 43},
    {"4-6", 44},
    {"4-7", 45},
    {"4-8", 46},
    {"4-9", 47},
    {"4-10", 48},
    {"4-11", 49},
    {"4-12", 50},
    {"4-13", 51},
    {"5-1", 52},
    {"5-2", 53},
    {"5-3", 54},
    {"5-4", 55},
    {"5-5", 56},
    {"5-6", 57},
    {"5-7", 58},
    {"5-8", 59},
    {"5-9", 60},
    {"5-10", 61},
    {"5-11", 62},
    {"5-12", 63},
    {"5-13", 64},
    {"6-1", 65},
    {"6-2", 66},
    {"6-3", 67},
    {"6-4", 68},
    {"6-5", 69},
    {"6-6", 70},
    {"6-7", 71},
    {"6-8", 72},
    {"6-9", 73},
    {"6-10", 74},
    {"6-11", 75},
    {"6-12", 76},
    {"6-13", 77},
    {"7-1", 78},
    {"7-2", 79},
    {"7-3", 80},
    {"7-4", 81},
    {"7-5", 82},
    {"7-6", 83},
    {"7-7", 84},
    {"7-8", 85},
    {"7-9", 86},
    {"7-10", 87},
    {"7-11", 88},
    {"7-12", 89},
    {"7-13", 90},
    {"8-1", 91},
    {"8-2", 92},
    {"8-3", 93},
    {"8-4", 94},
    {"8-5", 95},
    {"8-6", 96},
    {"8-7", 97},
    {"8-8", 98},
    {"8-9", 99},
    {"8-10", 100},
    {"8-11", 101},
    {"8-12", 102},
    {"8-13", 103},
    {"9-1", 104},
    {"9-2", 105},
    {"9-3", 106},
    {"9-4", 107},
    {"9-5", 108},
    {"9-6", 109},
    {"9-7", 110},
    {"9-8", 111},
    {"9-9", 112},
    {"9-10", 113},
    {"9-11", 114},
    {"9-12", 115},
    {"9-13", 116},
    {"10-1", 117},
    {"10-2", 118},
    {"10-3", 119},
    {"10-4", 120},
    {"10-5", 121},
    {"10-6", 122},
    {"10-7", 123},
    {"10-8", 124},
    {"10-9", 125},
    {"10-10", 126},
    {"10-11", 127},
    {"10-12", 128},
    {"10-13", 129},
    {"11-1", 130},
    {"11-2", 131},
    {"11-3", 132},
    {"11-4", 133},
    {"11-5", 134},
    {"11-6", 135},
    {"11-7", 136},
    {"11-8", 137},
    {"11-9", 138},
    {"11-10", 139},
    {"11-11", 140},
    {"11-12", 141},
    {"11-13", 142},
    {"12-1", 143},
    {"12-2", 144},
    {"12-3", 145},
    {"12-4", 146},
    {"12-5", 147},
    {"12-6", 148},
    {"12-7", 149},
    {"12-8", 150},
    {"12-9", 151},
    {"12-10", 152},
    {"12-11", 153},
    {"12-12", 154},
    {"12-13", 155},
    {"13-1", 156},
    {"13-2", 157},
    {"13-3", 158},
    {"13-4", 159},
    {"13-5", 160},
    {"13-6", 161},
    {"13-7", 162},
    {"13-8", 163},
    {"13-9", 164},
    {"13-10", 165},
    {"13-11", 166},
    {"13-12", 167},
    {"13-13", 168},
};

//欢乐颂
static const TrackPoint robot_track_arry[77] = {
    /* [  0] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
    { right_set_onebeat[28], &right_set_one_num[28], 0 },
    /* [  0] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
    { right_set_onebeat[28], &right_set_one_num[28], 0 },
    /* [  1] 3-4 (dur=1.00s, idx= 29, dist=1) -> right_set_onebeat */
    { right_set_onebeat[29], &right_set_one_num[29], 1 },
    /* [  2] 4-5 (dur=1.00s, idx= 43, dist=1) -> right_set_onebeat */
    { right_set_onebeat[43], &right_set_one_num[43], 1 },
    /* [  3] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
    { right_set_onebeat[56], &right_set_one_num[56], 0 },
    /* [  4] 5-4 (dur=1.00s, idx= 55, dist=1) -> right_set_onebeat */
    { right_set_onebeat[55], &right_set_one_num[55], 1 },
    /* [  5] 4-3 (dur=1.00s, idx= 41, dist=1) -> right_set_onebeat */
    { right_set_onebeat[41], &right_set_one_num[41], 1 },
    /* [  6] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
    { right_set_onebeat[27], &right_set_one_num[27], 1 },
    /* [  7] 2-1 (dur=1.00s, idx= 13, dist=1) -> right_set_onebeat */
    { right_set_onebeat[13], &right_set_one_num[13], 1 },
    /* [  8] 1-1 (dur=1.00s, idx=  0, dist=0) -> right_set_onebeat */
    { right_set_onebeat[0], &right_set_one_num[0], 0 },
    /* [  9] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 10] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [ 11] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
    { right_set_onebeat[28], &right_set_one_num[28], 0 },
    /* [ 12] 3-2 (dur=1.50s, idx= 27, dist=1) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[27], &right_set_oneandhalf_num[27], 1 },
    /* [ 13] 2-2 (dur=0.50s, idx= 14, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[14], &right_set_half_num[14], 0 },
    /* [ 14] 2-3 (dur=2.00s, idx= 15, dist=1) -> right_set_twobeat */
    { right_set_twobeat[15], &right_set_two_num[15], 1 },
    /* [ 15] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
    { right_set_onebeat[28], &right_set_one_num[28], 0 },
    /* [ 16] 3-4 (dur=1.00s, idx= 29, dist=1) -> right_set_onebeat */
    { right_set_onebeat[29], &right_set_one_num[29], 1 },
    /* [ 17] 4-5 (dur=1.00s, idx= 43, dist=1) -> right_set_onebeat */
    { right_set_onebeat[43], &right_set_one_num[43], 1 },
    /* [ 18] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
    { right_set_onebeat[56], &right_set_one_num[56], 0 },
    /* [ 19] 5-4 (dur=1.00s, idx= 55, dist=1) -> right_set_onebeat */
    { right_set_onebeat[55], &right_set_one_num[55], 1 },
    /* [ 20] 4-3 (dur=1.00s, idx= 41, dist=1) -> right_set_onebeat */
    { right_set_onebeat[41], &right_set_one_num[41], 1 },
    /* [ 21] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
    { right_set_onebeat[27], &right_set_one_num[27], 1 },
    /* [ 22] 2-1 (dur=1.00s, idx= 13, dist=1) -> right_set_onebeat */
    { right_set_onebeat[13], &right_set_one_num[13], 1 },
    /* [ 23] 1-1 (dur=1.00s, idx=  0, dist=0) -> right_set_onebeat */
    { right_set_onebeat[0], &right_set_one_num[0], 0 },
    /* [ 24] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 25] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [ 26] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
    { right_set_onebeat[27], &right_set_one_num[27], 1 },
    /* [ 27] 2-1 (dur=1.50s, idx= 13, dist=1) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[13], &right_set_oneandhalf_num[13], 1 },
    /* [ 28] 1-1 (dur=0.50s, idx=  0, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[0], &right_set_half_num[0], 0 },
    /* [ 29] 1-2 (dur=2.00s, idx=  1, dist=1) -> right_set_twobeat */
    { right_set_twobeat[1], &right_set_two_num[1], 1 },
    /* [ 30] 2-2 (dur=1.00s, idx= 14, dist=0) -> right_set_onebeat */
    { right_set_onebeat[14], &right_set_one_num[14], 0 },
    /* [ 31] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [ 32] 3-1 (dur=1.00s, idx= 26, dist=2) -> right_set_onebeat */
    { right_set_onebeat[26], &right_set_one_num[26], 2 },
    /* [ 33] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 34] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [ 35] 3-4 (dur=0.50s, idx= 29, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[29], &right_set_half_num[29], 1 },
    /* [ 36] 4-3 (dur=0.50s, idx= 41, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[41], &right_set_half_num[41], 1 },
    /* [ 37] 3-1 (dur=1.00s, idx= 26, dist=2) -> right_set_onebeat */
    { right_set_onebeat[26], &right_set_one_num[26], 2 },
    /* [ 38] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 39] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [ 40] 3-4 (dur=0.50s, idx= 29, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[29], &right_set_half_num[29], 1 },
    /* [ 41] 4-3 (dur=0.50s, idx= 41, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[41], &right_set_half_num[41], 1 },
    /* [ 42] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
    { right_set_onebeat[27], &right_set_one_num[27], 1 },
    /* [ 43] 2-1 (dur=1.00s, idx= 13, dist=1) -> right_set_onebeat */
    { right_set_onebeat[13], &right_set_one_num[13], 1 },
    /* [ 44] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 45] 2-5 (dur=1.00s, idx= 17, dist=3) -> right_set_onebeat */
    { right_set_twobeat[17], &right_set_two_num[17], 3 },
    /* [ 46] 5-3 (dur=2.00s, idx= 54, dist=2) -> right_set_twobeat */
    { right_set_twobeat[54], &right_set_two_num[54], 2 },
    /* [ 47] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
    { right_set_onebeat[28], &right_set_one_num[28], 0 },
    /* [ 48] 3-4 (dur=1.00s, idx= 29, dist=1) -> right_set_onebeat */
    { right_set_onebeat[29], &right_set_one_num[29], 1 },
    /* [ 49] 4-5 (dur=1.00s, idx= 43, dist=1) -> right_set_onebeat */
    { right_set_onebeat[43], &right_set_one_num[43], 1 },
    /* [ 50] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
    { right_set_onebeat[56], &right_set_one_num[56], 0 },
    /* [ 51] 5-4 (dur=1.00s, idx= 55, dist=1) -> right_set_onebeat */
    { right_set_onebeat[55], &right_set_one_num[55], 1 },
    /* [ 52] 4-3 (dur=1.00s, idx= 41, dist=1) -> right_set_onebeat */
    { right_set_onebeat[41], &right_set_one_num[41], 1 },
    /* [ 53] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
    { right_set_onebeat[27], &right_set_one_num[27], 1 },
    /* [ 54] 2-1 (dur=1.00s, idx= 13, dist=1) -> right_set_onebeat */
    { right_set_onebeat[13], &right_set_one_num[13], 1 },
    /* [ 55] 1-1 (dur=1.00s, idx=  0, dist=0) -> right_set_onebeat */
    { right_set_onebeat[0], &right_set_one_num[0], 0 },
    /* [ 56] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 57] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [ 58] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
    { right_set_onebeat[28], &right_set_one_num[28], 0 },
    /* [ 59] 3-2 (dur=1.50s, idx= 27, dist=1) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[27], &right_set_oneandhalf_num[27], 1 },
    /* [ 60] 2-2 (dur=0.50s, idx= 14, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[14], &right_set_half_num[14], 0 },
    /* [ 61] 2-3 (dur=2.00s, idx= 15, dist=1) -> right_set_twobeat */
    { right_set_twobeat[15], &right_set_two_num[15], 1 },
    /* [ 62] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
    { right_set_onebeat[28], &right_set_one_num[28], 0 },
    /* [ 63] 3-4 (dur=1.00s, idx= 29, dist=1) -> right_set_onebeat */
    { right_set_onebeat[29], &right_set_one_num[29], 1 },
    /* [ 64] 4-5 (dur=1.00s, idx= 43, dist=1) -> right_set_onebeat */
    { right_set_onebeat[43], &right_set_one_num[43], 1 },
    /* [ 65] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
    { right_set_onebeat[56], &right_set_one_num[56], 0 },
    /* [ 66] 5-4 (dur=1.00s, idx= 55, dist=1) -> right_set_onebeat */
    { right_set_onebeat[55], &right_set_one_num[55], 1 },
    /* [ 67] 4-3 (dur=1.00s, idx= 41, dist=1) -> right_set_onebeat */
    { right_set_onebeat[41], &right_set_one_num[41], 1 },
    /* [ 68] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
    { right_set_onebeat[27], &right_set_one_num[27], 1 },
    /* [ 69] 2-1 (dur=1.00s, idx= 13, dist=1) -> right_set_onebeat */
    { right_set_onebeat[13], &right_set_one_num[13], 1 },
    /* [ 70] 1-1 (dur=1.00s, idx=  0, dist=0) -> right_set_onebeat */
    { right_set_onebeat[0], &right_set_one_num[0], 0 },
    /* [ 71] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 72] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [ 73] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
    { right_set_onebeat[27], &right_set_one_num[27], 1 },
    /* [ 74] 2-1 (dur=1.50s, idx= 13, dist=1) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[13], &right_set_oneandhalf_num[13], 1 },
    /* [ 75] 1-1 (dur=0.50s, idx=  0, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[0], &right_set_half_num[0], 0 }
};

//友谊
static const TrackPoint robot_track_arry2[58] = {
    /* [first] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
    { right_set_onebeat[56], &right_set_one_num[56], 0 },
    /* [  0] 5-1 (dur=1.00s, idx= 52, dist=4) -> right_set_onebeat */
    { right_set_onebeat[52], &right_set_one_num[52], 4 },
    /* [  1] 1-1 (dur=1.50s, idx=  0, dist=0) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[0], &right_set_oneandhalf_num[0], 0 },
    /* [  2] 1-1 (dur=0.50s, idx=  0, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[0], &right_set_half_num[0], 0 },
    /* [  3] 1-3 (dur=1.00s, idx=  2, dist=2) -> right_set_onebeat */
    { right_set_onebeat[2], &right_set_one_num[2], 2 },
    /* [  4] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
    { right_set_onebeat[27], &right_set_one_num[27], 1 },
    /* [  5] 2-1 (dur=1.50s, idx= 13, dist=1) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[13], &right_set_oneandhalf_num[13], 1 },
    /* [  6] 1-2 (dur=0.50s, idx=  1, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[1], &right_set_half_num[1], 1 },
    /* [  7] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [  8] 3-1 (dur=1.00s, idx= 26, dist=2) -> right_set_onebeat */
    { right_set_onebeat[26], &right_set_one_num[26], 2 },
    /* [  9] 1-1 (dur=1.50s, idx=  0, dist=0) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[0], &right_set_oneandhalf_num[0], 0 },
    /* [ 10] 1-3 (dur=0.50s, idx=  2, dist=2) -> right_set_halfbeat */
    { right_set_halfbeat[2], &right_set_half_num[2], 2 },
    /* [ 11] 3-5 (dur=1.00s, idx= 30, dist=2) -> right_set_onebeat */
    { right_set_onebeat[30], &right_set_one_num[30], 2 },
    /* [ 12] 5-6 (dur=1.00s, idx= 57, dist=1) -> right_set_onebeat */
    { right_set_onebeat[57], &right_set_one_num[57], 1 },
    /* [ 13] 6-6 (dur=2.00s, idx= 70, dist=0) -> right_set_twobeat */
    { right_set_twobeat[70], &right_set_two_num[70], 0 },
    /* [ 14] 6-5 (dur=1.00s, idx= 69, dist=1) -> right_set_onebeat */
    { right_set_onebeat[69], &right_set_one_num[69], 1 },
    /* [ 15] 5-3 (dur=1.50s, idx= 54, dist=2) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[54], &right_set_oneandhalf_num[54], 2 },
    /* [ 16] 3-3 (dur=0.50s, idx= 28, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[28], &right_set_half_num[28], 0 },
    /* [ 17] 3-1 (dur=1.00s, idx= 26, dist=2) -> right_set_onebeat */
    { right_set_onebeat[26], &right_set_one_num[26], 2 },
    /* [ 18] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 19] 2-1 (dur=1.50s, idx= 13, dist=1) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[13], &right_set_oneandhalf_num[13], 1 },
    /* [ 20] 1-2 (dur=0.50s, idx=  1, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[1], &right_set_half_num[1], 1 },
    /* [ 21] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [ 22] 3-2 (dur=0.50s, idx= 27, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[27], &right_set_half_num[27], 1 },
    /* [ 23] 2-1 (dur=0.50s, idx= 13, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[13], &right_set_half_num[13], 1 },
    /* [ 24] 1-6 (dur=1.50s, idx=  5, dist=5) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[5], &right_set_oneandhalf_num[5], 5},
    /* [ 25] 6-6 (dur=0.50s, idx= 70, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[70], &right_set_half_num[70], 0 },
    /* [ 26] 6-5 (dur=1.00s, idx= 69, dist=1) -> right_set_onebeat */
    { right_set_onebeat[69], &right_set_one_num[69], 1 },
    /* [ 27] 5-1 (dur=1.00s, idx= 52, dist=4) -> right_set_onebeat */
    { right_set_onebeat[52], &right_set_one_num[52], 4 },
    /* [ 28] 1-6 (dur=2.00s, idx=  5, dist=5) -> right_set_twobeat */
    { right_set_twobeat[5], &right_set_two_num[5], 5 },
    /* [ 29] 6-5 (dur=1.00s, idx= 69, dist=1) -> right_set_onebeat */
    { right_set_onebeat[69], &right_set_one_num[69], 1 },
    /* [ 30] 5-3 (dur=1.50s, idx= 54, dist=2) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[54], &right_set_oneandhalf_num[54], 2 },
    /* [ 31] 3-3 (dur=0.50s, idx= 28, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[28], &right_set_half_num[28], 0 },
    /* [ 32] 3-1 (dur=1.00s, idx= 26, dist=2) -> right_set_onebeat */
    { right_set_onebeat[26], &right_set_one_num[26], 2 },
    /* [ 33] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 34] 2-1 (dur=1.50s, idx= 13, dist=1) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[13], &right_set_oneandhalf_num[13], 1 },
    /* [ 35] 1-2 (dur=0.50s, idx=  1, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[1], &right_set_half_num[1], 1 },
    /* [ 36] 2-6 (dur=1.00s, idx= 18, dist=4) -> right_set_onebeat */
    { right_set_onebeat[18], &right_set_one_num[18], 4 },
    /* [ 37] 6-5 (dur=1.00s, idx= 69, dist=1) -> right_set_onebeat */
    { right_set_onebeat[69], &right_set_one_num[69], 1 },
    /* [ 38] 5-3 (dur=1.50s, idx= 54, dist=2) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[54], &right_set_oneandhalf_num[54], 2 },
    /* [ 39] 3-3 (dur=0.50s, idx= 28, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[28], &right_set_half_num[28], 0 },
    /* [ 40] 3-5 (dur=1.00s, idx= 30, dist=2) -> right_set_onebeat */
    { right_set_onebeat[30], &right_set_one_num[30], 2 },
    /* [ 41] 5-6 (dur=1.00s, idx= 57, dist=1) -> right_set_onebeat */
    { right_set_onebeat[57], &right_set_one_num[57], 1 },
    /* [ 42] 6-1 (dur=2.00s, idx= 65, dist=5) -> right_set_twobeat */
    { right_set_twobeat[65], &right_set_two_num[65], 5 },
    /* [ 43] 1-5 (dur=1.00s, idx=  4, dist=4) -> right_set_onebeat */
    { right_set_onebeat[4], &right_set_one_num[4], 4 },
    /* [ 44] 5-3 (dur=1.50s, idx= 54, dist=2) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[54], &right_set_oneandhalf_num[54], 2 },
    /* [ 45] 3-3 (dur=0.50s, idx= 28, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[28], &right_set_half_num[28], 0 },
    /* [ 46] 3-1 (dur=1.00s, idx= 26, dist=2) -> right_set_onebeat */
    { right_set_onebeat[26], &right_set_one_num[26], 2 },
    /* [ 47] 1-2 (dur=1.00s, idx=  1, dist=1) -> right_set_onebeat */
    { right_set_onebeat[1], &right_set_one_num[1], 1 },
    /* [ 48] 2-1 (dur=1.50s, idx= 13, dist=1) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[13], &right_set_oneandhalf_num[13], 1 },
    /* [ 49] 1-2 (dur=0.50s, idx=  1, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[1], &right_set_half_num[1], 1 },
    /* [ 50] 2-3 (dur=1.00s, idx= 15, dist=1) -> right_set_onebeat */
    { right_set_onebeat[15], &right_set_one_num[15], 1 },
    /* [ 51] 3-2 (dur=0.50s, idx= 27, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[27], &right_set_half_num[27], 1 },
    /* [ 52] 2-1 (dur=0.50s, idx= 13, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[13], &right_set_half_num[13], 1 },
    /* [ 53] 1-6 (dur=1.50s, idx=  5, dist=5) -> right_set_oneandhalfbeat */
    { right_set_oneandhalfbeat[5], &right_set_oneandhalf_num[5], 5 },
    /* [ 54] 6-6 (dur=0.50s, idx= 70, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[70], &right_set_half_num[70], 0 },
    /* [ 55] 6-5 (dur=1.00s, idx= 69, dist=1) -> right_set_onebeat */
    { right_set_onebeat[69], &right_set_one_num[69], 1 },
    /* [ 56] 5-1 (dur=1.00s, idx= 52, dist=4) -> right_set_onebeat */
    { right_set_onebeat[52], &right_set_one_num[52], 4 }
};

////小星星
//static const TrackPoint robot_track_arry3[42] = {
//    /* [first] 1-1 (dur=1.00s, idx=  0, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[0], &right_set_one_num[0], 0 },
//    /* [  0] 1-1 (dur=1.00s, idx=  0, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[0], &right_set_one_num[0], 0 },
//    /* [  1] 1-5 (dur=1.00s, idx=  4, dist=4) -> right_set_onebeat */
//    { right_set_onebeat[4], &right_set_one_num[4], 4 },
//    /* [  2] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[56], &right_set_one_num[56], 0 },
//    /* [  3] 5-6 (dur=1.00s, idx= 57, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[57], &right_set_one_num[57], 1 },
//    /* [  4] 6-6 (dur=1.00s, idx= 70, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[70], &right_set_one_num[70], 0 },
//    /* [  5] 6-5 (dur=1.00s, idx= 69, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[69], &right_set_one_num[69], 1 },
//    /* [  6] 5-4 (dur=2.00s, idx= 55, dist=1) -> right_set_twobeat */
//    { right_set_twobeat[55], &right_set_two_num[55], 1 },
//    /* [  7] 4-4 (dur=1.00s, idx= 42, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[42], &right_set_one_num[42], 0 },
//    /* [  8] 4-3 (dur=1.00s, idx= 41, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[41], &right_set_one_num[41], 1 },
//    /* [  9] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[28], &right_set_one_num[28], 0 },
//    /* [ 10] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[27], &right_set_one_num[27], 1 },
//    /* [ 11] 2-2 (dur=1.00s, idx= 14, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[14], &right_set_one_num[14], 0 },
//    /* [ 12] 2-1 (dur=1.00s, idx= 13, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[13], &right_set_one_num[13], 1 },
//    /* [ 13] 1-5 (dur=2.00s, idx=  4, dist=4) -> right_set_twobeat */
//    { right_set_twobeat[4], &right_set_two_num[4], 4 },
//    /* [ 14] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[56], &right_set_one_num[56], 0 },
//    /* [ 15] 5-4 (dur=1.00s, idx= 55, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[55], &right_set_one_num[55], 1 },
//    /* [ 16] 4-4 (dur=1.00s, idx= 42, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[42], &right_set_one_num[42], 0 },
//    /* [ 17] 4-3 (dur=1.00s, idx= 41, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[41], &right_set_one_num[41], 1 },
//    /* [ 18] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[28], &right_set_one_num[28], 0 },
//    /* [ 19] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[27], &right_set_one_num[27], 1 },
//    /* [ 20] 2-5 (dur=2.00s, idx= 17, dist=3) -> right_set_twobeat */
//    { right_set_twobeat[17], &right_set_two_num[17], 3 },
//    /* [ 21] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[56], &right_set_one_num[56], 0 },
//    /* [ 22] 5-4 (dur=1.00s, idx= 55, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[55], &right_set_one_num[55], 1 },
//    /* [ 23] 4-4 (dur=1.00s, idx= 42, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[42], &right_set_one_num[42], 0 },
//    /* [ 24] 4-3 (dur=1.00s, idx= 41, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[41], &right_set_one_num[41], 1 },
//    /* [ 25] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[28], &right_set_one_num[28], 0 },
//    /* [ 26] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[27], &right_set_one_num[27], 1 },
//    /* [ 27] 2-1 (dur=2.00s, idx= 13, dist=1) -> right_set_twobeat */
//    { right_set_twobeat[13], &right_set_two_num[13], 1 },
//    /* [ 28] 1-1 (dur=1.00s, idx=  0, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[0], &right_set_one_num[0], 0 },
//    /* [ 29] 1-5 (dur=1.00s, idx=  4, dist=4) -> right_set_onebeat */
//    { right_set_onebeat[4], &right_set_one_num[4], 4 },
//    /* [ 30] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[56], &right_set_one_num[56], 0 },
//    /* [ 31] 5-6 (dur=1.00s, idx= 57, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[57], &right_set_one_num[57], 1 },
//    /* [ 32] 6-6 (dur=1.00s, idx= 70, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[70], &right_set_one_num[70], 0 },
//    /* [ 33] 6-5 (dur=1.00s, idx= 69, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[69], &right_set_one_num[69], 1 },
//    /* [ 34] 5-4 (dur=2.00s, idx= 55, dist=1) -> right_set_twobeat */
//    { right_set_twobeat[55], &right_set_two_num[55], 1 },
//    /* [ 35] 4-4 (dur=1.00s, idx= 42, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[42], &right_set_one_num[42], 0 },
//    /* [ 36] 4-3 (dur=1.00s, idx= 41, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[41], &right_set_one_num[41], 1 },
//    /* [ 37] 3-3 (dur=1.00s, idx= 28, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[28], &right_set_one_num[28], 0 },
//    /* [ 38] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[27], &right_set_one_num[27], 1 },
//    /* [ 39] 2-2 (dur=1.00s, idx= 14, dist=0) -> right_set_onebeat */
//    { right_set_onebeat[14], &right_set_one_num[14], 0 },
//    /* [ 40] 2-1 (dur=1.00s, idx= 13, dist=1) -> right_set_onebeat */
//    { right_set_onebeat[13], &right_set_one_num[13], 1 }
//};

//小星星（左半边）
static const TrackPoint robot_track_arry3[42] = {
    /* [first] 1-1 (dur=1.00s, idx=  0, dist=0) -> left_set_onebeat */
    { left_set_onebeat[0], &left_set_one_num[0], 0 },
    /* [  0] 1-1 (dur=1.00s, idx=  0, dist=0) -> left_set_onebeat */
    { left_set_onebeat[0], &left_set_one_num[0], 0 },
    /* [  1] 1-5 (dur=1.00s, idx=  4, dist=4) -> left_set_onebeat */
    { left_set_onebeat[4], &left_set_one_num[4], 4 },
    /* [  2] 5-5 (dur=1.00s, idx= 52, dist=0) -> left_set_onebeat */
    { left_set_onebeat[52], &left_set_one_num[52], 0 },
    /* [  3] 5-6 (dur=1.00s, idx= 53, dist=1) -> left_set_onebeat */
    { left_set_onebeat[53], &left_set_one_num[53], 1 },
    /* [  4] 6-6 (dur=1.00s, idx= 65, dist=0) -> left_set_onebeat */
    { left_set_onebeat[65], &left_set_one_num[65], 0 },
    /* [  5] 6-5 (dur=1.00s, idx= 64, dist=1) -> left_set_onebeat */
    { left_set_onebeat[64], &left_set_one_num[64], 1 },
    /* [  6] 5-4 (dur=2.00s, idx= 51, dist=1) -> left_set_twobeat */
    { left_set_twobeat[51], &left_set_two_num[51], 1 },
    /* [  7] 4-4 (dur=1.00s, idx= 39, dist=0) -> left_set_onebeat */
    { left_set_onebeat[39], &left_set_one_num[39], 0 },
    /* [  8] 4-3 (dur=1.00s, idx= 38, dist=1) -> left_set_onebeat */
    { left_set_onebeat[38], &left_set_one_num[38], 1 },
    /* [  9] 3-3 (dur=1.00s, idx= 26, dist=0) -> left_set_onebeat */
    { left_set_onebeat[26], &left_set_one_num[26], 0 },
    /* [ 10] 3-2 (dur=1.00s, idx= 25, dist=1) -> left_set_onebeat */
    { left_set_onebeat[25], &left_set_one_num[25], 1 },
    /* [ 11] 2-2 (dur=1.00s, idx= 13, dist=0) -> left_set_onebeat */
    { left_set_onebeat[13], &left_set_one_num[13], 0 },
    /* [ 12] 2-1 (dur=1.00s, idx= 12, dist=1) -> left_set_onebeat */
    { left_set_onebeat[12], &left_set_one_num[12], 1 },
    /* [ 13] 1-5 (dur=2.00s, idx=  4, dist=4) -> left_set_twobeat */
    { left_set_twobeat[4], &left_set_two_num[4], 4 },
    /* [ 14] 5-5 (dur=1.00s, idx= 52, dist=0) -> left_set_onebeat */
    { left_set_onebeat[52], &left_set_one_num[52], 0 },
    /* [ 15] 5-4 (dur=1.00s, idx= 51, dist=1) -> left_set_onebeat */
    { left_set_onebeat[51], &left_set_one_num[51], 1 },
    /* [ 16] 4-4 (dur=1.00s, idx= 39, dist=0) -> left_set_onebeat */
    { left_set_onebeat[39], &left_set_one_num[39], 0 },
    /* [ 17] 4-3 (dur=1.00s, idx= 38, dist=1) -> left_set_onebeat */
    { left_set_onebeat[38], &left_set_one_num[38], 1 },
    /* [ 18] 3-3 (dur=1.00s, idx= 26, dist=0) -> left_set_onebeat */
    { left_set_onebeat[26], &left_set_one_num[26], 0 },
    /* [ 19] 3-2 (dur=1.00s, idx= 25, dist=1) -> left_set_onebeat */
    { left_set_onebeat[25], &left_set_one_num[25], 1 },
    /* [ 20] 2-5 (dur=2.00s, idx= 16, dist=3) -> left_set_twobeat */
    { left_set_twobeat[16], &left_set_two_num[16], 3 },
    /* [ 21] 5-5 (dur=1.00s, idx= 52, dist=0) -> left_set_onebeat */
    { left_set_onebeat[52], &left_set_one_num[52], 0 },
    /* [ 22] 5-4 (dur=1.00s, idx= 51, dist=1) -> left_set_onebeat */
    { left_set_onebeat[51], &left_set_one_num[51], 1 },
    /* [ 23] 4-4 (dur=1.00s, idx= 39, dist=0) -> left_set_onebeat */
    { left_set_onebeat[39], &left_set_one_num[39], 0 },
    /* [ 24] 4-3 (dur=1.00s, idx= 38, dist=1) -> left_set_onebeat */
    { left_set_onebeat[38], &left_set_one_num[38], 1 },
    /* [ 25] 3-3 (dur=1.00s, idx= 26, dist=0) -> left_set_onebeat */
    { left_set_onebeat[26], &left_set_one_num[26], 0 },
    /* [ 26] 3-2 (dur=1.00s, idx= 25, dist=1) -> left_set_onebeat */
    { left_set_onebeat[25], &left_set_one_num[25], 1 },
    /* [ 27] 2-1 (dur=2.00s, idx= 12, dist=1) -> left_set_twobeat */
    { left_set_twobeat[12], &left_set_two_num[12], 1 },
    /* [ 28] 1-1 (dur=1.00s, idx=  0, dist=0) -> left_set_onebeat */
    { left_set_onebeat[0], &left_set_one_num[0], 0 },
    /* [ 29] 1-5 (dur=1.00s, idx=  4, dist=4) -> left_set_onebeat */
    { left_set_onebeat[4], &left_set_one_num[4], 4 },
    /* [ 30] 5-5 (dur=1.00s, idx= 52, dist=0) -> left_set_onebeat */
    { left_set_onebeat[52], &left_set_one_num[52], 0 },
    /* [ 31] 5-6 (dur=1.00s, idx= 53, dist=1) -> left_set_onebeat */
    { left_set_onebeat[53], &left_set_one_num[53], 1 },
    /* [ 32] 6-6 (dur=1.00s, idx= 65, dist=0) -> left_set_onebeat */
    { left_set_onebeat[65], &left_set_one_num[65], 0 },
    /* [ 33] 6-5 (dur=1.00s, idx= 64, dist=1) -> left_set_onebeat */
    { left_set_onebeat[64], &left_set_one_num[64], 1 },
    /* [ 34] 5-4 (dur=2.00s, idx= 51, dist=1) -> left_set_twobeat */
    { left_set_twobeat[51], &left_set_two_num[51], 1 },
    /* [ 35] 4-4 (dur=1.00s, idx= 39, dist=0) -> left_set_onebeat */
    { left_set_onebeat[39], &left_set_one_num[39], 0 },
    /* [ 36] 4-3 (dur=1.00s, idx= 38, dist=1) -> left_set_onebeat */
    { left_set_onebeat[38], &left_set_one_num[38], 1 },
    /* [ 37] 3-3 (dur=1.00s, idx= 26, dist=0) -> left_set_onebeat */
    { left_set_onebeat[26], &left_set_one_num[26], 0 },
    /* [ 38] 3-2 (dur=1.00s, idx= 25, dist=1) -> left_set_onebeat */
    { left_set_onebeat[25], &left_set_one_num[25], 1 },
    /* [ 39] 2-2 (dur=1.00s, idx= 13, dist=0) -> left_set_onebeat */
    { left_set_onebeat[13], &left_set_one_num[13], 0 },
    /* [ 40] 2-1 (dur=1.00s, idx= 12, dist=1) -> left_set_onebeat */
    { left_set_onebeat[12], &left_set_one_num[12], 1 }
};

//找朋友
static const TrackPoint robot_track_arry4[28] = {
    /* [first] 5-5 (dur=0.50s, idx= 56, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[56], &right_set_half_num[56], 0 },
    /* [  0] 5-6 (dur=0.50s, idx= 57, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[57], &right_set_half_num[57], 1 },
    /* [  1] 6-5 (dur=0.50s, idx= 69, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[69], &right_set_half_num[69], 1 },
    /* [  2] 5-6 (dur=0.50s, idx= 57, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[57], &right_set_half_num[57], 1 },
    /* [  3] 6-5 (dur=0.50s, idx= 69, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[69], &right_set_half_num[69], 1 },
    /* [  4] 5-6 (dur=0.50s, idx= 57, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[57], &right_set_half_num[57], 1 },
    /* [  5] 6-5 (dur=0.50s, idx= 69, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[69], &right_set_half_num[69], 1 },
    /* [  6] 5-5 (dur=1.00s, idx= 56, dist=0) -> right_set_onebeat */
    { right_set_onebeat[56], &right_set_one_num[56], 0 },
    /* [  7] 5-8 (dur=0.50s, idx= 59, dist=3) -> right_set_halfbeat */
    { right_set_halfbeat[59], &right_set_half_num[59], 3 },
    /* [  8] 8-7 (dur=0.50s, idx= 97, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[97], &right_set_half_num[97], 1 },
    /* [  9] 7-6 (dur=0.50s, idx= 83, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[83], &right_set_half_num[83], 1 },
    /* [ 10] 6-5 (dur=0.50s, idx= 69, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[69], &right_set_half_num[69], 1 },
    /* [ 11] 5-5 (dur=0.50s, idx= 56, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[56], &right_set_half_num[56], 0 },
    /* [ 12] 5-3 (dur=0.50s, idx= 54, dist=2) -> right_set_halfbeat */
    { right_set_halfbeat[54], &right_set_half_num[54], 2 },
    /* [ 13] 3-5 (dur=1.00s, idx= 30, dist=2) -> right_set_onebeat */
    { right_set_onebeat[30], &right_set_one_num[30], 2 },
    /* [ 14] 5-5 (dur=0.50s, idx= 56, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[56], &right_set_half_num[56], 0 },
    /* [ 15] 5-3 (dur=0.50s, idx= 54, dist=2) -> right_set_halfbeat */
    { right_set_halfbeat[54], &right_set_half_num[54], 2 },
    /* [ 16] 3-3 (dur=0.50s, idx= 28, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[28], &right_set_half_num[28], 0 },
    /* [ 17] 3-5 (dur=0.50s, idx= 30, dist=2) -> right_set_halfbeat */
    { right_set_halfbeat[30], &right_set_half_num[30], 2 },
    /* [ 18] 5-5 (dur=0.50s, idx= 56, dist=0) -> right_set_halfbeat */
    { right_set_halfbeat[56], &right_set_half_num[56], 0 },
    /* [ 19] 5-3 (dur=0.50s, idx= 54, dist=2) -> right_set_halfbeat */
    { right_set_halfbeat[54], &right_set_half_num[54], 2 },
    /* [ 20] 3-2 (dur=1.00s, idx= 27, dist=1) -> right_set_onebeat */
    { right_set_onebeat[27], &right_set_one_num[27], 1 },
    /* [ 21] 2-4 (dur=0.50s, idx= 16, dist=2) -> right_set_halfbeat */
    { right_set_halfbeat[16], &right_set_half_num[16], 2 },
    /* [ 22] 4-3 (dur=0.50s, idx= 41, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[41], &right_set_half_num[41], 1 },
    /* [ 23] 3-2 (dur=0.50s, idx= 27, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[27], &right_set_half_num[27], 1 },
    /* [ 24] 2-1 (dur=0.50s, idx= 13, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[13], &right_set_half_num[13], 1 },
    /* [ 25] 1-2 (dur=0.50s, idx=  1, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[1], &right_set_half_num[1], 1 },
    /* [ 26] 2-1 (dur=0.50s, idx= 13, dist=1) -> right_set_halfbeat */
    { right_set_halfbeat[13], &right_set_half_num[13], 1 }
};
#endif
