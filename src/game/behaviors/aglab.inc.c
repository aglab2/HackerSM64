void bhv_gate_rotat_ctl_init(void)
{
    f32 d;
    o->oGateCtlRotat = cur_obj_find_nearest_object_with_behavior(bhvGateRotat, &d);
    obj_scale(o->oGateCtlRotat, 1.2f);
    o->oGateCtlRotat->oFaceAngleYaw = (0x10000 / 3) * 2;
    o->oGateCtlState = 2;
}

extern Gfx mat_ccm_dl_f3d_material_002[];
extern Texture gate_draw_s1[];
extern Texture gate_draw_s2[];
extern Texture ccm_dl_default_rgba16[];

static Texture* sTextures[] = { gate_draw_s1, gate_draw_s2, ccm_dl_default_rgba16 };

void bhv_gate_rotat_ctl_loop(void)
{
    if (!o->oAction)
    {
        if (gMarioObject->platform == o)
        {
            o->oAction = 1;
            obj_scale_xyz(o, 1.f, 0.1f, 1.f);
            o->oGateCtlState++;
            o->oGateCtlState %= 3;
            o->oGateCtlRotat->oFaceAngleYaw = (0x10000 / 3) * o->oGateCtlState;
            Texture** texture = segmented_to_virtual(mat_ccm_dl_f3d_material_002);
            texture[11] = sTextures[o->oGateCtlState];
        }
    }
    else
    {
        if (o->oTimer < 10)
            return;

        if (gMarioObject->platform != o)
        {
            o->oAction = 0;
            obj_scale_xyz(o, 1.f, 1.f, 1.f);
        }
    }
}

extern Gfx mat_totwc_dl__auto_9_f3d[];
void bhv_rainbow_ctl_loop()
{
    u8* envc = segmented_to_virtual(mat_totwc_dl__auto_9_f3d) + 12 * 8 + 7;
    *envc = (1.5f + sins(o->oTimer * 937)) * 0x40;
}
