from plyer import notification
import os
import glob

notification.notify(
    title = "Title",
    message="Message",
    app_icon='./icon.png',
    timeout=5
    )
