type profile = {
  id: string,
  name: string,
  avatarUrl: string,
};

let loadImage = (url, cb) =>
  Js.Global.setTimeout(() => cb({j|image for $url|j}), 500) |> ignore;

let loadProfile = (id, cb) =>
  Js.Global.setTimeout(
    () => {
      let profile: profile = {
        id,
        name: "Profile Name",
        avatarUrl: {j|/img/$id/avatar.jpg|j},
      };
      cb(profile);
    },
    500,
  )
  |> ignore;

let loadAvatarImage = (id, cb) => cb(id);

loadAvatarImage("abc123", id =>
  loadProfile(id, profile => loadImage(profile.avatarUrl, Js.log))
);