using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace testapp {
    public class PlantAsset: Asset {

        Texture2D texture;

        public PlantAsset(Texture2D texture) {
            this.texture = texture;
        }

        public void draw(SpriteBatch spriteBatch) {
            spriteBatch.Draw(texture, new Rectangle(0, 0, 128, 128), Color.White);
        }
    }
}
