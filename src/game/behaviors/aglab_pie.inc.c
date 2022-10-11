struct PieObjectDesc
{
    s16 model;
    f32 x;
    f32 y;
    f32 z;
    const BehaviorScript* bhv;
};

struct PieObjectDesc sPieCoins[] = 
{
#define OBJECT(model, x, y, z, a1, a2, a3, p, bhv) { model, x, y, z, bhv }
    OBJECT(MODEL_YELLOW_COIN, 4868, -31, -4930, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_YELLOW_COIN, 4868, -31, -4930, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_YELLOW_COIN, 4868, -31, -4930, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_RED_COIN, 4887, -31, -9823, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_YELLOW_COIN, 7477, -31, -5517, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_YELLOW_COIN, 7477, -31, -5517, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_YELLOW_COIN, 7477, -31, -5517, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_RED_COIN, 4887, -31, -9823, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_RED_COIN, 4887, -31, -9823, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_RED_COIN, 9172, -31, -9251, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_RED_COIN, 9172, -31, -9251, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_RED_COIN, 9172, -31, -9251, 0, 90, 0, 0x00000000, bhvRedCoin),
    OBJECT(MODEL_YELLOW_COIN, 6127, -31, -5506, 0, 90, 0, 0x00000000, bhvYellowCoin),
    OBJECT(MODEL_BLUE_COIN, 8633, -31, -6701, 0, 90, 0, 0x00000000, bhvYellowCoin),
    OBJECT(MODEL_RED_COIN, 8005, -31, -8016, 0, 90, 0, 0x00000000, bhvYellowCoin),
    OBJECT(MODEL_RED_COIN, 7388, -31, -8607, 0, 90, 0, 0x00000000, bhvYellowCoin),
    OBJECT(MODEL_RED_COIN, 7995, -31, -4928, 0, 90, 0, 0x00000000, bhvYellowCoin),
    OBJECT(MODEL_YELLOW_COIN, 4898, -31, -6674, 0, 90, 0, 0x00000000, bhvYellowCoin),
    OBJECT(MODEL_YELLOW_COIN, 4343, -31, -8634, 0, 90, 0, 0x00000000, bhvYellowCoin),
    OBJECT(MODEL_BLUE_COIN, 6089, -31, -8617, 0, 90, 0, 0x00000000, bhvYellowCoin),
#undef OBJECT
};

u8 sPieClearCoins = 0;

void pie_coiner_loop()
{
    if (sPieClearCoins)
    {
        cur_obj_unload_object_with_behavior(bhvYellowCoin);
        cur_obj_unload_object_with_behavior(bhvRedCoin);

        for (unsigned int i = 0; i < sizeof(sPieCoins) / sizeof(*sPieCoins); i++)
        {
            struct PieObjectDesc* desc = &sPieCoins[i];
            struct Object* coin = spawn_object(o, desc->model, desc->bhv);
            coin->oPosX = desc->x;
            coin->oPosY = desc->y;
            coin->oPosZ = desc->z;
        }
        sPieClearCoins = 0;
    }
}

void pie_coiner_pre_area_loop()
{
    if (0 == sPieClearCoins)
    {
        cur_obj_unload_object_with_behavior(bhvCoinFormation);
        cur_obj_unload_object_with_behavior(bhvOneCoin);
        {
            {
                struct Object* arrow = spawn_object(o, MODEL_NONE, bhvCoinFormation);
                arrow->oPosX = 10303.f;
                arrow->oPosY = 146.f;
                arrow->oPosZ = 13795.f;
                arrow->oBehParams2ndByte = 4;
                arrow->oFaceAngleYaw = 0x4000;
            }
            for (int i = 0; i < 5; i++)
            {
                struct Object* coin = spawn_object(o, MODEL_YELLOW_COIN, bhvOneCoin);
                coin->oPosX = 10788.f;
                coin->oPosY = 146.f;
                coin->oPosZ = 13795.f;
            }
            {
                struct Object* coin = spawn_object(o, MODEL_YELLOW_COIN, bhvOneCoin);
                coin->oPosX = 10788.f;
                coin->oPosY = 146.f;
                coin->oPosZ = 15045.f;
            }
        }
        sPieClearCoins = 1;
    }
}
